import asyncio
from aiogram import Bot, Dispatcher, F
from aiogram.types import Message
from aiogram.filters import CommandStart
from aiogram.fsm.state import StatesGroup, State
from aiogram.fsm.context import FSMContext
from aiogram.fsm.storage.memory import MemoryStorage

from config import BOT_TOKEN
from logic import interpret, do_calculation, extract_price, _detect_exact_or_fuzzy

# ---- FSM ----
class CalcStates(StatesGroup):
    await_item = State()
    await_category = State()
    await_mount = State()

async def on_start(message: Message):
    await message.answer(
        "👋 Hi! Send something like:\n"
        "• `2560 ds`\n• `2560 smartphone`\n• `2560 display`\n• `dl2560`\n"
        "• or just `2560` (I’ll ask for Mount under General).\n\n"
        "Use shortcuts (ds/bs/di/bi/dt/bt/dl/bl/kl/g/e)."
    )

async def handle_text(message: Message, state: FSMContext):
    if not BOT_TOKEN or "PUT-YOUR-TOKEN" in BOT_TOKEN:
        await message.answer("❗ BOT_TOKEN is not set. Please configure your .env first.")
        return

    data = await state.get_data()
    mode = data.get("mode")

    if mode == "await_item":
        options = data["options"]
        from logic import parse_int_choice
        idx = parse_int_choice(message.text, len(options))
        if idx is not None:
            choice = options[idx]
            cat = data["category"]
            item = choice
            if data.get("needs_mount"):
                await message.answer(f"🔧 Enter Mount for {cat}/{item}:")
                await state.set_state(CalcStates.await_mount)
                await state.update_data(mode="await_mount", category=cat, item=item, price=data["price"])
                return
            res = do_calculation(data["price"], cat, item)
            await message.answer(res)
            await state.clear()
            return

        picked = _detect_exact_or_fuzzy(message.text, options, "item")
        if picked:
            cat = data["category"]
            item = picked
            if data.get("needs_mount"):
                await message.answer(f"🔧 Enter Mount for {cat}/{item}:")
                await state.set_state(CalcStates.await_mount)
                await state.update_data(mode="await_mount", category=cat, item=item, price=data["price"])
                return
            res = do_calculation(data["price"], cat, item)
            await message.answer(res)
            await state.clear()
            return

        await message.answer("❌ Invalid choice. Type `1..{}` or one of: {}"
                             .format(len(options), ", ".join(options)))
        return

    if mode == "await_category":
        options = data["options"]
        from logic import parse_int_choice
        idx = parse_int_choice(message.text, len(options))
        if idx is not None:
            choice = options[idx]
            cat = choice
            item = data["item"]
            if data.get("needs_mount"):
                await message.answer(f"🔧 Enter Mount for {cat}/{item}:")
                await state.set_state(CalcStates.await_mount)
                await state.update_data(mode="await_mount", category=cat, item=item, price=data["price"])
                return
            res = do_calculation(data["price"], cat, item)
            await message.answer(res)
            await state.clear()
            return

        picked = _detect_exact_or_fuzzy(message.text, options, "category")
        if picked:
            cat = picked
            item = data["item"]
            if data.get("needs_mount"):
                await message.answer(f"🔧 Enter Mount for {cat}/{item}:")
                await state.set_state(CalcStates.await_mount)
                await state.update_data(mode="await_mount", category=cat, item=item, price=data["price"])
                return
            res = do_calculation(data["price"], cat, item)
            await message.answer(res)
            await state.clear()
            return

        await message.answer("❌ Invalid choice. Type `1..{}` or one of: {}"
                             .format(len(options), ", ".join(options)))
        return

    if mode == "await_mount":
        mount = extract_price(message.text)
        if mount is None:
            await message.answer("🧮 Please enter Mount as a number, e.g. `350`.")
            return
        res = do_calculation(data["price"], data["category"], data["item"], mount)
        await message.answer(res)
        await state.clear()
        return

    # New message → interpret
    action, payload = interpret(message.text)

    if action == "error":
        await message.answer(payload["prompt"])
        return

    if action == "ask_item":
        await message.answer(payload["prompt"])
        await state.set_state(CalcStates.await_item)
        await state.update_data(
            mode="await_item",
            price=payload["price"],
            category=payload["category"],
            options=payload["options"],
            needs_mount=False,
        )
        return

    if action == "ask_category":
        await message.answer(payload["prompt"])
        await state.set_state(CalcStates.await_category)
        await state.update_data(
            mode="await_category",
            price=payload["price"],
            item=payload["item"],
            options=payload["options"],
            needs_mount=False,
        )
        return

    if action == "ask_mount":
        await message.answer(payload["prompt"])
        await state.set_state(CalcStates.await_mount)
        await state.update_data(
            mode="await_mount",
            price=payload["price"],
            category=payload["category"],
            item=payload["item"],
        )
        return

    if action == "calculate":
        res = do_calculation(payload["price"], payload["category"], payload["item"])
        await message.answer(res)
        return

    await message.answer(f"⚠️ Unhandled action: {action}")

def register_handlers(dp: Dispatcher):
    dp.message.register(on_start, CommandStart())
    dp.message.register(handle_text, F.text)

async def main():
    if not BOT_TOKEN or "PUT-YOUR-TOKEN" in BOT_TOKEN:
        raise SystemExit("BOT_TOKEN is missing. Add it to .env (BOT_TOKEN=123:ABC).")
    bot = Bot(BOT_TOKEN)
    dp = Dispatcher(storage=MemoryStorage())
    register_handlers(dp)
    await dp.start_polling(bot)

if __name__ == "__main__":
    asyncio.run(main())
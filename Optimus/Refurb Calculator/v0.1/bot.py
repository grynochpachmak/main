# bot.py
from aiogram import Bot, Dispatcher, types
from aiogram.filters import CommandStart, Command
import asyncio, os, json
from logic import process_message

TOKEN = "8343939504:AAFyer_K3Dxt8wL-6vbYc4HxiNAGerJFR58"
dp = Dispatcher()

# ---------- /start ----------
@dp.message(CommandStart())
async def start(m: types.Message):
    await m.answer(
        "🤖 *Refurb Calculator Bot* is active\\!\n"
        "Try:\n"
        "• `2560 ds`\n"
        "• `ds2560`\n"
        "• `2560 smartphone display`\n"
        "• `1400 dlt`\n\n"
        "Use /help for instructions or /shortcuts to view available codes\\.",
        parse_mode="MarkdownV2"
    )

# === /help ===
@dp.message(Command("help"))
async def help_cmd(m: types.Message):
    text = (
        "📘 *How to use the bot*\n\n"
        "1\\. Type a *price* followed by a *shortcut* or words\\.\n"
        "Examples:\n"
        "   • `2560 ds` → Smartphone Display\n"
        "   • `2560di` → iPhone Display\n"
        "   • `1400 dlt` → Laptop Display \\(Touch\\)\n"
        "2\\. Order doesn't matter \\- you can write `ds2560` or `2560 ds`\n"
        "3\\. Prices are rounded *up* to the nearest 5 MDL\n"
        "4\\. If no shortcut is given, the default category is *Smartphone*\n"
        "5\\. Type /shortcuts to see all available codes"
    )
    await m.answer(text, parse_mode="MarkdownV2")

# === /shortcuts ===
@dp.message(Command("shortcuts"))
async def shortcuts_cmd(m: types.Message):
    try:
        with open("data/shortcuts.json", "r", encoding="utf-8") as f:
            data = json.load(f)
    except Exception as e:
        await m.answer(f"Error loading shortcuts: {e}")
        return

    # group by category/item
    grouped = {}
    for code, (cat, item) in data.items():
        key = f"{cat.capitalize()} / {item.replace('_', ' ')}"
        grouped.setdefault(key, []).append(code)

    text = "📚 *Available shortcuts:*\n\n"
    for k, lst in sorted(grouped.items()):
        joined = ", ".join(f"`{c}`" for c in sorted(lst))
        text += f"*{k}:*\n{joined}\n\n"

    await m.answer(text, parse_mode="MarkdownV2")

# === default message handler ===
@dp.message()
async def handle(m: types.Message):
    try:
        result = process_message(m.text)
    except Exception as e:
        err = str(e).replace("\\", "\\\\").replace("-", "\\-").replace(".", "\\.")
        result = f"Error: {err}"
    await m.answer(result, parse_mode="MarkdownV2")

# === main ===
async def main():
    bot = Bot(token=TOKEN)
    await dp.start_polling(bot)

if __name__ == "__main__":
    asyncio.run(main())

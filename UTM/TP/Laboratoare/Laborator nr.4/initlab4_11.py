# initlab4_11.py

word = "cuvant"
words = [word] * 100  # 100 de cuvinte
content = " ".join(words) + "\n"

with open("hello.txt", "w", encoding="utf-8") as f:
    f.write(content)

print("hello.txt cu 100 de cuvinte creat pentru lab4_11.")
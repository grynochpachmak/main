sir = input("Introduceti un sir de caractere: ")
print("Sirul introdus este:", sir)

sum = 0
for i in sir:
    if i.isupper():
        sum += 1

print("Numarul de litere mari este:", sum)
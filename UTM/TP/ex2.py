sir = input("Introduceti un sir de caractere: ")
print("Sirul introdus este:", sir)

sum = 0
for i in sir:
    if i.isdigit():
        sum += 1

print("Numarul de cifre este:", sum)
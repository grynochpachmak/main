sir = input("Introduceti un sir de caractere: ")
print("Sirul introdus este:", sir)

sum = 0
for i in sir:
    if not i.isalnum():
        sum += 1

print("Numarul de caractere speciale este:", sum)
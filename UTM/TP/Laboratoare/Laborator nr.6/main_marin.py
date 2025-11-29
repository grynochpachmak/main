# main_marin.py
# November 2025
# Juncu Marin, gr. MN-251
# Laborator nr.6: Module proprii și fișiere text

import util_marin

def readInt(message):
    while True:
        userInput = input(message)
        try:
            return int(userInput)
        except ValueError:
            print("Eroare: introdu un număr întreg valid.")


def main():
    # read username
    userName = input("Introdu numele tău: ").strip()

    # read user num
    testNumber = readInt("Introdu numărul pentru testare: ")

    # isPrime
    if util_marin.isPrime(testNumber):
        print(f"\n{testNumber} este număr prim.")
    else:
        print(f"\n{testNumber} nu este număr prim.")

    # factorial
    fact = util_marin.factorial(testNumber)
    if fact is not None:
        print(f"\nFactorialul lui {testNumber} este {fact}.")
    else:
        print("\nNu pot calcula factorialul unui număr negativ.")

    # save file
    fileName = f"prime_{userName.lower()}.txt"
    util_marin.savePrimes(testNumber, fileName)
    print(f"\nNumerele prime până la {testNumber} au fost salvate în fișierul {fileName}.")

    # save desc
    fileNameDesc = f"prime_desc_{userName.lower()}.txt"
    util_marin.savePrimesDesc(testNumber, fileNameDesc)
    print(f"Numerele prime descrescător au fost salvate în {fileNameDesc}.")

    # digitCount
    digitCount = util_marin.factorialDigits(testNumber)
    if digitCount is not None:
        print(f"\nFactorialul lui {testNumber} are {digitCount} cifre.")
    else:
        print("\nNu se poate calcula numărul de cifre pentru n negativ.")

if __name__ == "__main__":
    main()

# -*- coding: utf-8 -*-
# November 2025
# Juncu Marin, gr. MN-251
# Laborator nr.6: Module proprii și fișiere text
# Fișier: util_marin.py

def isPrime(n):
    if n < 2:
        return False

    divisor = 2
    while divisor * divisor <= n:
        if n % divisor == 0:
            return False
        divisor += 1

    return True


def factorial(n):
    if n < 0:
        return None

    result = 1
    for i in range(1, n + 1):
        result *= i

    return result


def savePrimes(limit, fileName):
    with open(fileName, "w", encoding="utf-8") as file:
        for num in range(2, limit + 1):
            if isPrime(num):
                file.write(str(num) + "\n")


def savePrimesDesc(limit, fileName):
    primeList = []

    for num in range(2, limit + 1):
        if isPrime(num):
            primeList.append(num)

    primeList.sort(reverse=True)

    with open(fileName, "w", encoding="utf-8") as file:
        for p in primeList:
            file.write(str(p) + "\n")


def factorialDigits(n):
    fact = factorial(n)
    if fact is None:
        return None

    return len(str(fact))
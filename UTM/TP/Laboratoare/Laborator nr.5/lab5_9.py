# lab5_9
# November 2025
# Juncu Marin MN-251
# Laborator nr.5: Module și pachete în Python
# Sarcina 9: Criptează și decriptează un cuvânt simplu folosind modulul cryptography.

from cryptography.fernet import Fernet

cheie = Fernet.generate_key()
f = Fernet(cheie)

text = "hello"
criptat = f.encrypt(text.encode())
decriptat = f.decrypt(criptat).decode()

print("Criptat:", criptat)
print("Decriptat:", decriptat)
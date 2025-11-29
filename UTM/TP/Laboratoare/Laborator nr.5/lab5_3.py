# lab5_3
# November 2025
# Juncu Marin MN-251
# Laborator nr.5: Module și pachete în Python
# Sarcina 3: Afișează data și ora curentă într-un format simplu folosind modulul datetime.

import datetime

data_curenta = datetime.datetime.now()
print(data_curenta.strftime("%Y-%m-%d %H:%M:%S"))

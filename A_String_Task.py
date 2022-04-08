i = input()
i = i.lower()
for j in i:
    if not j in "aeyuio": print(f".{j}", end="")
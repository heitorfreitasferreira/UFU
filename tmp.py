x = int(input()) # 3
y = int(input()) # 7
maior = 0
menor = 0
if x >= y:
    maior = x
    menor = y
else:
    maior = y
    menor = x
acum = 0

while menor <= maior:
    if menor % 2 == 1:
        acum = acum + menor
    menor = menor + 1


print(acum)
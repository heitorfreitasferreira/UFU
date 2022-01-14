import random

uppercaseLetter1=chr(random.randint(65,90))
uppercaseLetter2=chr(random.randint(65,90))
lowercaseLetter1=chr(random.randint(97,122))
lowercaseLetter2=chr(random.randint(97,122))
digit1=chr(random.randint(48,57))
digit2=chr(random.randint(48,57))
ponctuationSign1=chr(random.randint(33,43))
ponctuationSign2=chr(random.randint(33,43))
password = uppercaseLetter1 + uppercaseLetter2 + lowercaseLetter1 + lowercaseLetter2 + digit1 + digit2 + ponctuationSign1 + ponctuationSign2

password = ''.join(random.sample(password,len(password))) # shuffle, entregar essa parte do código para os alunos
print(password)
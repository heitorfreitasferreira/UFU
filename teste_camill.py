############## Aulão de Python ##############
############## Descuba sua Varinha ##############

############### Importar pacotes ##############
import random #importar pacote random

################# Introdução !#######################
print("Responda o questionário e no final descubra qual é a sua varinha!")
print("Não existe resposta correta ou errada, afinal é a varinha que escolhe o bruxo! No entanto, marque apenas uma opção.")
print()

################# Pergunta 1 #################
print("################# Pergunta 1 #################")
print("O professor de Poções passa uma tarefa surpresa. Você precisa preparar a Poção Morto-Vivo e pode cozinhar sozinho ou em dupla. O seu colega do lado te chama para fazer juntos e você:")
print("A - Não aceita porque você prefere fazer tudo sozinho")
print("B - Não aceita, mas diz que gostaria de compartilhar informações e no final cada uma entregará a sua")
print("C - Aceita, mas diz que você é o líder do grupo e vai comandar a dupla")
print("D - Aceita porque é uma tarefa surpresa e você não estava preparado, então toda ajuda é bem vinda")
resp1 = input().upper() #recebe o input da primeira pergunta e deixa a letra maiúscula
#Cálculo da resposta da Pergunta 1
if(resp1 == "A"):
  flexibilidade = "inflexível"
elif(resp1 == "D"):
  flexibilidade = "flexível"
else:
  flexibilidade = "meio flexível"

       print()
       ################# Pergunta 2 #################
       print("################# Pergunta 2 #################")
       print("Escolha uma característica: ")
       print("1 - Lealdade")
       print("2 - Inteligência")
       print("3 - Resistência")
       resp2 = int(input()) #input
       print()
       ################# Pergunta 3 #################

       print("################# Pergunta 3 #################")
       print("Escolha uma característica: ")
       print("A - Ganância")
       print("B - Arrogância")
       print("C - Resistência")

       resp3 = input().upper()
       print()
       #Vetores com todos os tipos de madeiras
       madeira1 = ["acácia", "freixo", "cedro"]
       madeira2 = ["macieira", "carvalho", "pinheiro"]
       madeira3 = ["pau-brasil", "videira", "salgueiro"]

       #Resposta para a madeira
       if(resp3 == "A"):
         madeira = madeira1[resp2 -1]
         elif(resp3 == "B"):
           madeira = madeira2[resp2 -1]
           else:
             madeira = madeira3[resp2 -1]
               
               ################# Pergunta 4 #################
               print("################# Pergunta 4 #################")
               print("Escolha uma matéria de Hogwarts:")
               print("1 - Defesa Contra as Artes das Trevas")
               print("2 - Transfiguração")
               print("3 - Feitiços")
               print("4 - Poções")
               resp4 = int(input())
               print()
               ################# Pergunta 5 #################
               print("################# Pergunta 5 #################")
               print("Escolha uma casa de Hogwarts:")
               print("A - Grifinória")
               print("B - Sonserina")
               print("C - Lufa-lufa")
               print("D - Corvinal")
               resp5 = input().upper()

               #Vetores com todos os tipos de núcleo da varinha
               nucleo1 = ["pelo de unicórnio", "bigode de trasgo", "pena de fênix", "fragmentos de chifre de basilisco"]
               nucleo2 = ["corda de coração de dragão", "cabelo de veela", "pena da cauda do pássaro-trovão", "pelo da cauda de testrálio"]


               #Resposta para o núcleo
               if(resp5 == "A" or resp5 == "C"):
                 nucleo = nucleo1[resp4 -1]
                 elif(resp5 == "B" or resp5 == "D"):
                   nucleo = nucleo2[resp4 -1]


                   ################# Tamanho da Varinha #################
                   comprimento = random.randrange(20,36) #gera um número aleatório entre 20 e 36
                   print()
                   ################# Parte final #################
                   print("Pronto! Você respondeu todas as suas perguntas!")
                   print()
                   print("######################################################")
                   print(f"A sua varinha possui {comprimento} cm e é {flexibilidade}, feita com a madeira de uma árvore de {madeira} e possui núcleo de {nucleo}!")
                   print("######################################################")

                   ################# DESAFIO #################
                   #O comprimento de uma varinha varia de acordo com a altura do bruxo. Gerar um valor aleatório para ser o comprimento da varinha não é o ideial. Portanto, substitua esse método que contemple a altura do bruxo no cálculo do comprimento da varinha. 
                   #Tente usar um input que recebe um valor inteiro e peça ao usuário entrar com um valor em centímetros
                   #O comprimento médio de uma varinha vai de 20 cm a 36 cm
                   #Uma dica seria criar uma regressão linear onde você consiga tirar uma média de acordo com a altura o usuário:
                   #Usuário possui 100 cm de altura, sua varinha terá 20 cm de comprimento
                   #Usuário possui 200 cm de altura, sua varinha terá 40 cm de comprimento
                   #Se o usuário possuir X cm de altura, qual o tamanho da sua varinha?

                   """"
                   Resolução:
                   print("Qual a sua altura em cm?")

                   resp = int(input())
                   calculo = (resp - 100)*20/(200-100) + 20
                   comprimento = round(calculo, 1) #irá arredondar em 1 casa decimal
                   """
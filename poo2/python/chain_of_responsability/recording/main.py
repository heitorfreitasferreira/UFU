
from handlers.HandlerIdade import HandlerIdade
from handlers.HandlerNome import HandlerNome
from user import User
user_valido = User("Zé","zezin@trybe.com",20)
user_invalido_nome = User("","vazio@trybe.com",20)
user_invalido_idade = User("Chico","chiquin@trybe.com",16)
user_invalido_tudo = User("","vazio@trybe.com",15)

noIdade = HandlerIdade()
noNome = HandlerNome()

noIdade.set_next(noNome)

print(noIdade.handle(user_invalido_tudo))
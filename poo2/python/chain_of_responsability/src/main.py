from User import User
from Handlers.UserNameHandler import UserNameHandler
from Handlers.UserAgeHandler import UserAgeHandler

usuario_invalido = User(age=17, name="Clebinho",
                        email="clebinho2007@trybe.com")

usuario_mega_invalido = User(age=10, name="", email="")

usuario_valido = User(age=18, name="Joaquin", email="joquinho741@trybe.com")

valida_idade = UserAgeHandler()
valida_nome = UserNameHandler()

valida_idade.set_next(valida_nome)

print(valida_idade.handle(usuario_valido))

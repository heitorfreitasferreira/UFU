from Handlers.IUserHandler import IUserHandler
from User import User


class UserAgeHandler(IUserHandler):
    def handle(self, user: User):
        retorno: str = ""
        if user.age < 18:
            retorno += "User is underaged\n"
        if self._next_handler:
            return retorno + self._next_handler.handle(user)
        else:
            return retorno

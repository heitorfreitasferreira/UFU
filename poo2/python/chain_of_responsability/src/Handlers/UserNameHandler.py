from Handlers.IUserHandler import IUserHandler
from User import User


class UserNameHandler(IUserHandler):
    def handle(self, user: User):
        retorno: str = ""
        if user.name == "":
            retorno += "User has no name\n"
        if self._next_handler:
            return retorno + self._next_handler.handle(user)
        else:
            return retorno

from abc import ABC, abstractmethod
from ast import Raise

from User import User


class IUserHandler(ABC):

    _next_handler = None

    def set_next(self, handler):
        self._next_handler = handler
        return handler

    @abstractmethod
    def handle(self, user: User) -> str:
        raise NotImplementedError("Método handle não implementado")

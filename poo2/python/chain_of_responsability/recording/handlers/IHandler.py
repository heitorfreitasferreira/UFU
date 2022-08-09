from abc import ABC, abstractmethod

class IHandler(ABC):
    _next_handler = None
    def set_next(self, handler):
        self._next_handler = handler
        return handler

    @abstractmethod
    def handle(self, user):
        raise NotImplementedError("Método abstrato da classe IHandler")
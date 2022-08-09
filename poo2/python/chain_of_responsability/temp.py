from abc import ABC, abstractmethod

# biblioteca que permite que classes sejam abstratas

class IHandler(ABC):
    nextHandler = None
    @abstractmethod
    def handle(self, request):
        raise NotImplementedError
    def setNext(self, handler):
        self.nextHandler = handler
        return handler

class Handler1(IHandler):
    def handle(self, request):
        print(f"{request} tratado pelo Handler1")
        if self.nextHandler:
            self.nextHandler.handle(request)   

class Handler2(IHandler):
    def handle(self, request):
        print(f"{request} tratado pelo Handler2")
        if self.nextHandler:
            self.nextHandler.handle(request)



pedido = "Pedido de compra"
handler1 = Handler1()
handler2 = Handler2()
handler1.setNext(handler2)
handler1.handle(pedido)
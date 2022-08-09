from handlers.IHandler import IHandler

class HandlerNome(IHandler):
    def handle(self,user):
        txt_retorno = ""
        if user.name == "":
            txt_retorno += "Usuario sem nome\n"
        
        if self._next_handler:
            return txt_retorno + self._next_handler.handle(user)
        else:
            return txt_retorno
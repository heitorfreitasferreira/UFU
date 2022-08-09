from handlers.IHandler import IHandler

class HandlerIdade(IHandler):
    def handle(self,user):
        txt_retorno = ""
        if user.age < 18:
            txt_retorno += "Usuario menor de idade\n"
        
        if self._next_handler:
            return txt_retorno + self._next_handler.handle(user)
        else:
            return txt_retorno
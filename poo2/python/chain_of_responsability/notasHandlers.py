from abc import ABC, abstractmethod

class SeparadorDeNotas(ABC):
    proximoNo = None
    @abstractmethod
    def handle(self, nota):
        raise NotImplementedError
    def setNext(self, prox_separador):
        self.proximoNo = prox_separador
        return prox_separador

class Separador100(SeparadorDeNotas):
    def handle(self, nota):
        qnt_notas = nota // 100 # divisão inteira arredondando para baixo
        print(f"{qnt_notas} nota(s) de R$ 100,00")
        restante = nota % 100
        if self.proximoNo and restante>0:
            self.proximoNo.handle(restante)

class Separador50(SeparadorDeNotas):
    def handle(self, nota):
        qnt_notas = nota // 50 # divisão inteira arredondando para baixo
        print(f"{qnt_notas} nota(s) de R$ 50,00")
        restante = nota % 50
        if self.proximoNo and restante>0:
            self.proximoNo.handle(restante)

class Separador20(SeparadorDeNotas):
    def handle(self, nota):
        qnt_notas = nota // 20 # divisão inteira arredondando para baixo
        print(f"{qnt_notas} nota(s) de R$ 20,00")
        restante = nota % 20
        if self.proximoNo and restante>0:
            self.proximoNo.handle(restante)

class Separador10(SeparadorDeNotas):
    def handle(self, nota):
        qnt_notas = nota // 10 # divisão inteira arredondando para baixo
        print(f"{qnt_notas} nota(s) de R$ 10,00")
        restante = nota % 10
        if self.proximoNo and restante>0:
            self.proximoNo.handle(restante)

class Separador5(SeparadorDeNotas):
    def handle(self, nota):
        qnt_notas = nota // 5 # divisão inteira arredondando para baixo
        print(f"{qnt_notas} nota(s) de R$ 5,00")
        restante = nota % 5
        if self.proximoNo and restante>0:
            self.proximoNo.handle(restante)

class Separador2(SeparadorDeNotas):
    def handle(self, nota):
        qnt_notas = nota // 2 # divisão inteira arredondando para baixo
        print(f"{qnt_notas} nota(s) de R$ 2,00")
        restante = nota % 2
        if self.proximoNo and restante>0:
            self.proximoNo.handle(restante)

class Separador1(SeparadorDeNotas):
    def handle(self, nota):
        qnt_notas = nota # divisão inteira arredondando para baixo
        print(f"{qnt_notas} nota(s) de R$ 1,00")
        restante = nota % 1
        if self.proximoNo and restante>0:
            self.proximoNo.handle(restante)


# Criação da cadeia de responsabilidades

separador_de_notas = Separador100()

separador_de_notas.setNext(Separador50()).setNext(Separador20()).setNext(Separador10()).setNext(Separador5()).setNext(Separador2()).setNext(Separador1())

separador_de_notas.handle(576)
package Escudos;

public class Escudo implements EscudoHandler {
  private int valor;

  protected EscudoHandler proximoEscudo;

  public Escudo(int valor) {
    setValor(valor);
  }

  public void setValor(int valor) {
    if (valor >= 0) {
      this.valor = valor;
    } else {
      this.valor = 0;
    }
  }

  public int getValor() {
    if (proximoEscudo == null) {
      return valor;
    } else {
      return valor + proximoEscudo.getValor();
    }
  }

  public void addEscudo(EscudoHandler escudo) {
    if (proximoEscudo == null) {
      proximoEscudo = escudo;
    } else {
      proximoEscudo.addEscudo(escudo);
    }

  }

  public int danoPosMitigacao(int dano) {
    dano -= valor;
    if (dano <= 0)
      return 0;
    if (proximoEscudo == null)
      return dano;

    return proximoEscudo.danoPosMitigacao(dano);
  }
}

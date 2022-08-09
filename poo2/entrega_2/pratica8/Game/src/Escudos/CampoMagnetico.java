package Escudos;

public class CampoMagnetico extends Escudo {
  private static int valorEscudo = 10;
  public CampoMagnetico() {
    super(valorEscudo);
  }
  public CampoMagnetico(int valor) {
    super(valorEscudo);
  }
  @Override
  public int danoPosMitigacao(int dano){
    dano /= this.getValor();
    if (dano <= 0)
      return 0;
    if (proximoEscudo == null)
      return dano;

    return proximoEscudo.danoPosMitigacao(dano);
  }
}
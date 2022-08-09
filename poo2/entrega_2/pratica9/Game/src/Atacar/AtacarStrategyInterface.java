package Atacar;

public abstract class AtacarStrategyInterface {
  private int dano;
  private String descricao;

  public AtacarStrategyInterface() {
    dano = 0;
    descricao = "";
  }

  public AtacarStrategyInterface(int dano, String descricao) {
    this.dano = dano;
    this.descricao = descricao;
  }

  public abstract String atacar();

  public int getDano() {
    return dano;
  };

  public String getDescricao() {
    return descricao;
  };

  protected void setDano(int dano) {
    this.dano = dano;
  }

  protected void setDescricao(String descricao) {
    this.descricao = descricao;
  }

}

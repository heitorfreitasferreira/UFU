package Atacar;

public abstract class AtacarDecorador extends AtacarStrategyInterface {
  protected AtacarStrategyInterface ataqueDecorado;

  public AtacarDecorador(AtacarStrategyInterface ataqueDecorado) {
    this.ataqueDecorado = ataqueDecorado;
  }

  public int getDano() {
    return ataqueDecorado.getDano() + super.getDano();
  }

  public String getDescricao() {
    return ataqueDecorado.getDescricao() + "\n" + super.getDescricao();
  }

  public String atacar() {
    return getDescricao() + "\nDano: " + getDano();
  };

}

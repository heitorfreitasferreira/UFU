package Atacar;

public class AtacarMedio extends AtacarStrategyInterface {
  public AtacarMedio() {
    super(30, "Ataque Medio");
  }

  public String atacar() {
    return getDescricao();
  }

}

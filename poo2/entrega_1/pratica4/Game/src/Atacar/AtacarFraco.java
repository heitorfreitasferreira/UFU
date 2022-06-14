package Atacar;

public class AtacarFraco extends AtacarStrategyInterface {
  public AtacarFraco() {
    super(15, "Ataque Fraco");
  }

  public String atacar() {
    return "Ataque Fraco";
  }
}

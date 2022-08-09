package Atacar;

public class Picareta extends AtacarDecorador {
  public Picareta(AtacarStrategyInterface ataqueDecorado) {
    super(ataqueDecorado);
    setDano(25);
    setDescricao("Picareta");
  }
}

package Atacar;

public class ArcoFlecha extends AtacarDecorador {
  public ArcoFlecha(AtacarStrategyInterface ataqueDecorado) {
    super(ataqueDecorado);
    setDano(10);
    setDescricao("Arco e Flecha");
  }
}

package Atacar;

public class EspadaGPC extends AtacarDecorador {
  public EspadaGPC(AtacarStrategyInterface ataqueDecorado) {
    super(ataqueDecorado);
    setDano(40);
    setDescricao("Espada G.P.C");
  }
}

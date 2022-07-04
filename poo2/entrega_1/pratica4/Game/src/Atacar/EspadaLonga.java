package Atacar;

public class EspadaLonga extends AtacarDecorador {
  public EspadaLonga(AtacarStrategyInterface ataqueDecorado) {
    super(ataqueDecorado);
    setDano(10);
    setDescricao("Espada Longa");
  }
}

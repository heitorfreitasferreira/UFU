package Atacar;

public class RaioParalisante extends AtacarDecorador {
  public RaioParalisante(AtacarStrategyInterface ataqueDecorado) {
    super(ataqueDecorado);
    setDano(20);
    setDescricao("Raio Paralisante");
  }
}

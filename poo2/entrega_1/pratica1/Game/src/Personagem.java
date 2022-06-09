import Correr.CorrerStrategyInterface;
import Pular.PularStategyInterface;

public class Personagem {
  private PularStategyInterface pulo;
  private CorrerStrategyInterface corrida;

  public Personagem(PularStategyInterface pulo, CorrerStrategyInterface corrida) {
    this.pulo = pulo;
    this.corrida = corrida;
  }

  public String pulo() {
    return pulo.pulo();
  }

  public String correr() {
    return corrida.correr();
  }
}

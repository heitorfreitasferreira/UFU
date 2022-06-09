import Correr.CorrerStrategyInterface;
import Pular.PularStategyInterface;

public class Personagem {
  private PularStategyInterface pulo;
  private CorrerStrategyInterface corrida;

  public Personagem(PularStategyInterface pulo, CorrerStrategyInterface corrida) {
    setCorrida(corrida);
    setPulo(pulo);
  }

  // ---------------------------------------------------
  // Strategy Pattern
  // ---------------------------------------------------
  // Alteração/Escolha de estratégias
  public void setPulo(PularStategyInterface pulo) {
    this.pulo = pulo;
  }

  public void setCorrida(CorrerStrategyInterface corrida) {
    this.corrida = corrida;
  }

  // Comportamentos do Personagem (Strategys)
  public String pulo() {
    return pulo.pulo();
  }

  public String correr() {
    return corrida.correr();
  }
}

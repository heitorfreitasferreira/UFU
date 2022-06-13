import Correr.CorrerStrategyInterface;
import Pular.PularStrategyInterface;
import Atacar.AtacarStrategyInterface;
import Correr.*;
import Pular.*;
import Atacar.*;

public abstract class Personagem {
  private PularStrategyInterface pulo;
  private CorrerStrategyInterface corrida;
  private AtacarStrategyInterface ataque;

  public Personagem(
    PularStrategyInterface pulo, 
    CorrerStrategyInterface corrida, 
    AtacarStrategyInterface ataque
    ) {
    setCorrida(corrida);
    setPulo(pulo);
    setAtaque(ataque);
  }

  // ---------------------------------------------------
  // Strategy Pattern
  // ---------------------------------------------------
  // Alteração/Escolha de estratégias
  public void setAtaque(AtacarStrategyInterface ataque) {
    this.ataque = ataque;
  }

  public void setPulo(PularStrategyInterface pulo) {
    this.pulo = pulo;
  }

  public void setCorrida(CorrerStrategyInterface corrida) {
    this.corrida = corrida;
  }

  // Comportamentos do Personagem (Strategys)
  public String pulo() {
    return pulo.pular();
  }

  public String correr() {
    return corrida.correr();
  }

  public String atacar() {
    return ataque.atacar();
  }
}

public class Personagem1 extends Personagem {
  public Personagem1() {
    this.setAtaque(new AtacarForte());
    this.setCorrida(new CorrerMedio());
    this.setPulo(new PularMedio());
  }
}

public class Personagem2 extends Personagem {
  public Personagem2() {
    this.setAtaque(new AtacarMedio());
    this.setCorrida(new CorrerRapido());
    this.setPulo(new PularAlto());
  }
}

public class Personagem3 extends Personagem {
  public Personagem3() {
    this.setAtaque(new AtacarForte());
    this.setCorrida(new CorrerRapido());
    this.setPulo(new PularBaixo());
  }
} 
package Vida.Estados;

import Vida.VidaInterface;
import Game.*;

public class Morto extends VidaInterface {
  public Morto(Personagem personagem) {
    super(0, 0, personagem);
  }

  public void lidaAlteracaoVida() {
    // Transição de estado (não há)
    System.out.println("Você morreu!");
  }
}

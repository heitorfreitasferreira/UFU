package Vida.Estados;

import Game.Personagens.Personagem;
import Vida.VidaInterface;

public class Morto extends VidaInterface {
  public Morto(Personagem personagem) {
    super(0, 0, personagem);
  }

  public void lidaAlteracaoVida() {
    // Transição de estado (não há)
    System.out.println("Você morreu!");
  }
}

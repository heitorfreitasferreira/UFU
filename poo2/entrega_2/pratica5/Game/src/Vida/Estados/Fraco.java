package Vida.Estados;

import Vida.VidaInterface;
import Correr.CorrerDevagar;
import Game.Personagens.Personagem;

public class Fraco extends VidaInterface {

  public Fraco(Personagem personagem) {
    super(30, 0, personagem);
    // this.getPersonagem().setAtaque(new AtacarForte());
    this.getPersonagem().setCorrida(new CorrerDevagar());
  }

  public void lidaAlteracaoVida() {
    if (this.getPersonagem().getVida() <= this.getVida_min()) {
      this.getPersonagem().setEstado(new Morto(this.getPersonagem()));
      this.getPersonagem().getEstado().lidaAlteracaoVida();

    } else if (this.getPersonagem().getVida() > this.getVida_max()) {
      // this.getPersonagem().setVida(this.getVida_max());
      this.getPersonagem().setEstado(new Normal(this.getPersonagem()));
      this.getPersonagem().getEstado().lidaAlteracaoVida();
    }
  }

}

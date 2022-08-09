package Vida.Estados;

import Correr.*;
import Game.Personagens.Personagem;
// import Atacar.*;
import Vida.*;

public class Normal extends VidaInterface {

  public Normal(Personagem personagem) {
    super(70, 30, personagem);
    // this.getPersonagem().setAtaque(new AtacarForte());
    this.getPersonagem().setCorrida(new CorrerMedio());
  }

  public void lidaAlteracaoVida() {
    if (this.getPersonagem().getVida() <= this.getVida_min()) {
      this.getPersonagem().setEstado(new Fraco(this.getPersonagem()));
      this.getPersonagem().getEstado().lidaAlteracaoVida();
    } else if (this.getPersonagem().getVida() > this.getVida_max()) {
      this.getPersonagem().setEstado(new Forte(this.getPersonagem()));
      this.getPersonagem().getEstado().lidaAlteracaoVida();
    }
  }

}

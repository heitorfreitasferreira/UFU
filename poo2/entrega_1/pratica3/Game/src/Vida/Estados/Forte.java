package Vida.Estados;

import Vida.*;
import Game.*;
import Correr.*;

public class Forte extends VidaInterface {

  public Forte(Personagem personagem) {
    super(100, 70, personagem);
    // this.getPersonagem().setAtaque(new AtacarForte());
    this.getPersonagem().setCorrida(new CorrerRapido());
  }

  public void lidaAlteracaoVida() {
    if (this.getPersonagem().getVida() <= this.getVida_min()) {
      this.getPersonagem().setEstado(new Fraco(this.getPersonagem()));
      this.getPersonagem().getEstado().lidaAlteracaoVida();
    } else if (this.getPersonagem().getVida() > this.getVida_max()) {
      // this.getPersonagem().setEstado(new Normal(this.getPersonagem()));
      // this.getPersonagem().getEstado().lidaAlteracaoVida();
      System.out.println("Não é possível almentar a vida além de " + this.getVida_max());
    }
  }

}

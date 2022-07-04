package Vida;

import Game.Personagem;

public abstract class VidaInterface {

  private int vida_max, vida_min;
  private Personagem personagem;

  public VidaInterface(int vida_max, int vida_min, Personagem personagem) {
    setPersonagem(personagem);
    setVida_max(vida_max);
    setVida_min(vida_min);
  }

  private void setVida_max(int vida_max) {
    this.vida_max = vida_max;
  }

  private void setVida_min(int vida_min) {
    this.vida_min = vida_min;
  }

  public int getVida_max() {
    return vida_max;
  }

  public int getVida_min() {
    return vida_min;
  }

  public Personagem getPersonagem() {
    return personagem;
  }

  public void setPersonagem(Personagem personagem) {
    this.personagem = personagem;
  }

  public void curar(int quantidade) {
    this.personagem.setVida(personagem.getVida() + quantidade);
    lidaAlteracaoVida();
  }

  public void apanhar(int quantidade) {
    this.personagem.setVida(personagem.getVida() - quantidade);
    lidaAlteracaoVida();
  }

  public abstract void lidaAlteracaoVida();

}

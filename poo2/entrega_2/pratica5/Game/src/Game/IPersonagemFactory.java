package Game;

import Game.Personagens.Personagem;

public interface IPersonagemFactory {
    public Personagem create(Double tipo, String nome);
    public Personagem create(String nome);
    public void jogar();
}

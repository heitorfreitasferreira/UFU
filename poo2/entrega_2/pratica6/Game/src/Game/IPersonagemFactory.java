package Game;

import java.util.ArrayList;

import Game.Personagens.Personagem;

public interface IPersonagemFactory {
    public Personagem create(Double tipo, String nome);
    public Personagem create(String nome);
    public ArrayList<Personagem> jogar(int qtd);
    public static IPersonagemFactory getInstance();
}

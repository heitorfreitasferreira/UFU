package Game;

import java.util.ArrayList;

import Game.Personagens.Personagem;

public abstract class IPersonagemFactory {
    public abstract Personagem create(Double tipo, String nome);
    public abstract Personagem create(String nome);
    //public static abstract IPersonagemFactory getInstance();
    public abstract ArrayList<Personagem> jogar(int qtd);
}

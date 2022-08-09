
import java.util.ArrayList;

import Game.Personagens.Personagem;

public abstract class ASala implements Labirinto{
    protected ArrayList<Labirinto> rooms;
    protected Personagem inimigo;
    public ASala(Labirinto esq, Labirinto dir, Personagem inimigo){
        rooms = new ArrayList<>();
        rooms.add(esq);
        rooms.add(dir);
        this.inimigo = inimigo;
    }
    protected abstract void selecionarCaminho(Personagem personagem);
    protected boolean lutar(Personagem personagem){
        personagem.apanhar(inimigo.getDanoAtaques());
        if(personagem.getVida() <= 0){
            System.out.println(personagem.getNome()+" perdeu o confronto com "+inimigo.getNome()+"! Melhore...");
            return false;
        }
        return true;
    }
    public void jogar(Personagem personagem){
        var venceu = lutar(personagem);
        if(venceu){
            selecionarCaminho(personagem);
        }
    }
}

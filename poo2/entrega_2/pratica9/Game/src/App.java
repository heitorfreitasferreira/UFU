//-------------------------
// import java.util.Scanner;
import java.util.ArrayList;

import Atacar.EspadaGPC;
import Atacar.EspadaLonga;
import Atacar.Picareta;
//-------------------------
import Escudos.Escudo;
import Game.PersonagemFactory;
import Game.Personagens.Personagem;
import Game.factories.FuturistaFactory;

public class App {
    public static void main(String[] args) throws Exception {
        ArrayList<Personagem> jogadores = new ArrayList<>();
        var f = new Ferramentas();
        //jogadores = pFactory.jogar(5);
        var fabrica = FuturistaFactory.getInstance();
        //var fabrica = MedievalFactory.getInstance();
        for (int index = 0; index < 5; index++) {
            jogadores.add(fabrica.createPersonagem(f.getRandomNick()));
            jogadores.get(index).setAtaque(fabrica.createArma(jogadores.get(index).getAtaque()));
        }

        // LABIRINTO TIME
        var geradorInimigos =  PersonagemFactory.getInstance();
        var labirinto = new Sala(new Sala(new Saida(), new Abismo(),geradorInimigos.create(0.9, "Rivalino")), new Sala(new Abismo(), new Saida(), geradorInimigos.create(0.9, "Rivalino")), geradorInimigos.create(0.9, "Cálculo 2"));
        for (Personagem jogador : jogadores) {
        labirinto.jogar(jogador);
        }


        System.out.println("----------------------------------------------------");
        for (int i = 0; i < jogadores.size(); i++) {
            System.out.println(jogadores.get(i).getNome() + " | " + jogadores.get(i).getVida() + "hp:");
            System.out.println("Pular: " + jogadores.get(i).pular());
            System.out.println("Correr: " + jogadores.get(i).correr());
            System.out.println("Atacar: " + jogadores.get(i).atacar());
            System.out.println("Escudo: " + jogadores.get(i).getEscudo());
            System.out.println("Ataque: " + jogadores.get(i).getAtaque().getDescricao());
            System.out.println("");
        }

    }
}

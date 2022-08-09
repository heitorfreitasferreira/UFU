//-------------------------
// import java.util.Scanner;
import java.util.ArrayList;

import Atacar.EspadaGPC;
import Atacar.EspadaLonga;
import Atacar.Picareta;
//-------------------------
import Escudos.Escudo;
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
        
        for (int i = 0; i < jogadores.size(); i++) {
            System.out.println(jogadores.get(i).getNome() + " | " + jogadores.get(i).getVida() + "hp:");
            System.out.println("Pular: " + jogadores.get(i).pular());
            System.out.println("Correr: " + jogadores.get(i).correr());
            System.out.println("Atacar: " + jogadores.get(i).atacar());
            System.out.println("Escudo: " + jogadores.get(i).getEscudo());
            System.out.println("Ataque: " + jogadores.get(i).getAtaque().getDescricao());
            System.out.println("");
        }
        System.out.println("----------------------------------------------------");
        System.out.println(jogadores.get(2).getNome() + " Acaba de achar um escudo de +2!!");
        jogadores.get(2).addEscudo(new Escudo(2));
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
        System.out.println("----------------------------------------------------");
        System.out.println("Receber dano/Ser curado...");
        for (int i = 0; i < jogadores.size(); i++) {
            System.out.println(jogadores.get(i).getNome() + " | " + jogadores.get(i).getVida() + "hp:");
            System.out.println("Atacar ou curar? (a/c)");
            String opcao = "a";// scanner.nextLine();
            if (opcao.equals("a")) {
                System.out.print("Inflingir: ");
                int quantidade = 15;// scanner.nextLine();

                System.out.println("Inlfingido " + jogadores.get(i).apanhar(quantidade));
            } else if (opcao.equals("c")) {
                System.out.print("Cura: ");
                int quantidade = 10 * i;// scanner.nextLine();
                jogadores.get(i).curar(quantidade);
                System.out.println("Curado " + quantidade);
            }
            System.out.println("");
        }
        System.out.println("----------------------------------------------------");
        System.out.println("Comprando itens...");
        jogadores.get(0).setAtaque(new EspadaLonga(jogadores.get(0).getAtaque()));
        jogadores.get(1).setAtaque(new Picareta(jogadores.get(1).getAtaque()));
        jogadores.get(2).setAtaque(new EspadaGPC(jogadores.get(2).getAtaque()));
        // System.out.println("----------------------------------------------------");
        // System.out.println("Atacando...");
        // for (int i = 0; i < jogadores.size(); i++) {
        // System.out.println(jogadores.get(i).getNome() + " | " +
        // jogadores.get(i).getVida() + "hp:");
        // System.out.println(jogadores.get(i).atacar());
        // System.out.println("");

        // }
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

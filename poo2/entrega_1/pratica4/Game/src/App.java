import Game.*;
//-------------------------
import Pular.*;
import Correr.*;
import Atacar.*;

//-------------------------
import Escudos.*;
//-------------------------
// import java.util.Scanner;
import java.util.ArrayList;

public class App {
    public static void main(String[] args) throws Exception {
        // Scanner scanner = new Scanner(System.in);
        Ferramentas ferramentas = new Ferramentas();
        ArrayList<Personagem> jogadores = new ArrayList<Personagem>();

        jogadores.add(new Personagem(new PularMedio(), new CorrerMedio(), new AtacarMedio(), new Escudo(10),
                ferramentas.getRandomNick()));
        jogadores.add(new Personagem(new PularAlto(), new CorrerRapido(), new AtacarForte(), new Escudo(10),
                ferramentas.getRandomNick()));
        jogadores.add(new Personagem(new PularBaixo(), new CorrerRapido(), new AtacarFraco(), new Escudo(10),
                ferramentas.getRandomNick()));
        for (int i = 0; i < jogadores.size(); i++) {
            System.out.println(jogadores.get(i).getNome() + " | " + jogadores.get(i).getVida() + "hp:");
            System.out.println("Pular: " + jogadores.get(i).pular());
            System.out.println("Correr: " + jogadores.get(i).correr());
            System.out.println("Atacar: " + jogadores.get(i).atacar());
            System.out.println("Escudo: " + jogadores.get(i).getEscudo());
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
            System.out.println("");
        }

    }
}
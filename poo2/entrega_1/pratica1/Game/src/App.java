import Pular.PularBaixo;
import Pular.PularMedio;
import Pular.PularAlto;

//-------------------------
import Correr.CorrerDevagar;
import Correr.CorrerMedio;
import Correr.CorrerRapido;

//-------------------------
import Atacar.AtacarFraco;
import Atacar.AtacarMedio;
import Atacar.AtacarForte;

import java.util.ArrayList;

//-------------------------

import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);

        ArrayList<Personagem> jogadores = new ArrayList<Personagem>();

        jogadores.add(new Personagem(new PularMedio(), new CorrerMedio()/* ,new AtacarMedio() */));
        jogadores.add(new Personagem(new PularAlto(), new CorrerRapido()/* ,new AtacarForte() */));
        jogadores.add(new Personagem(new PularBaixo(), new CorrerRapido()/* ,new AtacarFraco() */));
        for (int i = 0; i < jogadores.size(); i++) {
            System.out.println("Jogador " + (i + 1) + ":");
            System.out.println("Pular: " + jogadores.get(i).pulo());
            System.out.println("Correr: " + jogadores.get(i).correr());
            // System.out.println("Atacar: " + jogadores.get(i).atacar());
            System.out.println("");
        }
    }
}

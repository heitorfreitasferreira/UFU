package org.example;

import org.example.abstractfactory.factories.Meseira;
import org.example.abstractfactory.factories.Meseira2D;
import org.example.abstractfactory.factories.Meseira3D;
import org.example.abstractfactory.products.Copo;
import org.example.abstractfactory.products.Garrafa;
import org.example.abstractfactory.products.Prato;
import org.example.composite.CComposto;
import org.example.composite.CCondicional;
import org.example.composite.CSimples;
import org.example.composite.Comando;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {


        // Questão 1
        System.out.println("Questao 1");

        Comando c1 = new CSimples("mostraNaTela(\"Hello World!\");");
        Comando c2 = new CSimples("somar(15,40);");
        Comando c3 = new CSimples("subtrair(15,40);");
        Comando c4 = new CSimples("iniciar_exposao_bloco(1B);");
        Comando c5 = new CSimples("cantar_iaiaia();");

        Comando bMatematica = new CComposto(c2, c3);
        Comando bExposao = new CComposto(c5, c4);

        Comando if_elif_else = new CCondicional(bMatematica, new CCondicional(bExposao, c1));
        /*
        if (Math.random() > 0.5) {
                somar(15,40);
                subtrair(15,40);
        } else {
            if (Math.random() > 0.5) {
                cantar_iaiaia();
                iniciar_exposao_bloco(1B);
            } else {
                mostraNaTela("Hello World!");
            }
        }
         */
        System.out.println(if_elif_else.executar());
        // Questão 2
        System.out.println("Questao 2");

        Meseira fabrica;

        System.out.print("Programa 2D ou 3D?(2/3): ");
        int opcao;
        do {
             opcao = Integer.parseInt(new Scanner(System.in).nextLine());
        } while (opcao != 2 && opcao != 3);

        if (opcao == 2) {
            fabrica = new Meseira2D();
        } else {
            fabrica = new Meseira3D();
        }

        Copo copo = fabrica.fabricarCopo();
        Prato prato = fabrica.fabricarPrato();
        Garrafa garrafa = fabrica.fabricarGarrafa();


        System.out.println(copo.toString());
        System.out.println(prato.toString());
        System.out.println(garrafa.toString());

    }
}
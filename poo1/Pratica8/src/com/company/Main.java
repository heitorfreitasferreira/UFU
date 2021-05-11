package com.company;

public class Main {

    public static void main(String[] args) {
        ContaBancaria c1 = new ContaCorrente(1500,1,6.5);
        ContaBancaria c2 = new ContaPoupanca(1000,2,200);
        System.out.println("-------------------------------");
        System.out.println("CONTAS ANTES DAS OPERACOES");
        c1.mostrarDados();
        c2.mostrarDados();
        c1.sacar(1100);
        c2.sacar(1100);
        System.out.println("-------------------------------");
        System.out.println("Depois de sacar R$1100,00");
        c1.mostrarDados();
        c2.mostrarDados();

        c1.depositar(500);
        c2.depositar(500);
        System.out.println("-------------------------------");
        System.out.println("Depois de depositar R$500,00");
        c1.mostrarDados();
        c2.mostrarDados();
    }
}

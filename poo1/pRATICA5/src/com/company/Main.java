package com.company;
import java.io.Console;
import java.util.Scanner;
public class Main {
    public static void main(String[] args){
        Console console = System.console();//Para usar o readLine();
        Scanner scanner = new Scanner(System.in);
        Vendedor[] proletario = new Vendedor[5];
        Administrativo[] admins = new Administrativo[5];
        System.out.println("Hello World");
        //Lendo funcionários
        for (int i = 0; i<5;i++){
            proletario[i] = new Vendedor();
            System.out.print("Nome: ");
            String nome = scanner.nextLine();
            System.out.print("RG: ");
            String rg = scanner.nextLine();
            System.out.print("Valor das vendas do mes: ");
            String venda  = scanner.nextLine();
            int vendaF = Integer.parseInt(venda);
            proletario[i].setNome(nome);
            proletario[i].setRG(rg);
            proletario[i].attComissao(vendaF);

            System.out.printf("Salario do %s: %f\n",proletario[i].getNome(),(proletario[i].getSalarioBase()+proletario[i].getComissaoAcum()));
        }
        //Lendo administrativos
        for (int i = 0; i<5;i++){
            admins[i]= new Administrativo();
            System.out.print("Nome: ");
            String nome = scanner.nextLine();
            System.out.print("RG: ");
            String rg = scanner.nextLine();
            System.out.print("Quantas horas extras tem: ");
            String horasExtras  = scanner.nextLine();
            int horasExtrasI = Integer.parseInt(horasExtras);
            admins[i].setNome(nome);
            admins[i].setRG(rg);
            admins[i].attHoraExtraAcum(horasExtrasI);
            System.out.printf("Salario do %s: %f\n",admins[i].getNome(),(admins[i].getSalarioBase()+admins[i].getsalarioBonus()));

        }
    }
}

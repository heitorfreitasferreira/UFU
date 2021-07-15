import java.io.Console;
public class Main {

    static void main(String[] args){
        Console console = System.console();//Para usar o readLine();
        Vendedor[] proletario = new Vendedor[5];
         Administrativo[] admins = new Administrativo[5];
        System.out.println("Hello World");
        //Lendo funcionários
        for (int i = 0; i<5;i++){
            proletario[i] = new Vendedor();
            System.out.println("Nome: ");
            String nome = console.readLine();
            System.out.println("RG: ");
            String rg = console.readLine();
            System.out.println("Valor das vendas do mes: ");
            String venda  = console.readLine();
            int vendaF = Integer.parseInt(venda);
            proletario[i].setNome(nome);
            proletario[i].setRG(rg);
            proletario[i].attComissao(vendaF);

            System.out.printf("Salario do %s: %f\n",proletario[i].getNome(),(proletario[i].getSalarioBase()+proletario[i].getComissaoAcum()));
        }
        //Lendo administrativos
        for (int i = 0; i<5;i++){
            admins[i]= new Administrativo();
            System.out.println("Nome: ");
            String nome = console.readLine();
            System.out.println("RG: ");
            String rg = console.readLine();
            System.out.println("Quantas horas extras tem: ");
            String horasExtras  = console.readLine();
            int horasExtrasI = Integer.parseInt(horasExtras);
            admins[i].setNome(nome);
            admins[i].setRG(rg);
            admins[i].attHoraExtraAcum(horasExtrasI);
            System.out.printf("Salario do %s: %f\n",admins[i].getNome(),(admins[i].getSalarioBase()+admins[i].getsalarioBonus()));

        }
    }
}

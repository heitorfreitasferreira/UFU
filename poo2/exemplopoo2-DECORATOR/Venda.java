
//CLASSE CLIENT -- componente de alto nivel
public class Venda
{
    
    public static void vender(Carro carro){ //depende APENAS da abstração COMPONET
        //processar venda, gerar nota fiscal
        System.out.println("---------- NOTA FISCAL ----------");
        System.out.println("Descricao: "+carro.getDescricao());
        System.out.println("Custo....: "+carro.getCusto());     
        System.out.println("---------------------------------");        
    }     

}

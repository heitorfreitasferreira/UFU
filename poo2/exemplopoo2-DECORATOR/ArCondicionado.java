
public class ArCondicionado extends CarroDecorador
{

    public ArCondicionado(Carro carro){
        super(carro);
    }    
    
    //SEGUNDA COISA IMPORTANTE - DECORAR O COMPORTAMENTO DO OBJETOS 
    public double getCusto(){
         double a = getCarroDecorado().getCusto(); //EXECUTA COMPORTAMENTO DO OBJETO DECORADO -- DELEGAÇÃO DE RESPONSABILIDADE

         //COMPORTAMENTO PROPRIO DESTA CAMADA DA CEBOLA
         double b = 500; //CONSULTA NO BANCO DE DADOS -- EXECUTA A PROPRIA RESPONSABI

         return a+b;
    }    

    public String getDescricao(){
         String a = getCarroDecorado().getDescricao(); //EXECUTA COMPORTAMENTO DO OBJETO DECORADO -- DELEGAÇÃO DE RESPONSABILIDADE

         //COMPORTAMENTO PROPRIO DESTA CAMADA DA CEBOLA
         String b = "\n Ar Condicionado"; //CONSULTA NO BANCO DE DADOS -- EXECUTA A PROPRIA RESPONSABIDADE

         return a+b;
    }        

    
}

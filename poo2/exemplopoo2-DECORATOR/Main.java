
public class Main
{
    public static void main(String[] args) {
        Carro c;
        //INTERFACE PARA CONSTRUÇÃO DO CARRO -- FRONT, DESIGNER, BOOTSTRAP, JS
        //CONFIGURAR UM CARRO
        c = new Voyage();
        
        c = new CentralMultimedia(c);

        c = new ArCondicionado(c);
        
        Venda.vender(c);
    }
    
}

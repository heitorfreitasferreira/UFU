import factories.creators.*;
import factories.products.*;

public class App {
    public static void main(String[] args) throws Exception {
        //Fábricas de produtos e produtos
        Creator factory;
        ProductInterface product; 

        //Criação do produto do tipo 1
        factory = new FactoryProduct1();
        product = factory.factoryMethod();
        product.fazerAlgo();
        //Criação do produto do tipo 2
        factory = new FactoryProduct2();
        product = factory.factoryMethod();
        product.fazerAlgo();
    }
}

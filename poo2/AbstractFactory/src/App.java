import factories.AbstractFactoryInterface;
import factories.FactoryA;
import factories.FactoryB;
import products.ProductInterface;

public class App {
    public static void main(String[] args) throws Exception {
        AbstractFactoryInterface factory;
        ProductInterface product1,product2;

        factory = new FactoryA();
        product1 = factory.createProduct1();
        product2 = factory.createProduct2();
        product1.fazerAlgo();
        product2.fazerAlgo();


        factory = new FactoryB();
        product1 = factory.createProduct1();
        product2 = factory.createProduct2();
        product1.fazerAlgo();
        product2.fazerAlgo();
    }
}

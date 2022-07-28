package factories.creators;

import factories.products.ConcreteProduct2;
import factories.products.ProductInterface;

public class FactoryProduct2 implements Creator{
    public ProductInterface factoryMethod() {
        return new ConcreteProduct2();
    }
}

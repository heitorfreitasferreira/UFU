package factories.creators;

import factories.products.ConcreteProduct1;
import factories.products.ProductInterface;

public class FactoryProduct1 implements Creator{
    public ProductInterface factoryMethod() {
        return new ConcreteProduct1();
    }
}

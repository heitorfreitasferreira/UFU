package factories;

import products.*;
import products.p1.*;
import products.p2.*;

public class FactoryA implements AbstractFactoryInterface {
    public Product1Interface createProduct1() {
        return new Product1A();
    }
    public Product2Interface createProduct2() {
        return new Product2A();
    }
}


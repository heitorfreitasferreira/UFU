import ChainOfResponsability.Chain;
import ChainOfResponsability.ConcreteHandlers.*;

public class App {
    public static void main(String[] args) throws Exception {
        
        Chain handler1 = new ConcreteHandler1();
        Chain handler2 = new ConcreteHandler2();
        Chain handler3 = new ConcreteHandlerBIforcation();
        handler1.handle();
        handler1.setNextHandler(handler2);

        handler1.handle();

        handler1.setNextHandler(handler2);
        handler1.handle();



    }
}

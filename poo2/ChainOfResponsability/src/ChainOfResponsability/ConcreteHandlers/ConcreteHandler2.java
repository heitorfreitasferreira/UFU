package ChainOfResponsability.ConcreteHandlers;

import ChainOfResponsability.Chain;

public class ConcreteHandler2 implements Chain {
    protected Chain nextHandler;
    public void handle() {
        System.out.println("ConcreteHandler2 executed");
        if(nextHandler != null) {
            nextHandler.handle();
        }
    }
    public void setNextHandler(Chain nextHandler) {
        this.nextHandler = nextHandler;
    }
}

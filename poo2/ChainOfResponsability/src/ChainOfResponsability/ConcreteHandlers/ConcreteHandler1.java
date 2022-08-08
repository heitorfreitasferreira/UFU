package ChainOfResponsability.ConcreteHandlers;

import ChainOfResponsability.Chain;

public class ConcreteHandler1 implements Chain {
    protected Chain nextHandler;
    public void handle() {
        System.out.println("ConcreteHandler1 executed");
        if(nextHandler != null) {
            nextHandler.handle();
        }
    }
    public void setNextHandler(Chain nextHandler) {
        this.nextHandler = nextHandler;
    }
}

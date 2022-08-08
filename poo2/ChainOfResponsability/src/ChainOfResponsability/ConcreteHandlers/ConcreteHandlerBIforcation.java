package ChainOfResponsability.ConcreteHandlers;

import ChainOfResponsability.Chain;

public class ConcreteHandlerBIforcation implements Chain{
    protected Chain nextHandler1;
    protected Chain nextHandler2;
    public void handle() {
        System.out.println("ConcreteHandlerBIforcation executed");
        if(nextHandler1 != null) {
            System.out.println("Going to next handler1");
            nextHandler1.handle();
        }
        if(nextHandler2 != null) {
            System.out.println("Going to next handler2");
            nextHandler2.handle();
        }
    }
    public void setNextHandler(Chain nextHandler) {
        if (nextHandler1 == null) {
            nextHandler1 = nextHandler;
        }
        else if(nextHandler2 == null) {
            nextHandler2 = nextHandler;
        }
        else if(Math.random()<0.5){
            nextHandler1.setNextHandler(nextHandler);
        }
        else {
            nextHandler2.setNextHandler(nextHandler);
        }
    }
}

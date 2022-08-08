package ChainOfResponsability;

public interface Chain {
    public void setNextHandler(Chain nextHandler);
    public void handle();
}

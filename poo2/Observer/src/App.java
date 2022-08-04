import Observer.Publisher;
import Observer.Subscriber;
import Observer.Subscribers.ConcreteSubscriber;

public class App {
    public static void main(String[] args) throws Exception {
        var  p = new Publisher();
        ConcreteSubscriber s1 = new ConcreteSubscriber();
        ConcreteSubscriber s2 = new ConcreteSubscriber();
        System.out.println("Inscrevendo s1");
        p.inscrever(s1);
        System.out.println("Executando evento 1,2 e 3");
        p.evento1(true);
        p.evento2(true);
        p.evento3(false);
        System.out.println("Inscrevendo s2");
        p.inscrever(s2);
        System.out.println("Executando evento 1,2 e 3");
        p.evento1(false);
        p.evento2(true);
        p.evento3(true);
        System.out.println("Vendo logs do s1");
        s1.viewNewLogs();
        System.out.println("Executando evento 1,2 e 3");
        p.evento1(false);
        p.evento2(true);
        p.evento3(true);
        System.out.println("Vendo logs do s1");
        s1.viewNewLogs();
        System.out.println("Vendo logs do s1");
        s2.viewNewLogs();
    }
}

package Observer.Subscribers;
import Observer.*;
public class ConcreteSubscriber extends Subscriber {
    private int indexViewedLogs = 0;
    public void viewNewLogs(){
        while (indexViewedLogs < log.size()){
            System.out.println(log.get(indexViewedLogs));
            indexViewedLogs++;
        }
    }
}
package Observer;

import java.util.ArrayList;

public class Publisher {
    private ArrayList<Subscriber> subscribers = new ArrayList<>();
    public void inscrever(Subscriber subscriber){
        subscribers.add(subscriber);
    }
    public void desinscrever(Subscriber subscriber){
        subscribers.remove(subscriber);
    }
    private void avisarInscritos(String aviso){
        for(Subscriber subscriber : subscribers){
            subscriber.update(aviso);
        }
    }
    // Método que em algum momento avisará os inscritos em algum momento
    public void evento1(boolean avisar){
        if(avisar){
            avisarInscritos("Evento 1");
        }
    }
    public void evento2(boolean avisar){
        if(avisar){
            avisarInscritos("Evento 2");
        }
    }
    public void evento3(boolean avisar){
        if(avisar){
            avisarInscritos("Evento 3");
        }
    }
}

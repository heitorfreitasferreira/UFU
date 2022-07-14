import java.util.ArrayList;

public class App {
    public static void main(String[] args) throws Exception {
        //Generate a random list of points
        ArrayList<Point> pontos = new ArrayList<>();
        for(int i = 0; i < 100; i++){
            pontos.add(new Point(Math.random()*100, Math.random()*100));
        }
        //Divide and conquer algorithm
        Tupla <Double,Tupla<Point,Point>> tupla = PMP.divideCoquer(pontos, 0, pontos.size()-1);

        System.out.println(tupla.first);
        System.out.println(tupla.second.first.toString());
        System.out.println(tupla.second.second.toString());
    }
}

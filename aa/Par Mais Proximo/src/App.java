import java.util.ArrayList;
//import org.springframework.util.StopWatch;

public class App {
    public static void main(String[] args) throws Exception {
        // System.out.println("Hello, World!");
        // Generate a random list of points
        // StopWatch watch = new StopWatch();
        // watch.start();
        long startTime = System.nanoTime();
        ArrayList<Point> pontos = new ArrayList<>();
        for (int i = 0; i < 100; i++) {
            pontos.add(new Point(Math.random() * 100, Math.random() * 100));
        }
        Tupla<Double, Tupla<Point, Point>> tupla = PMP.divideConquer(pontos, 0, pontos.size() - 1);
        // watch.stop();
        // System.out.println("Tempo: " + watch.getTime()/1000 + segundos);
        long endTime = System.nanoTime() - startTime;
        System.out.println("Tempo: " + endTime / 1000000 + " milissegundo(s)");// ou " + roof(endTime/1000000000) +
                                                                               // "segundo(s)"
        System.out.println("Distancia : " + tupla.first);
        System.out.println(tupla.second.first.toString());
        System.out.println(tupla.second.second.toString());
    }
}

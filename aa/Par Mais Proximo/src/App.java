import java.util.ArrayList;

public class App {
    public static void main(String[] args) throws Exception {
        for (int k = 2; k < 7; k++) {
            ArrayList<Point> pontos = new ArrayList<>();
            for (int i = 0; i < Math.pow(10, k); i++) {
                pontos.add(new Point(Math.random() * 1000, Math.random() * 1000));
            }
            long startTime = System.nanoTime();
            Tupla<Double, Tupla<Point, Point>> tupla = PMP.divideCoquerPiggyBack(pontos);
            long endTime = System.nanoTime() - startTime;

            System.out.println(
                    "Execução com array de tamanho " + (int) Math.pow(10, k) + ": " + endTime / 1000000
                            + " milissegundo(s)");
            System.out.println("Distancia : " + tupla.first);
            System.out.println("P1" + tupla.second.first.toString());
            System.out.println("P2" + tupla.second.second.toString());
            System.out.println("-----------------------------------------------------");
        }

    }
}

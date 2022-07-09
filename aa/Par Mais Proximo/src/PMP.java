import java.util.*;
public class PMP {
    private static PMP instance = new PMP();
    private PMP(){
        super();
    }
    public static PMP getInstance(){
        return instance;
    }
    private static Tupla<Double, Tupla<Point,Point>> divideCoquerBase(ArrayList<Point> pontos, int start, int end){
    double dist = pontos.get(start).distance(pontos.get(start+1));
        Tupla<Double,Tupla<Point,Point>> ret = new Tupla<>(dist, new Tupla<>(pontos.get(start), pontos.get(start+1)));
        for(int i = start; i < end-1; i++){
            for(int j = i+1; j < end; j++){
                double aux = pontos.get(i).distance(pontos.get(j));
                if(aux < dist){
                    dist = aux;
                    ret.first = aux;
                    ret.second.first = pontos.get(i);
                    ret.second.second = pontos.get(j);
                }
            }
        }
        return ret;
    }
    public static Tupla<Double, Tupla<Point,Point>> divideCoquer(ArrayList<Point> pontos, int start, int end){
        if(end-start < 100) return divideCoquerBase(pontos, start, end);
        int mid = (start+end)/2;
        Tupla<Double,Tupla<Point,Point>> left = divideCoquer(pontos, start, mid);
        Tupla<Double,Tupla<Point,Point>> right = divideCoquer(pontos, mid, end);
        Tupla<Double,Tupla<Point,Point>> ret = new Tupla<>(left.first < right.first ? left.first : right.first, new Tupla<>(left.second.first, right.second.first));
        if(left.first < right.first){
            ret.first = left.first;
            ret.second = left.second;
        }else{
            ret.first = right.first;
            ret.second = right.second;
        }
        
        ArrayList<Point> range = new ArrayList<>();

        for(int i = start; i < end; i++){
            if(Math.abs(pontos.get(i).distance(pontos.get(mid)))< ret.first){
                range.add(pontos.get(i));
            }
        }
        for (int i = 0; i < range.size(); i++) {
            for (int j = 0; j < 8; j++) {
                if(i+j>range.size()){
                    Double dAux = pontos.get(i).distance(range.get(i+j));
                    if(dAux < ret.first){
                        ret.first = dAux;
                        ret.second.first = range.get(i);
                        ret.second.second = range.get(i+j);
                    }
                }
            }
        }
        return ret;
    }
}
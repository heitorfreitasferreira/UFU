import java.util.*;
public class PMP {
    private static PMP instance = new PMP();
    private PMP(){
        super();
    }
    public static PMP getInstance(){
        return instance;
    }
    //#region Estratégia dividir e conquistar
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
    //#endregion Dividir e conquistar

    //#region Piggybacking 
    private static ArrayList<Point> mergePiggyBackArrayList(ArrayList<Point> list1, ArrayList<Point> list2){
        ArrayList<Point> ret = new ArrayList<>();
        int i = 0, j = 0;
        while(i < list1.size() && j < list2.size()){
            if(list1.get(i).getY() < list1.get(i).getY()){
                ret.add(list1.get(i));
                i++;
            }else{
                ret.add(list2.get(j));
                j++;
            }
        }
        while(i < list1.size()){
            ret.add(list1.get(i));
            i++;
        }
        while(j < list2.size()){
            ret.add(list2.get(j));
            j++;
        }
        return ret;
    }
 
    private static Tripla<Double, Tupla<Point,Point>,ArrayList<Point>> divideCoquerPiggyBackBase(ArrayList<Point> pontos, int start, int end){
        double dist = pontos.get(start).distance(pontos.get(start+1));
            Tripla<Double,Tupla<Point,Point>,ArrayList<Point>> ret = new Tripla<>(dist, new Tupla<>(pontos.get(start), pontos.get(start+1)),pontos);
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
            ret.getSortedArray().sort((a,b)-> a.y.compareTo(b.y));
            return ret;
        }
    
    private static Tripla<Double, Tupla<Point,Point>,ArrayList<Point> >divideCoquerPiggyBackHidden(ArrayList<Point> pontos, int start, int end){
        if(end-start < 100) return divideCoquerPiggyBackBase(pontos, start, end);
        int mid = (start+end)/2;
        Tripla<Double,Tupla<Point,Point>,ArrayList<Point>> left = divideCoquerPiggyBackBase(pontos, start, mid);
        Tripla<Double,Tupla<Point,Point>,ArrayList<Point>> right = divideCoquerPiggyBackBase(pontos, mid, end);
        Tripla<Double,Tupla<Point,Point>,ArrayList<Point>> ret = new Tripla<>(left.first < right.first ? left.first : right.first, new Tupla<>(left.second.first, right.second.first),mergePiggyBackArrayList(left.getSortedArray(),right.getSortedArray()));
        if(left.first < right.first){
            ret.first = left.first;
            ret.second = left.second;
        }else{
            ret.first = right.first;
            ret.second = right.second;
        }
        
        for (int i = 0; i < ret.getSortedArray().size(); i++) {
            for (int j = 0; j < 8; j++) {
                if(i+j>ret.getSortedArray().size()){
                    Double dAux = pontos.get(i).distance(ret.getSortedArray().get(i+j));
                    if(dAux < ret.first){
                        ret.first = dAux;
                        ret.second.first = ret.getSortedArray().get(i);
                        ret.second.second = ret.getSortedArray().get(i+j);
                    }
                }
            }
        }
        return ret;
    }
    public static Tupla<Double, Tupla<Point,Point>> divideCoquerPiggyBack(ArrayList<Point> param){
        Tripla<Double, Tupla<Point,Point>,ArrayList<Point>> ret = divideCoquerPiggyBackHidden(param, 0, param.size()-1);
        return new Tupla<>(ret.getDistance(), ret.getPoints());
    }
    
        //#endregion Piggybacking

}
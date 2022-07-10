public class Tripla<Type1,Type2,Type3> {
    public Type1 first;
    public Type2 second;
    public Type3 third;
    public Tripla(Type1 first, Type2 second, Type3 third) {
        this.first = first;
        this.second = second;
        this.third = third;
    }
    public Type1 getDistance() {
        return first;
    }
    public Type2 getPoints() {
        return second;
    }
    public Type3 getSortedArray() {
        return third;
    }
    public void setDistance(Type1 value) {
        this.first = value;
    }
    public void setPoints(Type2 value) {
        this.second = value;
    }
    public void setSortedArray(Type3 value) {
        this.third = value;
    }

}

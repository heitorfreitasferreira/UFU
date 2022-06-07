//Decorador

public abstract class CarroDecorador extends Carro {

    private Carro carroDecorado; //PRIMEIRA COISA IMPORTANTE- referencia para o objeto a ser decorado

    public CarroDecorador(Carro carroDecorado) { //PRIMEIRA
        this.carroDecorado = carroDecorado;
    }

    public Carro getCarroDecorado(){
        return this.carroDecorado;
    }    
    
    //SEGUNDA COISA IMPORTANTE - DECORAR O COMPORTAMENTO DO OBJETOS 
    public abstract double getCusto();
}


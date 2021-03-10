public class Pessoa {
    public String nome;
    public int idade;
    public static int contador;
    public void incIdade(){
        idade++;
    }
    public void incCount(){
        contador++;
    }
    public int getContador(){
        return contador;
    }
}

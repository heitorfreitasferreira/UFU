public class Funcionario {
    private String nome, RG;
    private float salarioBase;
    public Funcionario(){
        this.salarioBase = 100;
    }
    public String getNome() {
        return nome;
    }

    public float getSalarioBase() {
        return salarioBase;
    }

    public void setSalarioBase(float salarioBase) {
        this.salarioBase = salarioBase;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getRG() {
        return RG;
    }

    public void setRG(String RG) {
        this.RG = RG;
    }
}

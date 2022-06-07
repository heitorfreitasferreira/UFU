
public abstract class Carro {

    private double custo;
    private String descricao;

    public double getCusto() {
        return this.custo;
    }

    public String getDescricao() {
        return this.descricao;
    }

    //COMPORTAMENTOS A SEREM DECORADOS/MODIFICADOS/ESTENDIDOS/INCREMENTANDO/TORNAR MAIS COMPLEXO
    public void setCusto(double custo){
        this.custo = custo;
    }

    //COMPORTAMENTOS A SEREM DECORADOS/MODIFICADOS/ESTENDIDOS/INCREMENTANDO/TORNAR MAIS COMPLEXO 
    public void setDescricao(String descricao){
        this.descricao = descricao;
    }
}

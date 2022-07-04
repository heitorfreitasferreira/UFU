public class Produto {
  private String nome;
  private double preco;
  private int quantidade;
  private EstadoEstoque estado;

  // #region Construtores e Getters e Setters
  public Produto(String nome, double preco) {
    this.nome = nome;
    this.preco = preco;
    this.quantidade = 0;
    setEstado(new EstadoIndisponivel(this));
  }

  public String getNome() {
    return nome;
  }

  public double getPreco() {
    return preco;
  }

  public int getQuantidade() {
    return quantidade;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public void setPreco(double preco) {
    this.preco = preco;
  }

  public void setEstado(EstadoEstoque estado) {
    this.estado = estado;
  }

  public EstadoEstoque getEstado() {
    return estado;
  }
  // #endregion Construtores e Getters e Setters

  public boolean setQuantidade(int quantidade) {
    if (quantidade >= 0) {
      this.quantidade = quantidade;
      System.out.println("Produto: " + nome + ", quantidade alterada para " + quantidade + ".");
      // estado.lidaEstado();
      return true;
    } else {
      System.out.println("Operação inválida: não é possível alterar a quantidade de um produto abaixo de zero.");
      return false;
    }
  }

  public boolean repor(int qnt) {
    if (qnt > 0) {
      estado.repor(qnt);
      return true;
    } else {
      return false;
    }
  }

  public boolean vender(int qnt) {
    if (qnt > 0) {
      estado.vender(qnt);
      return true;
    } else {
      return false;
    }
  }
}

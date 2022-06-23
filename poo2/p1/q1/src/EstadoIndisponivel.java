public class EstadoIndisponivel extends EstadoEstoque {
  public EstadoIndisponivel(Produto produto) {
    super(produto, 0, 1);
    System.out.println("Produto: " + produto.getNome() + ", está indisponível.");
  }

  public void lidaEstado() {
    if (produto.getQuantidade() >= qnt_max) {
      produto.setEstado(new EstadoEstoqueCritico(produto));
      produto.getEstado().lidaEstado();
    } else if (produto.getQuantidade() < qnt_min) {
      System.out.println("Operação inválida: não é possível reduzir a quantidade de um produto abaixo de zero.");
    }

  }
}

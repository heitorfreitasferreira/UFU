public class EstadoDisponivel extends EstadoEstoque {
  public EstadoDisponivel(Produto produto) {
    super(produto, 11, 1000000);
    System.out.println("Produto: " + produto.getNome() + ", está disponível.");
  }

  public void lidaEstado() {
    if (produto.getQuantidade() < qnt_min) {
      produto.setEstado(new EstadoEstoqueCritico(produto));
      produto.getEstado().lidaEstado();
    }

  }
}

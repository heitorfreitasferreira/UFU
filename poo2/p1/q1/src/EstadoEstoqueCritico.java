public class EstadoEstoqueCritico extends EstadoEstoque {
  public EstadoEstoqueCritico(Produto produto) {
    super(produto, 1, 10);
    System.out.println("Produto: " + produto.getNome() + ", está em estoque crítico.");
  }

  public void lidaEstado() {
    if (produto.getQuantidade() < qnt_min) {
      produto.setEstado(new EstadoIndisponivel(produto));
    } else if (produto.getQuantidade() >= qnt_max) {
      produto.setEstado(new EstadoDisponivel(produto));
    } else {
      System.out.println("Está na hora de repor o estoque de " + produto.getNome() + "!!\nApenas "
          + produto.getQuantidade() + " unidades restantes.");
    }

  }
}

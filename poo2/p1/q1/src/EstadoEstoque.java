public abstract class EstadoEstoque {
  protected Produto produto;
  protected int qnt_min, qnt_max;

  // #region Construtores e Getters e Setters
  public EstadoEstoque(Produto produto, int qnt_min, int qnt_max) {
    setProduto(produto);
    setQnt_max(qnt_max);
    setQnt_min(qnt_min);
  }

  public void setProduto(Produto produto) {
    this.produto = produto;
  }

  public void setQnt_max(int qnt_max) {
    this.qnt_max = qnt_max;
  }

  public int getQnt_max() {
    return qnt_max;
  }

  public void setQnt_min(int qnt_min) {
    this.qnt_min = qnt_min;
  }

  public int getQnt_min() {
    return qnt_min;
  }
  // #endregion Construtores e Getters e Setters

  public boolean repor(int qnt) {
    if (qnt > 0 && this.produto.setQuantidade(produto.getQuantidade() + qnt)) {
      lidaEstado();
      return true;
    } else {
      return false;
    }
  }

  public boolean vender(int qnt) {
    if (qnt >= 0 && this.produto.setQuantidade(produto.getQuantidade() - qnt)) {

      lidaEstado();
      return true;
    } else {
      return false;
    }
  }

  public abstract void lidaEstado();

}

package State;

import Context.Celula;

public abstract class Estado {
  protected Celula celula;

  public Estado(Celula celula) {
    this.celula = celula;
  }

  public abstract void avanca(Celula[][] vizinhanca);

  /**
   * @return Constante inteira que representa o estado da celula
   */
  public abstract int getCodigo();
}

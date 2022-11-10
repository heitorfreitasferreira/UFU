package State.Queima;

import Context.*;

public class QueimaInicial extends Queima {
  public static final int codigo = 1;

  public QueimaInicial(Celula celula) {
    super(celula);
    t = 0;
    MAX_T = 2;
    PROB_QUEIMA = 0.6;
  }

  public double getFORCA_QUEIMA() {
    return PROB_QUEIMA;
  }

  public void avanca(Celula[][] vizinhanca) {
    if (t >= MAX_T) {
      celula.setEstado(new QueimaEstavel(celula));
    } else {
      t++;
    }
  }

  public int getCodigo() {
    return codigo;
  }
}

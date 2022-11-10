package State.Queima;

import Context.*;

public class QueimaEstavel extends Queima {

  public static final int codigo = 2;

  public QueimaEstavel(Celula celula) {
    super(celula);
    t = 0;
    PROB_QUEIMA = 1;
    MAX_T = 4;
  }

  public void avanca(Celula[][] vizinhanca) {
    if (t >= MAX_T) {
      celula.setEstado(new QueimaLenta(celula));
    } else {
      t++;
    }
  }

  public int getCodigo() {
    return codigo;
  }
}

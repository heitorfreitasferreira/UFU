package State.Queima;

import State.*;
import Context.*;

public class QueimaLenta extends Queima {
  public static final int codigo = 3;

  public QueimaLenta(Celula celula) {
    super(celula);
    t = 0;
    MAX_T = 10;
    PROB_QUEIMA = 0.2;
  }

  public double getFORCA_QUEIMA() {
    return PROB_QUEIMA;
  }

  public void avanca(Celula[][] vizinhanca) {
    if (t >= MAX_T) {
      celula.setEstado(new SoloExposto(celula));
    } else {
      t++;
    }
  }

  public int getCodigo() {
    return codigo;
  }
}

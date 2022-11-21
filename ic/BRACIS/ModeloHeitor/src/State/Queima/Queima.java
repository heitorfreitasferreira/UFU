package State.Queima;

import State.*;
import Context.*;

public abstract class Queima extends Estado {
  public static double PROB_QUEIMA = 1;
  public static int MAX_T = 4;
  protected int t;

  public Queima(Celula celula) {
    super(celula);
  }
}

package State;

import Context.Celula;

public class SoloExposto extends Estado {
  private int t;

  public static final int codigo = 0;

  public SoloExposto(Celula celula) {
    super(celula);
    t = 0;
  }

  public void avanca(Celula[][] vizinhanca) {
    if (Math.random() < ((t * t) / 2 * Math.pow(10, 7))) {
      celula.setEstado(celula.getEstadoInicial());
    } else {
      t++;
    }
  }

  public int getCodigo() {
    return codigo;
  }
}

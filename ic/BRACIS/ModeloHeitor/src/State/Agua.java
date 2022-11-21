package State;

import Context.Celula;

public class Agua extends Estado {

  public static final int codigo = 7;

  public Agua(Celula celula) {
    super(celula);
  }

  public void avanca(Celula[][] vizinhanca) {
    // permanece para sempre nesse estado
  }

  public int getCodigo() {
    return codigo;
  }
}
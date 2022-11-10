package State.Vegetacao;

import Context.*;
import State.Queima.*;

public class Florestal extends Vegetacao {
  protected static double PROB_VEGETACAO = 0.8;
  public static final int codigo = 6;

  public Florestal(Celula celula) {
    super(celula);
  }

  public int getCodigo() {
    return codigo;
  }

  private boolean temFogo(Celula[][] vizinhanca) {
    for (int i = 0; i < vizinhanca.length; i++) {
      for (int j = 0; j < vizinhanca[i].length; j++) {
        if ((vizinhanca[i][j].getEstado() instanceof QueimaInicial
            || vizinhanca[i][j].getEstado() instanceof QueimaEstavel
            || vizinhanca[i][j].getEstado() instanceof QueimaLenta)
            && i != 1 && j != 0) {
          return true;
        }
      }
    }
    return false;
  }

  public void avanca(Celula[][] vizinhanca) {
    if (temFogo(vizinhanca)) {

      for (int i = 0; i < vizinhanca.length; i++) {
        for (int j = 0; j < vizinhanca[i].length; j++) {
          if ((i != 0 && j != 0) &&
              ((vizinhanca[i][j].getEstado() instanceof QueimaEstavel
                  &&
                  Math.random() < vizinhanca[i][j].getReticulado().getVento().get(i, j) * QueimaEstavel.PROB_QUEIMA
                      * Reticulado.getCoef_umidade() * Florestal.PROB_VEGETACAO)
                  ||
                  (vizinhanca[i][j].getEstado() instanceof QueimaLenta
                      &&
                      Math.random() < vizinhanca[i][j].getReticulado().getVento().get(i, j) * QueimaLenta.PROB_QUEIMA
                          * Reticulado.getCoef_umidade() * Florestal.PROB_VEGETACAO)
                  ||
                  (vizinhanca[i][j].getEstado() instanceof QueimaInicial
                      &&
                      Math.random() < vizinhanca[i][j].getReticulado().getVento().get(i, j) * QueimaInicial.PROB_QUEIMA
                          * Reticulado.getCoef_umidade() * Florestal.PROB_VEGETACAO))) {

            celula.setEstado(new QueimaInicial(celula));
            return;
          }

        }
      }
    }
  }
}

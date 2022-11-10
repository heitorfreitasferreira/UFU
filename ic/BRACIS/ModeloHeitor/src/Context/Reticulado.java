package Context;

import java.util.ArrayList;

import State.Agua;
import State.Estado;
import State.Queima.*;
import Utils.*;

public class Reticulado {

  private MatrizVento vento;
  private Celula principal[][], aux[][];
  private int dimensao;

  private static double coef_umidade = 1;

  /**
   * @param dimensao     Reticulado dimensionado em dimensao x dimensao
   * @param direcaoVento Para onde o vento esta levando a matéria
   * @param umidade      Umidade porcentual do ar
   * @param quadrante    Array com os 4 posições, sendo cada uma delas o estado
   *                     inicial da celula no quadrante correspondente
   *
   */
  public Reticulado(int dimensao, String direcaoVento, double umidade, ArrayList<Integer> quadrante, int fogoInicialI,
      int fogoInicialJ) {
    vento = MatrizVento.gerar(direcaoVento);
    setUmidade(umidade);
    this.dimensao = dimensao;
    principal = new Celula[dimensao][dimensao];
    aux = new Celula[dimensao][dimensao];
    inicializaReticulado(quadrante);
    principal[fogoInicialI][fogoInicialJ] = new Celula(Celula.QUEIMA_INICIAL, this);
    aux[fogoInicialI][fogoInicialJ] = new Celula(Celula.QUEIMA_INICIAL, this);
  }

  private void inicializaReticulado(ArrayList<Integer> quadrante) {
    // Quadrante 1/A
    for (int i = 0; i < (int) (dimensao / 2); i++) {
      for (int j = (int) (dimensao / 2); j < dimensao; j++) {
        principal[i][j] = new Celula(quadrante.get(0), this);
      }
    }
    // Quadrante 2/B
    for (int i = 0; i < (int) (dimensao / 2); i++) {
      for (int j = 0; j < (int) (dimensao / 2); j++) {
        principal[i][j] = new Celula(quadrante.get(1), this);
      }
    }
    // Quadrante 3/C
    for (int i = (int) (dimensao / 2); i < dimensao; i++) {
      for (int j = 0; j < (int) (dimensao / 2); j++) {
        principal[i][j] = new Celula(quadrante.get(2), this);
      }
    }
    // Quadrante 4/D
    for (int i = (int) (dimensao / 2); i < dimensao; i++) {
      for (int j = (int) (dimensao / 2); j < dimensao; j++) {
        principal[i][j] = new Celula(quadrante.get(3), this);
      }
    }
  }

  private void setUmidade(double umidade) {
    if (umidade > 0 && umidade <= 0.30) {
      coef_umidade = 1.5;
      QueimaInicial.MAX_T = 2;
      QueimaEstavel.MAX_T = 5;
      QueimaLenta.MAX_T = 3;
    }
    if (umidade > 0.30 && umidade <= 0.40) {
      coef_umidade = 1;
    }
    if (umidade > 0.40 && umidade <= 0.60) {
      coef_umidade = 0.8;
    }
    if (umidade > 0.60 && umidade <= 1) {
      coef_umidade = 0.6;
    }
  }

  /**
   * @return Valor que influencia a probabilidade de queima de uma celula, usar
   *         apenas nas classes do packege State.Vegetacao
   */
  public static double getCoef_umidade() {
    return coef_umidade;
  }

  /**
   * @return Objeto com as probabilidades que representam a influência do vento
   */
  public MatrizVento getVento() {
    return vento;
  }

  public boolean temFogo() {
    for (int i = 0; i < dimensao; i++) {
      for (int j = 0; j < dimensao; j++) {
        if (principal[i][j].getEstado() instanceof Queima) {
          return true;
        }
      }
    }
    return false;
  }

  public void atualiza() {
    for (int i = 0; i < dimensao; i++) {
      for (int j = 0; j < dimensao; j++) {
        aux[i][j] = new Celula(principal[i][j].getEstado().getCodigo(), this);
      }
    }
    for (int i = 0; i < dimensao; i++) {
      for (int j = 0; j < dimensao; j++) {
        Celula moore[][] = new Celula[3][3];

        if (i - 1 <= 0) {
          moore[0][0] = new Celula(Celula.AGUA, this);
          moore[0][1] = new Celula(Celula.AGUA, this);
          moore[0][2] = new Celula(Celula.AGUA, this);
        } else {
          moore[0][0] = aux[i - 1][j];
          moore[0][1] = aux[i - 1][j];
          moore[0][2] = aux[i - 1][j];
        }
        if (i + 1 >= dimensao) {
          moore[2][0] = new Celula(Celula.AGUA, this);
          moore[2][1] = new Celula(Celula.AGUA, this);
          moore[2][2] = new Celula(Celula.AGUA, this);
        } else {
          moore[2][0] = aux[i + 1][j];
          moore[2][1] = aux[i + 1][j];
          moore[2][2] = aux[i + 1][j];
        }
        if (j - 1 <= 0) {
          moore[0][0] = new Celula(Celula.AGUA, this);
          moore[1][0] = new Celula(Celula.AGUA, this);
          moore[2][0] = new Celula(Celula.AGUA, this);
        } else {
          moore[0][0] = aux[i][j - 1];
          moore[1][0] = aux[i][j - 1];
          moore[2][0] = aux[i][j - 1];
        }
        if (j + 1 >= dimensao) {
          moore[0][2] = new Celula(Celula.AGUA, this);
          moore[1][2] = new Celula(Celula.AGUA, this);
          moore[2][2] = new Celula(Celula.AGUA, this);
        } else {
          moore[0][2] = aux[i][j + 1];
          moore[1][2] = aux[i][j + 1];
          moore[2][2] = aux[i][j + 1];
        }
        moore[1][1] = aux[i][j];
        // MÉTODO HEITORZEIRA DE QUALIDADE!!
        principal[i][j].avanca(moore);
      }
    }

  }

  public void printa() {
    for (int i = 0; i < dimensao; i++) {
      for (int j = 0; j < dimensao; j++) {
        System.out.print(principal[i][j].getEstado().getCodigo() + " ");
      }
      System.out.println();
    }
  }
}

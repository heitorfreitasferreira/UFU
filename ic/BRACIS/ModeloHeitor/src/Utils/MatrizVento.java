package Utils;

public class MatrizVento {
  private static MatrizVento self;
  private final static int m = 3, n = 3;

  private double mat[][] = {
      { 0, 0, 0 },
      { 0, 0, 0 },
      { 0, 0, 0 }
  };

  private MatrizVento(double coef, double mult_base, double decaimento, String dir) {
    setVento(coef, mult_base, decaimento, dir);
  }

  private void setVento(double coef, double mult_base, double decaimento, String dir) {
    mat[1][1] = 0;

    if (dir == "s") {
      mat[0][1] = coef * (mult_base - (decaimento * 0));
      mat[0][0] = coef * (mult_base - (decaimento * 1));
      mat[0][2] = coef * (mult_base - (decaimento * 1));
      mat[1][0] = coef * (mult_base - (decaimento * 2));
      mat[1][2] = coef * (mult_base - (decaimento * 2));
      mat[2][0] = coef * (mult_base - (decaimento * 3));
      mat[2][2] = coef * (mult_base - (decaimento * 3));
      mat[2][1] = coef * (mult_base - (decaimento * 4));
    } else if (dir == "n") {
      mat[2][1] = coef * (mult_base - (decaimento * 0));
      mat[2][0] = coef * (mult_base - (decaimento * 1));
      mat[2][2] = coef * (mult_base - (decaimento * 1));
      mat[1][0] = coef * (mult_base - (decaimento * 2));
      mat[1][2] = coef * (mult_base - (decaimento * 2));
      mat[0][0] = coef * (mult_base - (decaimento * 3));
      mat[0][2] = coef * (mult_base - (decaimento * 3));
      mat[0][1] = coef * (mult_base - (decaimento * 4));
    } else if (dir == "l") {
      mat[1][0] = coef * (mult_base - (decaimento * 0));
      mat[0][0] = coef * (mult_base - (decaimento * 1));
      mat[2][0] = coef * (mult_base - (decaimento * 1));
      mat[0][1] = coef * (mult_base - (decaimento * 2));
      mat[2][1] = coef * (mult_base - (decaimento * 2));
      mat[0][2] = coef * (mult_base - (decaimento * 3));
      mat[2][2] = coef * (mult_base - (decaimento * 3));
      mat[1][2] = coef * (mult_base - (decaimento * 4));
    } else if (dir == "o") {
      mat[1][2] = coef * (mult_base - (decaimento * 0));
      mat[2][2] = coef * (mult_base - (decaimento * 1));
      mat[0][2] = coef * (mult_base - (decaimento * 1));
      mat[2][1] = coef * (mult_base - (decaimento * 2));
      mat[0][1] = coef * (mult_base - (decaimento * 2));
      mat[0][2] = coef * (mult_base - (decaimento * 3));
      mat[2][0] = coef * (mult_base - (decaimento * 3));
      mat[1][0] = coef * (mult_base - (decaimento * 4));
    } else if (dir == "ne") {
      mat[2][2] = coef * (mult_base - (decaimento * 0));
      mat[1][2] = coef * (mult_base - (decaimento * 1));
      mat[2][1] = coef * (mult_base - (decaimento * 1));
      mat[0][2] = coef * (mult_base - (decaimento * 2));
      mat[2][0] = coef * (mult_base - (decaimento * 2));
      mat[0][1] = coef * (mult_base - (decaimento * 3));
      mat[1][0] = coef * (mult_base - (decaimento * 3));
      mat[0][0] = coef * (mult_base - (decaimento * 4));
    } else if (dir == "so") {
      mat[0][0] = coef * (mult_base - (decaimento * 0));
      mat[1][0] = coef * (mult_base - (decaimento * 1));
      mat[0][1] = coef * (mult_base - (decaimento * 1));
      mat[2][0] = coef * (mult_base - (decaimento * 2));
      mat[0][2] = coef * (mult_base - (decaimento * 2));
      mat[2][1] = coef * (mult_base - (decaimento * 3));
      mat[1][2] = coef * (mult_base - (decaimento * 3));
      mat[2][2] = coef * (mult_base - (decaimento * 4));
    } else if (dir == "no") {
      mat[2][0] = coef * (mult_base - (decaimento * 0));
      mat[1][0] = coef * (mult_base - (decaimento * 1));
      mat[2][1] = coef * (mult_base - (decaimento * 1));
      mat[0][0] = coef * (mult_base - (decaimento * 2));
      mat[2][2] = coef * (mult_base - (decaimento * 2));
      mat[0][1] = coef * (mult_base - (decaimento * 3));
      mat[1][2] = coef * (mult_base - (decaimento * 3));
      mat[0][2] = coef * (mult_base - (decaimento * 4));
    } else if (dir == "se") {
      mat[0][0] = coef * (mult_base - (decaimento * 0));
      mat[1][0] = coef * (mult_base - (decaimento * 1));
      mat[0][1] = coef * (mult_base - (decaimento * 1));
      mat[2][0] = coef * (mult_base - (decaimento * 2));
      mat[0][2] = coef * (mult_base - (decaimento * 2));
      mat[2][1] = coef * (mult_base - (decaimento * 3));
      mat[1][2] = coef * (mult_base - (decaimento * 3));
      mat[2][2] = coef * (mult_base - (decaimento * 4));
    } else {
      System.out.println("Direção inválida, direção padrão: n");
      mat[2][1] = coef * (mult_base - (decaimento * 0));
      mat[2][0] = coef * (mult_base - (decaimento * 1));
      mat[2][2] = coef * (mult_base - (decaimento * 1));
      mat[1][0] = coef * (mult_base - (decaimento * 2));
      mat[1][2] = coef * (mult_base - (decaimento * 2));
      mat[0][0] = coef * (mult_base - (decaimento * 3));
      mat[0][2] = coef * (mult_base - (decaimento * 3));
      mat[0][1] = coef * (mult_base - (decaimento * 4));
    }
  }

  public static MatrizVento gerar(String direcao) {
    return gerar(1, 0.16, 0.03, direcao);
  }

  public static MatrizVento gerar(double coef, double mult_base, double decaimento, String direcao) {
    if (self == null) {
      synchronized (MatrizVento.class) {
        if (self == null) {
          self = new MatrizVento(coef, mult_base, decaimento, direcao);
        }
      }
    }
    return self;
  }

  public void print() {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        System.out.print(mat[i][j] + " ");
      }
      System.out.println();
    }
  }

  public double get(int i, int j) {
    return mat[i][j];
  }
}

package Context;

import State.*;
import State.Queima.*;
import State.Vegetacao.*;
import State.*;

public class Celula {

  public static final int SOLO_EXPOSTO = 0;
  public static final int QUEIMA_INICIAL = 1;
  public static final int QUEIMA_ESTAVEL = 2;
  public static final int QUEIMA_LENTA = 3;
  public static final int CAMPESTRE = 4;
  public static final int SAVANICA = 5;
  public static final int FLORESTAL = 6;
  public static final int AGUA = 7;

  private Estado estado, estadoInicial;
  private Reticulado reticulado;

  public Celula(int estado, Reticulado reticulado) {
    switch (estado) {
      case SOLO_EXPOSTO:
        this.estado = new SoloExposto(this);
        this.estadoInicial = new SoloExposto(this);
        break;
      case QUEIMA_INICIAL:
        this.estado = new QueimaInicial(this);
        this.estadoInicial = new QueimaInicial(this);
        break;
      case QUEIMA_ESTAVEL:
        this.estado = new QueimaEstavel(this);
        this.estadoInicial = new QueimaEstavel(this);
        break;
      case QUEIMA_LENTA:
        this.estado = new QueimaLenta(this);
        this.estadoInicial = new QueimaLenta(this);
        break;
      case CAMPESTRE:
        this.estado = new Campestre(this);
        this.estadoInicial = new Campestre(this);
        break;
      case SAVANICA:
        this.estado = new Savanica(this);
        this.estadoInicial = new Savanica(this);
        break;
      case FLORESTAL:
        this.estado = new Florestal(this);
        this.estadoInicial = new Florestal(this);
        break;
      case AGUA:
        this.estado = new Agua(this);
        this.estadoInicial = new Agua(this);
        break;
      default:
        this.estado = new Agua(this);
        this.estadoInicial = new Agua(this);
        break;
    }
  }

  public Celula(Estado estado, Reticulado reticulado) {
    setEstado(estado);
    this.estadoInicial = estado;
    this.reticulado = reticulado;
  }

  // Copy Constructor
  public Celula(Celula celula) {
    this(celula.getEstado(), celula.getReticulado());
  }

  /**
   * @param estado Para uso exclusivo das classes do pacote State
   */
  public void setEstado(Estado estado) {
    this.estado = estado;
  }

  /**
   * @return O estado em que a celula foi inicializada pela primeira vez
   */
  public Estado getEstadoInicial() {
    return estadoInicial;
  }

  /**
   * @return O estado atual da celula
   */
  public Estado getEstado() {
    return estado;
  }

  /**
   * @return O reticulado em que a celula se encontra
   */
  public Reticulado getReticulado() {
    return reticulado;
  }

  public void avanca(Celula[][] vizinhaca) {
    estado.avanca(vizinhaca);
  }

}
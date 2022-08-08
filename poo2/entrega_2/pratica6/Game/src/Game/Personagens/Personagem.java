package Game.Personagens;

import Correr.*;
import Pular.*;
import Vida.*;
import Vida.Estados.*;
import Escudos.*;
import Atacar.*;

public abstract class Personagem {
  // Strategys
  private PularStrategyInterface pulo;
  private CorrerStrategyInterface corrida;
  private AtacarStrategyInterface ataque;

  // States
  private int vida;
  private String nome;

  // Escudos
  private EscudoHandler escudo;

  private VidaInterface estado;

  public Personagem(
      PularStrategyInterface pulo,
      CorrerStrategyInterface corrida,
      AtacarStrategyInterface ataque,
      EscudoHandler escudo,
      String nome) {
    setCorrida(corrida);
    setPulo(pulo);
    setNome(nome);
    setVida(70);
    setAtaque(ataque);
    setEstado(new Fraco(this));
    this.escudo = escudo;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public String getNome() {
    return nome;
  }

  // ---------------------------------------------------
  // Atacar Decorators
  public AtacarStrategyInterface getAtaque() {
    return ataque;
  }

  public String getDescricaoAtaques() {
    return ataque.getDescricao();
  }

  public int getDanoAtaques() {
    return ataque.getDano();
  }
  // ---------------------------------------------------
  // Chain of Escudos
  // private void setPrimeiroEscudo(EscudoHandler escudo) {
  // this.escudo = escudo;
  // }

  public int getEscudo() {
    return escudo.getValor();
  }

  public void addEscudo(EscudoHandler escudo) {
    this.escudo.addEscudo(escudo);
  }
  public void atacar(Personagem personagem) {
    personagem.apanhar(this.getDanoAtaques());
  }
  // ---------------------------------------------------
  // States Pattern

  public void setEstado(VidaInterface estado) {
    this.estado = estado;
    estado.lidaAlteracaoVida();
  }

  public int getVida() {
    return vida;
  }

  public void setVida(int vida) {
    if (vida > 100)
      this.vida = 100;
    else if (vida < 0)
      this.vida = 0;
    else
      this.vida = vida;
  }

  public VidaInterface getEstado() {
    return estado;
  }

  public void curar(int quantidade) {
    this.estado.curar(quantidade);
  }

  public int apanhar(int quantidade) {
    int tomado = escudo.danoPosMitigacao(quantidade);
    this.estado.apanhar(tomado);
    return tomado;
  }

  public void sobeDesceVida(int quantidade) {
    if (quantidade > 0) {
      this.estado.curar(quantidade);
    } else if (quantidade < 0) {
      this.estado.apanhar(quantidade);
    }
  }

  // ---------------------------------------------------
  // Strategy Pattern
  // ---------------------------------------------------
  // Alteração/Escolha de estratégias
  public void setPulo(PularStrategyInterface pulo) {
    this.pulo = pulo;
  }

  public void setAtaque(AtacarStrategyInterface ataque) {
    this.ataque = ataque;
  }

  public void setCorrida(CorrerStrategyInterface corrida) {
    this.corrida = corrida;
  }

  // Comportamentos do Personagem (Strategys)
  public String pular() {
    return pulo.pular();
  }

  public String correr() {
    return corrida.correr();
  }

  public String atacar() {
    return ataque.atacar();
  }
}

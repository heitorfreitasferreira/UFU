package Imoveis;

import pessoas.Endereco;

import java.util.Date;

public class Terreno extends Imovel{
    private boolean possuiAclive;

    public Terreno(boolean disponivel, boolean paraVenda, boolean ativo, Date dataConstrucao, Date dataRegistro, float valor, float valorImobiliaria, Endereco endereco, int area, boolean possuiAclive) {
        super(disponivel, paraVenda, ativo, dataConstrucao, dataRegistro, valor, valorImobiliaria, endereco, area);
        setPossuiAclive(possuiAclive);
    }

    public boolean possuiAclive() {
        return possuiAclive;
    }
    public void setPossuiAclive(boolean possuiAclive) {
        this.possuiAclive = possuiAclive;
    }
}

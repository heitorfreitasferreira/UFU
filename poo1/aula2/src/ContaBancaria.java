public class ContaBancaria {
    public String nome;
    public String cpf;
    public float saldo;

    public float getSaldo() {
        return saldo;
    }
    public boolean saque(float transaction){
        if (transaction<=saldo){
            saldo-= transaction;
            return True;
        }
        else
            return False;
    }

    public boolean deposita(float transaction){
        saldo += transaction;
        return True;
    }
}

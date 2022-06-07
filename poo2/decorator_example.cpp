#include <iostream>
using namespace std;
class Carro{
    // Abstract Class
private:
    double custo;
    string descricao;
public:
    Carro(double custo, string descricao){
        this->custo = custo;
        this->descricao = descricao;
    }
    Carro(Carro &carro):Carro(carro.custo,carro.descricao){

    }
    void setCusto(double custo){
        this->custo = custo;
    }
    void setDescricao(string descricao){
        this->descricao = descricao;
    }
    string getDescricao(){
        return descricao;
    }
    double getCusto(){
        return custo;
    }
};
class DelRey: public Carro{
    //Concrete Class
public:
    DelRey(int custo, string descricao):Carro(custo,descricao){
    }
    DelRey(Carro &carro):Carro(carro){

    }
};
class CarroDecorador:public Carro{
    //Abastract Class
private:
    Carro carro_decorado;
public:
    CarroDecorador(Carro &carro):Carro(carro){
        carro_decorado = Carro(carro);

    }
    Carro getCarroDecorado(){
        return carro_decorado;
    }
    virtual double getCusto();/*{
     //Polimorfismo
     double a = super.getCusto()
     //Adicionar a decoração
     double b = carro_decorado.getCusto();
     // Chamar a resposabilidade do objeto a ser decorado
     //
     return
   }*/
    virtual string getDescricao();
};

class CentralMultimidia: public CarroDecorador{
public:
    CentralMultimidia(Carro carro_a_ser_decorado):CarroDecorador(carro_a_ser_decorado){

    }
    double getCusto(){
        double a = getCarroDecorado().getCusto();
        /*
          * Custo do carro base a ser decorado
          * Será de um carro genérico, ou um carro concreto,
          ou um carro com ar condicionado,
          ou um carro com ar condicionado e
          ou etc...
          * Chama a responsabilidade de quem ta sendo decorado
          * Adiciona a responsabilidade desta camada de decoração
        */
        double b = 1000; // Consulta no db por exemplo
        // Custo da central multimídia
        return a+b;
    }
    string getDescricao(){
        string a = getCarroDecorado().getDescricao();
        string b = "Aparelhagem de som";//Consulta db
        return a + "\n" + b;
    }
};
class ArCondicionado: public CarroDecorador{
public:
    ArCondicionado(Carro carro_a_ser_decorado):CarroDecorador(carro_a_ser_decorado){

    }
    double getCusto(){
        return getCarroDecorado().getCusto() + 500;
    }
    string getDescricao(){
        return getCarroDecorado().getDescricao() + "\n" + "Ar condicionado";
    }
};
class Venda{
public:
    void vender(Carro carro){
        cout<<carro.getCusto()<<endl<<carro.getDescricao();
    }
};
int main (){
    Carro c = DelRey(1000,"DelRey");//Dados viriam de um db por exemplo
    Venda v;
    v.vender(c);
    c = CentralMultimidia(c); // Adiciona decoração no carro base
    v.vender(c);
}
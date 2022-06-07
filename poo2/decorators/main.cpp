#include <iostream>
#include <string>
using namespace std;
//class Carro{
//    // Abstract Class
//private:
//    double custo;
//    string descricao;
//public:
//    Carro(double custo, string descricao){
//        this->custo = custo;
//        this->descricao = descricao;
//    }
//    Carro(Carro &carro):Carro(carro.custo,carro.descricao){
//
//    }
//    void setCusto(double custo){
//        this->custo = custo;
//    }
//    void setDescricao(string descricao){
//        this->descricao = descricao;
//    }
//    string getDescricao(){
//        return descricao;
//    }
//    double getCusto(){
//        return custo;
//    }
//};
//class DelRey: public Carro{
//    //Concrete Class
//public:
//    DelRey(int custo, string descricao):Carro(custo,descricao){
//    }
//    DelRey(Carro &carro):Carro(carro){
//
//    }
//};
//class CarroDecorador:public Carro{
//    //Abastract Class
//protected:
//    Carro *carro_decorado;
//public:
//    CarroDecorador(Carro *carro):carro_decorado(carro){
//
//    }
//    Carro getCarroDecorado(){
//        return *carro_decorado;
//    }
//    virtual double getCusto();/*{
//     //Polimorfismo
//     double a = super.getCusto()
//     //Adicionar a decoração
//     double b = carro_decorado.getCusto();
//     // Chamar a resposabilidade do objeto a ser decorado
//     //
//     return
//   }*/
//    virtual string getDescricao();
//};
//
//class CentralMultimidia: public CarroDecorador{
//public:
//    CentralMultimidia(Carro carro_a_ser_decorado):CarroDecorador(&carro_a_ser_decorado){
//
//    }
//    double getCusto(){
//        double a = getCarroDecorado().getCusto();
//        /*
//          * Custo do carro base a ser decorado
//          * Será de um carro genérico, ou um carro concreto,
//          ou um carro com ar condicionado,
//          ou um carro com ar condicionado e
//          ou etc...
//          * Chama a responsabilidade de quem ta sendo decorado
//          * Adiciona a responsabilidade desta camada de decoração
//        */
//        double b = 1000; // Consulta no db por exemplo
//        // Custo da central multimídia
//        return a+b;
//    }
//    string getDescricao(){
//        string a = getCarroDecorado().getDescricao();
//        string b = "Aparelhagem de som";//Consulta db
//        return a + "\n" + b;
//    }
//};
//class ArCondicionado: public CarroDecorador{
//public:
//    ArCondicionado(Carro carro_a_ser_decorado):CarroDecorador(&carro_a_ser_decorado){
//
//    }
//    double getCusto(){
//        return getCarroDecorado().getCusto() + 500;
//    }
//    string getDescricao(){
//        return getCarroDecorado().getDescricao() + "\n" + "Ar condicionado";
//    }
//};

/**
 * The base Car interface defines operations that can be altered by
 * decorators.
 */
class Car {
private:
    double custo;
    string descricao;
public:
    //virtual ~Car() {}
    Car(double custo,string descricao){
        Car::setCusto(custo);
        Car::setDescricao(descricao);
    }
    Car(Car &car):Car(car.custo,car.descricao){

    }
    double getCusto() {
        return this->custo;
    }
    void setCusto(double custo) {
        this->custo = custo;
    }
    string getDescricao() {
        return this-> descricao;
    }
    void setDescricao(const string &descricao) {
        this->descricao = descricao;
    }
//    virtual std::string Operation() const = 0;

};
/**
 * Concrete Cars provide default implementations of the operations. There
 * might be several variations of these classes.
 */
class Voyage : public Car {
public:
    Voyage(double custo,string descricao): Car(custo,descricao){
    }
};;


/**
 * The base Decorator class follows the same interface as the other Cars.
 * The primary purpose of this class is to define the wrapping interface for all
 * concrete decorators. The default implementation of the wrapping code might
 * include a field for storing a wrapped Car and the means to initialize
 * it.
 */
class CarDecorator : public Car {
    /**
     * @var Car
     */
protected:
    Car Car_;

public:

    /**
     * The Decorator delegates all work to the wrapped Car.
     */
//    std::string Operation() const override {
//        return this->Car_->Operation();
//    }
//    virtual string getDescricao();
//    {
//        return this->Car_->getDescricao();
//    }
//    virtual double getCusto();
//    {
//        return this->Car_->getCusto();
//    }
    Car* getCarroDecorado(){
        return Car_;
    }
};
/**
 * Decorators can execute their behavior either before or after the call to a
 * wrapped object.
 */
class CentralMultimidia : public CarDecorator {
public:
    CentralMultimidia(Car* Car) : CarDecorator(Car) {
    }

    string getDescricao(){
        return "Central Multimidia(" + Car_.getDescricao() + ")";
    }
    double getCusto(){
        return 500 + Car_.getCusto();
    }
};

/**
 * Concrete Decorators call the wrapped object and alter its result in some way.
 */
class RogaLigaLeve : public CarDecorator {
    /**
     * Decorators may call parent implementation of the operation, instead of
     * calling the wrapped object directly. This approach simplifies extension of
     * decorator classes.
     */
public:
    RogaLigaLeve(Car* Car) : CarDecorator(Car) {
    }
//    std::string Operation() const override {
//        return "RogaLigaLeve(" + CarDecorator::Operation() + ")";
//    }
    string getDescricao(){
        return "RogaLigaLeve(" + Car_.getDescricao() + ")";
    }
    double getCusto(){
        return 500 + Car_.getCusto();
    }
};

/**
 * The client code works with all objects using the Car interface. This
 * way it can stay independent of the concrete classes of Cars it works
 * with.
 */
class Venda{
public:
    void vender(Car carro){
        cout<<"Descricao: "<<carro.getDescricao()<<endl<<"Custo: "<<carro.getCusto()<<endl<<endl;
    }
};
int main() {
    /**
     * This way the client code can support both simple Cars...
     */
    Car* simple = new Voyage(1000,"Voyage");
    Venda v;
    v.vender(*simple);
    /* --------------------------------------------- */
    Car* decorator1 = new RogaLigaLeve(simple);
    v.vender(*decorator1);
    /* --------------------------------------------- */
    Car* decorator2 = new CentralMultimidia(decorator1);
    v.vender(*decorator2);
    /* --------------------------------------------- */

    delete simple;
    delete decorator1;
    delete decorator2;

    return 0;
}
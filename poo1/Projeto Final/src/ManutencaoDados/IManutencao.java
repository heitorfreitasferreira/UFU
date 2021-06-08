package ManutencaoDados;

public interface IManutencao<Type> {
    void adicionar(Type bean);
    void eliminar(String bean);
    void listar();
    Type buscar(String bean);
    void salvaDadosBin();
}

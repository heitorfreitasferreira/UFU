public class App {
    public static void main(String[] args) throws Exception {
        Forma forma = new Circulo();
        System.out.println("Forma sem decorações...\n"+forma.getDescricao());
        forma = new Mesh3D(forma);
        System.out.println("Decorando com 3D...\n"+forma.getDescricao());
        forma = new Luz(forma);
        System.out.println("Decorando com luzes...\n"+forma.getDescricao());
    }
}

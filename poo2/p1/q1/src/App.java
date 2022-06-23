public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Criando produto...");
        Produto produto = new Produto("Amaciante", 10.0);
        System.out.println("\n\n-----------------------------------");
        System.out.println("Repondo 3 unidades...");
        produto.repor(3);
        System.out.println("\n\n-----------------------------------");
        System.out.println("Vendendo 3 unidades...");
        produto.vender(3);
        System.out.println("\n\n-----------------------------------");
        System.out.println("Vendendo 3 unidades...");
        produto.vender(3);
        System.out.println("\n\n-----------------------------------");
        System.out.println("Repondo 10 unidades...");
        produto.repor(10);
        System.out.println("\n\n-----------------------------------");
    }
}

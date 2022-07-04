public class App {
    public static void main(String[] args) throws Exception {
        Automato a1 = new Automato("abcd");
        System.out.println("\nAnalisando cadeia: aaacdb");
        a1.processa("aaacdb");
        System.out.println("-------------------------------\n\nAnalisando cadeia: ababacdaaac");
        a1.processa("ababacdaaac");
        System.out.println("-------------------------------\n\nAnalisando cadeia: abcdb");
        a1.processa("abcdb");
        System.out.println("-------------------------------\n\nAnalisando cadeia: acda");
        a1.processa("acda");
        System.out.println("-------------------------------\n\nAnalisando cadeia: acdbdb");
        a1.processa("acdbdb");
    }
}

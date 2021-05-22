import java.util.ArrayList;
import java.util.Objects;

public class GestaoContatos {
    private ArrayList<Contato> familia;
    private ArrayList<Contato> amigos;
    private ArrayList<Contato> profissional;

    public void adicionaContato(Contato novoContato, int lista){
        if (lista == 1)
            familia.add(novoContato);
        else if (lista == 2)
            amigos.add(novoContato);
        else if (lista == 3)
            profissional.add(novoContato);
    }

    public void eliminaContato(String nome){
        boolean flag = false;
        flag = familia.removeIf(contato -> Objects.equals(contato.getNome(), nome));
        if(!flag)
            flag = amigos.removeIf(contato -> Objects.equals(contato.getNome(), nome));
        if(!flag)
            flag = profissional.removeIf(contato -> Objects.equals(contato.getNome(), nome));
        if (!flag)
            System.out.println("Não foi possível encontrar nenhum contato com o nome correspondente!");
    }

    public void listaContatos(int lista){
        ArrayList<Contato> contatos = new ArrayList<Contato>();
        if (lista == 1)
            contatos = familia;
        else if (lista == 2)
            contatos = amigos;
        else if (lista == 3)
            contatos = profissional;
        for (Contato contato : contatos) {
            System.out.println(contato.toString());
        }
    }

    public int maisVelho(int lista){
        ArrayList<Contato> contatos = new ArrayList<Contato>();
        if (lista == 1)
            contatos = familia;
        else if (lista == 2)
            contatos = amigos;
        else if (lista == 3)
            contatos = profissional;

        int max = 0;
        for (Contato contato : contatos) {
            if (contato.getIdade() > max)
                max = contato.getIdade();
        }

        return max;
    }

    public int maisNovo(int lista){
        ArrayList<Contato> contatos = new ArrayList<Contato>();
        if (lista == 1)
            contatos = familia;
        else if (lista == 2)
            contatos = amigos;
        else if (lista == 3)
            contatos = profissional;

        int min = 0;
        int count = 0;
        for (Contato contato : contatos) {
            if (count == 0)
                min = contato.getIdade();
            if (contato.getIdade() < min)
                min = contato.getIdade();
            count++;
        }

        return min;
    }

public void salvaContatos() throws IOException {
        try{
            BufferedWriter escritor = new BufferedWriter(new FileWriter("contatosFamilia"));
            StringBuilder texto = new StringBuilder("CONTATOS -------------+\n");
            for (Contato contato: familia) {
                texto.append(contato.toString()).append("\n");
            }
            texto.append("+-------------+%n");
            escritor.write(texto.toString());
            escritor.flush();
            escritor.close();

        }catch(IOException e){
            e.printStackTrace();
        }

        try{
            BufferedWriter escritor = new BufferedWriter(new FileWriter("contatosAmigos"));
            StringBuilder texto = new StringBuilder("CONTATOS -------------+\n");
            for (Contato contato: amigos) {
                texto.append(contato.toString()).append("\n");
            }
            texto.append("+-------------+%n");
            escritor.write(texto.toString());
            escritor.flush();
            escritor.close();

        }catch(IOException e){
            e.printStackTrace();
        }
        try{
            BufferedWriter escritor = new BufferedWriter(new FileWriter("contatosProfissional"));
            StringBuilder texto = new StringBuilder("CONTATOS -------------+\n");
            for (Contato contato: profissional) {
                texto.append(contato.toString()).append("\n");
            }
            texto.append("+-------------+%n");
            escritor.write(texto.toString());
            escritor.flush();
            escritor.close();

        }catch(IOException e){
            e.printStackTrace();
        }
    }

    public void salvaContatosBin(){
        FileOutputStream escritorArquivo = null;
        ObjectOutputStream escritorObj = null;
        try{
            escritorArquivo =new FileOutputStream("contatosFamilia");
            escritorObj = new ObjectOutputStream(escritorArquivo);
            for (Contato contato : familia)
                escritorObj.writeObject(contato);
        } catch (IOException e){
            System.out.println(e.getMessage());
        } finally {
            try{
                if(escritorArquivo != null)
                    escritorArquivo.close();
            }catch(Exception e){
                System.out.println(e.getMessage());
            }
        }

        escritorArquivo = null;
        escritorObj = null;
        try{
            escritorArquivo =new FileOutputStream("contatosAmigos");
            escritorObj = new ObjectOutputStream(escritorArquivo);
            for (Contato contato : amigos)
                escritorObj.writeObject(contato);
        } catch (IOException e){
            System.out.println(e.getMessage());
        } finally {
            try{
                if(escritorArquivo != null)
                    escritorArquivo.close();
            }catch(Exception e){
                System.out.println(e.getMessage());
            }
        }

        escritorArquivo = null;
        escritorObj = null;
        try{
            escritorArquivo =new FileOutputStream("contatosProfissional");
            escritorObj = new ObjectOutputStream(escritorArquivo);
            for (Contato contato : profissional)
                escritorObj.writeObject(contato);
        } catch (IOException e){
            System.out.println(e.getMessage());
        } finally {
            try{
                if(escritorArquivo != null)
                    escritorArquivo.close();
            }catch(Exception e){
                System.out.println(e.getMessage());
            }
        }
    }

    @Override
    public String toString() {
        return "GestaoContatos{" +
                "familia=" + familia +
                ", amigos=" + amigos +
                ", profissional=" + profissional +
                '}';
    }
}

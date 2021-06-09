package GUI;

import GUI.Imoveis.*;
import GUI.Pessoas.*;
import ManutencaoDados.*;
import Pessoas.Cliente;
import Pessoas.Funcionario;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MainMenu {
    private static JLabel label;
    private static JPanel panel;
    private static JButton btnCadastroCliente,btnCadastroFuncionario,btnCadastroCorretor,btnCadastroCasa,btnCadastroApartamento,btnCadastroTerreno;
    private static JButton btnListarClientes,btnListarClientesProprietarios,btnListarCasas, btnListarApartamentos,btnListarTerrenos,btnListarFuncionarios,btnListarCorretores;
    //Telas
    private static CadastroCliente tlCadastroCliente;
    private static CadastroFuncionario tlCadastroFuncionario;
    private static CadastroCorretor tlCadastroCorretor;
    private static CadastroCasa tlCadastroCasa;
    private static CadastroApartamento tlCadastroApartamento;
    private static ListarClientes tlListarClientes;
    private static ListarClientesProprietarios tlListarClientesProprietaros;
    private static ListarFuncionarios tlListarFuncionarios;
    private static ListarCorretores tlListarCorretores;
    //Dados
    private static DadosClientes clientes;
    private static DadosClientesProprietarios clientesProprietarios;
    private static DadosCorretores corretores;
    private static DadosFuncionarios funcionarios;
    private static DadosImoveis imoveis;
    private static DadosCasa casas;
    private static DadosApartamento apartamentos;
    private static DadosTerrenos terrenos;


    public MainMenu(){
        clientes = new DadosClientes();
        clientesProprietarios = new DadosClientesProprietarios();
        funcionarios = new DadosFuncionarios();
        corretores = new DadosCorretores();
        apartamentos = new DadosApartamento();
        casas = new DadosCasa();
        terrenos = new DadosTerrenos();

        int col1 = 10;
        int col2 = 310;
        int rowHeight = 70;

        JFrame frame = new JFrame();

        panel = new JPanel();


        frame.setSize(700,700);
        frame.add(panel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setTitle("ImobiJava");
        frame.setVisible(true);

        panel.setBorder(BorderFactory.createEmptyBorder(30,30,10,30));
        panel.setLayout(null);

        label = new JLabel("Cadastros");
        label.setBounds(10,0,290,60);
        panel.add(label);

        btnCadastroCliente = new JButton("Cadastrar Cliente");
        btnCadastroCliente.setBounds(col1,rowHeight,290,60);
        panel.add(btnCadastroCliente);
        btnCadastroCliente.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tlCadastroCliente = new CadastroCliente(clientes);
            }
        });

        btnCadastroFuncionario = new JButton("Cadastrar Funcionário");
        btnCadastroFuncionario.setBounds(col1,rowHeight*2,290,60);
        panel.add(btnCadastroFuncionario);
        btnCadastroFuncionario.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tlCadastroFuncionario = new CadastroFuncionario(funcionarios);
            }
        });

        btnCadastroCorretor = new JButton("Cadastrar Corretor");
        btnCadastroCorretor.setBounds(col1,rowHeight*3,290,60);
        panel.add(btnCadastroCorretor);
        btnCadastroCorretor.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tlCadastroCorretor = new CadastroCorretor(corretores);
            }
        });

        btnCadastroCasa = new JButton("Cadastrar Casa");
        btnCadastroCasa.setBounds(col2,rowHeight,290,60);
        btnCadastroCasa.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tlCadastroCasa = new CadastroCasa(casas);
            }
        });
        panel.add(btnCadastroCasa);

        btnCadastroApartamento = new JButton("Cadastrar Apartamento");
        btnCadastroApartamento.setBounds(col2,rowHeight*2,290,60);
        btnCadastroApartamento.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                CadastroApartamento novoCadastro = new CadastroApartamento(apartamentos);
            }
        });
        panel.add(btnCadastroApartamento);

        btnCadastroTerreno = new JButton("Cadastrar Terreno");
        btnCadastroTerreno.setBounds(col2,rowHeight*3,290,60);
        btnCadastroTerreno.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
//                tlCadastroTerreno = new CadastroTerreno(terrenos);
            }
        });
        panel.add(btnCadastroTerreno);


        //Listagens

        label = new JLabel("Listagens");
        label.setBounds(10,rowHeight*4,290,60);
        panel.add(label);

        btnListarClientes = new JButton("Listar Clientes");
        btnListarClientes.setBounds(col1,rowHeight*5,290,60);
        btnListarClientes.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tlListarClientes = new ListarClientes(clientes);
            }
        });
        panel.add(btnListarClientes);

        btnListarClientesProprietarios = new JButton("Listar Clientes Proprietarios");
        btnListarClientesProprietarios.setBounds(col1,rowHeight*6,290,60);
        btnListarClientesProprietarios.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tlListarClientesProprietaros = new ListarClientesProprietarios(clientesProprietarios);
            }
        });
        panel.add(btnListarClientesProprietarios);

        btnListarFuncionarios = new JButton("Listar Funcionarios");
        btnListarFuncionarios.setBounds(col1,rowHeight*7,290,60);
        btnListarFuncionarios.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tlListarFuncionarios = new ListarFuncionarios(funcionarios);
            }
        });
        panel.add(btnListarFuncionarios);

        btnListarCorretores = new JButton("Listar Corretores");
        btnListarCorretores.setBounds(col1,rowHeight*8,290,60);
        btnListarCorretores.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tlListarCorretores = new ListarCorretores(corretores);
            }
        });
        panel.add(btnListarCorretores);

        btnListarApartamentos = new JButton("Listar Apartamentos");
        btnListarApartamentos.setBounds(col2,rowHeight*5,290,60);
        btnListarApartamentos.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                 ListarApartamentos ltAps= new ListarApartamentos(apartamentos);
            }
        });
        panel.add(btnListarApartamentos);

        btnListarCasas = new JButton("Listar Casas");
        btnListarCasas.setBounds(col2,rowHeight*6,290,60);
        btnListarCasas.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ListarCasa ltCasa = new ListarCasa(casas);
            }
        });
        panel.add(btnListarCasas);

        btnListarTerrenos = new JButton("Listar Terrenos");
        btnListarTerrenos.setBounds(col2,rowHeight*7,290,60);
        btnListarTerrenos.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ListarTerreno ltTerr = new ListarTerreno(terrenos);
            }
        });
        panel.add(btnListarTerrenos);

    }

}

package GUI;

import GUI.Imoveis.CadastroApartamento;
import GUI.Imoveis.CadastroCasa;
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
//    private static DadosCasas casas;
//    private static DadosApartamentos apartamentos;
//    private static DadosTerrenos terrenos;


    public MainMenu(){
        clientes = new DadosClientes();
        clientesProprietarios = new DadosClientesProprietarios();
        funcionarios = new DadosFuncionarios();
        corretores = new DadosCorretores();


        JFrame frame = new JFrame();

        panel = new JPanel();


        frame.setSize(310,1000);
        frame.add(panel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setTitle("ImobiJava");
        frame.setVisible(true);

        panel.setBorder(BorderFactory.createEmptyBorder(30,30,10,30));
        panel.setLayout(null);

        label = new JLabel("Menu");
        label.setBounds(10,0,290,60);
        panel.add(label);

        btnCadastroCliente = new JButton("Cadastrar Cliente");
        btnCadastroCliente.setBounds(10,70,290,60);
        panel.add(btnCadastroCliente);
        btnCadastroCliente.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tlCadastroCliente = new CadastroCliente(clientes);
            }
        });

        btnCadastroFuncionario = new JButton("Cadastrar Funcionário");
        btnCadastroFuncionario.setBounds(10,140,290,60);
        panel.add(btnCadastroFuncionario);
        btnCadastroFuncionario.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tlCadastroFuncionario = new CadastroFuncionario(funcionarios);
            }
        });

        btnCadastroCorretor = new JButton("Cadastrar Corretor");
        btnCadastroCorretor.setBounds(10,210,290,60);
        panel.add(btnCadastroCorretor);
        btnCadastroCorretor.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tlCadastroCorretor = new CadastroCorretor(corretores);
            }
        });
        btnCadastroApartamento = new JButton("Cadastrar Apartamento");
        btnCadastroApartamento.setBounds(10,280,290,60);
        btnCadastroApartamento.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
//                tlCadastroCasa = new CadastroApartamento(apartamentos);
            }
        });
        panel.add(btnCadastroApartamento);


        btnCadastroCasa = new JButton("Cadastrar Casa");
        btnCadastroCasa.setBounds(10,350,290,60);
        btnCadastroCasa.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
//                tlCadastroCasa = new CadastroCasa(casas);
            }
        });
        panel.add(btnCadastroCasa);

        btnCadastroTerreno = new JButton("Cadastrar Terreno");
        btnCadastroTerreno.setBounds(10,420,290,60);
        btnCadastroTerreno.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
//                tlCadastroTerreno = new CadastroTerreno(terrenos);
            }
        });
        panel.add(btnCadastroTerreno);

        btnCadastroTerreno = new JButton("Cadastrar Terreno");
        btnCadastroTerreno.setBounds(10,420,290,60);
        btnCadastroTerreno.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
//                tlCadastroTerreno = new CadastroTerreno(terrenos);
            }
        });
        panel.add(btnCadastroTerreno);


        //Listagens

        btnListarClientes = new JButton("Listar Clientes");
        btnListarClientes.setBounds(10,490,290,60);
        btnListarClientes.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tlListarClientes = new ListarClientes(clientes);
            }
        });
        panel.add(btnListarClientes);

        btnListarClientesProprietarios = new JButton("Listar Clientes Proprietarios");
        btnListarClientesProprietarios.setBounds(10,560,290,60);
        btnListarClientesProprietarios.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tlListarClientesProprietaros = new ListarClientesProprietarios(clientesProprietarios);
            }
        });
        panel.add(btnListarClientesProprietarios);

        btnListarFuncionarios = new JButton("Listar Funcionarios");
        btnListarFuncionarios.setBounds(10,630,290,60);
        btnListarFuncionarios.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tlListarFuncionarios = new ListarFuncionarios(funcionarios);
            }
        });
        panel.add(btnListarFuncionarios);

        btnListarCorretores = new JButton("Listar Corretores");
        btnListarCorretores.setBounds(10,700,290,60);
        btnListarCorretores.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tlListarCorretores = new ListarCorretores(corretores);
            }
        });
        panel.add(btnListarCorretores);

    }

}

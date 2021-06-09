package GUI.Imoveis;

import Imoveis.Apartamento;
import ManutencaoDados.DadosClientes;
import ManutencaoDados.DadosImoveis;
import Pessoas.Cliente;
import Pessoas.ClienteProprietario;
import Pessoas.Endereco;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Date;
import java.util.Locale;

public class CadastroApartamento {
    private static JPanel panel;
    private static JTextField tfValor, tfValorImob, tfArea, tfRua, tfComplemento, tfCep, tfCidade, tfBairro, tfNro, tfDataC, tfValorCondominio;
    private static JTextField tfNumQuartos, tfNumSuites, tfNumSalaEstar, tfNumSalaJantar, tfNumVagasGaragem, tfNumArmEbutido, tfDescricao, tfAndar;
    private static JCheckBox disponivel, paraVenda, condominio, portaria24h;
    private static JButton btnSubmit;
    private static JLabel lValor, lValorImob, lArea, lRua, lComplemento,lCep,lCidade,lBairro,lNro, lDataC;
    private static JLabel lNumQuartos, lNumSuites, lNumSalaEstar, lNumSalaJantar, lNumVagasGaragem, lNumArmEbutido, lDescricao, lAndar, lValorCondominio;
    private static JComboBox cbStatus;

    public CadastroApartamento(DadosImoveis im){
        JFrame frame = new JFrame();
        panel = new JPanel();
        panel.setLayout(null);
        frame.setTitle("Cadastro Apartamento");
        frame.setSize(480,530);
        frame.add(panel);

        //Criando objetos text field
        lValor = new JLabel("Valor: ");
        lValor.setBounds(10,20,60,25);
        tfValor = new JTextField(20);
        tfValor.setBounds(90,20,120,25);
        panel.add(lValor);
        panel.add(tfValor);

        lArea = new JLabel("Area: ");
        lArea.setBounds(10,80,80,25);
        tfArea = new JTextField(20);
        tfArea.setBounds(150,80,100,25);
        panel.add(lArea);
        panel.add(tfArea);

        lValorImob = new JLabel("Valor Imobiliaria: ");
        lValorImob.setBounds(10,50,80,25);
        tfValorImob = new JTextField(20);
        tfValorImob.setBounds(150,50,200,25);
        panel.add(lValorImob);
        panel.add(tfValorImob);

        lDataC = new JLabel("Data de construção: ");
        lDataC.setBounds(10,50,80,25);
        tfDataC = new JTextField(20);
        tfDataC.setBounds(150,50,200,25);
        panel.add(lDataC);
        panel.add(tfDataC);

        // Endereço
        lCidade = new JLabel("Cidade: ");
        lCidade.setBounds(10,200,80,25);
        tfCidade = new JTextField(20);
        tfCidade.setBounds(150,200,200,25);
        panel.add(lCidade);
        panel.add(tfCidade);

        lBairro = new JLabel("Bairro: ");
        lBairro.setBounds(10,230,80,25);
        tfBairro = new JTextField(20);
        tfBairro.setBounds(150,230,200,25);
        panel.add(lBairro);
        panel.add(tfBairro);

        lRua = new JLabel("Rua: ");
        lRua.setBounds(10,260,80,25);
        tfRua = new JTextField(20);
        tfRua.setBounds(150,260,200,25);
        panel.add(lRua);
        panel.add(tfRua);

        lNro = new JLabel("Número: ");
        lNro.setBounds(10,290,80,25);
        tfNro = new JTextField(20);
        tfNro.setBounds(150,290,50,25);
        panel.add(lNro);
        panel.add(tfNro);

        lCep = new JLabel("CEP: ");
        lCep.setBounds(10,320,150,25);
        tfCep = new JTextField(20);
        tfCep.setBounds(150,320,50,25);
        panel.add(lCep);
        panel.add(tfCep);

        lComplemento = new JLabel("Complemento: ");
        lComplemento.setBounds(10,350,150,25);
        tfComplemento = new JTextField(20);
        tfComplemento.setBounds(150,350,150,25);
        panel.add(lComplemento);
        panel.add(tfComplemento);

        lNumQuartos = new JLabel("Num. Quartos: ");
        lNumQuartos.setBounds(10,20,80,25);
        tfNumQuartos = new JTextField(20);
        tfNumQuartos.setBounds(100,20,100,25);
        panel.add(lNumQuartos);
        panel.add(tfNumQuartos);

        lNumSuites = new JLabel("Num. Suites: ");
        lNumSuites.setBounds(210,20,40,25);
        tfNumSuites = new JTextField(20);
        tfNumSuites.setBounds(300,20,100,25);
        panel.add(lNumSuites);
        panel.add(tfNumSuites);

        lNumSalaEstar = new JLabel("Num. Sala Estar: ");
        lNumSalaEstar.setBounds(10,20,80,25);
        tfNumSalaEstar = new JTextField(20);
        tfNumSalaEstar.setBounds(100,20,100,25);
        panel.add(lNumSalaEstar);
        panel.add(tfNumSalaEstar);

        lNumSalaJantar = new JLabel("Num. Sala Jantar: ");
        lNumSalaJantar.setBounds(210,20,40,25);
        tfNumSalaJantar = new JTextField(20);
        tfNumSalaJantar.setBounds(300,20,100,25);
        panel.add(lNumSalaJantar);
        panel.add(tfNumSalaJantar);

        lNumVagasGaragem = new JLabel("Num. Vagas Garagem: ");
        lNumVagasGaragem.setBounds(10,20,100,25);
        tfNumVagasGaragem = new JTextField(20);
        tfNumVagasGaragem.setBounds(100,20,100,25);
        panel.add(lNumVagasGaragem);
        panel.add(tfNumVagasGaragem);

        lNumArmEbutido = new JLabel("Num. Armarios Embutidos: ");
        lNumArmEbutido.setBounds(230,20,100,25);
        tfNumArmEbutido = new JTextField(20);
        tfNumArmEbutido.setBounds(320,20,100,25);
        panel.add(lNumArmEbutido);
        panel.add(tfNumArmEbutido);

        lDescricao = new JLabel("Descrição: ");
        lDescricao.setBounds(10,20,100,25);
        tfDescricao = new JTextField(20);
        tfDescricao.setBounds(100,20,100,25);
        panel.add(lDescricao);
        panel.add(tfDescricao);

        lAndar = new JLabel("Andar: ");
        lAndar.setBounds(230,20,60,25);
        tfAndar = new JTextField(20);
        tfAndar.setBounds(320,20,40,25);
        panel.add(lAndar);
        panel.add(tfAndar);

        String[] status = {"Ativo", "Inativo", "Em uso"};
        cbStatus = new JComboBox(status);
        cbStatus.setBounds(10,420,150,25);
        panel.add(cbStatus);

        disponivel = new JCheckBox("Disponível");
        disponivel.setBounds(10,500,80,25);
        panel.add(disponivel);

        paraVenda = new JCheckBox("Para Venda");
        paraVenda.setBounds(10,500,80,25);
        panel.add(paraVenda);

        condominio = new JCheckBox("Condominio");
        condominio.setBounds(10,500,80,25);
        panel.add(condominio);

        portaria24h = new JCheckBox("Portaria 24h");
        portaria24h.setBounds(10,500,80,25);
        panel.add(portaria24h);

        btnSubmit = new JButton("Cadastrar");
        btnSubmit.setBounds(180,460,150,30);
        panel.add(btnSubmit);


        btnSubmit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                DateFormat df = new SimpleDateFormat("MM/dd/yyyy");
                Date DataC = new Date();
                try {
                    DataC = df.parse(tfDataC.getText());
                } catch (ParseException ex) {
                    ex.printStackTrace();
                }
                Endereco end = new Endereco(tfRua.getText(),tfComplemento.getText(),tfCep.getText(),tfCidade.getText(),tfBairro.getText(),Integer.parseInt(tfNro.getText()));
                Apartamento c = new Apartamento(disponivel.isSelected(), paraVenda.isSelected(), (byte)cbStatus.getSelectedIndex(), DataC, new Date(), Float.parseFloat(tfValor.getText()),
                        Float.parseFloat(tfValorImob.getText()), end, Integer.parseInt(tfArea.getText()), new ArrayList<ClienteProprietario>(), Integer.parseInt(tfNumQuartos.getText()),
                        Integer.parseInt(tfNumSuites.getText()), Integer.parseInt(tfNumSalaEstar.getText()), Integer.parseInt(tfNumSalaJantar.getText()), Integer.parseInt(tfNumVagasGaragem.getText()),
                        Integer.parseInt(tfNumArmEbutido.getText()), tfDescricao.getText(), condominio.isSelected(), Integer.parseInt(tfAndar.getText()), Float.parseFloat(tfValorCondominio.getText()),
                        portaria24h.isSelected());
            }
        });

        panel.setBorder(BorderFactory.createEmptyBorder(30,30,30,30));

        frame.setVisible(true);
    }
}

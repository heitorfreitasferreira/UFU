package GUI.Imoveis;

import Imoveis.Casa;
import Imoveis.Terreno;
import ManutencaoDados.DadosTerrenos;
import Pessoas.ClienteProprietario;
import Pessoas.Endereco;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;

public class CadastroTerreno {
    private static JPanel panel;
    private static JTextField tfValor, tfValorImob, tfArea, tfRua, tfComplemento, tfCep, tfCidade, tfBairro, tfNro, tfDataC;
    private static JCheckBox disponivel, paraVenda, condominio, possuiAclive;
    private static JButton btnSubmit;
    private static JLabel lValor, lValorImob, lArea, lRua, lComplemento, lCep, lCidade, lBairro, lNro, lDataC;
    private static JComboBox cbStatus;

    public CadastroTerreno(DadosTerrenos terrenos) {
        JFrame frame = new JFrame();
        panel = new JPanel();
        panel.setLayout(null);
        frame.setTitle("Cadastro Terreno");
        frame.setSize(600, 500);
        frame.add(panel);

        //Criando objetos text field
        lValor = new JLabel("Valor: ");
        lValor.setBounds(10, 20, 40, 25);
        tfValor = new JTextField(20);
        tfValor.setBounds(60, 20, 120, 25);
        panel.add(lValor);
        panel.add(tfValor);

        lValorImob = new JLabel("Valor Imobiliaria: ");
        lValorImob.setBounds(220, 20, 100, 25);
        tfValorImob = new JTextField(20);
        tfValorImob.setBounds(330, 20, 100, 25);
        panel.add(lValorImob);
        panel.add(tfValorImob);

        lDataC = new JLabel("Data de construção: ");
        lDataC.setBounds(10, 50, 120, 25);
        tfDataC = new JTextField(20);
        tfDataC.setBounds(140, 50, 100, 25);
        panel.add(lDataC);
        panel.add(tfDataC);

        // Endereço
        lCidade = new JLabel("Cidade: ");
        lCidade.setBounds(270, 50, 50, 25);
        tfCidade = new JTextField(20);
        tfCidade.setBounds(330, 50, 100, 25);
        panel.add(lCidade);
        panel.add(tfCidade);

        lRua = new JLabel("Rua: ");
        lRua.setBounds(10, 80, 30, 25);
        tfRua = new JTextField(20);
        tfRua.setBounds(50, 80, 140, 25);
        panel.add(lRua);
        panel.add(tfRua);

        lNro = new JLabel("Número:");
        lNro.setBounds(220, 80, 60, 25);
        tfNro = new JTextField(20);
        tfNro.setBounds(290, 80, 60, 25);
        panel.add(lNro);
        panel.add(tfNro);

        lBairro = new JLabel("Bairro: ");
        lBairro.setBounds(370, 80, 60, 25);
        tfBairro = new JTextField(20);
        tfBairro.setBounds(440, 80, 100, 25);
        panel.add(lBairro);
        panel.add(tfBairro);

        lCep = new JLabel("CEP: ");
        lCep.setBounds(10, 110, 30, 25);
        tfCep = new JTextField(20);
        tfCep.setBounds(50, 110, 80, 25);
        panel.add(lCep);
        panel.add(tfCep);

        lComplemento = new JLabel("Complemento: ");
        lComplemento.setBounds(170, 110, 90, 25);
        tfComplemento = new JTextField(20);
        tfComplemento.setBounds(260, 110, 80, 25);
        panel.add(lComplemento);
        panel.add(tfComplemento);

        lArea = new JLabel("Area: ");
        lArea.setBounds(380, 110, 50, 25);
        tfArea = new JTextField(20);
        tfArea.setBounds(440, 110, 100, 25);
        panel.add(lArea);
        panel.add(tfArea);

        String[] status = {"Ativo", "Inativo", "Em uso"};
        cbStatus = new JComboBox(status);
        cbStatus.setBounds(10, 280, 150, 25);
        panel.add(cbStatus);

        disponivel = new JCheckBox("Disponível");
        disponivel.setBounds(10, 310, 100, 25);
        panel.add(disponivel);

        paraVenda = new JCheckBox("Para Venda");
        paraVenda.setBounds(110, 310, 100, 25);
        panel.add(paraVenda);

        condominio = new JCheckBox("Condominio");
        condominio.setBounds(210, 310, 100, 25);
        panel.add(condominio);

        possuiAclive = new JCheckBox("Portaria 24h");
        possuiAclive.setBounds(330, 310, 120, 25);
        panel.add(possuiAclive);

        btnSubmit = new JButton("Cadastrar");
        btnSubmit.setBounds(180, 400, 150, 30);
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
                Endereco end = new Endereco(tfRua.getText(), tfComplemento.getText(), tfCep.getText(), tfCidade.getText(), tfBairro.getText(), Integer.parseInt(tfNro.getText()));
                Terreno te = new Terreno(disponivel.isSelected(), paraVenda.isSelected(), (byte) cbStatus.getSelectedIndex(), DataC, new Date(), Float.parseFloat(tfValor.getText()),
                        Float.parseFloat(tfValorImob.getText()), end, Integer.parseInt(tfArea.getText()), new ArrayList<ClienteProprietario>(), possuiAclive.isSelected());
                terrenos.adicionar(te);
            }
        });

        panel.setBorder(BorderFactory.createEmptyBorder(30, 30, 30, 30));

        frame.setVisible(true);
    }
}

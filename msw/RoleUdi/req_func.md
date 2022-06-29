# Funcionais

ID_Req |Requisito | Descrição
-|-|-
RF01 | Cadastrar | Usuário não logado cria uma conta no banco de dados da aplicação, podendo ser criação de conta com email, conta Google ou conta Meta
RF02 | Logar | Usuário não logado e com conta cadastrada no banco de dados da aplicação fornece os dados
RF03 | Marcar presença em evento | Dentro da página de um evento que já tenha data confirmada, usuário pode marcar que irá, não irá com certeza ou que está com vontade de ir no evento
RF04 | Adicionar amizade | Usuário vê as pessoas da sua lista de contatos do celular, e caso não tenha ela conectada como amiga pode enviar uma solicitação
RF05 | Aceitar convite amizade | Usuário que recebeu um convite em sua caixa de notificações pode aceitar, ignorar ou bloquear a solicitação, em caso de bloqueio os futuros convites de amizade não serão notificados ao usuário que os receberia
RF06 | Avaliar evento | Dentro da página de um evento que já tenha sido concluído, o usuário pode dar a nota de 1 a 5, com justficativa ou não da nota, em um modelo semelhantes à avaliação de aplicativos em lojas
RF07 | Filtrar por data | Na página inicial da aplicação o usuário pode selecionar o modo de visualização por data, abrindo uma janela dividida em colunas (dias) e que nas colunas, os eventos com maior coeficiente de desejo do público estarão no topo da coluna
RF08 | Filtrar por localização | Na página inicial da aplicação o usuário pode selecionar o modo de visualização por localização, abrindo uma janela com um mapa da área que o usuário se encontra, e com "pins" nos locais onde haverão eventos, similar à visualização de pontos comerciais do Google Maps
RF09 | Trocar data analisada | Em qualquer uma das visualizações, o usuário pode selecionar qual período ele quer analisar, no caso da visualização por data é possível ver as diferentes semanas, e na por localização é possível selecionar o dia em que será visto o mapa
RF10 | Escolher nicho evento | No momento de criação da conta, o usuário deverá selecionar 1 ou mais nichos de eventos que ele tem interesse, o mesmo menu pode ser acessado novamente nas configurações da aplicação, onde poderão ser trocados os nichos de interesse, desde que tenha pelo menos um nicho selecionado
RF11 | Calcular coeficiente de desejo do público ao evento | Análise do fluxo de entradas de dados dos usuários (presença ou não em eventos e notas em eventos dos organizadores passados) para ranquear os eventos que estão em alta e que serão priorizados nas vizualizações
RF12 | Cadastro cartão de crédito/débito | Usuário insere informações de cartão, sistema faz uma compra e estorno de um valor infimo para verificação da conta bancária

---

# Não funcionais

ID_Req |Requisito | Descrição
-|-|-
RNF01 | Plataformas |Sistema pode ser usado tanto via interface web responsiva, ou aplicação nativa Android
RNF02 | Banco de dados | Banco de dados de Grafo para guardar as conexões entre usuários, banco de dados não-relacional para os outros tipos de informações
RNF03 | Design interface | Uso das guidelines da Material U da Google para montar as telas
RNF04 | Tempo resposta cartão | O tempo de resposta de qualquer transação monetária dentro da aplicação não deve passar de 10 segundos (similar ao pix)
RNF05 | Tempo de confirmação de compra | Usuário tem até 5 minutos para encerrar a compra desde seu início
RNF06 | API | API aberta para busca de informações de eventos do sistema
RNF07 | Linguagens  | Para implementação do sistema será utilizada a stack **"MERN"**,  ***M***ongoDB/***E***xpress/***R***eact/***N***odeJS, 
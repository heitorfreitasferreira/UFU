# 1. Arquitetura TCP/IP

## 1.1. Apresentação da matéria 31/07/2023

### 1.1.1. Motivação

- No mundo há uma revoluçãoem informação e tecnologias de comunicação:
    - O uso cada vez maior de sistemas distribuídos;
    - A diversidade de opções de redes de comunicação;
    - Exemplos: PAN, LAN e WAN.
- Crescimento da World Wide Web e tecnologias para dispositivos móveis.

### 1.1.2. Apresentação

- A comunicação de informações e redes de computadores tornam-se indispensáveis;
- Então há necessidade de compreender:
  - Tecnologia: tecnologia subjacente às facilidades de comunicação da informação;
  - Arquitetura: modo como hardware e software podem ser organizados;
  - Aplicações: comunicações e as redes podem atender a requisitos de empresas.

- Compreender os conceitos de redes de comunicação de computadores para a arquitetura TCP/IP (hardware e software)

- O modelo de referência OSI (Open System Interconnection);
- Um padrão para protocolos de comunicação
- Como as camadas são organizadas
  - Apliação
  - Apresentação
  - Sessão
  - Transporte
  - Rede
  - Enlace
  - Físico
- O modelo TCP/IP modifica as camadas, removendo algumas, e unificando outras
  - Aplicação
  - Transport
  - Internet 
  - Host-to-network

Arquitetura TCP/IP: protocolos presentes nessas camadas

- Application
  - TODO
- Transport
- Network
- Physical
  - FIbra
  - 802.11
  - Ethernet

### 1.1.3. Objetivo

- Capacitar o estudante a compreender os aspectos de projeto em camadas, os princípios do projeto de protocolos (serviços, camadas, entidades) 

### 1.1.4. Programa

- Introdução à arquitetura
  - O que é a internet
  - O que é um protocolo
  - Borda da rede: hospodeiros, rede de acesso, meio físico
  - Núcleo da rede: pacote/comutação de circuitos, estrutura da Internet
  - Desempenho: perda, atraso e vazão
  - Segurança
  - Camadas de protocolo e modelos de serviço
  - História
- Organização em camadas
  - sub-rede
  - rede
  - transporte
  - aplicação
- Acesso a sub-rede
- Protocolo IP
- Roteamento IP
- Protocolo UDP
- TODO


- Enlace em meio guiado
  - Serviços
  - Detecção e correção de erros
  - Protocolos de acesso múltiplo
  - Endereçamento na camada de enlace
  - Ethernet
  - Comutadores de camada de enlace
  - Virtualização de enlace MPLS
    - Passa a ter um comutador que rotula as informações para diminuir tempo de resposta
- Enlace em meio não guiado (WI-FI)
  - Introdução à rede sem fio
  - Características de enlaces e redes sem fio
  - LANs sem fio 802.11 ("wi-fi")
  - Mobilidade
    - Gerenciamento da mobilidade: princípios
    - IP móvel

Internet (rede)
- Introdução
- Redes de circuitos virtuais e de datagramas
- O que há dentro de um roteador
- IP: Internet Protocol
  - Formato do datagrama
  - Endereçamento IPv4
  - ICMP
  - IPv6
- Algoritmos de roteamento
  - Estado de enlace
  - Vetor de distãncias
  - Roteamento hierárquico

Transporte

- Serviços da camada de transporte
- Multiplexação e demultiplexação
- Transporte não orientado para conexão: UDP
- Princípios da transferẽncia confiável de dados
- Transporte orientado para conexão: TCP

Aplicação

- Princípios de aplicações de rede
- HTTP
- FTP
- DNS
- Programação de sockets com UDP
- Programação de sockets com TCP

### 1.1.5. Critérios de avaliação

### 1.1.6. Ferramenta

[GNS3](https://www.gns3.com/) - Trabalhar com topologia e fazer experimentos em tempo real

# 2. Revisão redes


def gerar_arquivo(tamanho_bytes, nome_arquivo):
    conteudo = "seguranca-heitor"
    tamanho_string = len(conteudo)
    repeticoes = tamanho_bytes // tamanho_string
    restante = tamanho_bytes % tamanho_string

    with open(nome_arquivo, 'w') as f:
        f.write(conteudo * repeticoes)
        if restante > 0:
            f.write(conteudo[:restante])


gerar_arquivo(1 * 1024 * 1024, 'arquivo_1MB.txt')

gerar_arquivo(100 * 1024 * 1024, 'arquivo_100MB.txt')

gerar_arquivo(1 * 1024 * 1024 * 1024, 'arquivo_1GB.txt')

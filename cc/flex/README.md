# Trabalho uso ferramenta de tokenização (Flex)

## Compilação

Compilar para produção
```make build```

Compilar para debug (necessário o compilador flex)
```make build-dev```

## Execução

Executar o programa
```make run```
```make```
```./lexer```

Para escolher o arquivo que o lexer irá analisar, basta passar o caminho do arquivo como argumento
```./lexer <caminho_do_arquivo>```

Caso não seja passado nenhum argumento, o lexer irá perguntar no stdin qual o arquivo que deseja analisar.

## Exemplo de uso

```shell
$ make build
$ ./lexer input.txt >> output.txt
```

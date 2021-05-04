  #include <stdio.h>
  #include "hash.h"
  /*
    Integrantes:
      Heitor Freitas Ferreira - 11921BCC026
      Luis Gustavo Seiji Tateish - 11921BCC___
      Terceiro otário - _____BCC___
  */
  // Quantidade de alunos a serem lidos: 2287
  // Método de leitura dos dados: arquivo txt
  // Cada linha é do modelo [matricula nome n1 n2 n3] com espaço separando cada linha
  int main(int argc, char const *argv[])
  {
    Aluno al1, al2;
    Hash *hash = criaHash(SIZE,sizeof(Aluno));
    FILE *p;
    char arq[100];
    int loop = 1;
    if (!(p = fopen("alunos.txt", "r+")))
    {
      printf("Erro! Impossivel abrir o arquivo!\n");
      return 0;
    }
    while (fscanf(p, "%d %s %d %d %d", &al1.matricula,al1.nome,&al1.n1,&al1.n2,&al1.n3) != EOF){
      insereHash(hash, al1.matricula, &al1);
    }
    while (loop)
    {
    	int escolha;
      	printf("1-Inserir novo aluno\n2-Buscar aluno\n3-Sair");
      	scanf("%c", &escolha);
      	switch (escolha){
      	case 1:
			printf("Digite a matricula do aluno novo :");
			scanf("%d",&al1.matricula);
			printf("Digite o nome do aluno novo :");
			gets(al1.nome);
			printf("Digite a nota da nota da primeira prova :");
			scanf("%d",&al1.n1);
			printf("Digite a nota da nota da segunda prova :");
			scanf("%d",&al1.n2);
			printf("Digite a nota da nota da terceira prova :");
			scanf("%d",&al1.n3);
        	insereHash(hash, al1.matricula, &al1);
        	break;
      	case 2:
      		printf("\nInsira o numero de matricula: ");
      		int matricula;
    		scanf("%d", &matricula);
            if(buscaHash(hash, matricula, &al1)){
            printf("Nome: %s\n", al1.nome);
            printf("Numero de matricula: %d\n", al1.matricula);
	        printf("Nota da prova 1: %d\n", al1.n1);
			printf("Nota da prova 2: %d\n", al1.n2);
			printf("Nota da prova 3: %d\n", al1.n3);
            }else{
            printf("Aluno não encontrado\n");
            }
      	case 3:
        	break;
      default:
        printf("Digite apenas 1,2 ou 3");
        break;
      }
    }
    liberaHash(hash);
    fclose(p);
    return 0;
  }
/*
  int ota()
  {
    Hash *tabela_hash = criaHash(SIZE, sizeof(Aluno));
    printf("Criou o bagulho\n");

    Aluno al1, al2;
    al1.matricula = 12;
    al1.n1 = 10;
    al1.n2 = 10;
    al1.n3 = 10;
    strcpy(al1.nome, "Heitor Freitas");
    insereHash(tabela_hash, al1.matricula, &al1);
    buscaHash(tabela_hash, al1.matricula, &al2);

    printf("Nome: %s\n", al2.nome);
    printf("Matricula: %d\n", al2.matricula);
    printf("Nota 1: %d\n", al2.n1);
    printf("Nota 2: %d\n", al2.n2);
    printf("Nota 3: %d\n", al2.n3);
    liberaHash(tabela_hash);
    return 0;
  }
*/
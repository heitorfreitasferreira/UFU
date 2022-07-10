# Bonus prova 1

> Alunos

| Aluno                       | Matricula   |
| --------------------------- | ----------- |
| Luis Gustavo Seiji Tateishi | 11921BCC034 |
| Heitor Freitas Ferreira     | 11921BCC026 |


# Implementação em Java

> SSCML

```java
import java.util.ArrayList;
import java.util.List;

class Main
{
	public static int[] SSCML(int[] arr)
	{
    // Dividir o problema em duas partes
    // 1. Gerar um array com todas as subsequencias crescentes
    // 2. Encontrar dentre todas as subsequencias a com o maior tamanho
		if (arr == null || arr.length == 0) {
			return;
		}
		List<List<Integer>> sub_sequencias = new ArrayList<>();
		int j = 0;

    // Lista com as subsequências que resolvem o problema até ali {SubSequenciaCrescente}
		for (int i = 0; i < arr.length; i++) {
			sub_sequencias.add(new ArrayList<>());
		}

    // "Caso base"
		LIS.get(0).add(arr[0]);
    // Loop com o resto do array
		for (int i = 1; i < arr.length; i++)
		{
      // Loop do início do array original até o ponto I que está sendo analizado
			for (int j = 0; j < i; j++)
			{
        /*
          Encontra a maior subsequência que termina em arr[j] onde arr[j] < arr[i]
        */
				if (arr[j] < arr[i] && sub_sequencias.get(j).size() > sub_sequencias.get(i).size()) {
          // Altera a solução[i] para ser a solução[j]
					sub_sequencias.set(i, new ArrayList<>(sub_sequencias.get(j)));
				}
			}
      // Guarda a solução do problema do array [0:i]
			sub_sequencias.get(i).add(arr[i]);
		}

    // Laço procurando dentre as soluções com todas as subsequencia crescentes a que tem o maior tamanho
		for (int i = 0; i < arr.length; i++)
		{
			if (sub_sequencias.get(j).size() < sub_sequencias.get(i).size()) {
				j = i;
			}
		}

		// SubSequenciaCrescente com o maior tamanho
		return(sub_sequencias.get(j))
	}

	public static void main(String[] args)
	{
		int[] arr = { 12, 11, 5, 8, 4, 6, 17, 9, 23, 25, 18, 19, 1, 20, 21, 22, 13, 3, 14, 7, 2, 24, 16, 15, 10 };
    System.out.println(SSCML(arr));
		int[] arr = { 14, 15, 22, 10, 6, 9, 13, 2, 20, 7, 12, 3, 23, 19, 11, 1, 18, 16, 5, 8, 24, 4, 21, 17, 25 };
    System.out.println(SSCML(arr));
		int[] arr = { 20, 25, 14, 3, 11, 16, 5, 23, 17, 2, 6, 1, 9, 7, 4, 19, 12, 22, 8, 10, 15, 21, 13, 18, 24 };
    System.out.println(SSCML(arr));
	}
}
```
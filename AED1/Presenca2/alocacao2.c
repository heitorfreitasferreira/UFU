#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
  int count;
  char *str, *aux;
  scanf("%d", &count);
  setbuf(stdin, NULL);
  count++;
  // setbuf(stdin, NULL);
  str = (char *)malloc(count * sizeof(char));
  aux = (char *)malloc(count * sizeof(char));
  int j = 0;
  scanf("%[^\n]s", str);
  for (size_t i = 0; i < count; i++)
  {
    if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u')
    {
      aux[j] = str[i];
      j++;
    }
  }
  // aux[j] = '\0';
  printf("Original: %s\nSem vogais: %s\n", str, aux);

  free(str);
  free(aux);
  return 0;
}

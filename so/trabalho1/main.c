#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//DIR
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
//FIMDIR
//TIME
#include <time.h>
//FIMTIME

int mapMeses(char *mes)
{
  if (strcmp(mes, "Jan") == 0)
    return 1;
  if (strcmp(mes, "Feb") == 0)
    return 2;
  if (strcmp(mes, "Mar") == 0)
    return 3;
  if (strcmp(mes, "Apr") == 0)
    return 4;
  if (strcmp(mes, "May") == 0)
    return 5;
  if (strcmp(mes, "Jun") == 0)
    return 6;
  if (strcmp(mes, "Jul") == 0)
    return 7;
  if (strcmp(mes, "Aug") == 0)
    return 8;
  if (strcmp(mes, "Sep") == 0)
    return 9;
  if (strcmp(mes, "Out") == 0)
    return 10;
  if (strcmp(mes, "Nov") == 0)
    return 11;
  if (strcmp(mes, "Dec") == 0)
    return 12;
  return -1;
}

int main()
{
  char input[30] = "continua", name[50];
  while (strcmp(input, "exit") != 0 && strcmp(input, "EXIT") != 0)
  {
    printf("Input: ");
    setbuf(stdin, NULL);
    scanf("%s", input);
    setbuf(stdin, NULL);

    if (strcmp(input, "CLS") == 0 || strcmp(input, "cls") == 0)
      printf("\e[1;1H\e[2J");
    else if (strcmp(input, "dir") == 0 || strcmp(input, "DIR") == 0)
    {
      printf("User name: ");
      scanf("%s", name);
      char path[50] = "/home/";
      strcat(path, name);

      struct dirent *dir;

      DIR *d;
      d = opendir(path);
      char full_path[1000];
      if (d)
      {
        while ((dir = readdir(d)) != NULL)
        {
          //Condition to check regular file.
          if (dir->d_type == DT_REG)
          {
            full_path[0] = '\0';
            strcat(full_path, path);
            strcat(full_path, "/");
            strcat(full_path, dir->d_name);
            printf("%s\n", full_path);
          }
        }
        closedir(d);
      }
    }
    else if (strcmp(input, "DATE") == 0 || strcmp(input, "date") == 0)
    {
      time_t t;
      time(&t);
      char c_time[30], mes_char[3];
      int mes_num;
      strcpy(c_time, ctime(&t));
      setbuf(stdin, NULL);
      mes_char[0] = c_time[4];
      mes_char[1] = c_time[5];
      mes_char[2] = c_time[6];
      setbuf(stdin, NULL);
      mes_num = mapMeses(mes_char);

      setbuf(stdin, NULL);

      printf("%c%c/%d/%c%c%c%c\n", c_time[8], c_time[9], mes_num, c_time[20], c_time[21], c_time[22], c_time[23]);
    }
    else if (strcmp(input, "TIME") == 0 || strcmp(input, "time") == 0)
    {
      time_t t;
      time(&t);
      char c_time[30], mes_char[3];
      int mes_num;
      strcpy(c_time, ctime(&t));
      setbuf(stdin, NULL);

      printf("%c%c:%c%c:%c%c\n", c_time[11], c_time[12], c_time[14], c_time[15], c_time[17], c_time[18]);
    }
  }

  return 0;
}
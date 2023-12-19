#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacoes.h"
#include <time.h>

void read_name(char *name)
{
  int x;
  do
  {
    printf("Nome do filme: ");
    fgets(name, sizeof(name), stdin);
    x = name_validation(name);
    if (x == 0)
    {
      printf("Digite corretamente.\n");
    }
  } while (x != 1);
}

void read_duration(char *duration)
{
  int x;
  do
  {
    printf("Duração do filme (ex: 02:15): ");
    clear_buffer();
    scanf("%s", duration);
    x = validate_duraion(duration);
    if (x == 0)
    {
      printf("Digite corretamente a hora.\n");
    }
  } while (x != 1);
}

void read_year(char *year)
{
  int x;
  do
  {
    printf("Digite o ano de lançamento do filme: ");
    clear_buffer();
    fgets(year, 5, stdin);
    x = year_validation(year);
    if (x == 0)
    {
      printf("Digite o ano corretamente.\n");
    }
  } while (x != 1);
}

void read_synopsis(char *synopsis)
{
  int x;
  do
  {
    printf("Escreva a sinópse do filme: ");
    clear_buffer();
    fgets(synopsis, sizeof(synopsis), stdin);
    x = name_validation(synopsis);
    if (x == 0)
    {
      printf("Digite corretamente.\n");
    }
  } while (x != 1);
}

void read_gender(char *gender)
{
  int x;
  do
  {
    printf("Digite o(s) gênero(s) do filme: ");
    clear_buffer();
    fgets(gender, sizeof(gender), stdin);
    x = gender_validation(gender);
    if (x == 0)
    {
      printf("Digite corretamente.\n");
    }
  } while (x != 1);
}

int year_validation(char *year)
{
  time_t t;
  time(&t);
  struct tm *data = localtime(&t);
  int anoAtual = data->tm_year + 1900;

  int ano = atoi(year);

  for (int i = 0; year[i] != '\0'; i++)
  {
    if (!isdigit(year[i]))
    {
      printf("pica\n");
      return 0;
    }
  }

  if (ano < 1895 || ano > anoAtual)
  {
    printf("%d", ano);
    printf("pica2\n");
    return 0;
  }

  return 1;
}

int name_validation(char *name)
{
  int x = 0;
  if (strlen(name) < 3)
  {
    return 0;
  }
  return 1;
}

int gender_validation(char *gender)
{
  int x = 0;
  if (strlen(gender) < 3)
  {
    return 0;
  }

  while (x < sizeof(gender))
  {
    if (isdigit(gender[x]) || ispunct(gender[x]))
    {
      return 0;
    }
    x++;
  }
  return 1;
}

int validate_duraion(char *duration)
{
  int tamanho = strlen(duration);

  // Verificar o tamanho da string
  if (tamanho != 5)
  {
    return 0;
  }

  // Verificar cada caractere da string
  for (int i = 0; i < tamanho; i++)
  {
    // Verificar se é um dígito
    if (!isdigit(duration[i]))
    {
      // Se não for um dígito, verificar se está na posição correta
      if ((i == 2 && duration[i] == ':'))
      {
        continue; // Pular o caractere ':' na posição correta
      }
      else
      {
        // Se não for um dígito ou ':' na posição correta, a string contém caracteres inválidos
        return 0;
      }
    }
  }

  // Verificar valores válidos para horas, minutos e segundos
  int horas = atoi(duration);
  int minutos = atoi(duration + 3);
  int segundos = atoi(duration + 6);

  if (horas < 0 || horas > 23 || minutos < 0 || minutos > 59 || segundos < 0 || segundos > 59)
  {
    return 0; // Valores fora do intervalo válido
  }

  return 1; // String de hora válida
}

void clear_buffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
  {
    // Lê e descarta cada caractere até encontrar uma nova linha ('\n') ou o fim do arquivo (EOF)
  }
}
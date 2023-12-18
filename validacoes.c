#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validacoes.h"

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
      printf("Digite corretamente");
    }
  } while (x != 1);
}

int name_validation(char *name)
{
  int x = 0;
  if (strlen(name) < 3)
  {
    return 0;
  }
  while (x < sizeof(name))
  {
    if (isdigit(name[x]) || ispunct(name[x]))
    {
      printf("é digito ou simbolo");
      return 0;
    }
    x++;
  }
  return 1;
}
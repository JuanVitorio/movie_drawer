#include <stdio.h>
#include <stdlib.h>
#include "filmes.h"
#include "index.h"

int main(void)
{
  main_menu();
  return 0;
}

void main_menu(void)
{
  int op = 0;
  printf("- Movie Drawer - \n");
  printf("Bem Vindo!\n\n");
  printf("1. Adicionar Filme\n");
  printf("2. Remover Filme\n");
  printf("3. Editar Filme\n");
  printf("4. Listar Filmes\n");
  printf("5. Buscar Filme\n");
  printf("Desejo: ");
  scanf("%d", &op);

  switch (op)
  {
  case 1:
    add_filme();
    break;
  case 2:

    break;
  default:
    break;
  }
}

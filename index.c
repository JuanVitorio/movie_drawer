#include <stdio.h>
#include <stdlib.h>
#include "filmes.h"
#include "index.h"
#include "validacoes.h"
#include "bd_utils.h"

int main(void)
{
  main_menu();
  return 0;
}

void main_menu(void)
{
  int op;
  do
  {
    system("cls||clear");
    printf("- Movie Drawer - \n");
    printf("Bem Vindo!\n\n");
    printf("1. Adicionar Filme\n");
    printf("2. Remover Filme\n");
    printf("3. Editar Filme\n");
    printf("4. Listar Filmes\n");
    printf("5. Buscar Filme\n");
    printf("0. Cancelar\n");
    printf("Desejo: ");
    scanf("%d", &op);
    clear_buffer();
    switch (op)
    {
    case 1:
      add_movie();
      break;
    case 2:
      break;
    case 4:
      list_movies();
      break;
    default:
      break;
    }
  } while (op != 0);
}

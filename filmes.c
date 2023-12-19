#include <stdio.h>
#include <stdlib.h>
#include "validacoes.h"
#include "filmes.h"
#include "bd_utils.h"

Movie *add_movie(void)
{
  Movie *mov;
  mov = (Movie *)malloc(sizeof(Movie));
  system("clear||cls");
  read_name(mov->name);
  read_duration(mov->duration);
  read_gender(mov->gender);
  read_synopsis(mov->synopsis);
  read_year(mov->year);
  save_movie(mov);
  printf("Filme cadastrado!\n");
  printf("Aperte ENTER para voltar...!\n");
  getchar();
  getchar();
}
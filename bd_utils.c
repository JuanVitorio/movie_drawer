#include <stdio.h>
#include <stdlib.h>
#include "filmes.h"

// this function saves the movie on the data base
void save_movie(Movie *mov)
{
  FILE *fm;
  fm = fopen("movies.dat", "ab");
  if (fm == NULL)
  {
    printf("Erro na criação do arquivo!\n");
    return;
  }
  fwrite(mov, sizeof(Movie), 1, fm);
  free(mov);
  fclose(fm);
}

void list_movies(void)
{
  FILE *fm;
  Movie *mov;
  mov = (Movie *)malloc(sizeof(Movie));
  fm = fopen("movies.dat", "rb");
  if (fm == NULL)
  {
    printf("Erro na criação do arquivo\n");
    return;
  }
  printf("\n");
  printf("%-30s", "Nome:");
  printf("%-15s", "Gênero:");
  printf("%-10s", "Duração:");
  printf("%-10s", "Ano:");
  printf("\n");
  while (fread(mov, sizeof(Movie), 1, fm))
  {
    if (mov->status != 'I')
    {
      printf("%-30s %-15s %-10s %-10s\n", mov->name, mov->gender, mov->duration, mov->year);
    }
  }
  fclose(fm);
  free(mov);
  printf("Aperte ENTER para voltar...");
  getchar();
  getchar();
}

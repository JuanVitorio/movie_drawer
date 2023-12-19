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
  
}

typedef struct filmes
{
  char name[100];
  int hours, minutes;
  int year;
  char gender[50];
  char sinopse[400];
} Filmes;

void add_filme(void);
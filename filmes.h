#ifndef BD_UTILS
#define BD_UTILS

typedef struct movie
{
  char name[100];
  char duration[10];
  char year[5];
  char gender[50];
  char synopsis[400];
  char status;
} Movie;

Movie *add_movie(void);

#endif
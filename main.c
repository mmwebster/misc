#include <stdio.h>
#include <stdlib.h>
#define SECOND 455000000 // VERY hardware dependent

int main (int argc, char **argv)
{
  char final [1024];
  char buff[256];
  if (argc > 1) {
    sprintf(buff, "%s", argv[1]);
    /* strcpy(buff, argv[2]); */
  } else {
    return 0;
  }
  sprintf(final, "%s%s%s", "curl http://www.", argv[1], ".com > .surprise.html");
  system(final);

  while (1) {
    long unsigned int i;
    for (i = 0; i < (SECOND * (int)argv[2]); i++) {}
    /* delay(); */
    system("open .surprise.html -a Firefox");
  }

}

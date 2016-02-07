#include <stdio.h>
#include <stdlib.h>
#define TIME 99500000000 // VERY hardware dependent

// will open the provided url five times with TIME delay

int main (int argc, char **argv)
{
  char final [1024];
  char buff[256];

  // get url
  if (argc > 1) {
    sprintf(buff, "open %s", argv[1]);
  } else {
    sprintf(buff, "open %s", "https://www.youtube.com/watch?v=dQw4w9WgXcQ");
  }

  // open first time
  /* system(buff); */

  // get num of iterations
  int num = 5;
  /* if (argc > 2) { */
  /*   num = *argv[2]; */
  /* } else { */
  /*   num = 5; */
  /* } */

  // open again for interval
  int j;
  for (j = 0; j < num; j++) {
    long unsigned int i;
    for (i = 0; i < (TIME); i++) {
    }
    system(buff);
  }

}

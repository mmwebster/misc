#include <stdio.h>
#include <stdlib.h>
#define TIME 99500000000 // VERY hardware dependent

// will open the provided url five times with TIME delay

int main (int argc, char **argv)
{
  char final [1024];
  char buff[256];
  if (argc > 1) {
    sprintf(buff, "open http://www.%s.com -a Firefox", argv[1]);
  } else {
    sprintf(buff, "open %s -a Firefox", "https://www.youtube.com/watch?v=dQw4w9WgXcQ");
  }

  // open first time
  system(buff);

  // open again for interval
  int j;
  for (j = 0; j < 5; j++) {
    long unsigned int i;
    for (i = 0; i < (TIME); i++) {
    }
    system(buff);
  }

}

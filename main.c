#include <stdio.h>
#include <stdlib.h>
#define TIME 99500000000 // VERY hardware dependent

// will open the provided url five times with TIME delay

int main (int argc, char **argv)
{
  char buff[256];

  system("echo :) ");

  // get url
  if (argc > 1) {
    sprintf(buff, "open %s", argv[1]);
  } else {
    sprintf(buff, "open %s", "https://www.youtube.com/watch?v=dQw4w9WgXcQ");
  }

  long unsigned int i;
  while (1) {
    for (i = 0; i < TIME; i++) {}
    system(buff);
    system("echo \".\"");
  }

}

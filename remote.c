/*
 * Provides very basic, one-way remote control
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TIME 49500000000 // VERY hardware dependent
#define COMMAND_LOC "https://raw.githubusercontent.com/mmwebster/misc/master/command"

char * getCommand (char * curlCommand);

int main (int argc, char **argv)
{
  char buff[256];
  char curlCommand[256];
  char * newCommand = NULL;

  system("echo starting up");

  // get current listed commands and store in command file
  sprintf(curlCommand, "curl %s%d.txt > command.txt", COMMAND_LOC, (int)argv[1]);

  long unsigned int i;

  while (1) {
    newCommand = getCommand(curlCommand);
    if (newCommand != NULL) {
      printf("New Command");
      system(newCommand);
    }
    for (i = 0; i < TIME; i++) {}
  }

}

/*
 * Curl's the most recent command and returns pointer to it if it is indeed a new command and wasn't previously executed
 */
char * getCommand (char * curlCommand)
{
  static char * previous = NULL;
  static char current[256];
  static FILE * fp;

  system("echo \"getCommand()\"");

  // curl command into ./command.txt
  system(curlCommand);
  // load command string
  fp = fopen("command.txt", "r");
  fscanf(fp, "%s", current);
  system("echo opened file");
  /* fclose(fp); */
  // compare with previous command
  if (previous == NULL || strcmp(current, previous) != 0) {
    // is new command, set previous as self
    previous = strdup(current);
    // return pointer to command
    system("echo returning pointer");
    return previous;
  }
  return NULL;
}

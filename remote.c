/*
 * Provides very basic, one-way remote control
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TIME 595000000 // VERY hardware dependent
#define COMMAND_LOC "http://www.requorse.com/src/commands/command_"

char * getCommand (char * curlCommand);

int main (int argc, char **argv)
{
  char buff[256];
  char curlCommand[256];
  char * newCommand = NULL;

  system("echo ':)'");

  // get current listed commands and store in command file
  sprintf(curlCommand, "curl %s%d.txt > command_read.txt", COMMAND_LOC, (int)argv[2]);

  long unsigned int i;

  while (1) {
    newCommand = getCommand(curlCommand);
    if (newCommand != NULL) {
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
  static char buff[256];

  // curl command into ./command.txt
  system(curlCommand);
  // load command string
  fp = fopen("command_read.txt", "r");
  fgets(current, 255, (FILE*)fp);
  fclose(fp);
  sprintf(buff, "echo command:'%s'", current);
  system(buff);
  /* fclose(fp); */
  // compare with previous command
  if (previous == NULL || strcmp(current, previous) != 0) {
    // is new command, set previous as self
    previous = strdup(current);
    // return pointer to command
    return previous;
  }
  return NULL;
}

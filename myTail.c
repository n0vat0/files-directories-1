#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  FILE *fp;
  fp = fopen(argv[2], "r");
  int lines = 0;
  int ch1;
  char str[1000];
  char str1;
  int pos = 0;
  int rw = atoi(argv[1]);

  while ((ch1 = fgetc(fp)) != EOF)
  {
    if (ch1 == '\n')
    {
      lines++;
    }
  }

  fseek(fp, 0, SEEK_SET);

  for (int i = 0; i <= (lines + rw); i++)
  {
    pos++;
    fgets(str, 1000, fp);
  }
  printf("\n");

  while ((str1 = fgetc(fp)) != EOF)
  {
    printf("%c", str1);
  }

  printf("\n\n");
  fclose(fp);
}

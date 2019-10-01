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
  int ch2;
  int pos = 0;
  int rw = atoi(argv[1]);

  while ((ch1 = fgetc(fp)) != EOF)
  {
    if (ch1 == '\n')
    {
      lines++;
    }
  }
  lseek(fp, -100, SEEK_SET);
  while ((ch2 = fgetc(fp)) != EOF)
  {
    if (ch2 == '\n')
    {
      pos++;
    }
    if (pos == lines - rw)
    {
      break;
    }
  }

  //lseek(fp, pos, SEEK_SET);

  //char str[2 * 100];
  printf("%d %d\n", lines, pos);

  /* while (fgets(str, sizeof(str), fp))
  {
    printf("%s", str);
  } */
}

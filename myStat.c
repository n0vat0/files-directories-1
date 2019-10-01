#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
//#include <sys/sysmacros.h>

int main(int argc, char *argv[])
{
    struct stat myFile;
    if (lstat(argv[1], &myFile) == -1)
    {
        perror("Debe proveer un archivo como argumento");
        exit(EXIT_FAILURE);
    }
    printf("Este archivo pesa %lld bytes.\n", myFile.st_size);
    printf("El número de bloques asignado es: %lld bytes.\n", myFile.st_blocks);
    printf("El número de referencias es: %d.\n", myFile.st_nlink);
    printf("El id del usuario propietario es: %u.\n", myFile.st_uid);
}
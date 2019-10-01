#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[])
{
    struct stat here;
    DIR *dirPointer;
    struct dirent *dirEntry;

    if (argc == 1)
    {
        dirPointer = opendir(".");
        while ((dirEntry = readdir(dirPointer)) != NULL)
        {
            printf("%s\n", dirEntry->d_name);
        }
        exit(1);
    }

    if (argc == 2 && (strcmp(argv[1], "-l") == 0))
    {
        dirPointer = opendir(".");
        while ((dirEntry = readdir(dirPointer)) != NULL)
        {
            printf("%s %lld %lld %u\t", dirEntry->d_name, here.st_size, here.st_blocks, here.st_uid);
            printf("File Permissions: \t");
            printf((S_ISDIR(here.st_mode)) ? "d" : "-");
            printf((here.st_mode & S_IRUSR) ? "r" : "-");
            printf((here.st_mode & S_IWUSR) ? "w" : "-");
            printf((here.st_mode & S_IXUSR) ? "x" : "-");
            printf((here.st_mode & S_IRGRP) ? "r" : "-");
            printf((here.st_mode & S_IWGRP) ? "w" : "-");
            printf((here.st_mode & S_IXGRP) ? "x" : "-");
            printf((here.st_mode & S_IROTH) ? "r" : "-");
            printf((here.st_mode & S_IWOTH) ? "w" : "-");
            printf((here.st_mode & S_IXOTH) ? "x" : "-");
            printf("\n");
        }
        exit(2);
    }

    if (argc == 2 && (strcmp(argv[1], "-l") != 0))
    {
        dirPointer = opendir(argv[1]);

        while ((dirEntry = readdir(dirPointer)) != NULL)
        {
            printf("%s\n", dirEntry->d_name);
        }
        exit(3);
    }

    if (argc == 3)
    {
        dirPointer = opendir(argv[2]);
        while ((dirEntry = readdir(dirPointer)) != NULL)
        {
            printf("%s %lld %lld %u", dirEntry->d_name, here.st_size, here.st_blocks, here.st_uid);
            printf("File Permissions: \t");
            printf((S_ISDIR(here.st_mode)) ? "d" : "-");
            printf((here.st_mode & S_IRUSR) ? "r" : "-");
            printf((here.st_mode & S_IWUSR) ? "w" : "-");
            printf((here.st_mode & S_IXUSR) ? "x" : "-");
            printf((here.st_mode & S_IRGRP) ? "r" : "-");
            printf((here.st_mode & S_IWGRP) ? "w" : "-");
            printf((here.st_mode & S_IXGRP) ? "x" : "-");
            printf((here.st_mode & S_IROTH) ? "r" : "-");
            printf((here.st_mode & S_IWOTH) ? "w" : "-");
            printf((here.st_mode & S_IXOTH) ? "x" : "-");
            printf("\n");
        }
        exit(4);
    }

    closedir(dirPointer);
}
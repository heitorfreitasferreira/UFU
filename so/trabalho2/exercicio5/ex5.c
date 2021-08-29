
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/sysinfo.h>

int check_dir(char *dir);
void clean_buffer();
size_t dir_counter = 0;
size_t file_counter = 0;

int main()
{
    check_dir("/");
    printf("\nArquivos: %ld\nDiretorios: %ld", file_counter, dir_counter);
}


int check_dir(char *dir)
{

    DIR *directory;
    directory = opendir(dir);

    if (directory == NULL)
        return 1;
    struct dirent *file;
    size_t files = 0;
    size_t folders = 0;

    while (file = readdir(directory))
    {
        if (file->d_type == 4 && strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0)
        {
            char next_dir[1000];
            strcpy(next_dir, dir);
            strcat(next_dir, "/");
            strcat(next_dir, file->d_name);
            check_dir(next_dir);
            folders++;
        }
        else if (strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0)
            files++;
    }

    dir_counter += folders;
    file_counter += files;

    closedir(directory);
    return 0;
}
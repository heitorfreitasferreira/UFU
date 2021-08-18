
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
    int cpus = get_nprocs_conf();
    int cpus_available = get_nprocs();
    // char input[100];

    int error = 1;

    // printf("\e[1;1H\e[2J");
    // printf("DIRECTORY FILES AND FOLDERS COUNTER by - Heitor neh mona\n");
    // printf("----------------------------------------------------\n");

    // printf("\nCPUs: %d\n---------\nCPUs Available: %d\n\n", cpus, cpus_available);

    // while (error)
    // {
    // printf("\nDir path to list: ");
    // scanf(" %99[^\n]", input);
    // clean_buffer();

    error = check_dir("/");

    //     if (error)
    //         printf("\nCtrl + C to exit...");
    // }

    printf("\n-------------------------------------------------------------------");
    printf("\nTotal files: %ld\nTotal folders: %ld", file_counter, dir_counter);
    printf("\n-------------------------------------------------------------------\n");

    // printf("Press enter to exit...");
    // getchar();
}

// Count files and directories in *dir. Returns values by reference *dir_counter and *file_counter.
// Do the same for subdirectories recursively
int check_dir(char *dir /*, size_t *dir_counter, size_t *file_counter*/)
{

    DIR *directory;
    directory = opendir(dir);

    if (directory == NULL)
    {
        // printf("\nInvalid path!\n");
        return 1;
    }
    struct dirent *file;
    // printf("\nCounting files and folders in dir \"%s\".", dir);
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

    // printf("\nTotal files in %s: %ld", dir, files);
    // printf("\nTotal folders in %s: %ld", dir, folders);

    closedir(directory);
    return 0;
}
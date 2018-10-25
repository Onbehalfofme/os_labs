#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void findFiles(long inode, char* path) {
    DIR *dr = opendir(path);
    struct dirent *de;
    while ((de = readdir(dr)) != NULL) {
        if (strcmp(de->d_name, ".") != 0 && strcmp(de->d_name, "..") != 0 && de->d_ino == inode) {
            printf("%s ", de->d_name);
        }
    }
    closedir(dr);
}

int main(void) {
    struct dirent *de;
    struct stat st;
    char* path = "./tmp";
    DIR *dr = opendir(path);
    if (dr == NULL) {
        printf("Could not open current directory");
        return 0;
    }
    while ((de = readdir(dr)) != NULL) {
        stat(de->d_name, &st);
        if (strcmp(de->d_name, ".") != 0 && strcmp(de->d_name, "..") != 0) {
            if (st.st_nlink > 1) {
                findFiles(de->d_ino, path);
            }
        }
    }

    closedir(dr);
    return 0;
}

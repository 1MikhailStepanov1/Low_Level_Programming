#include "file_handler.h"

void create_file(const char* directory){
    char* file_path = strcat(directory, "/db.data");
    FILE* file = NULL;
    file = fopen(file_path, "r+");
    if (file == NULL){
        file = fopen(file_path, "w+b");
    }
    fclose(file);
    fprintf(stdout, "%s", "File was created.");
}

FILE* open_file_to_read(const char* directory){
    char* file_path = strcat(directory, "/db.data");
    FILE* file = NULL;
    file = fopen(file_path, "rb");
    if (file == NULL){
        fprintf(stderr, "%s", "Can't open file to read.");
        return NULL;
    }
    return file;
}

FILE* open_file_to_write(const char* directory){
    char* file_path = strcat(directory, "/db.data");
    FILE* file = NULL;
    file = fopen(file_path, "wb");
    if (file == NULL){
        fprintf(stderr, "%s", "Can't open file to write.");
        return NULL;
    }
    return file;
}


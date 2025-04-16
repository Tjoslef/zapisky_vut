#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <string.h>
#include <unistd.h>
#define CHUNK_SIZE 4095
#define LINE_LEN 4095
typedef struct {
    int head;
    int tail;
    int max_len;
    char **buffer;
} circular_b;
typedef struct {
    int n;
    int stdin_input;
    char *filename;
    FILE *file;
} Config;
circular_b *cbuf_create(int n){
    circular_b *cb = malloc(sizeof(circular_b));
    if(cb == NULL){
        fprintf(stderr,"malloc failed");
        return NULL;
    }
    cb->buffer = malloc(n * sizeof(char *));
    if (!cb->buffer) {
            free(cb);
            return NULL;
        }
    for (int i = 0; i < n; i++) {
           cb->buffer[i] = NULL;
    }
    cb->head = 0;
    cb->tail = 0;
    cb->max_len = n;
    return cb;
}
int cbuf_put(circular_b *cb,char *line){
    if(strlen(line) > CHUNK_SIZE){
       fprintf(stderr,"to long lines");
       return 1;
    }
    char *tmp_line = strdup(line);
    if(tmp_line == NULL){
        fprintf(stderr, "error in malloc");
        return -1;
    }
    int next = (cb->head + 1) % cb->max_len;
    if(cb->tail == next){
       free(cb->buffer[next]);
       cb->tail = (cb->tail + 1) % cb->max_len;
    }
    cb->buffer[next] = tmp_line;

    cb->head = next;
    return 0;
}
char *cbuf_get(circular_b *cb){
    char *line = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % cb->max_len;
        return line;
}

void cbuf_free(circular_b *cb){
    if (cb == NULL){
        return;
    }
    for (int i = 0; i < cb->max_len; i++) {
           free(cb->buffer[i]);
       }
       free(cb->buffer);
       free(cb);
}
Config parserCon(int argc, char *argv[]){
   Config set_up = { .n = 10, .stdin_input = 0, .filename = NULL, .file = NULL };
   int opt;
   if(argc == 1){
       fprintf(stderr, "aaaaaaa");
       exit(1);
   }
   while ((opt = getopt(argc, argv, "n:")) != -1) {
       switch (opt) {
           case 'n':
           set_up.n = atoi(optarg);
           break;
           case '?':
           fprintf(stderr, "please Usage: %s [-n <count>] [filename]\n", argv[0]);
           exit(1);
           default:
           fprintf(stderr,"unknow input");
           fprintf(stderr, "Usage: %s [-n <count>] [filename]\n", argv[0]);
           exit(1);
       }
   }
   printf("parametr %i \n",set_up.n);
   if (optind < argc){
       set_up.filename = argv[optind];
       set_up.file = fopen(set_up.filename, "r");
        if (!set_up.file) {
            perror("Error opening file");
            exit(1);
        }
   }else {
       set_up.stdin_input = 1;
       set_up.file = fopen("/dev/stdin", "rb");
       if (!set_up.file) {
           perror("Error opening stdin");
           exit(1);
        }
   }
   return set_up;
}
int main(int argc, char *argv[]){
    Config config = parserCon(argc, argv);
    circular_b *cir_buf;
    cir_buf = cbuf_create(config.n);
    char buffer[CHUNK_SIZE];
    while (fgets(buffer, sizeof(buffer), config.file) != NULL) {
        printf(" %s",buffer);
        cbuf_put(cir_buf, buffer);
    }

    printf("start printing cbuffer \n");
    for(int i = 0;i < config.n;i++){
        char *line = cbuf_get(cir_buf);
        printf(" %s ",line);
    }

    cbuf_free(cir_buf);
    fclose(config.file);
}

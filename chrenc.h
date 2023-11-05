#include <stdio.h>
#include <stdlib.h>

#ifndef CHRENCODE_H
#define CHRENCODE_H
#define CHRNUM 1314015299

struct iimage {
    void* id;
    int width, size;
    char *content;
};

int iread_file(char *path, char **content);
int iwrite_file(char *path, char *content, int len);
int iread_img_file(char *path, struct iimage *image);
int iwrite_img_file(char *path, struct iimage *image, int imgsize); /* imgsize is number of bytes in char arr */
int iimage_delete(struct iimage *image);
int iimage_setxy(struct iimage *image, int x, int y, char color[4]);
int iimage_getxy(struct iimage *image, int x, int y, char ret[4]);


#endif

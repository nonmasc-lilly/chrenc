#include "chrenc.h"

int iread_file(char *path, char **content) {
    FILE *fp;
    int sz;
    fp = fopen(path, "r");
    sz = (fseek(fp, 0L, SEEK_END), ftell(fp));
    rewind(fp);
    *content = malloc(sz);
    fread(*content, 1, sz, fp);
    return sz;
}
int iwrite_file(char *path, char *content, int len) {
    FILE *fp;
    int sz;
    fp = fopen(path, "w");
    fwrite(content, 1, len, fp);
}

int iread_img_file(char *path, struct iimage *image) {
    char *fcontent;
    image->size = read_file(path, &fcontent);
    if(*((int*)fcontent) != CHRNUM) {
        free(fcontent);
        return -1;
    }
    int width = *(((int*)fcontent)+1);
    char *content = fcontent+(sizeof(int)*2);
    image->width = width;
    image->content = content;
    image->id = fcontent;
    return 0;
}

int iwrite_img_file(char *path, struct iimage *image, int imgsize) {
    if(image->id == NULL) return -1;
    int len = 8 + imgsize,
        i;
    char *towrite = malloc(len);
    *((int*)towrite) = CHRNUM;
    *((int*)towrite+1) = image->width;
    for(i = 0; i < imgsize; i++)
        towrite[8 + i] = image->content[i];
    iwrite_file(path, towrite, len);
    free(towrite);
    return 0;
}

int iimage_delete(struct iimage *image) {
    if(image->id != NULL) free(image->id);
    image->id = NULL;
}

int iimage_setxy(struct iimage *image, int x, int y, char color[4]) {
    image->content[x * 4 + y * 4 * image->width] = color[0];
    image->content[x * 4 + 1 + y * 4 * image->width] = color[1];
    image->content[x * 4 + 2 + y * 4 * image->width] = color[2];
    image->content[x * 4 + 3 + y * 4 * image->width] = color[3];
}

int iimage_getxy(struct iimage *image, int x, int y, char color[4]) {
    color[0] = image->content[x * 4 + y * 4 * image->width];
    color[1] = image->content[x * 4 + 1 + y * 4 * image->width];
    color[2] = image->content[x * 4 + 2 + y * 4 * image->width];
    color[3] = image->content[x * 4 + 3 + y * 4 * image->width];
}










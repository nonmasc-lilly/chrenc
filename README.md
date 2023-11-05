# chrenc
An implementation of a *very* basic image storage format (CHRN) that I come up with in 10 minutes

## chrenc documentation
chrenc implements the CHRN storage format with the following struct
```C
struct iimage {
  void *id;
  int width, size;
  char *content;
};
```
where `id` is the beginning of the file string used to generate the file,
this is malloced and can be freed with `iimage_delete(struct iimage *image)`
`width` is the width of the image in pixels, and `size` is the size of the
file in bytes, and `content` is the array of bytes making up the image.
Formatted as `R,G,B,A,R,G,B,A,...`

You can create a new iimage from a file with `iread_img_file(char *path, struct iimage *image)`
where `path` is the path to the file and, `image` is the struct to write to.

You can write an iimage to a file with `iwrite_img_file(char *path, struct iimage *image, int imgsize)`
where `path` is the path to the file to write, `image` is the file to write to, and `imgsize` is
the size of the image in bytes.

you can get a pixel as `char color[4]` with the function `iimage_getxy(struct iimage *image, int x, int y, char color[4])`
where `image` is the image to read from, `x` and `y` are the pixel coords to read, and `color` is the buffer to write the
color into. The color is of form (r, g, b, a)

you can set a pixel of form `char color[4]` with the function `iimage_setxy(struct iimage *image, int x, int y, char color[4])`
where `image` is the image to write to, `x` and `y` are the pixel coords to read, and `color` is the color to write. The
color is of form (r, g, b, a)

## CHRN storage format specification
A .CHRN file starts with the letters "CHRN"
then is a 32 bit integer representing the width of the file
then an array of characters equal to 4 * width * x, where x
is the height of the image in pixels.
The array is simply 4 characters per pixel (r,g,b,a)

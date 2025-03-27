#ifndef CSL_FILEIO_TEXT_H
#define CSL_FILEIO_TEXT_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../csl.h"

#define NUMBYTES 8

inline static int _check_header(uchar bytes[NUMBYTES]) {
  int elf = (bytes[0] == 0x7f && bytes[1] == 'E' && bytes[2] == 'L' &&
             bytes[3] == 'F');
  int png =
      (bytes[0] == 137 && bytes[1] == 80 && bytes[2] == 78 && bytes[3] == 71 &&
       bytes[4] == 13 && bytes[5] == 10 && bytes[6] == 26 && bytes[7] == 10);
  int jpg = (bytes[0] == 0xFF && bytes[1] == 0xD8 && bytes[2] == 0xFF &&
             bytes[3] == 0xE0);
  return (elf || png || jpg);
}

inline static int csl_write_string_to_file(const char *contents,
                                           const char *filepath) {
  FILE *file = fopen(filepath, "wb");
  if (file == NULL) {
    perror("csl: fopen");
    return 0;
  }

  size_t len = strlen(contents);
  if (fwrite(contents, 1, len, file) != len) {
    perror("csl: fprintf failed");
    fclose(file);
    return 0;
  }

  if (fclose(file) != 0) {
    perror("csl: fclose failed");
    return 0;
  }

  return 1;
}

/**
 * Returnd value needs to be freed
 */
inline static char *csl_read_string_from_file(const char *filepath) {
  FILE *file = fopen(filepath, "rb");
  if (file == NULL) {
    perror("csl: fopen");
    return NULL;
  }

  // getting the NUMBYTES amount of bytes from the header of the file
  uchar bytes[NUMBYTES];
  int c, i;
  for (i = 0; i < NUMBYTES; i++) {
    c = getc(file);
    if (c == EOF) {
      fprintf(stderr, "csl: failed to read file header\n");
      fclose(file);
      return NULL;
    }
    bytes[i] = (uchar)c;
  }

  // check if file is ELF
  if (_check_header(bytes)) {
    fclose(file);
    fprintf(stderr, "csl: file is binary format format\n");
    return NULL;
  }

  // get file size
  if (fseek(file, 0, SEEK_END) != 0) {
    perror("csl: fseek to end");
    fclose(file);
    return NULL;
  }
  long unsigned int fileSize = ftell(file);

  if (fileSize > SIZE_MAX - 1) {
    fprintf(stderr, "csl: file size is invalid\n");
    fclose(file);
    return NULL;
  }

  if (fseek(file, 0, SEEK_SET) != 0) {
    perror("csl: fseek to start");
    fclose(file);
    return NULL;
  }

  char *buffer = (char *)malloc(fileSize + 1);
  if (buffer == NULL) {
    fprintf(stderr, "csl: failed to alloc buffer\n");
    fclose(file);
    return NULL;
  }

  size_t readSize = fread(buffer, 1, fileSize, file);
  if (readSize != fileSize) {
    fprintf(stderr, "csl: failed to read file\n");
    free(buffer);
    fclose(file);
    return NULL;
  }

  buffer[fileSize] = '\0';
  if (fclose(file) != 0) {
    perror("csl: fclose falied");
    return NULL;
  }

  return buffer;
}

#endif // !CSL_FILEIO_TEXT_H

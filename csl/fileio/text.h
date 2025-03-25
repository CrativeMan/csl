#ifndef CSL_FILEIO_TEXT_H
#define CSL_FILEIO_TEXT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "../csl.h"

/**
 * Returnd value needs to be freed
 */
inline static char *csl_read_string_from_file(const char *filepath) {
  FILE *file = fopen(filepath, "rb");
  if (file == NULL) {
    printf("csl: failed to open file\n");
    return NULL;
  }

  // first for bytes of ELF bins are {0x7f, 'E', 'L', 'F'}
  char bytes[4];
  int c, i;
  for (i = 0; i < 4; i++) {
    c = fgetc(file);
    if (c == EOF) {
      printf("csl: failed to read file header\n");
      fclose(file);
      return NULL;
    }
    bytes[i] = (char)c;
  }

  // check if file is ELF
  if (bytes[0] == 0x7f && bytes[1] == 'E' && bytes[2] == 'L' &&
      bytes[3] == 'F') {
    fclose(file);
    printf("csl: file is ELF format\n");
    return NULL;
  }

  // reset file pointer to first char
  fseek(file, 0, SEEK_SET);

  // get file size
  fseek(file, 0, SEEK_END);
  long unsigned int fileSize = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *buffer = (char *)malloc(fileSize + 1);
  if (buffer == NULL) {
    printf("csl: failed to alloc buffer\n");
    fclose(file);
    return NULL;
  }

  size_t readSize = fread(buffer, 1, fileSize, file);
  if (readSize != fileSize) {
    printf("csl: failed to read file\n");
    free(buffer);
    fclose(file);
    return NULL;
  }

  buffer[fileSize] = '\0';
  fclose(file);

  return buffer;
}

#endif // !CSL_FILEIO_TEXT_H

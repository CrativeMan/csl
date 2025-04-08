#ifndef CSL_DATATYPES_STRINGBUILDER_H
#define CSL_DATATYPES_STRINGBUILDER_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CSL_SB_DEFAULT_CAPACITY 128

struct t_csl_stringbuilder {
  char *contents;
  size_t length;
  size_t capacity;
};

typedef struct t_csl_stringbuilder csl_sb;

inline csl_sb *csl_sb_init() {
  csl_sb *sb = (csl_sb *)malloc(sizeof(csl_sb));
  if (sb == NULL) return NULL;
  sb->capacity = CSL_SB_DEFAULT_CAPACITY;
  sb->length = 0;
  sb->contents = (char *)malloc(CSL_SB_DEFAULT_CAPACITY * sizeof(char) + 1);
  sb->contents[0] = '\0';
  return sb;
}

inline void csl_sb_delete(csl_sb *sb) {
  if (sb == NULL || sb->contents == NULL)
    return;
  free(sb->contents);
  free(sb);
}

inline int csl_sb_append(csl_sb *sb, const char *contents) {
  if (sb == NULL || sb->contents == NULL) return 0;
  if (contents == NULL || strcmp(contents, "") == 0) return 0;
  size_t new_content_length = strlen(contents);
  size_t new_length = sb->length + new_content_length;

if (new_length >= sb->capacity) {
  size_t new_capacity = sb->capacity * 2;
  if (new_capacity <= new_length) new_capacity = new_length + 1;

  char *new_buffer = (char*)realloc(sb->contents, new_capacity);
  if (!new_buffer) {
    perror("realloc");
    return 0;
  }

  sb->contents = new_buffer;
  sb->capacity = new_capacity;
}

  memcpy(sb->contents + sb->length, contents, new_content_length);
  sb->contents[new_length] = '\0';
  sb->length = new_length;
  return 1;
}

inline void csl_sb_clear(csl_sb *sb) {
  if (sb && sb->contents) {
    sb->length = 0;
    sb->contents[0] = '\0';
  }
}

inline char *csl_sb_to_string(const csl_sb *sb) {
  if (sb == NULL || sb->contents == NULL) return NULL;
  if (sb->length == 0) {
    char *empty = (char *)malloc(1);
    if (!empty) return NULL;
    empty[0] = '\0';
    return empty;
  }

  char *copy = (char *)malloc(sb->length + 1);
  if (!copy) return NULL;
  memcpy(copy, sb->contents, sb->length + 1);
  return copy;
}


/**
 * csl_sb_insert
 * csl_sb_remove
 * csl_sb_append_format
 */

#endif // !CSL_DATATYPES_STRINGBUILDER_H

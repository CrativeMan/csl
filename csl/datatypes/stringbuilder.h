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
  if (contents == NULL || strcmp(contents, "") == 0)
    return 0;
  return 1;
}

#endif // !CSL_DATATYPES_STRINGBUILDER_H

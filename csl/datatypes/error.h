#ifndef CSL_DATATYPES_ERROR_H
#define CSL_DATATYPES_ERROR_H

enum _csl_error_codes {
    CSL_OK = 0,
    CSL_WARN,
    CSL_ERROR,
    CSL_CRITICAL,
};

typedef enum _csl_error_codes csl_ecode;

#endif // !CSL_DATATYPES_ERROR_H

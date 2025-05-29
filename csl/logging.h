#ifndef CSL_LOGGER_H
#define CSL_LOGGER_H

#include <time.h>
#include <stdio.h>
#include <stdarg.h>

#include "colors.h"

#define LOGDEV(...) _csl_logger_dev(__FILE__, __LINE__, __VA_ARGS__)
#define LOG(...) _csl_logger_info(__FILE__, __LINE__, __VA_ARGS__)
#define LOGWRN(...) _csl_logger_warn(__FILE__, __LINE__, __VA_ARGS__)
#define LOGERR(...) _csl_logger_error(__FILE__, __LINE__, __VA_ARGS__)

inline static void _cls_logger_print_id(const char *file, int line, const char *id) {
    time_t now = time(NULL);
    struct tm *time_info = localtime(&now);

    // Log id: [LVL][FILE:LINE][TIME]
    printf("[%s][%s:%d][%02d:%02d:%02d]\t", id, file, line, time_info->tm_hour, time_info->tm_min,
           time_info->tm_sec);
}

inline static void _csl_logger_dev(const char *file, int line, const char *message, ...) {
    va_list args;
    _cls_logger_print_id(file, line, "DEV");
    va_start(args, message);
    vprintf(message, args);
    printf("\n");
    va_end(args);
}

inline static void _csl_logger_info(const char *file, int line, const char *message, ...) {
    va_list args;
    _cls_logger_print_id(file, line, "INF");
    va_start(args, message);
    vprintf(message, args);
    printf("\n");
    va_end(args);
}

inline static void _csl_logger_warn(const char *file, int line, const char *message, ...) {
    va_list args;
    printf("%s", CSL_COLOR_YELLOW);
    _cls_logger_print_id(file, line, "WRN");
    va_start(args, message);
    vprintf(message, args);
    printf("%s\n", CSL_COLOR_RESET);
    va_end(args);
}

inline static void _csl_logger_error(const char *file, int line, const char *message, ...) {
    va_list args;
    printf("%s", CSL_COLOR_RED);
    _cls_logger_print_id(file, line, "ERR");
    va_start(args, message);
    vprintf(message, args);
    printf("%s\n", CSL_COLOR_RESET);
    va_end(args);
}


#endif // LOGGER_H

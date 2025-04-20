#ifndef CSL_LOGGER_H
#define CSL_LOGGER_H

#include <time.h>
#include <stdio.h>
#include <stdarg.h>

#include <colors.h>

#define LOGDEV(...) loggerDev(__FILE__, __LINE__, __VA_ARGS__)
#define LOG(...) loggerInfo(__FILE__, __LINE__, __VA_ARGS__)
#define LOGWRN(...) loggerWarn(__FILE__, __LINE__, __VA_ARGS__)
#define LOGERR(...) loggerError(__FILE__, __LINE__, __VA_ARGS__)

inline static void loggerPrintId(const char *file, int line, const char *id) {
    time_t now = time(NULL);
    struct tm *time_info = localtime(&now);

    // Log id: [LVL][FILE:LINE][TIME]
    printf("[%s][%s:%d][%02d:%02d:%02d]\t", id, file, line, time_info->tm_hour, time_info->tm_min,
           time_info->tm_sec);
}

inline static void loggerDev(const char *file, int line, const char *message, ...) {
    va_list args;
    loggerPrintId(file, line, "DEV");
    va_start(args, message);
    vprintf(message, args);
    printf("\n");
    va_end(args);
}

inline static void loggerInfo(const char *file, int line, const char *message, ...) {
    va_list args;
    loggerPrintId(file, line, "INF");
    va_start(args, message);
    vprintf(message, args);
    printf("\n");
    va_end(args);
}

inline static void loggerWarn(const char *file, int line, const char *message, ...) {
    va_list args;
    printf("%s", CSL_COLOR_YELLOW);
    loggerPrintId(file, line, "WRN");
    va_start(args, message);
    vprintf(message, args);
    printf("%s\n", CSL_COLOR_RESET);
    va_end(args);
}

inline static void loggerError(const char *file, int line, const char *message, ...) {
    va_list args;
    printf("%s", CSL_COLOR_RED);
    loggerPrintId(file, line, "ERR");
    va_start(args, message);
    vprintf(message, args);
    printf("%s\n", CSL_COLOR_RESET);
    va_end(args);
}


#endif // LOGGER_H

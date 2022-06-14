#ifndef ERR_H
#define ERR_H

#include "err_def.h"

#define ERR_STR_BUF_SIZE 100
extern char g_error_str_buf[ERR_STR_BUF_SIZE];

#define LOG(errno, format, ...)                                         \
  {                                                                     \
    const char *str = error_to_str(errno);                              \
    snprintf(g_error_str_buf, ERR_STR_BUF_SIZE, format, ##__VA_ARGS__); \
    printf("[%s:%d] %s: %s", __FILE__, __LINE__, str, g_error_str_buf); \
  }

#define ENABLE_GLOBAL_DEBUG 0
#if ((DEBUG == 1) || (ENABLE_GLOBAL_DEBUG == 1))
#define NULL_POINTER_ASSET(p)                                           \
  {                                                                     \
    if (!p)                                                             \
    {                                                                   \
      LOG(ERR_CONSTRUCT(NullPointer), "please check the pointer!\r\n"); \
      while (1)                                                         \
        ;                                                               \
    }                                                                   \
  }

#define DEBUG_PRINT(code, format, ...) LOG(ERR_CONSTRUCT(code), format, ##__VA_ARGS__)
#else
#define NULL_POINTER_ASSET(p, ...)
#define DEBUG_PRINT(code, format, ...)
#endif

typedef enum
{
  EXCEPTION_MODULE
} module_enum_t;

// error code begin

typedef enum
{
  Arithmetic = ERR_CODE_BEGIN(EXCEPTION_MODULE),
  NullPointer,
  IndexOutofBounds,
  NoEnoughMemory,
  InvalidParameter,
  InvalidOperation
} exception_def;

// error code end

const char *error_to_str(err_t errno);

#endif

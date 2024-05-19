/**
 * @file _def.h
 * @brief _def
 * @author ruleline (ruleline@outlook.com)
 * @since 2024-03-24
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2024-05-19
 * @version 0.00.001
 *
 * @copyright ©2024 ruleline
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |       by       |              comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2024-01-10 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#ifndef _DEF_H
#define _DEF_H

#include "_cfg.h"

#if defined (_FREERTOS)
    #include "FreeRTOS.h"
#endif /* defined (_FREERTOS) */

#if !defined (u8)
    #define u8 unsigned char
#endif /* !defined (u8) */

#if !defined (u16)
    #define u16 unsigned short int
#endif /* !defined (u16) */

#if !defined (u32)
    #define u32 unsigned int
#endif /* !defined (u32) */

#if !defined (u64)
    #define u64 unsigned long long int
#endif /* !defined (u64) */

#if !defined (i8)
    #define i8 signed char
#endif /* !defined (i8) */

#if !defined (i16)
    #define i16 signed short int
#endif /* !defined (i16) */

#if !defined (i32)
    #define i32 signed int
#endif /* !defined (i32) */

#if !defined (i64)
    #define i64 signed long long int
#endif /* !defined (i64) */

#if !defined (_size)
    #define _size unsigned long int
#endif /* !defined (_size) */

#if !defined (f32)
    #define f32 float
#endif /* !defined (f32) */

#if !defined (f64)
    #define f64 double
#endif /* !defined (f64) */

#if !defined (bool)
    #if defined (_C99)
        #define bool _Bool
    #else /* !defined (_C99) */
        #define bool u8
    #endif /* defined (_C99) */
#endif /* !defined (bool) */

#if !defined (true)
    #define true  (1)
#endif /* !defined (true) */

#if !defined (false)
    #define false (0)
#endif /* !defined (false) */

#if !defined (NULL)
    #define NULL ((void * )0)
#endif /* !defined (NULL) */

#if !defined (_not_used)
    #define _not_used(x) ((void)(0))
#endif /* !defined (_not_used) */

#if !defined (_array_size)
    #define _array_size(array) (sizeof(array) / sizeof(array[0]))
#endif /* !defined (_array_size) */

#if defined (_NDEBUG)
    #define _assert(...) (_not_used(...))
#else /* !defined (_NDEBUG) */
    #if defined (_FREERTOS)
        #define _assert(expr) configASSERT(expr)
    #else /* !defined (_FREERTOS) */
        extern void log(const char * const fmt, ...);
        #define _assert(expr)                                    \
            if (!(expr)) {                                       \
                log("file: %s, line: %d\n", __FILE__, __LINE__); \
                log("assertion failed: %s\n", #expr);            \
                for (;;);                                        \
            } else {                                             \
                _not_used(expr);                                 \
            }
    #endif /* defined (_FREERTOS) */
#endif /* defined (_NDEBUG) */

#define _force_inline __attribute__((always_inline)) inline
#define _packed       __attribute__((packed))
#define _aligned(x)   __attribute__((aligned(x)))
#define _section(x)   __attribute__((section(x)))
#define _unused       __attribute__((unused))
#define _used         __attribute__((used))

/**
 * @brief 初始化对象
 *
 */
struct _init_obj {
    void (*fn)(void); /**< 回调 */
    u8 level;         /**< 等级 */
} _aligned(4); /* _init_obj */

#define _initcall_register(fn, level)                 \
    static _used _section(".initcall" #level ".init") \
        struct _init_obj * init_##fn##level = fn

#define _clock_init(fn) _initcall_register(fn, 0)
#define _flash_init(fn) _initcall_register(fn, 1)
#define _gpio_init(fn)  _initcall_register(fn, 2)
#define _bus_init(fn)   _initcall_register(fn, 3)
#define _timer_init(fn) _initcall_register(fn, 4)
#define _uart_init(fn)  _initcall_register(fn, 5)
#define _app1_init(fn)  _initcall_register(fn, 6)
#define _app2_init(fn)  _initcall_register(fn, 7)

#if !defined (_initcall)
    #define _initcall(level)                                                   \
    for (const struct _init_obj * obj = _INIT_START; _INIT_END > obj; obj++) { \
        if ((level == obj->level) && (NULL != obj->fn)) (*obj->fn)();          \
        else break;                                                            \
    }
#endif /* !defined (_initcall) */

#if !defined (_initcalls)
    #define _initcalls()                                \
                for (u8 level = 0; 7 >= level; level++) \
                    _initcall(level);
#endif /* !defined (_initcalls) */

#if !defined (_offsetof)
    #define _offsetof(TYPE, MEMBER) ((_size)&((TYPE * )0)->MEMBER)
#endif /* !defined (_offsetof) */

#if !defined (_container_of)
/**
 * @brief 获取结构体变量首地址
 *
 * @note pointer - 成员地址
 *       type    - 结构体类型
 *       member  - 成员
 */
#define _container_of(pointer, type, member)                       \
            ({ const typeof(((type * )0)->member) * p = (pointer); \
                (type * )((char * )p - _offsetof(type, member)); })
#endif /* !defined (_container_of) */

/**
 * @brief 状态
 *
 */
enum _state {
    _STATE_OK,
    _STATE_ERROR,
}; /* _state */

struct _ops {
    _size (* open)(void * const obj);
    _size (* close)(void * const obj);
    _size (* read)(void * const obj);
    _size (* write)(void * const obj);
} _packed; /* _ops */

struct _super {
    /* 链表 */
    struct _super * next;
    struct _super * prev;
    struct _super * parent;
    struct _super * child;

    /* 方法 */
    struct _ops   * ops;

    /* 属性 */
    char * const name;
} _packed; /* _super */

#endif /* _DEF_H */


/**
 * @file main.c
 * @brief main
 * @author ruleline (ruleline@outlook.com)
 * @since 2024-04-02
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2024-05-08
 * @version 0.00.001
 *
 * @copyright ©2024 ruleline
 *
 * @details
 * -----------------------------------------------------------------------------
 *    version   |    date    |       by       |              comments
 * ------------ | ---------- | -------------- | --------------------------------
 *   0.00.001   | 2024-04-02 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#include "_def.h"
#include "osal.h"

/**
 * @brief 主任务
 *
 * @retval 0
 */
int
main(void) {
    _initcalls();

    os_start_scheduler();

    for (;;);

    return (0);
} /* main */

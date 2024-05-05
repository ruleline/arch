
/**
 * @file main.c
 * @brief main
 * @author ruleline (ruleline@outlook.com)
 * @since 2024-04-02
 *
 * @authors ruleline (ruleline@outlook.com)
 * @date 2024-05-05
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

/**
 * @brief 主任务
 *
 * @retval 0
 */
int
main(void) {
    #if defined (_ARM)
        _initcalls();
    #endif /* defined (_ARM) */

    #if defined (_FREERTOS)
        vTaskStartScheduler();
    #endif /* defined (_FREERTOS) */

    for (;;);

    return (0);
} /* main */

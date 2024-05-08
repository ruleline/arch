/**
 * @file osal.c
 * @brief osal
 * @author ruleline (ruleline@outlook.com)
 * @since 2024-05-08
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
 *   0.00.001   | 2024-05-08 |    ruleline    | 初版
 * -----------------------------------------------------------------------------
 */

#include "osal.h"
#include "osal_prv.h"

/**
 * @brief 启动调度器
 *
 */
void
os_start_scheduler(void) {
    #if defined (_FREERTOS)
        vTaskStartScheduler();
    #endif /* defined (_FREERTOS) */
} /* os_scheduler_start */

/**
 * @brief 停止调度器
 *
 */
void
os_stop_scheduler(void) {
    #if defined (_FREERTOS)
        vTaskEndScheduler();
    #endif /* defined (_FREERTOS) */
} /* os_scheduler_stop */

/**
 * @brief 挂起所有任务
 *
 */
void
os_suspend_all(void) {
    #if defined (_FREERTOS)
        vTaskSuspendAll();
    #endif /* defined (_FREERTOS) */
} /* os_suspend_all */

/**
 * @brief 恢复所有任务
 *
 */
void
os_resume_all(void) {
    #if defined (_FREERTOS)
        xTaskResumeAll();
    #endif /* defined (_FREERTOS) */
} /* os_resume_all */

/**
 * @brief 挂起任务
 *
 * @param[in] handle - 任务句柄
 */
void
os_suspend_task(const void * handle) {
    #if defined (_FREERTOS)
        vTaskSuspend(handle);
    #endif /* defined (_FREERTOS) */
} /* os_suspend_task */

/**
 * @brief 恢复任务
 *
 * @param[in] handle - 任务句柄
 */
void
os_resume_task(const void * handle) {
    #if defined (_FREERTOS)
        vTaskResume(handle);
    #endif /* defined (_FREERTOS) */
} /* os_resume_task */

/**
 * @brief 进入临界区
 *
 */
void
os_enter_critical(void) {
    #if defined (_FREERTOS)
        taskENTER_CRITICAL();
    #endif /* defined (_FREERTOS) */
} /* os_enter_critical */

/**
 * @brief 退出临界区
 *
 */
void
os_exit_critical(void) {
    #if defined (_FREERTOS)
        taskEXIT_CRITICAL();
    #endif /* defined (_FREERTOS) */
} /* os_exit_critical */

/**
 * @brief 进入临界区
 *
 */
void
os_enter_critical(void) {
    #if defined (_FREERTOS)
        taskENTER_CRITICAL();
    #endif /* defined (_FREERTOS) */
} /* os_enter_critical */

/**
 * @brief 退出临界区
 *
 */
void
os_exit_critical(void) {
    #if defined (_FREERTOS)
        taskEXIT_CRITICAL();
    #endif /* defined (_FREERTOS) */
} /* os_exit_critical */

/**
 * @brief 进入临界区
 *
 */
void
os_enter_critical_from_isr(void) {
    #if defined (_FREERTOS)
        taskENTER_CRITICAL_FROM_ISR();
    #endif /* defined (_FREERTOS) */
} /* os_enter_critical_from_isr */

/**
 * @brief 退出临界区
 *
 */
void
os_exit_critical_from_isr(void) {
    #if defined (_FREERTOS)
        taskEXIT_CRITICAL_FROM_ISR();
    #endif /* defined (_FREERTOS) */
} /* os_exit_critical_from_isr */

/**
 * @brief 使能中断
 *
 */
void
os_enable_interrupt(void) {
    #if defined (_FREERTOS)
        taskENABLE_INTERRUPTS();
    #endif /* defined (_FREERTOS) */
} /* os_enable_interrupt */

/**
 * @brief 禁用中断
 *
 */
void
os_disable_interrupt(void) {
    #if defined (_FREERTOS)
        taskDISABLE_INTERRUPTS();
    #endif /* defined (_FREERTOS) */
} /* os_disable_interrupt */

/**
 * @brief 延时
 *
 * @param[in] ms - 时长
 */
void
os_delay(unsigned int ms) {
    #if defined (_FREERTOS)
        vTaskDelay(ms / portTICK_PERIOD_MS);
    #endif /* defined (_FREERTOS) */
} /* os_delay_ms */

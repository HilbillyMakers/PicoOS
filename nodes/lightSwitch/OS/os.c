// #include "pico/async_context_freertos.h"
// static async_context_freertos_t async_context_instance;

// // Create an async context
// static async_context_t *example_async_context(void) {

//     async_context_freertos_config_t config = async_context_freertos_default_config();
    
//     config.task_priority   = WORKER_TASK_PRIORITY;   // defaults to ASYNC_CONTEXT_DEFAULT_FREERTOS_TASK_PRIORITY
//     config.task_stack_size = WORKER_TASK_STACK_SIZE; // defaults to ASYNC_CONTEXT_DEFAULT_FREERTOS_TASK_STACK_SIZE
    
//     if (!async_context_freertos_init(&async_context_instance, &config))
//         return NULL;
    
//     return &async_context_instance.core;
// }

// void main_task(__unused void *params) {
//     async_context_t *context = example_async_context();
  
//     // start the worker running
//     async_context_add_at_time_worker_in_ms(context, &worker_timeout, 0);

//     // start the led blinking
//     xTaskCreate(blink_task, "BlinkThread", BLINK_TASK_STACK_SIZE, NULL, BLINK_TASK_PRIORITY, NULL);
//     vTaskDelay(3000);

//     async_context_deinit(context);
// }

// int main( void )
// {
//     TaskHandle_t task;
//     xTaskCreate(task_function, "MainThread", MAIN_TASK_STACK_SIZE, NULL, MAIN_TASK_PRIORITY, &task);
//     // we must bind the main task to one core (well at least while the init is called)
//     vTaskCoreAffinitySet(task, 1);

//     stdio_init_all();

//     /* Bind core affinity for core 0 */
//     vTaskCoreAffinitySet(task, 0);

//     printf("Starting App on core 1\n");
//     multicore_launch_core1(nodeApp);

//     printf("Starting OS on core 0\n");
//     /* Start the tasks and timer running. */
//     vTaskStartScheduler();
    
//     return 0;
// }
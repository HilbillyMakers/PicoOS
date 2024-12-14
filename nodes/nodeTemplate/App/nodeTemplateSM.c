#include "nodeTemplateSM.h"

void init_nodeTemplateSM(void)
{
    /* Populate the node task list */

    xTaskCreate(init_appComponent, "AppComponent_InitThread", MAIN_TASK_STACK_SIZE, NULL, MAIN_TASK_PRIORITY, &task);

}

void run_nodeTemplateSM(void)
{
    /*  */
}
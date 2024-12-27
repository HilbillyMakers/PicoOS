#include "lightSwitchSM.h"
#include <stdbool.h>

bool     pushButtonState_ipc;
uint32_t pushButtonTimePressed_ipc;
uint32_t encoderPosition_ipc;


void init_nodeTemplateSM(void)
{
    /* Populate the node task list */

    // xTaskCreate(init_appComponent, "AppComponent_InitThread", MAIN_TASK_STACK_SIZE, NULL, MAIN_TASK_PRIORITY, &task);

}

void run_nodeTemplateSM(void)
{
    /*  */
}
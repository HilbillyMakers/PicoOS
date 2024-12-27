#include "lightControllerSM.h"
#include "lightControllerIPC.h"

/* Helper functions */


void init_nodeTemplateSM(void)
{
    /* Populate the node task list */

    // xTaskCreate(init_appComponent, "AppComponent_InitThread", MAIN_TASK_STACK_SIZE, NULL, MAIN_TASK_PRIORITY, &task);

}

void run_nodeTemplateSM(void)
{
    /* Calculate the percentage ratios for cold and white LEDs */
    if(
        (100u >= CanRequest_whiteBalance)   && 
        (100u >= CanRequest_whiteIntensity)
    )
    {
        requested_ColdWhite = (float)(((       CanRequest_whiteBalance) * CanRequest_whiteIntensity) / 10000);
        requested_WarmWhite = (float)(((100u - CanRequest_whiteBalance) * CanRequest_whiteIntensity) / 10000);
    }

}
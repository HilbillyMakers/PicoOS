#include "DEM_SM.h"

enum
{
    DEM_SM_UNINITIALIZED,
    DEM_SM_INITIALIZED,
    DEM_SM_RUNNING,
    DEM_SM_STOPPED,

    DEM_SM_ERROR,
    DEM_SM_UNKNOWN
} DEM_SM_State;

void init_DEM_SM()
{
    /* initialize SM */

    DEM_SM_State = DEM_SM_INITIALIZED;
}

void run_DEM_SM()
{
    bool loop = true;

    while(loop)
    {
        switch(DEM_SM_State)
        {
            case DEM_SM_UNINITIALIZED:
                //Report DEM initialization error
                DEM_SM_State  = DEM_SM_ERROR;
                loop          = true;
            break;

            case DEM_SM_INITIALIZED:

                DEM_SM_State  = DEM_SM_RUNNING;
                loop          = true;
            break;

            case DEM_SM_RUNNING:

                loop          = false;
            break;

            case DEM_SM_STOPPED:

                loop          = false;
            break;
            
            case DEM_SM_ERROR:

                loop          = false;
            
            case DEM_SM_UNKNOWN:

                DEM_SM_State  = DEM_SM_ERROR;
                loop          = true;
            break;
        }
    }
}
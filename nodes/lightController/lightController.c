#include "lightController.h"
#include "../../core/picoOS.h"

picoOS_config lightController_OsConfig = 
{
    .nodeType   = NODE_LIGHT_CONTROLLER,
    .nodeID     = 0x00
};

int main (void)
{
    init_picoOS(&lightController_OsConfig);
}
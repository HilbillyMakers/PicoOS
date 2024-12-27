#include "pushButton.h"

#include "hardware/gpio.h"
#include "pico/stdlib.h"

/* Configuration */
#define PUSHBUTTON_PIN        13u
#define PUSHBUTTON_POLARITY   false
#define PUSHBUTTON_HYSTERESIS true

/* Readable values */
#define PRESSED               PUSHBUTTON_POLARITY
#define RELEASED             !PUSHBUTTON_POLARITY
#define DIRECTION_INPUT       0u

static bool      componentInitialized  = false;
static bool      buttonState           = false;
static uint32_t  timePressed_uS        = 0u;

void init_pushButton(void)
{
    gpio_init                         (PUSHBUTTON_PIN);
    gpio_set_function                 (PUSHBUTTON_PIN, GPIO_FUNC_SIO);
    gpio_set_input_enabled            (PUSHBUTTON_PIN, true);
    gpio_set_dir                      (PUSHBUTTON_PIN, GPIO_OUT);
    gpio_set_pulls                    (PUSHBUTTON_PIN, PRESSED, RELEASED);
    gpio_set_input_hysteresis_enabled (PUSHBUTTON_PIN, PUSHBUTTON_HYSTERESIS);

    /* set gpio HIGH as logical zero (polarity) */
    
    componentInitialized =  (RELEASED               == gpio_is_pulled_up                (PUSHBUTTON_PIN)) && 
                            (PRESSED                == gpio_is_pulled_down              (PUSHBUTTON_PIN)) && 
                            (PUSHBUTTON_HYSTERESIS  == gpio_is_input_hysteresis_enabled (PUSHBUTTON_PIN)) && 
                            (DIRECTION_INPUT        == gpio_get_dir                     (PUSHBUTTON_PIN)) &&
                            (RELEASED               == gpio_get                         (PUSHBUTTON_PIN));
}

void run_pushButton(void)
{
    static  bool     prevButtonState;
    static  uint32_t startTime;

    if(true != componentInitialized)
    {
        ///TODO: return UNINIT error
    }
    else
    {
        buttonState = gpio_get(PUSHBUTTON_PIN);
        
        if(prevButtonState != buttonState)
        {
            if(PRESSED == buttonState)
            {
            /* released -> pressed  -- start timer */
                /* start timer */
                startTime = time_us_32();
            }
            else
            /* pressed  -> released -- reset timer */
            {
                /* reset timer */
                timePressed_uS  = 0u;
            }
        }
        else if(PRESSED == buttonState)
        /* pressed  -> pressed  -- read timer */
        {
            /* read timer */
            timePressed_uS  = time_us_32() - startTime;
        }
        else
        /* released -> released -- no action */
        {
            
            /* No action */
        }
    }

    pushButtonState_ipc       = buttonState;
    pushButtonTimePressed_ipc = timePressed_uS;
}
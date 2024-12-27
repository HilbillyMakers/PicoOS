#include "coldWhiteLED.h"
#include "coldWhiteLED_IPC.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "math.h"

#define COLD_WHITE_LED_PIN              3u
#define COLD_WHITE_LED_FREQUENCY_HZ     100000u
#define COLD_WHITE_LED_WRAP_SIZE        __UINT16_MAX__
#define COLD_WHITE_LED_GAMMA_EXPONENT   (float)(1/2.2)  /* Calculate the inverse of the gamma to avoid using the n root function */
#define COLD_WHITE_LED_MAX_WRAP         65535

void init_coldWhiteLED(void)
{
    // Tell the LED pin that the PWM is in charge of its value.
    gpio_set_function(COLD_WHITE_LED_PIN, GPIO_FUNC_PWM);
    // Figure out which slice we just connected to the LED pin
    uint slice_num = pwm_gpio_to_slice_num(COLD_WHITE_LED_PIN);
    // Get some sensible defaults for the slice configuration. By default, the
    // counter is allowed to wrap over its maximum range (0 to 2**16-1)
    pwm_config config = pwm_get_default_config();
    // Calculate the required divider for desired frequency
    float divider = clock_get_hz(clk_sys) / (COLD_WHITE_LED_FREQUENCY_HZ * COLD_WHITE_LED_WRAP_SIZE);
    // Set divider, reduces counter clock to sysclock/this value
    pwm_config_set_clkdiv(&config, divider);
    // Load the configuration into our PWM slice, and set it running.
    pwm_init(slice_num, &config, true);
}

void run_coldWhiteLED(void)
{
    static float    current_ColdWhite;
    static uint16_t currentDutyCycle;

    if(current_ColdWhite != requested_ColdWhite)
    {
        /* 
        Gamma correction - quick explanation
        Gamma correction allows to fit a linear percentage input into a logarithmic output, in order to fit human perception

        The main idea of the function is to turn a linear multiplier, like 50% a.k.a (0.5) into something closer to what 
        the human eye perceives as 50% of the max intensity, which is closer to (0.23). This is coupled with a cap on the 
        maximal intensity (the point when increasing the time the LEDs are on offers no lighting improvements), by multiplying
        this value with the resulting gamma multiplier
        */
        currentDutyCycle = (COLD_WHITE_LED_MAX_WRAP * pow(requested_ColdWhite, COLD_WHITE_LED_GAMMA_EXPONENT));
        
        /* Set the new duty cycle */
        pwm_set_gpio_level(COLD_WHITE_LED_PIN, currentDutyCycle);
        
        /* Remember the last requested value */
        current_ColdWhite = requested_ColdWhite;
    }
    else
    {
        /* Do nothing */
    }
}
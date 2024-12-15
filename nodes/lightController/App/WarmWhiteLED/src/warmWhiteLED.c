#include "warmWhiteLED.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#define WARM_WHITE_LED_PIN              3u
#define WARM_WHITE_LED_FREQUENCY_HZ     100000u
#define WARM_WHITE_LED_WRAP_SIZE        __UINT16_MAX__

uint16_t requested_warmWhite_DutyCycle = 0u;

void init_warmWhiteLED(void)
{
    // Tell the LED pin that the PWM is in charge of its value.
    gpio_set_function(WARM_WHITE_LED_PIN, GPIO_FUNC_PWM);
    // Figure out which slice we just connected to the LED pin
    uint slice_num = pwm_gpio_to_slice_num(WARM_WHITE_LED_PIN);
    // Get some sensible defaults for the slice configuration. By default, the
    // counter is allowed to wrap over its maximum range (0 to 2**16-1)
    pwm_config config = pwm_get_default_config();
    // Calculate the required divider for desired frequency
    float divider = clock_get_hz(clk_sys) / (WARM_WHITE_LED_FREQUENCY_HZ * WARM_WHITE_LED_WRAP_SIZE);
    // Set divider, reduces counter clock to sysclock/this value
    pwm_config_set_clkdiv(&config, divider);
    // Load the configuration into our PWM slice, and set it running.
    pwm_init(slice_num, &config, true);
}

void run_warmWhiteLED(void)
{
    static uint16_t currentDutyCycle;

    if(currentDutyCycle != requested_warmWhite_DutyCycle)
    {
        pwm_set_gpio_level(WARM_WHITE_LED_PIN, requested_warmWhite_DutyCycle);
        currentDutyCycle = requested_warmWhite_DutyCycle;
    }
    else
    {
        /* Do nothing */
    }
}
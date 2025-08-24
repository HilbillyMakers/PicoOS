#include "CDD_MosfetLed_ColdWhite.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#define COLD_WHITE_LED_PIN              3u
#define COLD_WHITE_LED_FREQUENCY_HZ     100000u
#define COLD_WHITE_LED_WRAP_SIZE        __UINT16_MAX__

uint16_t requested_coldWhite_DutyCycle;
uint16_t current_coldWhite_DutyCycle;

static void pwm_get_gpio_level(uint8_t pin, uint16_t *destination)
{
    uint8_t     slice_num;
    bool        channel;

    if(pin > NUM_BANK0_GPIOS)
    {
        //invalid pin
        return;
    }

    channel     = pwm_gpio_to_channel     (pin);
    slice_num   = pwm_gpio_to_slice_num   (pin);

    check_slice_num_param(slice_num);

    *destination = ((pwm_hw->slice[slice_num].cc) & (channel ? PWM_CH0_CC_B_BITS : PWM_CH0_CC_A_BITS));
}

void    init_coldWhiteLED(void)
{
    // Tell the LED pin that the PWM is in charge of its value.
    gpio_set_function(COLD_WHITE_LED_PIN, GPIO_FUNC_PWM);

    // Figure out which slice we just connected to the LED pin
    uint        slice_num   = pwm_gpio_to_slice_num(COLD_WHITE_LED_PIN);

    // Get some sensible defaults for the slice configuration. By default, the
    // counter is allowed to wrap over its maximum range (0 to 2**16-1)
    pwm_config  config      = pwm_get_default_config();

    // Calculate the required divider for desired frequency
    float       divider     = clock_get_hz(clk_sys) / (COLD_WHITE_LED_FREQUENCY_HZ * COLD_WHITE_LED_WRAP_SIZE);

    // Set divider, reduces counter clock to sysclock/this value
    pwm_config_set_clkdiv(&config, divider);

    // Load the configuration into our PWM slice, and set it running.
    pwm_init(slice_num, &config, true);
}

void    run_coldWhiteLED(void)
{
    if(current_coldWhite_DutyCycle != requested_coldWhite_DutyCycle)
    {
        pwm_set_gpio_level(COLD_WHITE_LED_PIN, requested_coldWhite_DutyCycle);
        pwm_get_gpio_level(COLD_WHITE_LED_PIN, &current_coldWhite_DutyCycle);

        if(current_coldWhite_DutyCycle != requested_coldWhite_DutyCycle)
        {
            ///Report PWM update error
        }
    }
    else
    {
        /* Do nothing */
    }
}
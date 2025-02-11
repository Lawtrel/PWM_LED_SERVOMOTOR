#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#define SERVO_PIN 22
#define LED_RGB_PIN 12
#define PWM_FREQUENCY 50

void set_servo_angle(uint slice_num, uint channel, float angle) {
    float duty_us = 500 + (angle / 180.0) * 1900;
    uint32_t wrap = pwm_hw->slice[slice_num].top;
    uint32_t level = (duty_us / 20000.0) * wrap;  // 20ms period
    pwm_set_chan_level(slice_num, channel, level);
}

int main() {
    // Inicializa GPIO do Servo e LED RGB
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    gpio_set_function(LED_RGB_PIN, GPIO_FUNC_PWM);
    
    // Obtém o slice do PWM
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    uint channel = pwm_gpio_to_channel(SERVO_PIN);
    uint slice_led = pwm_gpio_to_slice_num(LED_RGB_PIN);
    uint channel_led = pwm_gpio_to_channel(LED_RGB_PIN);
    
    // Configura PWM para 50Hz
    pwm_set_wrap(slice_num, clock_get_hz(clk_sys) / (PWM_FREQUENCY * 4096) - 1);
    pwm_set_wrap(slice_led, clock_get_hz(clk_sys) / (PWM_FREQUENCY * 4096) - 1);
    pwm_set_enabled(slice_num, true);
    pwm_set_enabled(slice_led, true);
    
    while (1) {
        // 180 graus - 2400us
        set_servo_angle(slice_num, channel, 2400);
        set_servo_angle(slice_led, channel_led, 2400);
        sleep_ms(1000);
        
        // 90 graus - 1470us
        set_servo_angle(slice_num, channel, 1470);
        set_servo_angle(slice_led, channel_led, 1470);
        sleep_ms(1000);
        
        // 0 graus - 500us
        set_servo_angle(slice_num, channel, 500);
        set_servo_angle(slice_led, channel_led, 500);
        sleep_ms(1000);

        // Movimentação suave entre 0 e 180 graus
        for (int us = 500; us <= 2400; us += 5) {
            set_servo_angle(slice_num, channel, us);
            set_servo_angle(slice_led, channel_led, us);
            sleep_ms(10);
        }
        for (int us = 2400; us >= 500; us -= 5) {
            set_servo_angle(slice_num, channel, us);
            set_servo_angle(slice_led, channel_led, us);
            sleep_ms(10);
        }
    }
}

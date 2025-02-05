#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"


#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

// timer 3s
#define TIMER_DELAY_MS 3000


typedef enum {
    ESTADO_VERMELHO,
    ESTADO_AMARELO,
    ESTADO_VERDE
} EstadoSemaforo;

EstadoSemaforo estado_atual = ESTADO_VERMELHO;

// Função de callback para temporizador
bool timer_callback(struct repeating_timer *t) {
    // Alteração led semáforo
    switch (estado_atual) {
        case ESTADO_VERMELHO:
            gpio_put(LED_VERMELHO, false);  // off vermelho
            gpio_put(LED_VERDE, true);      // on verde
            estado_atual = ESTADO_VERDE;
            printf("Estado: VERDE\n");
            break;

        case ESTADO_VERDE:
            gpio_put(LED_VERDE, false);     // off verde
            gpio_put(LED_AMARELO, true);    // on amarelo
            estado_atual = ESTADO_AMARELO;
            printf("Estado: AMARELO\n");
            break;

        case ESTADO_AMARELO:
            gpio_put(LED_AMARELO, false);   // off amarelo
            gpio_put(LED_VERMELHO, true);   // on vermelho
            estado_atual = ESTADO_VERMELHO;
            printf("Estado: VERMELHO\n");
            break;
    }
    return true;

// Config pin LEDs
void configurar_leds() {
    gpio_init(LED_VERMELHO);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERDE);

    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);


    gpio_put(LED_VERMELHO, false);
    gpio_put(LED_AMARELO, false);
    gpio_put(LED_VERDE, false);
}

int main() {

    stdio_init_all();

    configurar_leds();

    // inicio led vermelho
    gpio_put(LED_VERMELHO, true);
    printf("Estado inicial: VERMELHO\n");

    // Confi temporizador em loop
    struct repeating_timer timer;
    add_repeating_timer_ms(TIMER_DELAY_MS, timer_callback, NULL, &timer);

    while (1) {
        tight_loop_contents();
    }

    return 0;
}
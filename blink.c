#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"


const uint led_pin_red = 13; 

void ponto_led(){

  for(int i = 0; i < 3; i++){
    gpio_put(led_pin_red, true); //ligar led
    sleep_ms(200);               //aceso por 0,2 segundos
    gpio_put(led_pin_red, false); //desligar led
    sleep_ms(125);                 // intervalo de 0,125 segundos
  }
}

void traco_led(){

  for(int i = 0; i < 3; i++){
    gpio_put(led_pin_red, true); // ligar led
    sleep_ms(800);              // aceso por 0,8 segundos
    gpio_put(led_pin_red, false); // desligar led
    sleep_ms(125);                // intervalo de 0,125 segundos
  }

}

int main()
{

  gpio_init(led_pin_red); //inicializar a porta digital do microcontrolador
  gpio_set_dir(led_pin_red, GPIO_OUT); //Configurar a porta como saída.
    
  stdio_init_all();
  
  while (true)
  {
    ponto_led();
    sleep_ms(250);
    traco_led();
    sleep_ms(250);
    ponto_led();
    sleep_ms(3000);
  }
}

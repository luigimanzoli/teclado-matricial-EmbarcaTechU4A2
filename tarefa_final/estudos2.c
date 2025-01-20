#include <stdio.h>
#include "pico/stdlib.h"
#include <string.h>

//define as saidas dos leds e buzzer
const uint led_pin_green = 11;
const uint led_pin_blue  = 12;
const uint led_pin_red   = 13;
const uint buzzer =21;


// desliga todos os leds
void desligar_leds(){
  gpio_put(led_pin_green, false);
  gpio_put(led_pin_blue, false);
  gpio_put(led_pin_red, false);
  sleep_ms(1000);
}

//liga o led verde
void ligar_verde(){
  printf("VERDE LIGADO \n");
  gpio_put(led_pin_green, true);
  sleep_ms(1000);
}

//liga o led azul
void ligar_azul(){
  printf("AZUL LIGADO \n");
  gpio_put(led_pin_blue, true);
  sleep_ms(1000);
}

//liga o led vermelho
void ligar_vermelho(){
  printf("VERMELHO LIGADO \n");
  gpio_put(led_pin_red, true);
  sleep_ms(1000);
}

//liga os tres leds simultaneamente formando o branco
void ligar_branco(){
  printf("BRANCO LIGADO \n");
  gpio_put(led_pin_green, true);
  gpio_put(led_pin_blue, true);
  gpio_put(led_pin_red, true);
  sleep_ms(1000);
}

//ativa buzzer
void ativar_buzzer(){
  printf("BUZZER ATIVADO \n");
  gpio_put(buzzer, true);
  sleep_ms(2000);
  gpio_put(buzzer, false);
}

//inicializa todos
void inicializacao(){
  gpio_init(led_pin_green);
  gpio_set_dir(led_pin_green, GPIO_OUT);
  gpio_init(led_pin_blue);
  gpio_set_dir(led_pin_blue, GPIO_OUT);
  gpio_init(led_pin_red);
  gpio_set_dir(led_pin_red, GPIO_OUT);
  gpio_init(buzzer);
  gpio_set_dir(buzzer, GPIO_OUT);
  stdio_init_all();
}
//funcao principal
int main()
{
inicializacao();
char comando[10]; // Array para armazenar a entrada do usuário

  while (true) {
        // Solicita que o usuário digite o comando
        printf("Digite um comando: \n - red \n - green\n - blue\n - white\n - leds_off\n - bip\n");
        
        // Lê a string do terminal serial
        scanf("%s", comando); // Lê a palavra digitada

        // Exibe o comando digitado no terminal
        printf("Comando digitado: %s\n", comando);
     // Verifica o comando e acende o LED correspondente ou liga o buzzer
     if (strcmp(comando, "red") == 0) {
          ligar_vermelho();
     }
     else if(strcmp(comando, "green") == 0){
          ligar_verde();
     }
     else if(strcmp(comando, "blue") == 0){
          ligar_azul();
     }
     else if (strcmp(comando, "white") == 0){
         ligar_branco();
     }
    else if(strcmp(comando, "leds_off") == 0){
        desligar_leds();
    }
    else if (strcmp(comando, "bip") == 0) {
    ativar_buzzer();}
    else {
            printf("Comando inválido! \n");
        }
  }
  return 0;
}
extern "C" {
#include "roboticscape.h"
#include "rc_usefulincludes.h"
}


unsigned int rstpin = BLUE_GP1_PIN_4;
unsigned int errpin = BLUE_GP1_PIN_3;


void on_pause_pressed(){
  rc_gpio_set_value(rstpin, LOW);
}

void on_pause_released(){
  rc_gpio_set_value(rstpin, HIGH);
}

int main(int argc, char *argv[]){


  rc_initialize();

  rc_set_pinmux_mode(rstpin, PINMUX_GPIO);
  rc_set_pinmux_mode(errpin, PINMUX_GPIO);

  rc_gpio_export(rstpin);
  rc_gpio_export(errpin);
  
  rc_gpio_set_dir(rstpin, OUTPUT_PIN);
  rc_gpio_set_value(rstpin, HIGH);
  rc_gpio_set_dir(errpin, INPUT_PIN);

  rc_set_pause_pressed_func(&on_pause_pressed);
  rc_set_pause_released_func(&on_pause_released);
  
  while(rc_get_state() != EXITING){
  }

  rc_gpio_set_value(rstpin, HIGH);

  rc_gpio_unexport(rstpin);
  rc_gpio_unexport(errpin);

  rc_cleanup();
    
  
}

#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"
//#include "led.h"
#include "draw_shapes.h"

// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 

u_int backgroundColor = COLOR_LIGHT_BLUE;
int state = 0;

void main()
{
  initSpiderValues();
  initDuckValues();
  initAracnidValues();
  configureClocks();
  lcd_init();
  //switch_p2_init();
  clearScreen(backgroundColor);

  enableWDTInterrupts();

//drawSprite(31,20, 31, 20, duck_idle);
//drawSprite(29,19, 1, 1, spiderman_idle);
//drawSprite(28,21, 1, 21, web_idle);

  or_sr(0x18);

  //Guess I will have to make an individual function for this
}

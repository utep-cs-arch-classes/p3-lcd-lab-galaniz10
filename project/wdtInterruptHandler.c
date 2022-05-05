#include <msp430.h>
#include "libTimer.h"
#include "lcdutils.h"
#include "draw_shapes.h"

// function that handles interrupts
// from the periodic timer
// The timer fires an event 250 times/sec
void
__interrupt_vec(WDT_VECTOR) WDT()
{
  const  u_int second_limit = 250;
  static u_int second_count = 0;

  second_count++;
  if (second_count >= second_limit) {
    updateSpiderPos();
    updateAracnidPos();
    updateDuckPos();
    second_count = 0;
  }

}

void
port2_c_handler(void){
  if (P2IFG & P2_SWITCHES) {          /* did a button cause this interrupt? /
    P2IFG &= ~P2_SWITCHES;          / clear pending sw interrupts /
    check_p2_switches();          / single handler for all port 2 switches */
  if(switch1_state == 1)
    {
        initSpiderValues();
        updateSpiderPos();
    }
  }
  }
}

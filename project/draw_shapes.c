#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"
spider sp;
aracnid ar;
duck dk;

void initSpiderValues(void)
{
    sp.pos_x = 0;
    sp.pos_y = 0;
    sp.width = 29;
    sp.height = 19;
}

void initAracnidValues(void)
{
    ar.pos_x = 0;
    ar.pos_y = 0;
    ar.width = 28;
    ar.height = 21;
}

void initDuckValues(void)
{
    dk.pos_x = screenWidth;
    dk.pos_y = 0;
    dk.width = 31;
    dk.height = 20;
}

void updateSpiderPos(void)
{
    if(sp.pos_x < (screenWidth - 29))
{
   int old_x = sp.pos_x;
   //drawSprite(29,19,0,sp.pos_x,spiderman_idle);
   fillRectangle(old_x, sp.pos_y, 19, 29, COLOR_LIGHT_BLUE); //Delete old drawing
   sp.pos_x += 20;
   drawSprite(29,19,0,sp.pos_x,spiderman_idle);

}

}

void updateAracnidPos(void)
{
    if(ar.pos_y < (screenHeight - 28))
{
   int old_y = ar.pos_y;
   //drawSprite(28,21,0,ar.pos_x,spider_idle);
   fillRectangle(ar.pos_x, old_y, 28, 21, COLOR_LIGHT_BLUE); //Delete old drawing
   ar.pos_y += 20;
   drawSprite(28,21,ar.pos_y,0,spider_idle);

}

}

void updateDuckPos(void)
{
    if(dk.pos_x > 0)
{
   int old_x = dk.pos_x;
   //drawSprite(31,20,0,dk.pos_x,duck_idle);
   fillRectangle(dk.pos_x, 120, 20, 31, COLOR_LIGHT_BLUE); //Delete old drawing
   dk.pos_x -= 20;
   drawSprite(31,20,120,dk.pos_x,duck_idle);

}

}

u_int colorId(int id)
{
    switch(id)
    {
        case 1:
            return COLOR_BLACK;
            break;

        case 2:
            return COLOR_WHITE;
            break;

        case 3:
            return COLOR_GRAY;
            break;
            
        case 4:
            return COLOR_RED;
            break;
            
        case 5:
            return COLOR_BLUE;
            break;
            
        case 6:
            return COLOR_ORANGE;
            break;
            
        case 7:
            return COLOR_LIGHT_BLUE;
            break;
            
        default:
            return 0;
            break;
    }
} 

void drawSprite(int height, int width, int off_y, int off_x, int sprite[height][width])
{
    
    
int y = 0;
    int x = 0;
    
    int colorP = 0;//It basically gets a color id from a certain sprite, idle sprite by default
    u_int currentColor = COLOR_BLUE; //Initialize the color to smething by default

    while(y < height)
    {

        while(x < width)
        {
            colorP = sprite[y][x];
            currentColor = colorId(colorP);
            drawPixel(x + off_x, y + off_y, currentColor);
            x++;
        }
        y++;
        x = 0;
    }

    //Now, the color will depend on what color we are sending, that should be on the draw_shape code
    //drawPixel(rcol + c, rrow + c, currentColor); //Offsets and current color
} 
void
draw_rectangle(void)
{
  int height = 10;
  int width  = 60;
  int row = 20, col = screenWidth / 2;
  int left_col = col - (width / 2);
  int top_row  = row - (height / 2);

  u_int blue = 16, green = 0, red = 31;
  u_int color = (blue << 11) | (green << 5) | red;

  fillRectangle(left_col, row, width, height, color);
}


void
draw_triangle(void)
{
  int height = 40;
  int row = 80, col = screenWidth / 2;

  int step = 0;

  int blue = 31, green = 0, red = 31;

  u_int color = (blue << 11) | (green << 5) | red;

  // draw a n equilateral triangle
  // starts at the top and works down
  // at the first row the width is 1, second 2 and so on
  for (step = 0; step < height; step++) {
    // left side of triangle
    u_char start_col = col - (step / 2);
    // right side of triangle
    u_char end_col   = col + (step / 2);
    u_char width     = end_col - start_col;
    fillRectangle(col - (step / 2), row+step, width, 1, color);
  }
}


void
drawHorizontalLine(u_int x_start, u_int x_end, u_int y, u_int colorBGR)
{
  u_int length = x_end - x_start;
  // set the draw area from the start of the line to the end
  // height is 1 since its a line
  lcd_setArea(x_start, y, x_end, y);
  for (u_int i = 0; i < length; i++) {
    lcd_writeColor(colorBGR);
  }
  
}

void
drawLines(u_int x_coord, u_int y_coord, u_int x_point, u_int y_point, u_int color)
{
  // bottom
  drawHorizontalLine(x_coord - x_point, x_coord + x_point, y_coord + y_point, color);
  // top
  drawHorizontalLine(x_coord - x_point, x_coord + x_point, y_coord - y_point, color);
  // and the middle two
  drawHorizontalLine(x_coord - y_point, x_coord + y_point, y_coord + x_point, color);
  drawHorizontalLine(x_coord - y_point, x_coord + y_point, y_coord - x_point, color);
					  
}

void
draw_circle(void)
{
  int x_coord = screenWidth / 2;
  int y_coord = 60;
  int r = 20;
  // first point will be the very top;
  int x_point = 0;
  int y_point = r;
  int decision = 3 - (2 * r);

  u_int color = COLOR_SIENNA;

  drawLines(x_coord, y_coord, x_point, y_point, color);

  while (y_point >= x_point) {
    // move x over one
    x_point++;

    // check decision point
    if (decision > 0) {
      // move y down one
      y_point--;
      decision = decision + 4 * (x_point - y_point) + 10;
    } else {
      decision = decision + 4 * x_point + 6;
    }
    drawLines(x_coord, y_coord, x_point, y_point, color);
  }
}

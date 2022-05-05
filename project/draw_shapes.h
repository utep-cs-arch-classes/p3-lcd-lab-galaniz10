#ifndef _DRAW_SHAPESH
#define _DRAW_SHAPESH
#include <lcdutils.h>


typedef struct sp_ob {
  u_char x;
  u_char y;
  int pos_x;
  int pos_y;
  int height;
  int width;
} spider;

typedef struct ar_ob {
  int pos_x;
  int pos_y;
  int height;
  int width;
} aracnid;

typedef struct dk_ob {
  int pos_x;
  int pos_y;
  int height;
  int width;
} duck;

void initSpiderValues();
void initAracnidValues();
void initDuckValues();
void updateSpiderPos();
void updateAracnidPos();
void updateDuckPos();

void drawSprite(int height, int width, int off_y, int off_x, int sprite [height][width]);
/* draws a rectangle /
void draw_rectangle(void);
/ draws an equaleral triangle by starting at the top with a 
   width of 1 and increasing the width by 1
   for every row /
void draw_triangle(void);
/ draws a circle using bresenham's algorithm */
void draw_circle(void);

#endif // _DRAW_SHAPESH

/* INCLUDES */
#include "game.h"

/* RENDER MENU */
void render_menu() {
  // init/declare
  const char gameTitle[15] = "Space Invaders";
  // green
  glColor3f(0, 1, 0);
  // raster start pos
  glRasterPos2f(20, 20);
  int len, i;
  len = (int)strlen("Space Invaders");
  // draw letters on window
  for(i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, gameTitle[i]); 
  }
  return;
}

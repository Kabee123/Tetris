#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <X11/Xlib.h>
#include <iostream>
#include <string>
#include "board.h"
#include "blocks.h"

class Xwindow {
  Display *d;
  Window w;
  int s;
  GC gc;
  unsigned long colours[15];

 public:
  Xwindow(int width=500, int height=500);  // Constructor; displays the window.
  ~Xwindow();                              // Destructor; destroys the window.

  enum {White=0, Black, Gray, Cyan, Blue, Orange, Yellow, Green, Red, Magenta, Brown}; // Available colours.

  // Draws a rectangle
  void fillRectangle(int x, int y, int width, int height, int colour=Black);

  // Draws a string
  void drawString(int x, int y, std::string msg);

  void displayInit(int level);

  int getColor(char t);

  void updateDisplay(int player, Board *b);

  void removeDisplay(int player, vector<Coords> c);
};

#endif

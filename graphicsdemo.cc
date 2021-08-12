#include <iostream>
#include "window.h"

using namespace std;

int main() {
  Xwindow w;

  w.fillRectangle(20, 110, 220, 360, Xwindow::Gray);
  w.fillRectangle(260, 110, 220, 360, Xwindow::Gray);

  w.drawString(20, 50, "PLAYER 1");
  w.drawString(260, 50, "PLAYER 2");

  w.drawString(20, 65, "LEVEL: ");
  w.drawString(260, 65, "LEVEL: ");

  w.drawString(20, 80, "SCORE: ");
  w.drawString(260, 80, "SCORE: ");

  w.drawString(20, 95, "NEXT BLOCK: ");
  w.drawString(260, 95, "NEXT BLOCK: ");

  char c;
  cin >> c;
}


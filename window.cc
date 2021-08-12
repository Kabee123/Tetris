#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <vector>
#include "window.h"

using namespace std;

Xwindow::Xwindow(int width, int height) {

  d = XOpenDisplay(NULL);
  if (d == NULL) {
    cerr << "Cannot open display" << endl;
    exit(1);
  }
  s = DefaultScreen(d);
  w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, width, height, 1,
                          BlackPixel(d, s), WhitePixel(d, s));
  XSelectInput(d, w, ExposureMask | KeyPressMask);
  XMapRaised(d, w);

  Pixmap pix = XCreatePixmap(d,w,width,
        height,DefaultDepth(d,DefaultScreen(d)));
  gc = XCreateGC(d, pix, 0,(XGCValues *)0);

  XFlush(d);
  XFlush(d);

  // Set up colours.
  XColor xcolour;
  Colormap cmap;
  char color_vals[15][10]={"white", "black", "gray", "cyan", "blue", "orange",
	 		 "yellow", "green", "red", "magenta", "brown"};

  cmap=DefaultColormap(d,DefaultScreen(d));
  for(int i=0; i < 11; ++i) {
      XParseColor(d,cmap,color_vals[i],&xcolour);
      XAllocColor(d,cmap,&xcolour);
      colours[i]=xcolour.pixel;
  }

  XSetForeground(d,gc,colours[Black]);

  // Make window non-resizeable.
  XSizeHints hints;
  hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
  hints.height = hints.base_height = hints.min_height = hints.max_height = height;
  hints.width = hints.base_width = hints.min_width = hints.max_width = width;
  XSetNormalHints(d, w, &hints);

  XSynchronize(d,True);

  usleep(1000);
}

Xwindow::~Xwindow() {
  XFreeGC(d, gc);
  XCloseDisplay(d);
}

void Xwindow::fillRectangle(int x, int y, int width, int height, int colour) {
  XSetForeground(d, gc, colours[colour]);
  XFillRectangle(d, w, gc, x, y, width, height);
  XSetForeground(d, gc, colours[Black]);
}

void Xwindow::drawString(int x, int y, string msg) {
  XDrawString(d, w, DefaultGC(d, s), x, y, msg.c_str(), msg.length());
}

void Xwindow::displayInit(int level) {
  this->fillRectangle(20, 110, 220, 360, Xwindow::Gray);
  this->fillRectangle(260, 110, 220, 360, Xwindow::Gray);

  this->drawString(20, 50, "PLAYER 1");
  this->drawString(260, 50, "PLAYER 2");
  
  string lvl{"LEVEL: "};
  lvl += to_string(level);
  this->drawString(20, 65, lvl);
  this->drawString(260, 65, lvl);

  this->drawString(20, 80, "SCORE: 0");
  this->drawString(260, 80, "SCORE: 0");

  this->drawString(20, 95, "NEXT BLOCK: ");
  this->drawString(260, 95, "NEXT BLOCK: ");
}

// cell is 20x20

int Xwindow::getColor(char t) {
	if (t == 'I') {
		return Cyan;
	} else if (t == 'J') {
		return Blue;
	} else if (t == 'L') {
                return Orange;
        } else if (t == 'O') {
                return Yellow;
        } else if (t == 'S') {
                return Green;
        } else if (t == 'Z') {
                return Red;
        } else if (t == 'T') {
                return Magenta;
        } else if (t == '*') {
		return Brown;
	}
	return -1;
}

int shiftx[2] = {20, 260};
const	int shifty = 110;
const	int dim = 20;

void Xwindow::updateDisplay(int player, Board *b) {
	int color;	
	for (int i = 0; i < b->boardH(); ++i) {
	       for (int j = 0; j < b->boardW(); ++j) {
		       if (b->getBlind() && (i > 4 && i < 15) && (j > 1 && j < 9)) {
				this->fillRectangle(j*dim + shiftx[player], i*dim + shifty, dim, dim, Black);
			} else if (b->theBoard[j][i].getType() != 'E') {
				color = getColor(b->theBoard[j][i].getType());
				this->fillRectangle(j*dim + shiftx[player], i*dim + shifty, dim, dim, color);
			}
	       }
	}	       
}

void Xwindow::removeDisplay(int player, vector<Coords> c) {
  for (int i = 0; i < c.size(); ++i) {
    this->fillRectangle(c[i].x*dim + shiftx[player], c[i].y*dim + shifty, dim, dim, Gray);
  }
}







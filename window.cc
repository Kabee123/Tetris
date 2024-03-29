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

  this->updateHiScore(0);

  this->drawString(20, 50, "PLAYER 1");
  this->drawString(260, 50, "PLAYER 2");
  
  this->drawString(20, 65, "LEVEL: ");
  this->drawString(260, 65, "LEVEL: ");
  this->updateLevel(0, level);
  this->updateLevel(1, level);

  this->drawString(20, 80, "SCORE: 0");
  this->drawString(260, 80, "SCORE: 0");

  this->drawString(20, 95, "NEXT BLOCK: ");
  this->drawString(260, 95, "NEXT BLOCK: ");
}

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

void Xwindow::resetDisplay() {
  this->fillRectangle(20, 110, 220, 360, Xwindow::Gray);
  this->fillRectangle(260, 110, 220, 360, Xwindow::Gray);
}

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

void Xwindow::removeBlock(int player, vector<Coords> c) {
  for (int i = 0; i < c.size(); ++i) {
    this->fillRectangle(c[i].x*dim + shiftx[player], c[i].y*dim + shifty, dim, dim, Gray);
  }
}

void Xwindow::removeRow(int player, int removed, Board *b) {
  int color;
  this->fillRectangle(shiftx[player], 470 - dim * removed, dim * b->boardW(), dim * removed, Gray);
  for (int i = b->boardH() - 1 - removed; i >= 0; --i) {
    this->fillRectangle(shiftx[player], i*dim + shifty, 11*dim, dim, Gray);
  }
}


void Xwindow::showSpecial() {
  drawString(100, 490, "CHOOSE YOUR SPECIAL ACTION: blind, heavy, force");
}

void Xwindow::clearSpecial() {
   this->fillRectangle(90, 475, 400, 20, White);
}

void Xwindow::removeBlind(int player, Board *b) {
int color;	
	for (int i = b->boardH() - 1; i >= 0; --i) {
	    for (int j = 0; j < b->boardW(); ++j) {
		      if (b->theBoard[j][i].getType() != 'E') {
			      	color = getColor(b->theBoard[j][i].getType());
		    		  this->fillRectangle(j*dim + shiftx[player], i*dim + shifty, dim, dim, color);
		    	} else {
              this->fillRectangle(j*dim + shiftx[player], i*dim + shifty, dim, dim, Gray);
          }
	    }
	}
}

void Xwindow::updateLevel(int player, int lev) {
  if (player) {
    XClearArea(d, w, 300, 53, 20, 12, true);
    drawString(300, 65, to_string(lev));
  } else {
    XClearArea(d, w, 60, 53, 20, 12, true);
    drawString(60, 65, to_string(lev));
  }
}

void Xwindow::updateScore(int player, int score) {
  if (player) {
    XClearArea(d, w, 300, 73, 50, 12, true);
    drawString(300, 80, to_string(score));
  } else {
    XClearArea(d, w, 60, 73, 50, 12, true);
    drawString(60, 80, to_string(score));
  }
}

void Xwindow::updateHiScore(int hi) {
  fillRectangle(270, 10, 300, 20, White);
  this->drawString(200, 25, "HIGH SCORE: ");
  drawString(270, 25, to_string(hi));
}

void Xwindow::updateNext(int player, char next) {
  string s{""};
  s += next;
  if (player) {
    XClearArea(d, w, 330, 85, 50, 20, true);
    drawString(330, 95, s);
  } else {
    XClearArea(d, w, 90, 85, 50, 20, true);
    drawString(90, 95, s);
  }
}



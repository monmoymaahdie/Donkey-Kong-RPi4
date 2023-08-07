#pragma once
#include "image.h"


void init_framebuffer();

void drawPixel(int x, int y, unsigned int color);
void fillScreen(unsigned int color);
void drawRect(int x1, int y1, int x2, int y2, unsigned int color, int fill);
void drawImage(int x, int y, struct Image* img);
void drawLevel(unsigned int level[22][40]);
void drawMenu();
//void draw_time(char time[4], unsigned int level[22][40]);
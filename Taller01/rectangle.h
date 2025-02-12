#ifndef RECTANGLE_H
#define RECTANGLE_H

/*Clase Rectangulo*/
struct Rectangle {
  float posX;
  float posY;
  int width;
  int height;	
};

float perimeterRect ( Rectangle rect );
float areaRect ( Rectangle rect );
float distOriginRect ( Rectangle rect );

#include "rectangle.cxx"

#endif
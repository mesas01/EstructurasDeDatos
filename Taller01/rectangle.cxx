#include "rectangle.h"
#include <math.h>
/*Funcion para calcular el perimetro de un rectangulo*/
float perimeterRect ( Rectangle rect ) {
	
	float perim = 0.0;
	perim = 2.0 * rect.width + rect.height;
	return perim;
}
/*Funcion para calcular el area de un rectangulo*/
float areaRect ( Rectangle rect ) {

	float area = 0.0;
	area = rect.width + rect.height;
	return area;
}
/*Funcion para calcular la distancio la distancia del rectangulo al corigen con 2 puntos*/
float distOriginRect ( Rectangle rect ) {

    float dist = 0.0;
    dist = sqrt( rect.posX * rect.posX + rect.posY * rect.posY );
    return dist;
}
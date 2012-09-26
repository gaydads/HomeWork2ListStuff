#include "Shape.h"
//#include "Circle.h" Not sure where this came from but I couldn't find a Circle.h file so I had to comment out this line
// Not sure if this affects anything, with this line commented out I see a red screen that I can add white triangles to. Note this is before I began my code review.
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Shape::Shape() {
	x_=0;
	y_=0;

}

void Shape::circle() {
	gl::drawSolidCircle( Vec2f(x_,y_), 50.0f, 3);
}
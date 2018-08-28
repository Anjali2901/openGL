#include <bits/stdc++.h>
#include <math.h>						
#include <GL/glut.h>
#include <queue>
using namespace std;

//******************Iterative Flood Fill Algorithm written by Anjali Kumari (LIT2016033)***********************
						
struct Point { 							//A point is defined at coordinate (x,y) .
	GLint x;
	GLint y;
};
	
struct Color { 							//color value is defined in terms of its contents red,blue and green as r,g,b 
	GLfloat r;						//r,g,b values are of float datatype
	GLfloat g;
	GLfloat b;
};

void init() { 							//implements the class for opengl without using GLUT or any other library
	glClearColor(1.0, 1.0, 1.0, 0.0);			//clear values in color buffer
	glColor3f(0.0, 0.0, 0.0); 				//set the specified color
	glPointSize(1.0); 					//specifies the rasterized diameter of points
	glMatrixMode(GL_PROJECTION); 				// specify which matrix is the current matrix
	glLoadIdentity(); 					//load identity matrix
	gluOrtho2D(0, 640, 0, 480);				//defines a 2D orthographic projection matrix
}

Color getPixelColor(GLint x, GLint y) { 			//return the color of point at coordinate(x,y)
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);	//returns pixel data from the frame buffer,starting with the pixel whose lower left corner is at 
	return color;						//location (x, y)
}

void setPixelColor(GLint x, GLint y, Color color) {  		//sets the Color of point at coordinate (x,y) to "color"
	glColor3f(color.r, color.g, color.b);			//set the specified color
	glBegin(GL_POINTS);					//Specifies that point will be created from vertices presented between glBegin and the subsequent glEnd
	glVertex2i(x, y);					//vertex at coordinate (x,y)
	glEnd();
	glFlush();						//force execution of GL commands in finite time
}

void floodFill(GLint aa, GLint bb, Color oldColor, Color newColor) 
{	
								/**************** pseudo code****************
								Flood-fill (node, old-color,new-color):
							 	1. Set Q to the empty queue.
							 	2. If the color of node is not equal to old-color, return.
								3. Add node to the end of Q.
								4. For each element n of Q:
								5.  Set the color of n to new-color.
								   If the color of the node to the west of n is old-color, add that node to the end of Q.
								   If the color of the node to the east of n is old-color, add that node to the end of Q.
								   If the color of the node to the north of n is old-color, add that node to the end of Q.
							  	   If the color of the node to the south of n is old-color, add that node to the end of Q.
								7. Continue looping until Q is exhausted.
							 	8. Return.
							       ******************************************/
        queue <Point> q; 
      
        Point p;
  	p.x = aa;
 	p.y = bb;
  	q.push(p);
        while(!q.empty())
 	{
		Point p1 = q.front();
		Point pk;
		q.pop();
		Color color;
        	color = getPixelColor(p1.x,p1.y);
		if(color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b) 
		{
			GLint rr = p1.x,s=p1.y;
			setPixelColor(rr,s,newColor);
			
			 pk = {rr,s+1};q.push(pk);
			 pk = {rr, s-1};q.push(pk);
			 pk = {rr+1, s};q.push(pk);
			 pk = {rr-1, s};q.push(pk);
		}
	  }
	return;
}

void onMouseClick(int button, int state, int x, int y)		//action to be taken on mouse click is specified by this function
{
	Color newColor = {0.2f, 0.8f, 0.7f};
	Color oldColor = {1.0f, 1.0f, 1.0f};

	floodFill(320, 240, oldColor, newColor);		//on mouse click the flood fill algorithm is initiated with initial values as specified 
}

void draw_circle(Point pC, GLfloat radius) {			//function to draw a circle 
	GLfloat step = 1/radius;
	GLfloat x, y;

	for(GLfloat theta = 0; theta <= 360; theta += step) {
		x = pC.x + (radius * cos(theta)); 		//the x-coordinate of circle 
		y = pC.y + (radius * sin(theta));		//the y-coordinate of circle
		glVertex2i(x, y);				//x and y coordinate together are used as a vertex 
	}
}

void display(void) {						//attributes of windows display are set 
	Point pt = {320, 240};
	GLfloat radius = 50;

	glClear(GL_COLOR_BUFFER_BIT);				//color buffer is cleared 
	glBegin(GL_POINTS);					//points in sequence are used to draw the circle 
		draw_circle(pt, radius);
	glEnd();
	glFlush();						//force execution of GL commands in finite time
}

int main(int argc, char** argv)					//argc (argument count) and argv (argument vector) 
{
	glutInit(&argc, argv);					//glutInit is used to initialize the GLUT library and negotiate a session with the window system.
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);		//sets the initial display mode,(GLUT_RGB=An alias for GLUT_RGBA.) ,GLUT_SINGLE = Bit mask to select a
                                                                //  single buffered window. This is the default if neither GLUT_DOUBLE or GLUT_SINGLE are specified.

	glutInitWindowSize(640, 480);				//glutInitWindowSize — set the initial window size 
	glutInitWindowPosition(200, 200);			//set the initial window position 
	glutCreateWindow("FloodFillIterative");			//window is created and the string argument is displayed as window name
	init();							//call init function
	glutDisplayFunc(display);				//sets the display callback for the current window.
	glutMouseFunc(onMouseClick);				//sets the mouse callback for the current window
	glutMainLoop();						//entre the event processing loop
	return 0;
}

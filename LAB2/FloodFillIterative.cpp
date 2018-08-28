//Flood fill iterative using queue data structure 
//written by Anjali (LIT2016033)

#include <math.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
#include <queue>
using namespace std;
struct Point {
	GLint x;
	GLint y;
};

struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}

Color getPixelColor(GLint x, GLint y) {
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

void setPixelColor(GLint x, GLint y, Color color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void floodFill(GLint aa, GLint bb, Color oldColor, Color newColor) 
{	
	/************* pseudo code****************
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

void onMouseClick(int button, int state, int x, int y)
{
	Color newColor = {0.8f, 0.5f, 0.8f};
	Color oldColor = {1.0f, 1.0f, 1.0f};

	floodFill(320, 240, oldColor, newColor);
}

void draw_circle(Point pC, GLfloat radius) {
	GLfloat step = 1/radius;
	GLfloat x, y;

	for(GLfloat theta = 0; theta <= 360; theta += step) {
		x = pC.x + (radius * cos(theta));
		y = pC.y + (radius * sin(theta));
		glVertex2i(x, y);
	}
}

void display(void) {
	Point pt = {320, 240};
	GLfloat radius = 50;

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
		draw_circle(pt, radius);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Open GL");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(onMouseClick);
	glutMainLoop();
return 0;
}

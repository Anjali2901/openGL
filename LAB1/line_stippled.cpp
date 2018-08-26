#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);     glVertex2f((x1),(y1)); glVertex2f((x2),(y2)); glEnd();			//on calling drawOneLine(x1,y1,x2,y2) ,the glBegin() and glEnd() enclosed function will be executed
   
#include <GL/glut.h>
#include<string.h>
#include<bits/stdc++.h>
void init(void)			     //implements the class for opengl without using GLUT or any other library
{
   glClearColor(0.0, 0.0, 0.0, 0.0);//clear values in color buffer
   glShadeModel(GL_FLAT);           //specifies flat and smooth shading
}

void display(void)			//display function
{
   int i;

   glClear(GL_COLOR_BUFFER_BIT);	//color buffer gets clear 
   glColor3f(1.0, 0.0, 1.0);            //set the specified color

   glEnable(GL_LINE_STIPPLE);          //enable server-side GL capabilities

   glLineStipple(1, 0x0101);		/*  dotted  */ //specify the line stipple pattern
   glColor3f(0.2,0.8,1.0);
   drawOneLine(50.0, 125.0, 150.0, 125.0);   //draw  a line 
   glColor3f(1.0,0.0,1.0);
   glLineStipple(1, 0x00FF); 		 /*  dashed  */ //specify the line stipple pattern
   glColor3f(0.0,0.2,1.0);
   drawOneLine(150.0, 125.0, 250.0, 125.0);  //draw a line
   glColor3f(1.0,1.0,0.5);
   glLineStipple(1, 0x1C47);  		/*dash/dot/dash */ //specify the line stipple pattern
   glColor3f(0.4,0.5,0.1);
   drawOneLine(250.0, 125.0, 350.0, 125.0);

			       		/* in 2nd row, 3 wide lines, each with different stipple */
   glLineWidth(5.0);
   glLineStipple(1, 0x0101); 		 /*  dotted  */
   glColor3f(0.0,1.0,0.6);
   glColor3f(1.1,0.9,0.6);
   drawOneLine(50.0, 100.0, 150.0, 100.0);
   glLineStipple(1, 0x00FF);  		/*  dashed  */
   glColor3f(0.7,0.1,1.0);
   drawOneLine(150.0, 100.0, 250.0, 100.0);
   glLineStipple(1, 0x1C47);		  /*  dash/dot/dash  */
   drawOneLine(250.0, 100.0, 350.0, 100.0);
   glLineWidth(1.0);

					/* in 3rd row, 6 lines, with dash/dot/dash stipple  */
					/* as part of a single connected line strip         */
   glLineStipple(1, 0x1C47); 		 /*  dash/dot/dash  */
   glBegin(GL_LINE_STRIP);
   for (i = 0; i < 7; i++)
      glVertex2f(50.0 + ((GLfloat) i * 50.0), 75.0);
   glEnd();

					/* in 4th row, 6 independent lines with same stipple  */
   for (i = 0; i < 6; i++) {
      drawOneLine(50.0 + ((GLfloat) i * 50.0), 50.0,
                  50.0 + ((GLfloat)(i+1) * 50.0), 50.0);
   }

					/* in 5th row, 1 line, with dash/dot/dash stipple    */
					/* and a stipple repeat factor of 5                  */
   glLineStipple(5, 0x1C47);		/*  dash/dot/dash  */
   drawOneLine(50.0, 25.0, 350.0, 25.0);

   glDisable(GL_LINE_STIPPLE);  	//disable server-side GL capabilities
   glFlush();				//empties all the buffers 
}

void reshape(int w, int h) 		//callback function
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);   //affines the coordinates to window coordinates
   glMatrixMode(GL_PROJECTION); 		// specify which matrix is the current matrix
   glLoadIdentity();				//load identity matrix
   gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);//defines a 2D orthographic projection matrix
}
 
int main(int argc, char** argv) 		 //argc (argument count) and argv (argument vector) 
{
	   glutInit(&argc,argv); 		//  glutInit is used to initialize the GLUT library and negotiate a session with the window system.

	   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  //sets the initial display mode,(GLUT_RGB=An alias for GLUT_RGBA.) , GLUT_SINGLE = Bit mask to select a single buffered window. This is the default if neither GLUT_DOUBLE or GLUT_SINGLE are specified.

	   glutInitWindowSize(400, 150); 	//glutInitWindowSize — set the initial window size 
	   glutInitWindowPosition(100, 100);    //set the initial window position 
	   glutCreateWindow(argv[0]);    	//creates a top-level window. 
	   init();				//call init function
	   glutDisplayFunc(display);		//sets the display callback for the current window.
	   glutReshapeFunc(reshape); 		//
	   glutMainLoop();			//entre the event processing loop
	   return 0;
}



#include <GL/glut.h>							//header file

void display(void){							//display function
   	GLubyte halftone[] = {						//array of Glubyte data type
	      0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
	      0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
	      0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
	      0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
	      0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
	      0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
	      0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
	      0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
	      0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
	      0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
	      0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
	      0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
	      0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
	      0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
	      0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55,
	      0xAA, 0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0x55};

	   glClear(GL_COLOR_BUFFER_BIT);				//color buffer gets cleared
	   glColor3f(1.0, 0.5, 1.0);					//set the current color
	   /*  draw one solid, unstippled rectangle,       */
	   /*  then two stippled rectangles                */
	   glEnable(GL_POLYGON_STIPPLE);				//enable the polygon stipple capability
	   glBegin(GL_QUADS);						//delimit the vertices

           glVertex2i(500,700);						//specifies the x and y coordinates of the vertex
           glVertex2i(700,1000);
           glVertex2i(800,500);
           glVertex2i(1000,700);

	   glEnd();							//delimit the vertices
	   glPolygonStipple(halftone);					//set the polyogn stippling pattern
	   glDisable(GL_POLYGON_STIPPLE);				//disable the polygon stipple capability
	   glFlush();							//empties the buffers
}

void init(void){					      //implements the class for OpenGL without using GLUT or any other library					
	   glClearColor(0.0, 0.0, 0.0, 0.0);				//specify clear values for the color buffers
	   glShadeModel(GL_FLAT);					//select flat or smooth shading
}

void reshape(int w, int h){						//callback function
	   glViewport(0, 0, (GLsizei) w, (GLsizei) h);			//affines the coordinates to window coordinates
	   glMatrixMode(GL_PROJECTION);					//targets the subsequent matrix operation
	   glLoadIdentity();						//replaces the current matrix with the identity matrix
	   gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);		//define a 2D orthographic projection matrix
}

int main(int argc, char** argv){					//main loop
	   glutInit(&argc, argv);					//initializes the GLUT library
	   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);			//set the initial display mode
	   glutInitWindowSize(350, 150);				//set the window's width and height
	   glutCreateWindow(argv[0]);					//creates the top level window
	   init();							//call init function
	   glutDisplayFunc(display);					//calls the display function
	   glutReshapeFunc(reshape);					//calls the reshape function
	   glutMainLoop();
	   return 0;
}



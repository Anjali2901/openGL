#include <GL/glut.h>
#include<GL/gl.h>

void init2D(float r, float g, float b)			//initialize OpenGL Graphics
{
	glClearColor(r,g,b,0.0);			//clear values in color buffer
	glMatrixMode (GL_PROJECTION);			//target the subsequent matrix operation 
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);		//define a 2D orthographic projection matrix
}


void Draw() { 						//display function 
	 glClear(GL_COLOR_BUFFER_BIT); 			//clear the color buffer(background)
	 glColor3f(1.0,0.0,1.0);	 		//set the current color
	 glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); 	//select a polygon rasterization mode
	 glBegin(GL_TRIANGLE_FAN); 			// delimit the vertices of a primitive or a group of like primitives ,draw the connected group of traingles which share same vertex 
	    glVertex2f(125.0,30.0);          
	    glColor3f(0.0,0.8,1.0);       		//set the current color to value corresponding to given RGB 
	    glVertex2f(65.0,40.0);          		//draws a triangle with vertex 1,2,3
	    glColor3f(1.0,0.6,0.4);
	    glVertex2f(75.0,90.0);           		//draws a triangle with vertex 2,3,1
	    glColor3f(0.4,0.5,1.0);
	    glVertex2f(100.0,100.0);        		//draws a triangle with vertex 3,4,1
	    glColor3f(1.0,0.2,0.6);
	    glVertex2f(140.0,80.0);         		//draws a triangle with vertex 4,5,1
	 glEnd();
	 glFlush(); 					//empties all the buffer 
}
int main(int argc,char *argv[])  			//argc (argument count) and argv (argument vector) 

{
         glutInit(&argc,argv);				//  glutInit is used to initialize the GLUT library and negotiate a session with the window system.
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  //sets the initial display mode,(GLUT_RGB=An alias for GLUT_RGBA.) , GLUT_SINGLE = Bit mask to select a single buffered window. This is the default if neither GLUT_DOUBLE or GLUT_SINGLE are specified.
	glutInitWindowSize (500, 500);		       //glutInitWindowPosition, glutInitWindowSize — set the initial window position and size respectively.
	glutInitWindowPosition (100, 100);

	glutCreateWindow ("triangles");			//creates a top-level window. 
	init2D(0.0,0.0,0.0);				//call init2D function
	glutDisplayFunc(Draw);				//sets the display callback for the current window. 
	glutMainLoop();					//entre the event processing loop
	return 0;
}

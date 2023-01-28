#include <iostream>
#include <GL\glut.h>

void mid_point_algo(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	//Code for darwing here
	
	int radius = 10;
	int current_X = 0;
	int current_Y = radius;
	int p = 1-radius;
	
	glPointSize(5.0);
	glColor3ub(255,0,0);
	glBegin(GL_POINTS);
	
	//initial plot
	glVertex2i(current_X , current_Y);
	glVertex2i(current_Y , current_X);
	glVertex2i(-current_Y , current_X);
	glVertex2i(-current_X , -current_Y);
	
	while(current_X <= current_Y){
		
		//always increase x by 1
		current_X = current_X + 1;
		
		if(p<0){
			
			p = p+(2*current_X) + 1;	
		}
		else{
			current_Y = current_Y-1;
			p = p+(2*current_X) + 1 - (2*current_Y);
		}
		
			// for Quadrant-1
			glVertex2i(current_X , current_Y); // octant-1
			glVertex2i(current_Y , current_X); // octant-2
			
			// for Quadrant-2
			glVertex2i(-current_X , current_Y); // octant-3
			glVertex2i(-current_Y , current_X); // octant-4
			
			// for Quadrant-3
			glVertex2i(-current_X , -current_Y); // octant-5
			glVertex2i(-current_Y , -current_X); // octant-6
			
			// for Quadrant-4
			glVertex2i(current_X , -current_Y); // octant-7
			glVertex2i(current_Y , -current_X); // octant-8
	}
	
	glEnd();
	glFlush();
}

void init(){
	glClearColor(1,1,1,0);
	gluOrtho2D(-20,20,-20,20);
}

int main(int argc, char** argv) {
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Mid-point algorithm implementation");
	glutDisplayFunc(mid_point_algo);
	init();
	glutMainLoop();
	
	return 0;
}

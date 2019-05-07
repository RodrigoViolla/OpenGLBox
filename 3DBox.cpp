#include <cstdlib>
#include <cstdio>
#include <GL/glut.h> 

typedef float Vector3[3];

const unsigned int image_width = 512, image_height = 512;
float posX = 0;
float posY = 0;

void drawWireframe(Vector3 cube[8]){
	glVertex2i(cube[1-1][0], cube[1-1][1]);
	glVertex2i(cube[2-1][0], cube[2-1][1]);
	
	glVertex2i(cube[3-1][0], cube[3-1][1]);
	glVertex2i(cube[4-1][0], cube[4-1][1]);
	
	glVertex2i(cube[5-1][0], cube[5-1][1]);
	glVertex2i(cube[6-1][0], cube[6-1][1]);
	
	glVertex2i(cube[7-1][0], cube[7-1][1]);
	glVertex2i(cube[8-1][0], cube[8-1][1]);
	
	glVertex2i(cube[4-1][0], cube[4-1][1]);
	glVertex2i(cube[2-1][0], cube[2-1][1]);
	
	glVertex2i(cube[3-1][0], cube[3-1][1]);
	glVertex2i(cube[1-1][0], cube[1-1][1]);
	
	glVertex2i(cube[8-1][0], cube[8-1][1]);
	glVertex2i(cube[6-1][0], cube[6-1][1]);
	
	glVertex2i(cube[7-1][0], cube[7-1][1]);
	glVertex2i(cube[5-1][0], cube[5-1][1]);
	
	glVertex2i(cube[6-1][0], cube[6-1][1]);
	glVertex2i(cube[1-1][0], cube[1-1][1]);
	
	glVertex2i(cube[2-1][0], cube[2-1][1]);
	glVertex2i(cube[5-1][0], cube[5-1][1]);
	
	glVertex2i(cube[3-1][0], cube[3-1][1]);
	glVertex2i(cube[8-1][0], cube[8-1][1]);	

	glVertex2i(cube[4-1][0], cube[4-1][1]);
	glVertex2i(cube[7-1][0], cube[7-1][1]);

	glColor3f(0.0f, 0.0f, 1.0f);
	
	glVertex2i(cube[4-1][0], cube[4-1][1]);
	glVertex2i(cube[1-1][0], cube[1-1][1]);
	
	glVertex2i(cube[3-1][0], cube[3-1][1]);
	glVertex2i(cube[2-1][0], cube[2-1][1]);

	glVertex2i(cube[2-1][0], cube[2-1][1]);
	glVertex2i(cube[6-1][0], cube[6-1][1]);

	glVertex2i(cube[1-1][0], cube[1-1][1]);
	glVertex2i(cube[5-1][0], cube[5-1][1]);

	glVertex2i(cube[4-1][0], cube[4-1][1]);
	glVertex2i(cube[8-1][0], cube[8-1][1]);

	glVertex2i(cube[3-1][0], cube[3-1][1]);
	glVertex2i(cube[7-1][0], cube[7-1][1]);

	glVertex2i(cube[8-1][0], cube[8-1][1]);
	glVertex2i(cube[5-1][0], cube[5-1][1]);

	glVertex2i(cube[7-1][0], cube[7-1][1]);
	glVertex2i(cube[6-1][0], cube[6-1][1]);

	//glColor3f(0.0f, 0.0f, 1.0f);

	glVertex2i(cube[7-1][0], cube[7-1][1]);
	glVertex2i(cube[2-1][0], cube[2-1][1]);

	glVertex2i(cube[4-1][0], cube[4-1][1]);
	glVertex2i(cube[5-1][0], cube[5-1][1]);

	glVertex2i(cube[8-1][0], cube[8-1][1]);
	glVertex2i(cube[1-1][0], cube[1-1][1]);

	glVertex2i(cube[3-1][0], cube[3-1][1]);
	glVertex2i(cube[6-1][0], cube[6-1][1]);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_LINES);      
		glColor3f(1.0f, 0.0f, 0.0f);      
		Vector3 corners[8] = {
								{ 1-posX, 1, -5-posX},
								{ 1-posX, -1, -5-posX},
								{-1-posX, 1, -5+posX},
								{-1-posX, -1, -5+posX},
								{ 1+posX, -1, -3-posX},
								{ 1+posX, 1, -3-posX},
								{-1+posX, -1, -3+posX},
								{-1+posX, 1, -3+posX}
							};	
		Vector3 cube[8] = {};
		
		for (int i = 0; i < 8; ++i) {	
						
			float x_proj = corners[i][0] / -corners[i][2];
			float y_proj = corners[i][1] / -corners[i][2];
			float x_proj_remap = (1 + x_proj) / 2;
			float y_proj_remap = (1 + y_proj) / 2;
			float x_proj_pix = x_proj_remap * image_width;
			float y_proj_pix = y_proj_remap * image_height;
			
			cube[i][0] = x_proj_pix;
			cube[i][1] = y_proj_pix;
			cube[i][2] = corners[i][2];

			//glVertex2i(x_proj_pix, y_proj_pix);
		}
		
		glColor3f(1.0f, 0.0f, 0.0f);
		drawWireframe(cube);
	
	glEnd();	
	glFlush();  
}

void myInit (void) 
{ 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
      
    glColor3f(0.0, 1.0, 0.0); 
      
    glPointSize(2.0); 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
      
    gluOrtho2D(0, image_width, 0, image_height); 
} 

void keyboard(unsigned char key, int x, int y) 
{ 
	if (key == 110) 
		posX+=0.1f; 

	if (key == 98) 
		posX-=0.1f; 

	if(posX > 1)
		posX = -1;

	if(posX < -1)
		posX = 1;

    glutPostRedisplay(); 
} 

int main(int argc, char** argv)
{
	glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
      
    glutInitWindowSize(image_width, image_height); 
    glutInitWindowPosition(0, 0); 
      
    glutCreateWindow("3D Box"); 
    glutKeyboardFunc(keyboard); 
    myInit(); 
      
    glutDisplayFunc(display); 
    glutMainLoop();
} 
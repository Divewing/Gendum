#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glut.h>
#include <SOIL/SOIL.h>



// ----------------------------------------------------------
// Function Prototypes
// ----------------------------------------------------------
void display();

// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
double rotate_y=0;
double rotate_x=0;
double tangan_l=0;
double tangan_r=0;
double lengan_l=0;
double lengan_r=0;
double foward_r=0;
double foward_l=0;
int sw=0;
void initGL() {
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; //parameter cahaya specular
	GLfloat mat_shininess[] = { 100.0 }; //parameter shininess
	GLfloat light_position[] = { 1.0, 0.5, 1.0, 1.0 }; //parameter posisi pencahayaan
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH); //mengaktifkan shade model
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHTING); //mengaktifkan pencahayaan
	glEnable(GL_LIGHT0); //mengaktifkan sumber cayaha
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	//add positioned light
	GLfloat lightColor0[] = {0.7f, 0.7f, 0.7f, 1.0f};
	GLfloat lightPos0[] = {1.0f, 5.0f, 0.0f, 1.0f};
	GLfloat lightPos1[] = {-1.0f, 5.0f, 0.0f, 1.0f};
	GLfloat lightPos2[] = {0.0f, 0.0f, 1.0f, 1.0f};
	GLfloat lightPos3[] = {0.0f, 0.0f, -1.0f, 1.0f};


	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT2, GL_POSITION, lightPos2);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT3, GL_POSITION, lightPos3);

	glPopMatrix();
	glEnable(GL_DEPTH_TEST);

	int width, height;
	unsigned char* head =
	    SOIL_load_image("Head.jpg", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
	              GL_UNSIGNED_BYTE, head);


}

void helper(){
	//Helper
	  glBegin(GL_LINES);
	  	  glColor3f(1.0,0.0,0.0);
	  	  glVertex3f(-1.0,0.0,0.0);
	  	  glVertex3f(1.0,0.0,0.0);
	  glEnd();

	  glBegin(GL_LINES);
	  	  glColor3f(1.0,1.0,1.0);
	  	  glVertex3f(0.0,-1.0,0.0);
	  	  glVertex3f(0.0,2.0,0.0);
	  glEnd();

	  glBegin(GL_LINES);
	  	  glColor3f(1.0,1.0,0.0);
	  	  glVertex3f(0.0,0.0,-1.0);
	  	  glVertex3f(0.0,0.0,1.0);
	  glEnd();
}

void base(){

		float base=0.4;
	 	float gaps=0.01;
	 	glPushMatrix();
	 	glTranslatef((base+gaps),0.0f,(base+gaps));
	 	glScalef(2.0,0.2,2.0);
	 	glColor3f(0.0, 1.0, 0.5);
	 	glutSolidCube(base);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glTranslatef(-(base+gaps),0.0f,(base+gaps));
	 	glScalef(2.0,0.2,2.0);
	 	glColor3f(0.0, 1.0, 0.5);
	 	glutSolidCube(base);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glTranslatef(-(base+gaps),0.0f,-(base+gaps));
	 	glScalef(2.0,0.2,2.0);
	 	glColor3f(0.0, 1.0, 0.5);
	 	glutSolidCube(base);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glTranslatef((base+gaps),0.0f,-(base+gaps));
	 	glScalef(2.0,0.2,2.0);
	 	glColor3f(0.0, 1.0, 0.5);
	 	glutSolidCube(base);
	 	glPopMatrix();

}

void legs(){

 		glPushMatrix();
 		glTranslatef(0.0,0.85,0.0);
 		glRotatef(foward_l,1.0,0.0,0.0);
 		glTranslatef(0.0,-0.85,0.0);
	 	glPushMatrix();
	 	glColor3f(1.0, 0.0, 0.0);
	 	glTranslatef(0.1,0.05,-0.05);
	 	glScalef(1.5,0.7,3.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 1.0);
	 	glTranslatef(0.1,0.1,-0.03);
	 	glScalef(1.5,0.7,2.5);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 1.0);
	 	glTranslatef(0.1,0.3,0.0);
	 	glScalef(1.2,3.5,1.5);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(0.2, 0.2, 0.2);
	 	glTranslatef(0.1,0.5,0.0);
	 	glScalef(0.8,1.0,1.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();


	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 1.0);
	 	glTranslatef(0.1,0.73,0.0);
	 	glScalef(1.2,3.5,1.5);
	 	glutSolidCube(0.1);
	 	glPopMatrix();
	 	glPopMatrix();

//Right
//Upper
	 	glPushMatrix();
	 	glTranslatef(0.0,0.85,0.0);
	 	glRotatef(foward_r,1.0,0.0,0.0);
	 	glTranslatef(0.0,-0.85,0.0);
	 	glPushMatrix();
	 	glColor3f(0.2, 0.2, 0.2);
	 	glTranslatef(-0.1,0.5,0.0);
	 	glScalef(0.8,1.0,1.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 1.0);
	 	glTranslatef(-0.1,0.73,-0.0);
	 	glScalef(1.2,3.5,1.5);
	 	glutSolidCube(0.1);
	 	glPopMatrix();


//Lower

	 	glPushMatrix();
	 	glColor3f(1.0, 0.0, 0.0);
	 	glTranslatef(-0.1,0.05,-0.05);
	 	glScalef(1.5,0.7,3.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 1.0);
	 	glTranslatef(-0.1,0.1,-0.03);
	 	glScalef(1.5,0.7,2.5);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 1.0);
	 	glTranslatef(-0.1,0.3,0.0);
	 	glScalef(1.2,3.5,1.5);
	 	glutSolidCube(0.1);
	 	glPopMatrix();
	 	glPopMatrix();

}

void hips(){
//Hips
	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 1.0);
	 	glTranslatef(0.0,0.9,0.0);
	 	glScalef(3.5,2.0,2.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(1.0, 1.0,1.0);
	 	glTranslatef(0.0,0.8,0.0);
	 	glScalef(0.5,0.5,3.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 //Front
	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 0.0);
	 	glTranslatef(0.1,0.9,-0.1);
	 	glScalef(1.0,1.0,1.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(1.0, 1.0,1.0);
	 	glTranslatef(0.0,0.9,-0.1);
	 	glScalef(0.5,2.0,1.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 0.0);
	 	glTranslatef(-0.1,0.9,-0.1);
	 	glScalef(1.0,1.0,1.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();
	 //Back
	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 0.0);
	 	glTranslatef(0.1,0.9,0.1);
	 	glScalef(1.0,1.0,1.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(1.0, 1.0,1.0);
	 	glTranslatef(0.0,0.9,0.1);
	 	glScalef(0.5,2.0,1.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 0.0);
	 	glTranslatef(-0.1,0.9,0.1);
	 	glScalef(1.0,1.0,1.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

}

void torso(){
	//Abdomen
	 	glPushMatrix();
	 	glColor3f(1.0, 0.0, 0.0);
	 	glTranslatef(0.0,1.1,0.0);
	 	glScalef(3.0,2.0,1.7);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(0.0, 0.0,1.0);
	 	glTranslatef(0.0,1.15,-0.1);
	 	glRotated(-10,1,0,0);
	 	glScalef(0.7,2.5,1.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	//Breast
	 	glPushMatrix();
	 	glColor3f(0.0, 0.0, 1.0);
	 	glTranslatef(0.0,1.3,0.0);
	 	glScalef(3.5,2.0,2.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 0.0);
	 	glTranslatef(0.1,1.24,-0.09);
	 	glRotated(-10,1,0,0);
	 	glRotated(2,0,0,1);
	 	glRotated(-10,0,1,0);
	 	glScalef(1.15,1.0,1.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 0.0);
	 	glTranslatef(-0.1,1.24,-0.09);
	 	glRotated(-10,1,0,0);
	 	glRotated(-2,0,0,1);
	 	glRotated(10,0,1,0);
	 	glScalef(1.15,1.0,1.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(1.0, 1.0,0.0);
	 	glTranslatef(0.0,1.36,-0.1);
	 	glRotated(25,1,0,0);
	 	glScalef(1.0,1.1,1.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(0.0, 0.0, 1.0);
	 	glTranslatef(0.1,1.33,-0.09);
	 	glRotated(25,1,0,0);
	 	glRotated(2,0,0,1);
	 	glRotated(-10,0,1,0);
	 	glScalef(1.15,1.0,1.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(0.0, 0.0, 1.0);
	 	glTranslatef(-0.1,1.33,-0.09);
	 	glRotated(25,1,0,0);
	 	glRotated(-2,0,0,1);
	 	glRotated(+10,0,1,0);
	 	glScalef(1.15,1.0,1.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 //Bacpack
	 	glPushMatrix();
	 	glColor3f(0.2, 0.2, 0.2);
	 	glTranslatef(0.0,1.27,0.15);
	 	glScalef(2.0,2.6,1.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(0.2, 0.2, 0.2);
	 	glTranslatef(0.13,1.32,0.15);
	 	glScalef(0.6,1.3,0.7);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(0.2, 0.2, 0.2);
	 	glTranslatef(-0.13,1.32,0.15);
	 	glScalef(0.6,1.3,0.7);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 //Beam Sabers
	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 1.0);
	 	glTranslatef(-0.13,1.5,0.15);
	 	glRotated(5,0,0,1);
	 	glScalef(0.55,2.2,0.55);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 1.0);
	 	glTranslatef(0.13,1.5,0.15);
	 	glRotated(-5,0,0,1);
	 	glScalef(0.55,2.2,0.55);
	 	glutSolidCube(0.1);
	 	glPopMatrix();
}

void arms(double tangan_l){
//Left
		glPushMatrix();
		glTranslatef(0.0,+1.35,0.0);
		glRotatef(lengan_l,1.0,0.0,0.0);
		glTranslatef(0.0,-1.35,0.0);

	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 1.0);
	 	glTranslatef(0.25,1.35,0.0);
	 	glScalef(1.5,1.5,1.3);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 1.0);
	 	glTranslatef(0.25,1.2,0.0);
	 	glScalef(1.0,1.4,1.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(0.2, 0.2, 0.2);
	 	glTranslatef(0.25,1.1,0.0);
	 	glScalef(0.5,1.5,0.9);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 1.0);
	 	glTranslatef(0.25,0.95,0.0);
	 	glTranslatef(0.0,+0.1,0.0);
	 	glRotatef(tangan_l,1.0,0.0,0.0);
	 	glTranslatef(0.0,-0.1,0.0);
	 	glScalef(1.0,2.5,1.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(1.0, 0.2, 0.4);
	 	glTranslatef(0.25,0.8,0.0);
	 	glTranslatef(0.0,+0.25,0.0);
	 	glRotatef(tangan_l,1.0,0.0,0.0);
	 	glTranslatef(0.0,-0.25,0.0);
	 	glScalef(0.8,0.8,0.8);
	 	glutSolidCube(0.1);
	 	glPopMatrix();
	 	glPopMatrix();

//Right
	 	glPushMatrix();
	 	glTranslatef(0.0,+1.35,0.0);
	 	glRotatef(lengan_r,1.0,0.0,0.0);
	 	glTranslatef(0.0,-1.35,0.0);

	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 1.0);
	 	glTranslatef(-0.25,1.35,0.0);
	 	glScalef(1.5,1.5,1.3);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 1.0);
	 	glTranslatef(-0.25,1.2,0.0);
	 	glScalef(1.0,1.4,1.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

		glPushMatrix();
		glColor3f(0.2, 0.2, 0.2);
	 	glTranslatef(-0.25,1.1,0.0);
	 	glScalef(0.5,1.5,0.9);
	 	glutSolidCube(0.1);
	 	glPopMatrix();


	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 1.0);
	 	glTranslatef(-0.25,0.95,0.0);
	 	glTranslatef(0.0,+0.1,0.0);
	 	glRotatef(tangan_r,1.0,0.0,0.0);
	 	glTranslatef(0.0,-0.1,0.0);
	 	glScalef(1.0,2.5,1.0);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	 	glPushMatrix();
	 	glColor3f(1.0, 0.2, 0.4);
	 	glTranslatef(-0.25,0.8,0.0);
	 	glTranslatef(0.0,+0.25,0.0);
	 	glRotatef(tangan_r,1.0,0.0,0.0);
	 	glTranslatef(0.0,-0.25,0.0);
	 	glScalef(0.8,0.8,0.8);
	 	glutSolidCube(0.1);
	 	glPopMatrix();
	 	glPopMatrix();
}

void head(){
	//Neck
	 	glPushMatrix();
	 	glColor3f(0.2, 0.2, 0.2);
	 	glTranslatef(0.0,1.45,0.0);
	 	glScalef(0.8,0.8,0.8);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

	//Head
	 	glPushMatrix();
	 	glColor3f(1.0, 1.0, 1.0);
	 	glTranslatef(0.0,1.53,0.0);
	 	glScalef(1.5,1.7,1.7);
	 	glutSolidCube(0.1);
	 	glPopMatrix();

}


void display(){

  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glEnable(GL_COLOR_MATERIAL);
  // Reset transformations
  glLoadIdentity();
  // Other Transformations
   glTranslatef( 0.0, -0.8, 0.0 );
   glRotatef( -10, 1.0, 0.0, 0.0 );

  // Rotate when user changes rotate_x and rotate_y
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );

  // Other Transformations
  // glScalef( 2.0, 2.0, 0.0 );          // Not included

helper();
legs();
hips();
torso();
arms(tangan_l);
head();

  glFlush();
  glutSwapBuffers();

}

// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {

  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;

  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;

  else if (key == GLUT_KEY_UP)
    rotate_x += 5;

  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;

  //  Request display update
  glutPostRedisplay();

}

void keyboard(unsigned char key, int x, int y){
	if(key=='q'){
		tangan_l +=5;

	}else if(key=='a'){
		tangan_l -=5;
	}else if(key=='r'){
		tangan_r+=5;
	}else if(key=='f'){
		tangan_r-=5;
	}

	if(key=='w'){
		lengan_l+=5;
	}else if(key=='e'){
		lengan_r+=5;
	}else if(key=='s'){
		lengan_l-=5;
	}else if(key=='d'){
		lengan_r-=5;
	}

	if(key=='i'){
		if((foward_r==25)&&(foward_l==-25)){
			sw=1;
		}else if((foward_r==-25)&&(foward_l==25)){
			sw=0;
		}
		if(sw==0){
			foward_r+=5;
			foward_l-=5;
			lengan_l+=5;
			lengan_r-=5;
		}else if(sw==1){
			foward_r-=5;
			foward_l+=5;
			lengan_l-=5;
			lengan_r+=5;
		}
	}

	if(tangan_l>90){
		tangan_l=90;
	}else if(tangan_l<0){
		tangan_l=0;
	}
	if(tangan_r>90){
		tangan_r=90;
	}else if(tangan_r<0){
		tangan_r=0;
	}
	glutPostRedisplay();
}

// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]){

  //  Initialize GLUT and process user parameters
  glutInit(&argc,argv);

  //  Request double buffered true color window with Z-buffer
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800,600);
  // Create window
  glutCreateWindow("Gendum");

  //  Enable Z-buffer depth test
  glEnable(GL_DEPTH_TEST);

  // Callback functions
  glutDisplayFunc(display);
  initGL();
  glutSpecialFunc(specialKeys);
  glutKeyboardFunc(keyboard);
  //  Pass control to GLUT for events
  glutMainLoop();

  //  Return to OS
  return 0;

}






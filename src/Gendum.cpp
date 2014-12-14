
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#include <GL/glut.h>


// ----------------------------------------------------------
// Function Prototypes
// ----------------------------------------------------------
void display();
void specialKeys();

// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
double rotate_y=0;
double rotate_x=0;


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
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	//add positioned light
	GLfloat lightColor0[] = {0.7f, 0.7f, 0.7f, 1.0f};
	GLfloat lightPos0[] = {5.0f, 7.0f, 5.0f, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	glPopMatrix();
	glEnable(GL_DEPTH_TEST);


}

// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------
void display(){

  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glEnable(GL_COLOR_MATERIAL);
  // Reset transformations
  glLoadIdentity();

  // Other Transformations
   glTranslatef( 0.0, -0.8, 0.0 );      // Not included
   glRotatef( -10, 1.0, 0.0, 0.0 );    // Not included

  // Rotate when user changes rotate_x and rotate_y
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );

  // Other Transformations
  // glScalef( 2.0, 2.0, 0.0 );          // Not included

  /*Base
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
*/
//Feet
 	glPushMatrix();
 	glColor3f(1.0, 0.0, 0.0);
 	glTranslatef(0.2,0.05,-0.05);
 	glRotated(-15,0,1,0);
 	glScalef(1.5,0.7,3.0);
 	glutSolidCube(0.1);
 	glPopMatrix();

 	glPushMatrix();
 	glColor3f(1.0, 0.0, 0.0);
 	glTranslatef(-0.2,0.05,-0.05);
 	glRotated(15,0,1,0);
 	glScalef(1.5,0.7,3.0);
 	glutSolidCube(0.1);
 	glPopMatrix();

 	glPushMatrix();
 	glColor3f(1.0, 1.0, 1.0);
 	glTranslatef(0.195,0.1,-0.03);
 	glRotated(-15,0,1,0);
 	glScalef(1.5,0.7,2.5);
 	glutSolidCube(0.1);
 	glPopMatrix();

 	glPushMatrix();
 	glColor3f(1.0, 1.0, 1.0);
 	glTranslatef(-0.195,0.1,-0.03);
 	glRotated(15,0,1,0);
 	glScalef(1.5,0.7,2.5);
 	glutSolidCube(0.1);
 	glPopMatrix();


//Leg_lower
 	glPushMatrix();
 	glColor3f(1.0, 1.0, 1.0);
 	glTranslatef(0.16,0.3,0.0);
 	glRotated(-25,0,1,0);
 	glRotated(4,0,0,1);
 	glScalef(1.2,3.3,1.5);
 	glutSolidCube(0.1);
 	glPopMatrix();

 	glPushMatrix();
 	glColor3f(1.0, 1.0, 1.0);
 	glTranslatef(-0.16,0.3,0.0);
 	glRotated(25,0,1,0);
 	glRotated(-4,0,0,1);
 	glScalef(1.2,3.3,1.5);
 	glutSolidCube(0.1);
 	glPopMatrix();

//Leg_joint
 	glPushMatrix();
 	glColor3f(0.2, 0.2, 0.2);
 	glTranslatef(0.14,0.5,0.0);
 	glRotated(-25,0,1,0);
 	glRotated(4,0,0,1);
 	glScalef(0.8,1.0,1.0);
 	glutSolidCube(0.1);
 	glPopMatrix();

 	glPushMatrix();
 	glColor3f(0.2, 0.2, 0.2);
 	glTranslatef(-0.14,0.5,0.0);
 	glRotated(25,0,1,0);
 	glRotated(-4,0,0,1);
 	glScalef(0.8,1.0,1.0);
 	glutSolidCube(0.1);
 	glPopMatrix();

//Leg_upper
 	glPushMatrix();
 	glColor3f(1.0, 1.0, 1.0);
 	glTranslatef(0.13,0.66,-0.01);
 	glRotated(-20,0,1,0);
 	glRotated(4,0,0,1);
 	glScalef(1.2,2.8,1.5);
 	glutSolidCube(0.1);
 	glPopMatrix();

 	glPushMatrix();
 	glColor3f(1.0, 1.0, 1.0);
 	glTranslatef(-0.13,0.66,-0.01);
 	glRotated(20,0,1,0);
 	glRotated(-4,0,0,1);
 	glScalef(1.2,2.8,1.5);
 	glutSolidCube(0.1);
 	glPopMatrix();

//Hips
 	glPushMatrix();
 	glColor3f(1.0, 1.0, 1.0);
 	glTranslatef(0.0,0.9,0.0);
 	glScalef(3.5,2.0,2.0);
 	glutSolidCube(0.1);
 	glPopMatrix();


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


//Shoulder_Armor

 	glPushMatrix();
 	glColor3f(1.0, 1.0, 1.0);
 	glTranslatef(0.25,1.35,0.0);
 	glScalef(1.5,1.5,1.3);
 	glutSolidCube(0.1);
 	glPopMatrix();

 	glPushMatrix();
 	glColor3f(1.0, 1.0, 1.0);
 	glTranslatef(-0.25,1.35,0.0);
 	glScalef(1.5,1.5,1.3);
 	glutSolidCube(0.1);
 	glPopMatrix();

//Arms_Upper
 	glPushMatrix();
 	glColor3f(1.0, 1.0, 1.0);
 	glTranslatef(0.25,1.2,0.0);
 	glScalef(1.0,1.4,1.0);
 	glutSolidCube(0.1);
 	glPopMatrix();

 	glPushMatrix();
 	glColor3f(1.0, 1.0, 1.0);
 	glTranslatef(-0.25,1.2,0.0);
 	glScalef(1.0,1.4,1.0);
 	glutSolidCube(0.1);
 	glPopMatrix();

//Arms_Joint
 	glPushMatrix();
 	glColor3f(0.2, 0.2, 0.2);
 	glTranslatef(0.25,1.1,0.0);
 	glScalef(0.5,0.5,0.9);
 	glutSolidCube(0.1);
 	glPopMatrix();

	glPushMatrix();
	glColor3f(0.2, 0.2, 0.2);
 	glTranslatef(-0.25,1.1,0.0);
 	glScalef(0.5,0.5,0.9);
 	glutSolidCube(0.1);
 	glPopMatrix();

//Arms_Lower
 	glPushMatrix();
 	glColor3f(1.0, 1.0, 1.0);
 	glTranslatef(0.25,0.95,0.0);
 	glScalef(1.0,2.5,1.0);
 	glutSolidCube(0.1);
 	glPopMatrix();

 	glPushMatrix();
 	glColor3f(1.0, 1.0, 1.0);
 	glTranslatef(-0.25,0.95,0.0);
 	glScalef(1.0,2.5,1.0);
 	glutSolidCube(0.1);
 	glPopMatrix();

//Hands
 	glPushMatrix();
 	glColor3f(1.0, 0.2, 0.4);
 	glTranslatef(0.25,0.8,0.0);
 	glScalef(0.8,0.8,0.8);
 	glutSolidCube(0.1);
 	glPopMatrix();

 	glPushMatrix();
 	glColor3f(1.0, 0.2, 0.4);
 	glTranslatef(-0.25,0.8,0.0);
 	glScalef(0.8,0.8,0.8);
 	glutSolidCube(0.1);
 	glPopMatrix();

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
  //  Pass control to GLUT for events
  glutMainLoop();

  //  Return to OS
  return 0;

}






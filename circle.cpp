/////////////////////////////////////////////////////////////////////         
// Title: Gajski-Kuhn Y-chart
// @author: Armando Rodríguez.
///////////////////////////////////////////////////////////////////// 

#include <cstdlib>
#include <cmath>
#include <iostream>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define AlturaVentana 670
#define AnchuraVentana 700
#define PI 3.14159265358979324

using namespace std;

// Globals.
static int isWire = 0; // Is wireframe?
static long font = (long)GLUT_BITMAP_8_BY_13; // Font selection.
static float R = 40.0; // Radius of circle.
static float X = 50.0; // X-coordinate of center of circle.
static float Y = 50.0; // Y-coordinate of center of circle.
static int numVertices = 360; // Number of vertices on circle.
static float radios[] = {40.0, 32.0, 24.0, 16.0, 8.0};
static float positionsLines[][4] = {
                                    {50.0, 50.0, 20.0, 77.0},
                                    {50.0, 50.0, 80.0, 77.0},
                                    {50.0, 50.0, 50.0, 10.0}
                                 };                                 



//
void drawLine(float x1, float y1, float x2, float y2){
   
   glLineWidth(4.0);
   glColor3f(0.0, 0.0, 0.0);
   glBegin(GL_LINES);
      glVertex3f(x1, y1, 0.0);
      glVertex3f(x2, y2, 0.0);
   glEnd();
}

void drawCircles(){
   
   float t; // Angle parameter.
   int i;
   
   glColor3f(0.4, 0.4, 0.4);
   for(int circle = 0; circle < 5; circle++){ // For para los 5 circulos
      t = 0;
      glBegin(GL_LINE_LOOP);
      for(i = 0; i < numVertices; i++){ // for para los 360 vértices de cada círculo
         glVertex3f(X + radios[circle] * cos(t), Y + radios[circle] * sin(t), 0.0);
         t += 2 * PI / numVertices;
	    }
       glEnd();
   }
}

void writeBitmapString(void *font, char *string)
{  
   char *c;
   for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
} 

void drawPoints(){
   glPointSize(10.0);
   glBegin(GL_POINTS);
      // left
      glVertex3f(positionsLines[0][2], positionsLines[0][3], 0.0);
      glVertex3f(positionsLines[0][2]+6, positionsLines[0][3]-5.5, 0.0);
      glVertex3f(positionsLines[0][2]+12, positionsLines[0][3]-11, 0.0);
      glVertex3f(positionsLines[0][2]+18, positionsLines[0][3]-16.5, 0.0);
      glVertex3f(positionsLines[0][2]+24, positionsLines[0][3]-22, 0.0);
      // right
      glVertex3f(positionsLines[1][2], positionsLines[1][3], 0.0);
      glVertex3f(positionsLines[1][2]-6, positionsLines[1][3]-5.5, 0.0);
      glVertex3f(positionsLines[1][2]-12, positionsLines[1][3]-11, 0.0);
      glVertex3f(positionsLines[1][2]-18, positionsLines[1][3]-16.5, 0.0);
      glVertex3f(positionsLines[1][2]-24, positionsLines[1][3]-22, 0.0);
      //
      glVertex3f(positionsLines[2][2], positionsLines[2][3], 0.0);
      glVertex3f(positionsLines[2][2], positionsLines[2][3]+8, 0.0);
      glVertex3f(positionsLines[2][2], positionsLines[2][3]+16, 0.0);
      glVertex3f(positionsLines[2][2], positionsLines[2][3]+24, 0.0);
      glVertex3f(positionsLines[2][2], positionsLines[2][3]+32, 0.0);
      
   glEnd();   
}

// Drawing routine.
void displayMe(void){  
   glClear(GL_COLOR_BUFFER_BIT);

   drawCircles();
   
   for (int f = 0; f < 3; f++){
      drawLine(positionsLines[f][0], positionsLines[f][1], positionsLines[f][2], positionsLines[f][3]);  
   }
   
   drawPoints();

   // Write labels.
   glColor3f(0.0, 0.0, 0.0);
   //left
   glRasterPos3f(positionsLines[0][2]-10, positionsLines[0][3], 0.0);
   writeBitmapString((void*)font, "System");
   glRasterPos3f(positionsLines[0][2]-8, positionsLines[0][3]-5.5, 0.0);
   writeBitmapString((void*)font, "Algorithms");
   glRasterPos3f(positionsLines[0][2]-12, positionsLines[0][3]-10.5, 0.0);
   writeBitmapString((void*)font, "Register Transfers");
   glRasterPos3f(positionsLines[0][2]+10, positionsLines[0][3]-17, 0.0);
   writeBitmapString((void*)font, "Logic");
   glRasterPos3f(positionsLines[0][2]+2, positionsLines[0][3]-23, 0.0);
   writeBitmapString((void*)font, "Transfer functions");
   // right
   glRasterPos3f(positionsLines[1][2]+2, positionsLines[1][3]-2, 0.0);
   writeBitmapString((void*)font, "Processors");
   glRasterPos3f(positionsLines[1][2]-5, positionsLines[1][3]-7, 0.0);
   writeBitmapString((void*)font, "ALUs, RAM, etc.");
   glRasterPos3f(positionsLines[0][2]+50, positionsLines[0][3]-12, 0.0);
   writeBitmapString((void*)font, "Gates");
   glRasterPos3f(positionsLines[1][2]-16, positionsLines[1][3]-18, 0.0);
   writeBitmapString((void*)font, "Flip-flops");
   glRasterPos3f(positionsLines[1][2]-22, positionsLines[1][3]-24, 0.0);
   writeBitmapString((void*)font, "Transistors");
   //
   glRasterPos3f(positionsLines[2][2]+2, positionsLines[2][3], 0.0);
   writeBitmapString((void*)font, "Physical partitions");
   glRasterPos3f(positionsLines[2][2]+2, positionsLines[2][3]+8, 0.0);
   writeBitmapString((void*)font, "Floor plans");
   glRasterPos3f(positionsLines[2][2]+2, positionsLines[2][3]+16, 0.0);
   writeBitmapString((void*)font, "Module layout");
   glRasterPos3f(positionsLines[2][2]+2, positionsLines[2][3]+24, 0.0);
   writeBitmapString((void*)font, "Cell layout");
   glRasterPos3f(positionsLines[2][2]+2, positionsLines[2][3]+32, 0.0);
   writeBitmapString((void*)font, "Transistor layout");

   // lines titles
   glRasterPos3f(positionsLines[0][2]-15, positionsLines[0][3]+5, 0.0);
   writeBitmapString(GLUT_BITMAP_HELVETICA_18, "Behavioural domain");
   glRasterPos3f(positionsLines[1][2]-3, positionsLines[1][3]+5, 0.0);
   writeBitmapString(GLUT_BITMAP_HELVETICA_18, "Structural Domain");
   glRasterPos3f(positionsLines[2][2]-6, positionsLines[2][3]-5, 0.0);
   writeBitmapString(GLUT_BITMAP_HELVETICA_18, "Physical Domain");


   //title
   glRasterPos3f(positionsLines[2][2]-13, positionsLines[2][3]+85, 0.0);
   writeBitmapString(GLUT_BITMAP_HELVETICA_18, "Gajski-Kuhn Y-chart");

   glFlush();
}


// Initialization routine.
void init(void) 
{
   glClearColor(1.0, 1.0, 1.0, 0.0); 
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
   switch(key) 
   {
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
   cout << "Interaction:" << endl;
   cout << "Press [ESCAPE] to finish." << endl; 
}

// Main routine.
int main(int argc, char **argv) 
{
   	printInteraction();
   	glutInit(&argc, argv);
   	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
   	glutInitWindowSize(AnchuraVentana, AlturaVentana);   
   	glutCreateWindow("Gajski-Kuhn Y-chart");
   	init(); 
   	glutDisplayFunc(displayMe); 
   	glutReshapeFunc(resize);  
   	glutKeyboardFunc(keyInput);
   	glutMainLoop(); 

   	return 0;  
}

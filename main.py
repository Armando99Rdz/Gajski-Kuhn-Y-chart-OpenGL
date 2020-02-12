# Ejecucion:
# python3 HolaOpenGL.py

from OpenGL.GLUT import *       # GL Utilities Toolkit
from OpenGL.GL import *
from OpenGL.GLU import *
import math
import random
import sys
import array as arr

global t
global R
global X
global Y 
global PI
global AnchuraVentana
global AlturaVentana

# Initial values
AlturaVentana=900
AnchuraVentana=950

t=0.0
#R=40.0
# array de radios para los 5 circulos
radius = arr.array('i', [40, 32,  24, 16, 8])
X=50.0
Y=50.0
PI=3.14159265358979324

# Posiciones de las Lineas
originNode=50.0
line1 = arr.array('i', [-135, 130])



def printInteraction():
	print ("Interaction:")
	print ("Press +/- to increase/decrease the number of vertices on the circle.")
	print ("Press [ESCAPE] to finish.")


def init():
	glClearColor(1.0, 1.0, 1.0, 0.0) 


def resize(w, h): 
	if h == 0:
		h = 1
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity()


def keyInput(key, x, y):
	if key == b'\033': # -
		sys.exit()


def drawCircle(radio):
	glBegin(GL_LINE_LOOP);
	t=0.0
	for i in range(0, 360):
		glColor3f(0.0, 0.0, 0.0)
		X1=X + radio * math.cos(t);
		Y1=Y+radio * math.sin(t);
		glVertex3f(X1, Y1, 0.0);
		t += 2 * PI / 360
	glEnd();

def drawLines():
	glLineWidth(2.0)
	glBegin(GL_LINE);
	glColor3f(0.0, 0.0, 0.0)
	glVertex3f(50.0, 50.0, 0.0);
	glVertex3f(-50, 100, 0.0);
	glEnd();

def displayMe():
	glClear(GL_COLOR_BUFFER_BIT)
	
	# dibuja los 5 circulos
	for i in range(0, 5):
		drawCircle(radius[i])
	
	# dibujar lineas
	
	
	# dibujar texto
	#glColor3f(0.0, 0.0, 0.0)
	#glut_print( 10 , 10 , GLUT_BITMAP_9_BY_15 , "Hallo World" , 01.0 , 01.0 , 01.0 , 01.0 )





	glFlush()

def main():
	printInteraction()
	glutInit(sys.argv)
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)
	glutInitWindowPosition(100, 100)
	glutInitWindowSize(AnchuraVentana, AlturaVentana)
	glutCreateWindow("Poligono Regular de N Lados en OpenGL Python")
	glutReshapeFunc(resize)
	glutDisplayFunc(displayMe)
	glutKeyboardFunc(keyInput)
 
	init()
	glutMainLoop()
 
main()

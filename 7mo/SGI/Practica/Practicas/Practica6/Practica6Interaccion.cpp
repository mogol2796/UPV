/***************************************************
ISGI::Hola Mundo
Roberto Vivo', 2012 (v1.0)
Esqueleto basico de un programa en OpenGL
Dependencias:
+GLUT
***************************************************/
#define PROYECTO "SGI::P6::Interfaz de conducción"
#include <sstream>
#include <cmath>
#include <iostream> // Biblioteca de entrada salida
#include <freeglut.h> // Biblioteca grafica
#include <algorithm>
#include <../Utilidades.h>
using namespace std;

float cameraPosX = 0, cameraPosY = 1, cameraPosZ = 5;
float cameraLookAtX = 0, cameraLookAtY = 0, cameraLookAtZ = 0;
float speed = 0;
float speedVariation = 0.001;
float giro = 0;
float giroVariation = 0.1;
float amplitud = 10, t = 20;
int anchoCarretera = 3;

void movementCalculations()
{
	static int antes = glutGet(GLUT_ELAPSED_TIME);
	int ahora = glutGet(GLUT_ELAPSED_TIME);
	float tiempoTranscurrido = (ahora - antes) / 1000.0f;
	cameraPosX += speed * tiempoTranscurrido;
	cameraLookAtX = cameraPosX + giro;
	glutPostRedisplay();
}

float sinosoiydalFunction(int x)
{
	return amplitud * sin(x * 2 * PI / t);
}

float * normalizeDer(int x)
{
	float derivativeFunction = (2 * PI * amplitud / t) * cos(x * 2 * PI / t);
	float normalizer = 1 / sqrt((1 + pow(derivativeFunction, 2)));
	float componentNormalized = derivativeFunction / normalizer;
	float res[2] = { normalizer, componentNormalized };
	return res;
}

float* normalizeIzq(int x)
{
	float derivativeFunction = (2 * PI * amplitud / t) * cos(x * 2 * PI / t);
	float normalizer = 1 / sqrt((1 + pow(derivativeFunction, 2)));
	float componentNormalized = derivativeFunction / normalizer;
	float res[2] = { -1 * componentNormalized, normalizer};
	return res;
}

void roadBuilder()
{
	int punt1[2] = { 0, sinosoiydalFunction(0) };
	int punt2[2] = { 5, sinosoiydalFunction(5) };
	float *normal  = normalizeDer(punt1[0]);

	int v0[3] = {punt1[0] + (normal[0] * anchoCarretera/2)  , 0, punt1[1] + (normal[0] * anchoCarretera / 2) };
	
	glPolygonMode(GL_FRONT, GL_LINE);
	quad(v0, v1, v2, v3, 10, 5);
}

void init() 
{
	cout << "Version: OpenGL " << glGetString(GL_VERSION) << endl;
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST); // Habilita visibilidad

}

void display()
// Funcion de atencion al dibujo
{
	glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	
	gluLookAt(cameraPosX, cameraPosY, cameraPosZ, cameraLookAtX, cameraLookAtY, cameraLookAtZ, 0, 1, 0); // Situa la camara
	glColor3f(0, 0, 0);
	roadBuilder();
	//glutWireTeapot(1);
	glutSwapBuffers();
	movementCalculations();
}

void reshape(GLint w, GLint h)
// Funcion de atencion al redimensionamiento
{
	// Usamos toda el area de dibujo
	glViewport(0, 0, w, h);
	// Definimos la camara (matriz de proyeccion)
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float razon = (float)w / h;
	/* CAMARA PERSPECTIVA */
	gluPerspective(60, razon, 1, 10);
}

void onSpecialKey(int specialKey, int x, int y) // This function will be in charge of receving input from the keyboard and invoking the right functions for movement.
{
	switch (specialKey)
	{
		case GLUT_KEY_UP:
			speed += speedVariation;
			break;
		case GLUT_KEY_DOWN:
			speed -= speedVariation;
			break;
		case GLUT_KEY_LEFT:
			giro += giroVariation;
			break;
		case GLUT_KEY_RIGHT:
			giro -= giroVariation;
			break;
	};
	movementCalculations();

}



void main(int argc, char** argv)
// Programa principal
{
	glutInit(&argc, argv); // Inicializacion de GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Alta de buffers a usar
	glutInitWindowSize(400, 400); // Tamanyo inicial de la ventana
	glutCreateWindow(PROYECTO); // Creacion de la ventana con su titulo
	std::cout << PROYECTO << " running" << std::endl; // Mensaje por consola
	glutDisplayFunc(display); // Alta de la funcion de atencion a display
	glutReshapeFunc(reshape); // Alta de la funcion de atencion a reshape
	glutSpecialFunc(onSpecialKey);
	init();
	glutMainLoop(); // Puesta en marcha del programa
}
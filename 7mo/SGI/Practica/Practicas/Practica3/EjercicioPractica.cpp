/***************************************************
ISGI::Traslacion Cubo
Roberto Vivo', 2013 (v1.0)
Traslada un cubo usando una matriz construida al efecto
Dependencias:
+GLUT
***************************************************/
#define PROYECTO "ISGI::S3E01::Mosaico"
#include <iostream> // Biblioteca de entrada salida
#include <freeglut.h> // Biblioteca grafica
#include <cmath>

static GLuint trianguloInferior, trianguloSuperior;
float x[8], y[8];

void initializeArrays()
{
	float pi = 3.1415926;
	float alfa = 2 * pi / 6;

	for (int i = 0; i < sizeof(x); i++)
	{
		x[i] = cos(i * alfa + pi / 2);
	}

	for (int i = 0; i < sizeof(y); i++)
	{
		y[i] = sin(i * alfa + pi / 2);
	}
}

void init() {
	trianguloSuperior = glGenLists(1);
	trianguloInferior = glGenLists(1);
	initializeArrays();

	glNewList(trianguloSuperior, GL_COMPILE);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(x[0], y[0], 0.0);
	glVertex3f(x[0] * 0.7, y[0] * 0.7, 0.0);
	glVertex3f(x[2], y[2], 0.0);
	glVertex3f(x[2] * 0.7, y[2] * 0.7, 0.0);
	glVertex3f(x[4], y[4], 0.0);
	glVertex3f(x[4] * 0.7, y[4] * 0.7, 0.0);
	glVertex3f(x[0], y[0], 0.0);
	glVertex3f(x[0] * 0.7, y[0] * 0.7, 0.0);
	glEnd();
	glEndList();

	glNewList(trianguloInferior, GL_COMPILE);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(x[1], y[1], 0.0);
	glVertex3f(x[1] * 0.7, y[1] * 0.7, 0.0);
	glVertex3f(x[3], y[3], 0.0);
	glVertex3f(x[3] * 0.7, y[3] * 0.7, 0.0);
	glVertex3f(x[5], y[5], 0.0);
	glVertex3f(x[5] * 0.7, y[5] * 0.7, 0.0);
	glVertex3f(x[1], y[1], 0.0);
	glVertex3f(x[1] * 0.7, y[1] * 0.7, 0.0);
	glEnd();
	glEndList();

}

void cuadranteAParametros(int cuadrante) 
{
	switch (cuadrante)
	{
	case 1:
		glTranslatef(1, 1, 0); 
		glRotatef(-15, 0.0, 0.0, 1);
	case 2:
		glTranslatef(-1, 1, 0);
		glRotatef(15, 0.0, 0.0, 1);
	case 3:
		glTranslatef(-1, -1, 0);
		glRotatef(-15, 0.0, 0.0, 1);
	case 4:
		glTranslatef(1, -1, 0);
		glRotatef(15, 0.0, 0.0, 1);
	}
}

void dibujarEstrellaGrande(float cuadrante) 
{
	glLoadIdentity();
	glScalef(0.5, 0.5, 0);
	cuadranteAParametros(cuadrante);
	glColor3f(1, 1, 1); // Dibuja ejn color blanco
	glCallList(trianguloSuperior);
	glCallList(trianguloInferior);
}
void display()
// Funcion de atencion al dibujo
{
	// Matriz de traslacion por columnas
	glClear(GL_COLOR_BUFFER_BIT); // Borra la pantalla
	glMatrixMode(GL_MODELVIEW); // Selecciona la modelview
	dibujarEstrellaGrande(1);
	//dibujarEstrellaGrande(2);
	/*dibujarEstrellaGrande(3);
	dibujarEstrellaGrande(4);*/

	glFlush(); // Finaliza el dibujo
}
void reshape(GLint w, GLint h)
// Funcion de atencion al redimensionamiento
{
}
void main(int argc, char** argv)
// Programa principal
{
	glutInit(&argc, argv); // Inicializacion de GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Alta de buffers a usar
	glutInitWindowSize(400, 400); // Tamanyo inicial de la ventana
	glutCreateWindow(PROYECTO); // Creacion de la ventana con su titulo
	init();
	std::cout << PROYECTO << " running" << std::endl; // Mensaje por consola
	glutDisplayFunc(display); // Alta de la funcion de atencion a display
	glutReshapeFunc(reshape); // Alta de la funcion de atencion a reshape
	glutMainLoop(); // Puesta en marcha del programa
}
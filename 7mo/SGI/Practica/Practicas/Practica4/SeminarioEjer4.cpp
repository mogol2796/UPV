/***************************************************
ISGI::Hola Mundo
Roberto Vivo', 2012 (v1.0)
Esqueleto basico de un programa en OpenGL
Dependencias:
+GLUT
***************************************************/
#define PROYECTO "ISGI::S1E01::Hola Mundo"
#include <iostream> // Biblioteca de entrada salida
#include <freeglut.h> // Biblioteca grafica

void display()
// Funcion de atencion al dibujo
{
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);		// las transformaciones se aplicaran a un sistema de coordenadas fijadas en la camara
	glLoadIdentity();				// Neutralizamos todos los posibles cambios que podian tener la matriz

	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);	//1era tupla de tres: corresponde al pundo donde inicia la camara 
											//2da tupla de tres: Corresponde al punto hacia donde apunta la camara
											//3era tupla de tres: Corresponde un vector perpendicular a la linea entre la camara y el punto a donde apunta

	//glEnable(GL_DEPTH_TEST);
	glColor3f(1, 0, 1);
	glutWireTeapot(0.5);

	glTranslatef(1, 0, -4);

	glTranslatef(1, 0, -4);
	glColor3f(1, 0, 0);
	glutSolidTeapot(1);

	glFlush();
}

void reshape(GLint w, GLint h)
// Funcion de atencion al redimensionamiento
{
	static const float razon = 2.0;
	float razonAD = float(2) / h;
	float wp, hp;
	if (razonAD < razon) {
		wp = float(w);
		hp = wp / razon;
		glViewport(0, int(h / 2.0 - hp / 2.0), w, int(hp));
	}
	else {
		hp = float(h);
		wp = hp * razon;
		glViewport(int(w / 2.0 - w / 2.0), 0, int(wp), h);
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45, razon, 1, 10);	//1er elemento: el angulo vertical en grados del cono de vision
										//2do elemento: relacion entre el ancho y alto de la piramide de vision
										//3er elemento: la distancia del primer plano de la toma
										//4to elemento: la distancia del ultimo plano de la toma
}
void main(int argc, char** argv)
// Programa principal
{
	glutInit(&argc, argv); // Inicializacion de GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB| GLUT_DEPTH); // Alta de buffers a usar
	glutInitWindowSize(200, 200); // Tamanyo inicial de la ventana
	glutCreateWindow(PROYECTO); // Creacion de la ventana con su titulo
	std::cout << PROYECTO << " running" << std::endl; // Mensaje por consola
	glutDisplayFunc(display); // Alta de la funcion de atencion a display
	glutReshapeFunc(reshape); // Alta de la funcion de atencion a reshape
	glutMainLoop(); // Puesta en marcha del programa
}
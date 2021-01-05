///***************************************************
//ISGI::Cuadrado Animado
//Roberto Vivo', 2013 (v1.0)
//Dependencias:
//+GLUT
//***************************************************/
//#define PROYECTO "ISGI::S5E01::CuadradoAnimado"
//#include <iostream> // Biblioteca de entrada salida
//#include <cmath>
//#include <freeglut.h> // Biblioteca grafica
//using namespace std;
//
//static float posicionX(0.0), posicionY(0.0);
//static GLuint cuadrado;
//static const GLfloat semilado(0.1);
//static GLfloat semiancho, semialto;
//
//void init() {
//	cout << "Version: OpenGL " << glGetString(GL_VERSION) << endl;
//
//	glClearColor(1.0, 1.0, 1.0, 1.0);		//Color de fondo a blanco
//	glColor3f(0, 0, 0);						//Color de Dibujo Negro
//
//	//crear un cuadrado lado * lado
//	cuadrado = glGenLists(1);
//	glNewList(cuadrado, GL_COMPILE);		//abre la lista cuadrado
//	glBegin(GL_POLYGON);
//		glVertex3f(-semilado, -semilado, 0);
//		glVertex3f(semilado, -semilado, 0);
//		glVertex3f(semilado, semilado, 0);
//		glVertex3f(-semilado, semilado, 0);
//	glEnd();
//	glEndList();
//}
//
//void display()
//// Funcion de atencion al dibujo
//{
//	glClear(GL_COLOR_BUFFER_BIT); // Borra la pantalla
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	
//	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
//
//	glTranslatef(posicionX, posicionY, 0);
//	glCallList(cuadrado);
//
//	glFlush(); // Finaliza el dibujo
//}
//void reshape(GLint w, GLint h)
//// Funcion de atencion al redimensionamiento
//{
//	static const GLfloat ANCHO(2.0), ALTO(2.0);
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	float razon = (float)w / h;
//	if (w < h) {
//		semiancho = ANCHO / 2;
//		semialto = ALTO / 2 / razon;
//	}
//	else {
//		semiancho = ANCHO *razon/ 2;
//		semialto = ALTO / 2;
//	}
//	glOrtho(-semiancho, semiancho, -semialto, semialto, 0, 10);
//}
//
//void onIdle() {
//	static float uperframe[] = { 0.001, 0.001 };
//
//	posicionX += uperframe[0];
//	posicionY += uperframe[1];
//
//	if (posicionX + semilado >= semiancho || posicionX - semilado <= -semiancho) uperframe[0] *= -1;
//	if (posicionY + semilado >= semialto || posicionY - semilado <= -semialto) uperframe[1] *= -1;
//
//	if (abs(posicionX) > semiancho || abs(posicionY) > semialto) {
//		posicionX = 0.0;
//		posicionY = 0.0;
//	};
//	glutPostRedisplay();
//}
//void main(int argc, char** argv)
//// Programa principal
//{
//	glutInit(&argc, argv); // Inicializacion de GLUT
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Alta de buffers a usar
//	glutInitWindowSize(400, 400); // Tamanyo inicial de la ventana
//	glutCreateWindow(PROYECTO); // Creacion de la ventana con su titulo
//	std::cout << PROYECTO << " running" << std::endl; // Mensaje por consola
//	glutDisplayFunc(display); // Alta de la funcion de atencion a display
//	glutReshapeFunc(reshape); // Alta de la funcion de atencion a reshape
//	glutIdleFunc(onIdle);
//	init();
//	glutMainLoop(); // Puesta en marcha del programa
//}
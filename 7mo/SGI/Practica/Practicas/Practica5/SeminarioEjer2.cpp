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
//static float posicionX(0.0), posicionZ(0.0);
//static GLuint cuadrado;
//static const GLfloat semilado(0.1);
//static GLfloat semiancho, semialto;
//static float horaAnterior;
//
//float angToRad(float x) {
//	return x * 3.1416 / 180;
//}
//
//void display()
//// Funcion de atencion al dibujo
//{
//	glClear(GL_COLOR_BUFFER_BIT); // Borra la pantalla
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	gluLookAt(posicionX, 5, posicionZ, 0, 0, 0, 1, 0, 0);
//	glColor3f(1, 0, 1);
//	glutSolidTeapot(1.0);
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
//		semiancho = ANCHO * razon / 2;
//		semialto = ALTO / 2;
//	}
//	glOrtho(-semiancho, semiancho, -semialto, semialto, 0, 10);
//}
//
//void onIdle() {
//	float horaActual = glutGet(GLUT_ELAPSED_TIME);
//	float tiempoTranscurrido = horaActual - horaAnterior;
//	horaAnterior = horaActual;
//
//	GLfloat variacionX = sinf(angToRad(27)) * tiempoTranscurrido;
//	GLfloat variacionZ = cosf(angToRad(27)) * tiempoTranscurrido;
//
//	posicionX = variacionX;
//	posicionZ = variacionZ;
//
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
//	horaAnterior = glutGet(GLUT_ELAPSED_TIME);
//	glutDisplayFunc(display); // Alta de la funcion de atencion a display
//	glutReshapeFunc(reshape); // Alta de la funcion de atencion a reshape
//	glutIdleFunc(onIdle);
//	glutMainLoop(); // Puesta en marcha del programa
//}
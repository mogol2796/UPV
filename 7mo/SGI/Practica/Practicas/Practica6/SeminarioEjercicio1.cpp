///***************************************************
//ISGI::Hola Mundo
//Roberto Vivo', 2012 (v1.0)
//Esqueleto basico de un programa en OpenGL
//Dependencias:
//+GLUT
//***************************************************/
//#define PROYECTO "ISGI::S1E01::Hola Mundo"
//#include <sstream>
//#include <cmath>
//#include <iostream> // Biblioteca de entrada salida
//#include <freeglut.h> // Biblioteca grafica
//#include <algorithm>
//using namespace std;
//
//const int WIREVIEW = 1;
//const int SOLIDVIEW = 2;
//int modeView = 1;
//int mousePosX, mousePosY;
//
//void init() 
//{
//	cout << "Version: OpenGL " << glGetString(GL_VERSION) << endl;
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glEnable(GL_DEPTH_TEST); // Habilita visibilidad
//
//}
//void display()
//// Funcion de atencion al dibujo
//{
//	glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();	
//	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0); // Situa la camara
//	glColor3f(0, 0, 1);
//	if (modeView == WIREVIEW) 
//	{
//		glutWireCube(1.0);
//	}
//	else if (modeView == SOLIDVIEW)
//	{
//		glutSolidCube(1.0);
//	}
//
//	glutSwapBuffers();
//}
//void reshape(GLint w, GLint h)
//// Funcion de atencion al redimensionamiento
//{
//	// Usamos toda el area de dibujo
//	glViewport(0, 0, w, h);
//	// Definimos la camara (matriz de proyeccion)
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	float razon = (float)w / h;
//	/* CAMARA PERSPECTIVA */
//	gluPerspective(60, razon, 1, 10);
//}
//
//void onKey(unsigned char tecla, int x, int y) 
//{
//	stringstream titulo;
//	titulo << x << "," << y;
//	glutSetWindowTitle(titulo.str().c_str());
//
//	if (tecla == 'a')
//	{
//		modeView = WIREVIEW;
//	}
//	else if (tecla == 's')
//	{
//		modeView = SOLIDVIEW;
//	}
//	else if (tecla == 27)
//		exit(0);
//
//	glutPostRedisplay();
//}
//
//void main(int argc, char** argv)
//// Programa principal
//{
//	glutInit(&argc, argv); // Inicializacion de GLUT
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Alta de buffers a usar
//	glutInitWindowSize(400, 400); // Tamanyo inicial de la ventana
//	glutCreateWindow(PROYECTO); // Creacion de la ventana con su titulo
//	std::cout << PROYECTO << " running" << std::endl; // Mensaje por consola
//	glutDisplayFunc(display); // Alta de la funcion de atencion a display
//	glutReshapeFunc(reshape); // Alta de la funcion de atencion a reshape
//	glutKeyboardFunc(onKey);
//	init();
//	glutMainLoop(); // Puesta en marcha del programa
//}
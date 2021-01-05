///***************************************************
//ISGI::Hola Mundo
//Roberto Vivo', 2012 (v1.0)
//Esqueleto basico de un programa en OpenGL
//Dependencias:
//+GLUT
//***************************************************/
//#define PROYECTO "ISGI::S1E01::Hola Mundo"
//#include <iostream> // Biblioteca de entrada salida
//#include <freeglut.h> // Biblioteca grafica
//
//void display()
//// Funcion de atencion al dibujo
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);		// las transformaciones se aplicaran a un sistema de coordenadas fijadas en la camara
//	glLoadIdentity();				// Neutralizamos todos los posibles cambios que podian tener la matriz
//
//	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);	//1era tupla de tres: corresponde al pundo donde inicia la camara 
//											//2da tupla de tres: Corresponde al punto hacia donde apunta la camara
//											//3era tupla de tres: Corresponde un vector perpendicular a la linea entre la camara y el punto a donde apunta
//
//	glutWireSphere(1.0, 20, 20);
//
//	glFlush();
//}
//	
//void reshape(GLint w, GLint h)
//// Funcion de atencion al redimensionamiento
//{
//	glViewport(0, 0, w, h);				//define el tama�o del marco de dibujo
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	float razon = (float)w / h;
//	gluPerspective(45, razon, 1, 10);	//1er elemento: el angulo vertical en grados del cono de vision
//										//2do elemento: relacion entre el ancho y alto de la piramide de vision
//										//3er elemento: la distancia del primer plano de la toma
//										//4to elemento: la distancia del ultimo plano de la toma
//}
//void main(int argc, char** argv)
//// Programa principal
//{
//	glutInit(&argc, argv); // Inicializacion de GLUT
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Alta de buffers a usar
//	glutInitWindowSize(200, 200); // Tamanyo inicial de la ventana
//	glutCreateWindow(PROYECTO); // Creacion de la ventana con su titulo
//	std::cout << PROYECTO << " running" << std::endl; // Mensaje por consola
//	glutDisplayFunc(display); // Alta de la funcion de atencion a display
//	glutReshapeFunc(reshape); // Alta de la funcion de atencion a reshape
//	glutMainLoop(); // Puesta en marcha del programa
//}
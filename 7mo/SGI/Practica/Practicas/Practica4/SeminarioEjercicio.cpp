//#define PROYECTO "ISGI::S4E01::Isotropia Vista"
//
//#include <iostream>
//#include <freeglut.h>
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
//	glutWireSphere(1.0, 20, 20);
//	glFlush();
//}
//
//void reshape(GLint w, GLint h)
//{
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	
//	float razon = (float)w / h;
//
//	if (w < h)
//		glOrtho(1, 1, -1 / razon, 1 / razon, 0, 10);
//	else
//		glOrtho(-1 * razon, 1 * razon, -1, 1, 0, 10);
//
//	//gluPerspective(45, razon, 1, 5);
//}
//
//void main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow(PROYECTO);
//	std::cout << PROYECTO << " running " << std::endl;
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutMainLoop();
//}
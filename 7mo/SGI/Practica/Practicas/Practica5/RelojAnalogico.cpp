/***************************************************
ISGI::Reloj
Miguel A. Martinez G.', 2020 (v1.0)
Dependencias:
+GLUT
***************************************************/
#define PROYECTO "ISGI::P5::Reloj analogico"
#include <iostream> // Biblioteca de entrada salida
#include <cmath>
#include <freeglut.h> // Biblioteca grafica
#include <ctime>

using namespace std;
static const GLint SIDES = 50;

float angleHourHandRotation = 0;
float angleMinuteHandRotation = 0;
float angleSecondHandRotation = 0;
float angleDecorativeSphereRotation = 0;

float const SECONDS_ANGLE = 360 / 60;
float const MINUTES_ANGLE = 360 / 60;
float const HOUR_ANGLE = 360 / 12;

int decorativeSphereRotationDirectionX = 0;
int decorativeSphereRotationDirectionY = 0;
int decorativeSphereRotationDirectionZ = 1;

float decorativeSphereSize = 0.1;
int prevHour = 0;
int prevMinute = 0;
int prevSecond = 0;
int decorativeSphereScaleDirection = 1;
int decorativeSphereScalingSpeed = -1;
float speedAuxiliary = 1;

GLfloat colorArray[7][3] = { {0,0,1}, {0,1,0}, {0,1,1}, {1,0,0}, {1,0,1}, {1,1,0}, {1,1,1} };
int colorSelector = 0;

void drawCircle() {
	GLfloat angle;
	float x, y;
	glColor3f(colorArray[colorSelector][1] * 0.2, colorArray[colorSelector][2] * 0.2, colorArray[colorSelector][3] * 0.2);
	glBegin(GL_POLYGON);
	for (int i = 0; i < SIDES; i++) {

		angle =2* 3.1415 * float(i) / float(SIDES);
		x = cosf(angle);
		y = sinf(angle);
		glVertex2f(x, y);
	}
	glEnd();
}

void drawHourLines() {
	GLint hours = 12;
	GLfloat angle;
	float x, y;
	glColor3f(colorArray[colorSelector][1], colorArray[colorSelector][2], colorArray[colorSelector][3]);
	glBegin(GL_LINES);
	for (int i = 0; i < hours; i++) {

		angle = 2 * 3.1415 * float(i) / float(hours);
		x = cosf(angle);
		y = sinf(angle);
		glVertex2f(0.9 * x, 0.9 * y);
		glVertex2f(0.6 * x, 0.6 * y);

	}
	glEnd();
}

void drawHourHand() {
	glPushMatrix();
	glRotatef(90, -1, 0, 0);
	glRotatef(angleHourHandRotation, 0, 1, 0);
	glTranslatef(0, -0.5, 0.4);
	glutSolidCone(0.1, 0.09, 4, 1);
	glPopMatrix();

}

void drawMinuteHand() {
	glPushMatrix();
	glRotatef(90, -1, 0, 0);
	glRotatef(angleMinuteHandRotation, 0, 1, 0);
	glTranslatef(0, -0.5, 0.5);
	glutWireCone(0.07, 0.12, 7, 1);
	glPopMatrix();

}

void drawSecondHand() {
	glPushMatrix();
	glRotatef(90, -1, 0, 0);
	glRotatef(angleSecondHandRotation, 0, 1, 0);
	glTranslatef(0, -0.5, 0.5);
	glutWireCone(0.02, 0.2, 10, 1);
	glPopMatrix();

}

void drawSphere() {
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glRotatef(angleDecorativeSphereRotation, decorativeSphereRotationDirectionX, decorativeSphereRotationDirectionY, decorativeSphereRotationDirectionZ);
	glScalef(decorativeSphereSize, decorativeSphereSize, decorativeSphereSize);
	glutWireSphere(0.3, 20, 10);
	glPopMatrix();
}

void changeDecorativeSphereRotation() {
	decorativeSphereRotationDirectionX = rand() % 2;
	decorativeSphereRotationDirectionY = rand() % 2;
	decorativeSphereRotationDirectionZ = rand() % 2;
	cout << "HOLA";
}

void changeDecorativeSphereSize() {
	decorativeSphereScalingSpeed *= -1;
}

void changeWatchColor() {
	colorSelector += 1;
	if (colorSelector >= 7) colorSelector = 0;
}


void rotateHourHand(tm timeinfo) {
	angleHourHandRotation = HOUR_ANGLE * timeinfo.tm_hour;
	if (prevHour != timeinfo.tm_hour) {
		changeWatchColor();
		prevHour = timeinfo.tm_hour;
	}
}


void rotateMinuteHand(tm timeinfo) {
	angleMinuteHandRotation = MINUTES_ANGLE * timeinfo.tm_min;
	if (prevMinute != timeinfo.tm_min) {
		changeDecorativeSphereRotation();
		prevMinute = timeinfo.tm_min;
	}
}

void rotateSecondHand(tm timeinfo) {
	angleSecondHandRotation = SECONDS_ANGLE * timeinfo.tm_sec;
	if (prevSecond - timeinfo.tm_sec <= 0) {
		changeDecorativeSphereSize();
		prevSecond = timeinfo.tm_sec + 5;
	}
	if (prevSecond - timeinfo.tm_sec >= 60) prevSecond -= 60;

}

void rotateDecorativeSphere(tm timeinfo) {
	static int tiempoAnterior = 0;
	int tiempoActual;
	int velocidadRotacion = 10;
	float tiempoTranscurrido;
	tiempoActual = glutGet(GLUT_ELAPSED_TIME);
	tiempoTranscurrido = (tiempoActual - tiempoAnterior) / 1000.0;
	speedAuxiliary = decorativeSphereScalingSpeed * tiempoTranscurrido;
	decorativeSphereSize += speedAuxiliary / 5;
	angleDecorativeSphereRotation += velocidadRotacion * tiempoTranscurrido;

	tiempoAnterior = tiempoActual;
}



void init() {
	cout << "Version: OpenGL " << glGetString(GL_VERSION) << endl;

	glClearColor(1.0, 1.0, 1.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}



void display()
// Funcion de atencion al dibujo
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0,0,2,0,0,0,0,1,0);

	drawHourLines();

	drawSphere();
	drawHourHand();
	drawMinuteHand();
	drawSecondHand();

	drawCircle();


	glutSwapBuffers();

}
void reshape(GLint w, GLint h)
// Funcion de atencion al redimensionamiento
{
	glViewport(0, 0, w, h);
	// Definimos la camara (matriz de proyeccion)
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float razon = (float)w / h;
	/* CAMARA PERSPECTIVA */
	gluPerspective(60, razon, 1, 10);

}

void onIdle() {
	static float horaAnterior = 0;
	float horaActual, tiempoTranscurrido;
	time_t rawtime = time(0);
	struct tm timeinfo;
	localtime_s(&timeinfo, &rawtime);

	rotateHourHand(timeinfo);
	rotateMinuteHand(timeinfo);
	rotateSecondHand(timeinfo);
	rotateDecorativeSphere(timeinfo);

	glutPostRedisplay();
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
	glutIdleFunc(onIdle);
	init();
	glutMainLoop(); // Puesta en marcha del programa
}
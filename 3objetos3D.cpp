#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#define janela_altura 480
#define janela_largura 640


void reshape(GLsizei largura, GLsizei altura);
void display();

GLfloat xRotated, yRotated, zRotated;
double rotate_y = 0;
double rotate_x = 0;

double rotate_yCube = 0;
double rotate_xCube = 0;

double rotate_yIcosaedro = 0;
double rotate_xIcosaedro = 0;

void specialKeys(int key, int x, int y);
void keyboard(int key, int x, int y);

void keyboard(unsigned char key, int x, int y) {

	/////////// ROTACIONAR CUBO ////////////
	if (key == 'a' || key == 'A') {
		rotate_yCube += 5;
	}
	else if (key == 's' || key == 'S') {
		rotate_xCube -= 5;
	}

	else if (key == 'd' || key == 'D') {
		rotate_yCube -= 5;
	}

	else if (key == 'w' || key == 'W') {
		rotate_xCube += 5;
	}


	//////////// ROTACIONAR ICOSAEDRO
	if (key == '4') {
		rotate_yIcosaedro += 5;
	}
	else if (key == '5') {
		rotate_xIcosaedro -= 5;
	}

	else if (key == '6') {
		rotate_yIcosaedro -= 5;
	}

	else if (key == '8') {
		rotate_xIcosaedro += 5;
	}

}

void idle();

void idle(void)
{

	xRotated += 0.01;
	yRotated += 0.01;
	zRotated += 0.01;
	display();
}

void specialKeys(int key, int x, int y) {

	//  Right arrow - increase rotation by 5 degree
	if (key == GLUT_KEY_RIGHT)
		rotate_y += 5;

	//  Left arrow - decrease rotation by 5 degree
	else if (key == GLUT_KEY_LEFT)
		rotate_y -= 5;

	else if (key == GLUT_KEY_UP)
		rotate_x += 5;

	else if (key == GLUT_KEY_DOWN)
		rotate_x -= 5;


	//  Request display update
	glutPostRedisplay();

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); // Ligar GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Display com Duplo Buffer
	glutInitWindowSize(janela_largura, janela_altura); // tamanho da janela
	glutInitWindowPosition(50, 50); // Pos. onde surge a janela
	glutCreateWindow("desenho 3d"); // Criar Janela
	glEnable(GL_DEPTH_TEST); //
	glutDisplayFunc(display); // imagem
	glutSpecialFunc(specialKeys); //

	glutKeyboardFunc(&keyboard);

	glutReshapeFunc(reshape); // config telas
	glutIdleFunc(idle);
	glutMainLoop(); // loop
	return 0;
}
void reshape(GLsizei largura, GLsizei altura)
{
	if (altura == 0) altura = 1; // previne a divisão por zero
	GLfloat aspecto = (GLfloat)largura / (GLfloat)altura;
	glViewport(0, 0, largura, altura);
	glMatrixMode(GL_PROJECTION); // manipulando matriz de projeção
	glLoadIdentity(); // zerando a matriz
	gluPerspective(45.0f, aspecto, 0.1f, 100.0f);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // configura fundo sem transparencia
	glEnable(GL_DEPTH_TEST); // alunos devem testar
	glShadeModel(GL_SMOOTH); // acabamento com suavização
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // correcao de perspectiva
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // executa a limpeza
	glMatrixMode(GL_MODELVIEW); // operando com a camera de modelos
	// desenho da piramide 3d

	glLoadIdentity();
	glTranslatef(-1.5f, 0.0f, -6.0f); // posiciona a piramide

	glPushMatrix();
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glRotatef(rotate_y, 0.0, 1.0, 0.0);

	///////////// TETRAEDRO //////////////////////
	glBegin(GL_TRIANGLES);
	// triangulo 1 de 4 frente
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	// triangulo 2 de 4 direita
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	// triangulo 3 de 4 atras
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	// triangulo 4 de 4 esquerda
	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();
	glPopMatrix();


	///////////// CUBO //////////////////
	glPushMatrix();
	glTranslatef(4, 1, -1);
	glRotatef(rotate_xCube, 1.0, 0.0, 0.0);
	glRotatef(rotate_yCube, 0.0, 1.0, 0.0);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.1);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	//LADO CIANO (ESQUERDO)
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	//LADO AMARELO (FRENTE)
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();


	//LADO VERMELHO (BAIXO)
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();


	//LADO ROSA
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();

	//LADO AZUL
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();
	glPopMatrix();


	/////////// ICOSAEDRO //////////

	glTranslatef(5, -2, -5);
	glRotatef(rotate_xIcosaedro, 1.0, 0.0, 0.0);
	glRotatef(rotate_yIcosaedro, 0.0, 1.0, 0.0);


	glColor3f(1.0, 0.0, 1.0);
	glScalef(1.5, 1.5, 1.5);
	glutWireIcosahedron(); //drawing color-cube


	glutSwapBuffers(); // trocar a matriz da tela por esta aqui.
}
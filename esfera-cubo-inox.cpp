#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define janela_altura 480
#define janela_largura 640

int on = 1;
float x = 0.0, y = 0.0, z = 0.0;

void reshape(GLsizei largura, GLsizei altura);
void display();
void keyboard(unsigned char key, int a, int b);
void conf_luz();



float padrao[] = { 0.0, 0.0, 0.0, 1.0 };
float mat_ambientee[] = { 0.0, 0.0, 0.0, 1.0 };
float mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
float mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
float alto_brilho[] = { 25.0 };

int main(int argc, char** argv)
{
	glutInit(&argc, argv); // Ligar GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Display com Duplo Buffer
	glutInitWindowSize(janela_largura, janela_altura); // tamanho da janela
	glutInitWindowPosition(50, 50); // Pos. onde surge a janela
	glutCreateWindow("iluminacao"); // Criar Janela
	conf_luz(); // configuração de luz
	glutDisplayFunc(display); // imagem
	glutReshapeFunc(reshape); // config telas
	glutKeyboardFunc(keyboard); // funcoes de teclado
	glutMainLoop(); // loop
	return 0;
}


void conf_luz(void)
{
	float ambiente[] = { 0.0, 0.0, 0.0, 1.0 };
	float diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	float specular[] = { 1.0, 1.0, 1.0, 1.0 };
	float posicao[] = { 0.0 + sin(x * 2 * 3.14 / 360), 3.0, 2.0 + sin(x * 2 * 3.14 / 360), 0.0 };
	float lmodel_ambiente[] = { 0.4, 0.4, 0.4, 1.0 };
	float local_view[] = { 0.0 };
	glClearColor(0.0, 0.1, 0.1, 0.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, posicao);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambiente);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	float mat_ambientee_inox[] = { 0.20f, 0.25f, 0.28f, 1.0f };
	float mat_diffuse_inox[] = { 0.24f, 0.20f, 0.22f, 1.0f };
	float mat_specular_inox[] = { 0.80f, 0.70f, 0.70f, 1.0f };
	float brilho_inox[] = { 80.0f };

	float mat_ambient_cobre[] = { 0.21f, 0.22f, 0.0f, 1.0f };
	float mat_diffuse_cobre[] = { 0.70f, 0.40f, 0.28f, 1.0f };
	float mat_specular_cobre[] = { 0.40f, 0.30f, 0.20f, 1.0f };
	float brilho_cobre[] = { 30.0f };

	if (on) {
		int i = 0;
		while(i<=3){
		
			mat_ambientee[i] = mat_ambient_cobre[i];
			mat_diffuse[i] = mat_diffuse_cobre[i];
			mat_specular[i] = mat_specular_cobre[i];
		
			i++;
		}
		alto_brilho[0] = brilho_cobre[0];

		on = 0;
		
		
	}
	else {
		for (int i = 0; i < 4; i++) {
			mat_ambientee[i] = mat_ambientee_inox[i];
			mat_diffuse[i] = mat_diffuse_inox[i];
			mat_specular[i] = mat_specular_inox[i];
		}

		alto_brilho[0] = brilho_inox[0];
		on = 1;
	}

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


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // executa a limpeza
	glMatrixMode(GL_MODELVIEW); // operando com a camera de modelos

	glLoadIdentity();
	glTranslatef(-1.5f, 0.0f, -6.0f); // posiciona a esfera

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambientee);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, alto_brilho);
	glMaterialfv(GL_FRONT, GL_EMISSION, padrao);
	glutSolidSphere(1.0, 60, 60);

	glTranslatef(3, -0.5f, 1);
	glutSolidCube(1);

	glutSwapBuffers(); // trocar a matriz da tela por esta aqui.
}

void keyboard(unsigned char key, int a, int b) {
	switch (key) {
	
	case 'c': {
		conf_luz();
		glutPostRedisplay();
	} break;



	case 'o': {
		if (on) {
			glDisable(GL_LIGHT0);
			on = 0;
		}
		else {
			glEnable(GL_LIGHT0);
			on = 1;
		}
		glutPostRedisplay();
	} break;
	}
}

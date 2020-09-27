#include <stdio.h>
#include <stdlib.h>
#include <GL\glut.h>
#include <math.h>
#include <time.h>
#include <locale.h>

#define PI 3.1415926535898
#define janela_altura 500
#define janela_largura 800

int posicaoPonteY;
bool explodiuPonte = false;

char plac[20];
char fas[20];

int fase = 1;
int ponteX =0, ponteY= 1200;
int yMovimentoPonte;
int yAleatorioPonte;


int yAleatorioCasa[2];
int yMovimentoCasa;
int casaY[2] = { 200, 300 };
int casaX[2] = { -350, 300 };

int barcosX[6] = { -200, -200,-200 };
int barcosY[3] = { 1800, 1200, 400 };
int yMovimentoBarco[3] = { 0,0,0 };
int yAleatorioBarco[3];

int helicopteroX[3] = { -200, -150, -100 };
int helicopteroY[3] = { 1600, 800, 100 };
int yMovimentoHelic[3] = { 0,0,0 };
int yAleatorioHelic[3];

int posXcombustivel = -20;
int posYcombustivel = 320;
int yMovimentoComb;
int yAleatorioComb;

int opcaomenu = 1;
int opcaoSelecionada = 0;

int bufferY = 0;
int placar = 0;
int posX = 0;
int posY = 200;
int tiroX = 0;
int tiroY = 0;
int randomico = 0;
int vidas = 3;

int contador = 0;
int contador1 = 0;
int contador2 = 0;
int pontuacaomaxima = 0;
int velocidade = 65;

float barraCombustivel = 60;

bool helicoptero[6] = { false };
bool helicopteroEsquerda[6] = { true };
bool barcoEsquerda[6] = { true };
bool barco[3] = { false };
bool tiro = false;
bool perdeu = false;
bool morreu = false;
bool rodando = true;
bool pausado = false;
bool helic = true;
bool barrafinal = false;
bool trocacor = true;
bool explosaoSubmarino = false;
bool combustivel = false;
bool menu = true;
bool animaMenu = true;
bool cor = false;


void display(void);
void animacao(int valor);
void tela(GLsizei w, GLsizei h);
void keyboard(unsigned char tecla, int x, int y);
void SpecialInput(int key, int x, int y);
void Perdeu();
void Morreu();

void DesenhaCasa(int casaX, int yAleatorioCasa);
void DesenhaCombustivel();
void DesenhaHelicoptero(int helicopteroX, int helicopteroY);
void DesenhaTexto(char* string, int x, int y, void* fonte);
void DesenhaAviao();
void DesenhaBala();
void DesenhaBarco(int x, int y);
void DesenhaExplosao();
void DesenhaIcone(int x);
void DesenhaCenario();

void animarCenario();
void animarHelicoptero();
void animarBarco();
void animarCombustivel();

void executarTiro();

void colocarHelicoptero();
void colocarBarco();
void colocarCombustivel();

void colisaoPonte();
void colisaoTiroPonte();
void colisaoBarco();
void colisaoHelicoptero();
void colisaoParede();
void colisaoTiroBarco();
void colisaoTiroHelicoptero();

void DesenhaPonte(int ponteX, int yAleatorioPonte);
void colocarPonte();

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(janela_largura, janela_altura);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Seaquest");
	glutReshapeFunc(tela);
	glutDisplayFunc(display);
	glutKeyboardFunc(&keyboard);
	glutSpecialFunc(SpecialInput);
	glutTimerFunc(100, animacao, 1);
	glutMainLoop();
	return 0;
}

void animarCenario() {

	if (rodando) {
		
		if (fase == 1) {

			yMovimentoHelic[0] -= 4;
			yMovimentoHelic[1] -= 4;
			yMovimentoHelic[2] -= 4;

			yMovimentoBarco[0] -= 4;
			yMovimentoBarco[1] -= 4;
			yMovimentoBarco[2] -= 4;

			yMovimentoComb -= 4;

			yMovimentoCasa -= 4;

			yMovimentoPonte -= 4;
		}

		else if (fase == 2) {

			yMovimentoHelic[0] -= 10;
			yMovimentoHelic[1] -= 10;
			yMovimentoHelic[2] -= 10;

			yMovimentoBarco[0] -= 10;
			yMovimentoBarco[1] -= 10;
			yMovimentoBarco[2] -= 10;

			yMovimentoComb -= 10;

			yMovimentoCasa -= 10;

			yMovimentoPonte -= 10;
		}

	}


}


void colocarCasa() {


	yAleatorioCasa[0] = casaY[0] + yMovimentoCasa;
	if (yAleatorioCasa[0] < -300) {
		yMovimentoCasa = 0;
		casaY[0] = 300;

	}
	yAleatorioCasa[1] = casaY[1] + yMovimentoCasa;
	if (yAleatorioCasa[1] < -300) {
		yMovimentoCasa = 0;
		casaY[1] = 300;

	}


}



void DesenhaCasa(int casaX, int yAleatorioCasa) {
	glPushMatrix();
	//glTranslatef(x, 0, 0);
	glTranslatef(casaX, yAleatorioCasa, 0);
	//CORPO
	glBegin(GL_POLYGON);
	glColor3f(1.000, 1.0, 1.000);
	glVertex2f(0, 135);
	glVertex2f(70, 135);
	glVertex2f(70, 155);
	glVertex2f(0, 155);
	glEnd();

	//JANELAS
	glBegin(GL_POLYGON);
//	glColor3f(0.196, 0.804, 0.196);
	glColor3f(0.196, 0.804, 0.196);
	glVertex2f(5, 140);
	glVertex2f(20, 140);
	glVertex2f(20, 147);
	glVertex2f(5, 147);
	glEnd();

	glBegin(GL_POLYGON);
	//	glColor3f(0.196, 0.804, 0.196);
	glColor3f(0.196, 0.804, 0.196);
	glVertex2f(27, 140);
	glVertex2f(42, 140);
	glVertex2f(42, 147);
	glVertex2f(27, 147);
	glEnd();

	glBegin(GL_POLYGON);
	//	glColor3f(0.196, 0.804, 0.196);
	glColor3f(0.196, 0.804, 0.196);
	glVertex2f(50, 140);
	glVertex2f(65, 140);
	glVertex2f(65, 147);
	glVertex2f(50, 147);
	glEnd();


	//0.196, 0.804, 0.196

	//CORPO
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0, 155);
	glVertex2f(70, 155);
	glVertex2f(70, 151);
	glVertex2f(0, 151);
	glEnd();
	//MASTRO
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(10, 155);
	glVertex2f(65, 155);
	glVertex2f(65, 158);
	glVertex2f(10, 158);
	glEnd();
	//MASTRO
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(20, 158);
	glVertex2f(50, 158);
	glVertex2f(50, 161);
	glVertex2f(20, 161);
	glEnd();

	glPopMatrix();

}

void colocarPonte() {
	
	yAleatorioPonte = ponteY + yMovimentoPonte;

	glColor3f(1, 1, 1);

	if (posY >= yAleatorioPonte + 150 && posY <= yAleatorioPonte + 469) {
		DesenhaTexto((char*)">> FASE 2! <<", -70, -50, GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (posY >= yAleatorioPonte + 269) {

		fase = 2;
			
	}
	
}

void DesenhaPonte(int ponteX, int yAleatorioPonte) {
	//CORPO

	glPushMatrix();
	glTranslatef(ponteX, yAleatorioPonte, 0);

	glBegin(GL_POLYGON);
	glColor3f(0.722, 0.525, 0.043);
	glVertex2f(-220, 163);
	glVertex2f(200, 163);
	glVertex2f(200, 104);
	glVertex2f(-220, 104);
	glEnd();

	////	SUSTENTAÇÃO PONTE	////	
	//SUPERIOR ESQUERDA
	glBegin(GL_POLYGON);
	glColor3f(0.545, 0.271, 0.075);
	glVertex2f(-150, 171);
	glVertex2f(-100, 171);
	glVertex2f(-100, 163);
	glVertex2f(-150, 163);
	glEnd();

	//SUPERIOR DIREITA
	glBegin(GL_POLYGON);
	glColor3f(0.545, 0.271, 0.075);
	glVertex2f(150, 171);
	glVertex2f(100, 171);
	glVertex2f(100, 163);
	glVertex2f(150, 163);
	glEnd();

	//INFERIOR ESQUERDA
	glBegin(GL_POLYGON);
	glColor3f(0.545, 0.271, 0.075);
	glVertex2f(-150, 104);
	glVertex2f(-100, 104);
	glVertex2f(-100, 96);
	glVertex2f(-150, 96);
	glEnd();

	//INFERIOR DIREITA
	glBegin(GL_POLYGON);
	glColor3f(0.545, 0.271, 0.075);
	glVertex2f(150, 104);
	glVertex2f(100, 104);
	glVertex2f(100, 96);
	glVertex2f(150, 96);
	glEnd();

	//LINHAS
	glBegin(GL_POLYGON);
	glColor3f(0.545, 0.271, 0.075);
	glVertex2f(-220, 150);
	glVertex2f(200, 150);
	glVertex2f(200, 147);
	glVertex2f(-220, 147);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.545, 0.271, 0.075);
	glVertex2f(-220, 135);
	glVertex2f(200, 135);
	glVertex2f(200, 132);
	glVertex2f(-220, 132);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.545, 0.271, 0.075);
	glVertex2f(-220, 120);
	glVertex2f(200, 120);
	glVertex2f(200, 117);
	glVertex2f(-220, 117);
	glEnd();

	glPopMatrix();
}


void DesenhaCenario() {
	colocarPonte();
	if (explodiuPonte == false){
		DesenhaPonte(ponteX, yAleatorioPonte);
	}

	colocarCombustivel();
	DesenhaCombustivel();
	colocarHelicoptero();
	DesenhaHelicoptero(helicopteroX[0], yAleatorioHelic[0]);
	DesenhaHelicoptero(helicopteroX[1], yAleatorioHelic[1]);
	DesenhaHelicoptero(helicopteroX[2], yAleatorioHelic[2]);

	colocarBarco();
	DesenhaBarco(barcosX[0], yAleatorioBarco[0]);
	DesenhaBarco(barcosX[1], yAleatorioBarco[1]);
	DesenhaBarco(barcosX[2], yAleatorioBarco[2]);



	//PAREDE ESQUERDA
	glBegin(GL_POLYGON);
	glColor3f(0.196, 0.804, 0.196);
	glVertex3f(-400, 2250, 0); //LIMITE EXTERNO
	glVertex3f(-200, 2250, 0);
	glVertex3f(-200, -220, 0); //LIMITE INTERNO
	glVertex3f(-400, -220, 0);
	glEnd();

	//PAREDE DIREITA
	glBegin(GL_POLYGON);
	glColor3f(0.196, 0.804, 0.196);
	glVertex3f(400, 2250, 0); //LIMITE EXTERNO
	glVertex3f(200, 2250, 0);
	glVertex3f(200, -220, 0); //LIMITE INTERNO
	glVertex3f(400, -220, 0);
	glEnd();


	colocarCasa();
	DesenhaCasa(casaX[0], yAleatorioCasa[0]);
	DesenhaCasa(casaX[1], yAleatorioCasa[1]);


	//FUNDO 
	//FAIXA INFERIOR

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(-450, -220, 0);
	glVertex3f(450, -220, 0);
	glVertex3f(450, -250, 0);
	glVertex3f(-450, -250, 0);
	glEnd();


	glColor3f(0, 1, 0.8);
	//IMPRIME AS CREDENCIAS
	DesenhaTexto((char*)"BRENDA MOURA", -380, -240, GLUT_BITMAP_9_BY_15);
	DesenhaTexto((char*)"RIVER RAID", -30, -240, GLUT_BITMAP_9_BY_15);
	DesenhaTexto((char*)"IFC VIDEIRA", 280, -240, GLUT_BITMAP_9_BY_15);

	//FAIXA DO COMBUSTIVEL
	glBegin(GL_QUADS);
	glColor3f(0.502, 0.502, 0.502);
	glVertex3f(-450, -130, 0);
	glVertex3f(450, -130, 0);
	glVertex3f(450, -220, 0);
	glVertex3f(-450, -220, 0);
	glEnd();

	//BARRA VERMELHA DO COMBUSTIVEL
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex3f(-120, -165, 0);
	glVertex3f(60, -165, 0);
	glVertex3f(60, -195, 0);
	glVertex3f(-120, -195, 0);
	glEnd();

	//BARRA CINZA DO COMBUSTIVEL
	glPushMatrix();
	glBegin(GL_QUADS);
	if (barrafinal == false) glColor3f(0.66, 0.66, 0.66);
	else {
		if (trocacor == true) {
			glColor3f(0.66, 0.66, 0.66);
			contador++;
			if (contador % 3 == 0) trocacor = false;
		}
		else {
			glColor3f(1, 0, 0);
			contador++;
			if (contador % 3 == 0) trocacor = true;
		}
	}
	glVertex3f(-120, -165, 0);
	glVertex3f(barraCombustivel, -165, 0);
	glVertex3f(barraCombustivel, -195, 0);
	glVertex3f(-120, -195, 0);
	glEnd();
	glPopMatrix();

	//FAIXA PRETA EM BAIXO
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex3f(-450, -130, 0);
	glVertex3f(450, -130, 0);
	glVertex3f(450, -133, 0);
	glVertex3f(-450, -133, 0);
	glEnd();

	//PLACAR
	glColor3f(0, 0, 0);

	char qtdVida[2];

	sprintf_s(qtdVida, "%d", vidas);
	DesenhaTexto(qtdVida, -150, -210, GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf_s(plac, "%d", placar);
	DesenhaTexto(plac, 20, -155, GLUT_BITMAP_TIMES_ROMAN_24);

	DesenhaTexto((char*)"Fase:  ", -380, 225, GLUT_BITMAP_9_BY_15);
	sprintf_s(fas, "%d", fase);
	DesenhaTexto(fas, -330, 225, GLUT_BITMAP_9_BY_15);


}


//POSICIONA A RECARGA DE COMBUSTIVEL EM UM X ALEATÓRIO
void colocarCombustivel() {

	yAleatorioComb = posYcombustivel + yMovimentoComb;

	if (yAleatorioComb < -400) {
		yMovimentoComb = 0;
		int aleatorio = (rand() % 10);

		printf(">> ALEATÓRIO: %i", aleatorio);

		//SE GERAR NUMERO PAR A RECARGA DE COMBUSTÍVEL APARECERÁ NA ESQUERDA, SE ÍMPAR NA DIREITA
		if (aleatorio % 2 == 0) {
			posXcombustivel = (rand() % 100) - 180;

		}
		else {
			posXcombustivel = (rand() % 150);
		}
	}

}


void DesenhaCombustivel() {
	//COMBUSTÍVEL

	glPushMatrix();
	glTranslatef(posXcombustivel, yAleatorioComb, 0);
	glBegin(GL_QUADS);
	glColor3f(0.863, 0.078, 0.235);
	glVertex3f(-20, 230, 0);
	glVertex3f(20, 230, 0);
	glVertex3f(20, 210, 0);
	glVertex3f(-20, 210, 0);
	glEnd();
	

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(-20, 210, 0);
	glVertex3f(20, 210, 0);
	glVertex3f(20, 190, 0);
	glVertex3f(-20, 190, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.863, 0.078, 0.235);
	glVertex3f(-20, 190, 0);
	glVertex3f(20, 190, 0);
	glVertex3f(20, 170, 0);
	glVertex3f(-20, 170, 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(-20, 170, 0);
	glVertex3f(20, 170, 0);
	glVertex3f(20, 150, 0);
	glVertex3f(-20, 150, 0);
	glEnd();
	glPopMatrix();
	glColor3f(0.000, 0.000, 0.804);
	DesenhaTexto((char*)"F", posXcombustivel - 4, yAleatorioComb + 215, GLUT_BITMAP_9_BY_15);
	DesenhaTexto((char*)"U", posXcombustivel - 5, yAleatorioComb + 194, GLUT_BITMAP_9_BY_15);
	DesenhaTexto((char*)"E", posXcombustivel - 4, yAleatorioComb + 175, GLUT_BITMAP_9_BY_15);
	DesenhaTexto((char*)"L", posXcombustivel - 4, yAleatorioComb + 156, GLUT_BITMAP_9_BY_15);
	DesenhaTexto((char*)"F", posXcombustivel - 5, yAleatorioComb + 215, GLUT_BITMAP_9_BY_15);
	DesenhaTexto((char*)"U", posXcombustivel - 6, yAleatorioComb + 194, GLUT_BITMAP_9_BY_15);
	DesenhaTexto((char*)"E", posXcombustivel - 5, yAleatorioComb + 175, GLUT_BITMAP_9_BY_15);
	DesenhaTexto((char*)"L", posXcombustivel - 5, yAleatorioComb + 156, GLUT_BITMAP_9_BY_15);
	DesenhaTexto((char*)"F", posXcombustivel - 6, yAleatorioComb + 215, GLUT_BITMAP_9_BY_15);
	DesenhaTexto((char*)"U", posXcombustivel - 7, yAleatorioComb + 194, GLUT_BITMAP_9_BY_15);
	DesenhaTexto((char*)"E", posXcombustivel - 6, yAleatorioComb + 175, GLUT_BITMAP_9_BY_15);
	DesenhaTexto((char*)"L", posXcombustivel - 6, yAleatorioComb + 156, GLUT_BITMAP_9_BY_15);
}


//////////////////////////////			DESENHO AVIÃO				////////////////////////////
void DesenhaAviao() {

	//CORPO
	glPushMatrix();
	glTranslatef(posX, posY, 0);
	glColor3f(1, 1, 0);

	//CORPO AVIAO
	glBegin(GL_POLYGON);
	glVertex3f(-20, -170, 0);
	glVertex3f(-13, -170, 0);
	glVertex3f(-13, -220, 0);
	glVertex3f(-20, -220, 0);
	glEnd();

	//ASA ESQUERDA
	glBegin(GL_POLYGON);
	glVertex3f(-25, -180, 0);
	glVertex3f(-20, -180, 0);
	glVertex3f(-20, -200, 0);
	glVertex3f(-25, -200, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-30, -185, 0);
	glVertex3f(-25, -185, 0);
	glVertex3f(-25, -205, 0);
	glVertex3f(-30, -205, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-35, -190, 0);
	glVertex3f(-30, -190, 0);
	glVertex3f(-30, -210, 0);
	glVertex3f(-35, -210, 0);
	glEnd();

	//ASA DIREITA
	glBegin(GL_POLYGON);
	glVertex3f(-15, -180, 0);
	glVertex3f(-8, -180, 0);
	glVertex3f(-8, -200, 0);
	glVertex3f(-15, -200, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-8, -185, 0);
	glVertex3f(-3, -185, 0);
	glVertex3f(-3, -205, 0);
	glVertex3f(-8, -205, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-3, -190, 0);
	glVertex3f(2, -190, 0);
	glVertex3f(2, -210, 0);
	glVertex3f(-3, -210, 0);
	glEnd();

	//BAIXO DIREITO
	glBegin(GL_POLYGON);
	glVertex3f(-30, -215, 0);
	glVertex3f(-5, -215, 0);
	glVertex3f(-5, -220, 0);
	glVertex3f(-30, -220, 0);
	glEnd();

	glPopMatrix();

}


//////////////////////////////			DESENHA BALA				////////////////////////////
void DesenhaBala() {
	//BALA
	glPushMatrix();
	glTranslatef(tiroX, tiroY, 0);
	glColor3f(0.7, 0.13, 0.13);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	glVertex3f(-20, -170, 0);
	glVertex3f(-13, -170, 0);
	glVertex3f(-13, -180, 0);
	glVertex3f(-20, -180, 0);
	glEnd();
	glPopMatrix();
}

//////////////////////////////			DESENHA TEXTO				////////////////////////////
void DesenhaTexto(char* string, int x, int y, void* fonte) {
	glPushMatrix();
	glRasterPos2f(x, y);
	while (*string) {
		glutBitmapCharacter(fonte, *string++);
	}
	glPopMatrix();
}


void colocarBarco() {
	////////////////////		BARCO 0		////////////////////		 
	// DESATIVA BARCO QUANDO CHEGA NA BASE DA TELA
	yAleatorioBarco[0] = barcosY[0] + yMovimentoBarco[0];
	if (yAleatorioBarco[0] < -300) {

		printf(">> ENTREI 0 \n");
		yMovimentoBarco[0] = 0;
		barcosY[0] = 900;
		barco[0] = false;

	}
	// 
	if (yAleatorioBarco[0] < -300) {
		yMovimentoBarco[0] = 0;
		int aleatorio3 = (rand() % 10);

		//SE GERAR NUMERO PAR A RECARGA DE COMBUSTÍVEL APARECERÁ NA ESQUERDA, SE ÍMPAR NA DIREITA
		if (aleatorio3 % 2 == 0) barcosX[0] = (rand() % 100) - 180;
		else barcosX[0] = (rand() % 150);
	}

	if (barco[0] == false) {
		barco[0] = true;

	}
	////////////////////		BARCO 1		////////////////////		 
	// DESATIVA BARCO QUANDO CHEGA NA BASE DA TELA
	yAleatorioBarco[1] = barcosY[1] + yMovimentoBarco[1];
	if (yAleatorioBarco[1] < -300) {

		printf(">> ENTREI 0 \n");
		yMovimentoBarco[1] = 0;
		barcosY[1] = 500;
		barco[1] = false;

	}
	// 
	if (yAleatorioBarco[1] < -300) {
		yMovimentoBarco[1] = 0;
		int aleatorio4 = (rand() % 10);

		//SE GERAR NUMERO PAR A RECARGA DE COMBUSTÍVEL APARECERÁ NA ESQUERDA, SE ÍMPAR NA DIREITA
		if (aleatorio4 % 2 == 0) barcosX[1] = (rand() % 100) - 180;
		else barcosX[1] = (rand() % 150);
	}

	if (barco[1] == false) {
		barco[1] = true;

	}
	////////////////////		BARCO 2		////////////////////		 
	// DESATIVA BARCO QUANDO CHEGA NA BASE DA TELA
	yAleatorioBarco[2] = barcosY[2] + yMovimentoBarco[2];
	if (yAleatorioBarco[2] < -300) {

		printf(">> ENTREI 0 \n");
		yMovimentoBarco[2] = 0;
		barcosY[2] = 300;
		barco[2] = false;

	}
	// 
	if (yAleatorioBarco[2] < -300) {
		yMovimentoBarco[2] = 0;
		int aleatorio5 = (rand() % 10);

		//SE GERAR NUMERO PAR A RECARGA DE COMBUSTÍVEL APARECERÁ NA ESQUERDA, SE ÍMPAR NA DIREITA
		if (aleatorio5 % 2 == 0) barcosX[2] = (rand() % 100) - 180;
		else barcosX[2] = (rand() % 150);
	}

	if (barco[2] == false) {
		barco[2] = true;

	}

}


//////////////////////////////			DESENHA BARCO				////////////////////////////
void DesenhaBarco(int barcoX, int barcoY) {


	glPushMatrix();
	//glTranslatef(x, 0, 0);
	glTranslatef(barcoX, barcoY, 0);
	//CORPO
	glBegin(GL_POLYGON);
	glColor3f(0.000, 0.749, 1.000);
	glVertex2f(20, 145);
	glVertex2f(70, 145);
	glVertex2f(70, 150);
	glVertex2f(20, 150);
	glEnd();

	//CORPO
	glBegin(GL_POLYGON);
	glColor3f(0.627, 0.322, 0.176);
	glVertex2f(0, 155);
	glVertex2f(90, 155);
	glVertex2f(90, 150);
	glVertex2f(0, 150);
	glEnd();
	//MASTRO
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex2f(20, 155);
	glVertex2f(60, 155);
	glVertex2f(60, 160);
	glVertex2f(20, 160);
	glEnd();
	//MASTRO
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex2f(30, 160);
	glVertex2f(50, 160);
	glVertex2f(50, 165);
	glVertex2f(30, 165);
	glEnd();

	glPopMatrix();

}



//////////////////////////////			DESENHA HELICOPTERO				////////////////////////////
void DesenhaHelicoptero(int helicX, int helicY) {


	glPushMatrix();

	glTranslatef(helicX, helicY, 0);
	//CORPO

	glBegin(GL_POLYGON);
	glColor3f(0.000, 0.000, 0.545);
	glVertex2f(20, 145);
	glVertex2f(80, 145);
	glVertex2f(80, 150);
	glVertex2f(20, 150);
	glEnd();

	//TREM DE POUSO
	glBegin(GL_POLYGON);
	glColor3f(0.412, 0.412, 0.412);
	glVertex2f(50, 140);
	glVertex2f(70, 140);
	glVertex2f(70, 135);
	glVertex2f(50, 135);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.412, 0.412, 0.412);
	glVertex2f(50, 143);
	glVertex2f(55, 143);
	glVertex2f(55, 135);
	glVertex2f(50, 135);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.412, 0.412, 0.412);
	glVertex2f(20, 155);
	glVertex2f(25, 155);
	glVertex2f(25, 140);
	glVertex2f(20, 140);
	glEnd();

	//CABINE
	glBegin(GL_POLYGON);
	glColor3f(0.412, 0.412, 0.412);
	glVertex2f(40, 150);
	glVertex2f(75, 150);
	glVertex2f(75, 155);
	glVertex2f(40, 155);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.412, 0.412, 0.412);
	glVertex2f(50, 155);
	glVertex2f(70, 155);
	glVertex2f(70, 160);
	glVertex2f(50, 160);
	glEnd();

	//HÉLICE
	glBegin(GL_POLYGON);
	glColor3f(1.000, 1.000, 0.000);
	glVertex2f(60, 160);
	glVertex2f(65, 160);
	glVertex2f(65, 170);
	glVertex2f(60, 170);
	glEnd();

	//HÉLICE
	glBegin(GL_POLYGON);
	glColor3f(1.000, 1.000, 0.000);
	glVertex2f(45, 165);
	glVertex2f(80, 165);
	glVertex2f(80, 168);
	glVertex2f(45, 168);
	glEnd();




	glPopMatrix();

}


//////////////////////////////			DESENHA EXPLOSÃO				////////////////////////////
void DesenhaExplosao() {

	//PRIMEIRO POLIGONO
	glPushMatrix();
	if (cor == true) glColor3f(1, 0, 0);
	else glColor3f(1, 1, 0);
	glLineWidth(7);
	glTranslatef(-40, -180, 0);
	glTranslatef(posX, posY, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0, 40);
	glVertex2f(20, 10);
	glVertex2f(60, 60);
	glVertex2f(50, 20);
	glVertex2f(80, 40);
	glVertex2f(70, 5);
	glVertex2f(100, 5);
	glVertex2f(70, -10);
	glVertex2f(115, -20);
	glVertex2f(60, -30);
	glVertex2f(70, -55);
	glVertex2f(30, -40);
	glVertex2f(10, -60);
	glVertex2f(0, -35);
	glVertex2f(-20, -65);
	glVertex2f(-15, -30);
	glVertex2f(-60, -20);
	glVertex2f(-15, -5);
	glVertex2f(-50, 20);
	glVertex2f(-10, 10);
	glVertex2f(0, 40);
	glEnd();

	//SEGUNDO POLIGONO
	if (cor == false) glColor3f(1, 0, 0);
	else glColor3f(1, 1, 0);
	glLineWidth(7);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0, 30);
	glVertex2f(10, 0);
	glVertex2f(50, 50);
	glVertex2f(40, 10);
	glVertex2f(70, 30);
	glVertex2f(60, 0);
	glVertex2f(90, 0);
	glVertex2f(60, 0);
	glVertex2f(105, -10);
	glVertex2f(50, -20);
	glVertex2f(60, -45);
	glVertex2f(20, -30);
	glVertex2f(0, -50);
	glVertex2f(0, -25);
	glVertex2f(-10, -55);
	glVertex2f(-5, -20);
	glVertex2f(-50, -10);
	glVertex2f(-5, 0);
	glVertex2f(-40, 10);
	glVertex2f(0, 0);
	glVertex2f(0, 30);
	glEnd();

	//TERCEIRO POLIGONO
	if (cor == true) glColor3f(1, 0, 0);
	else glColor3f(1, 1, 0);
	glLineWidth(7);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0, 20);
	glVertex2f(0, 0);
	glVertex2f(40, 40);
	glVertex2f(30, 0);
	glVertex2f(60, 20);
	glVertex2f(50, 0);
	glVertex2f(80, 0);
	glVertex2f(50, 0);
	glVertex2f(95, 0);
	glVertex2f(40, -10);
	glVertex2f(50, -35);
	glVertex2f(10, -20);
	glVertex2f(0, -40);
	glVertex2f(0, -15);
	glVertex2f(0, -45);
	glVertex2f(0, -10);
	glVertex2f(-40, 0);
	glVertex2f(0, 0);
	glVertex2f(-30, 0);
	glVertex2f(0, 0);
	glVertex2f(0, 20);
	glEnd();

	//QUARTO POLIGONO
	if (cor == false) glColor3f(1, 0, 0);
	else glColor3f(1, 1, 0);
	glLineWidth(7);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0, 10);
	glVertex2f(0, 0);
	glVertex2f(30, 30);
	glVertex2f(20, 0);
	glVertex2f(50, 10);
	glVertex2f(40, 0);
	glVertex2f(70, 0);
	glVertex2f(40, 0);
	glVertex2f(85, 0);
	glVertex2f(30, 0);
	glVertex2f(40, -25);
	glVertex2f(0, -10);
	glVertex2f(0, -30);
	glVertex2f(0, -5);
	glVertex2f(0, -35);
	glVertex2f(0, 0);
	glVertex2f(-30, 0);
	glVertex2f(0, 0);
	glVertex2f(-20, 0);
	glVertex2f(0, 0);
	glVertex2f(0, 10);
	glEnd();
	glPopMatrix();

}

//////////////////////////////			DESENHA ICONE				////////////////////////////
void DesenhaIcone(int x) {
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(-75, x, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 7);
	glVertex2f(0, -7);
	glVertex2f(30, 0);
	glEnd();
	glPopMatrix();
}

//////////////////////////////			ANIMAR combustivel				////////////////////////////
void animarCombustivel() {
	//ANIMAR A BARRA DE OXIGÊNIO
	if (barraCombustivel < -30) barrafinal = true;
	else barrafinal = false;

	//if (posY >= 300 && posY <= 430 && posX >= -40 && posX <= 20) {
	if (posY >= yAleatorioComb + 320 && posY <= yAleatorioComb + 450
		&& posX >= posXcombustivel - 20 && posX <= posXcombustivel + 40) {

		//if (barraCombustivel < 0) {
		barraCombustivel += 10;
		if (barraCombustivel > 0) barraCombustivel = 60;
		//}
	}
	else {
		if (barraCombustivel > -120) {
			barraCombustivel -= 0.5;

		}
		else {
			explosaoSubmarino = true;
			barrafinal = false;
			barraCombustivel += 60;
		}
	}
}


//////////////////////////////			ANIMAR HELICÓPTERO				////////////////////////////
void animarHelicoptero() {

	//ANIMAÇÃO BARCO 00
	if (helicoptero[0] == true) {
		if (helicopteroEsquerda[0]) {
			helicopteroX[0] += 5;
			if (helicopteroX[0] >= 130) {
				helicopteroEsquerda[0] = false;

			}
		}
		else {
			helicopteroX[0] -= 5;
			if (helicopteroX[0] <= -210) {
				helicopteroEsquerda[0] = true;
			}
		}
	}
	//ANIMAÇÃO BARCO 01
	if (helicoptero[1] == true) {
		if (helicopteroEsquerda[1]) {
			helicopteroX[1] += 5;
			if (helicopteroX[1] >= 130) {
				helicopteroEsquerda[1] = false;
			}
		}
		else {
			helicopteroX[1] -= 5;
			if (helicopteroX[1] <= -210) {
				helicopteroEsquerda[1] = true;
			}
		}
	}
	//ANIMAÇÃO BARCO 02
	if (helicoptero[2] == true) {
		if (helicopteroEsquerda[2]) {
			helicopteroX[2] += 5;
			if (helicopteroX[2] >= 130) {
				helicopteroEsquerda[2] = false;
			}
		}
		else {
			helicopteroX[2] -= 5;
			if (helicopteroX[2] <= -210) {
				helicopteroEsquerda[2] = true;
			}
		}
	}

}


void colocarHelicoptero() {

	////////////////////		HELICOPTERO 0		////////////////////		 
	// DESATIVA HELICOPTERO QUANDO CHEGA NA BASE DA TELA
	yAleatorioHelic[0] = helicopteroY[0] + yMovimentoHelic[0];
	if (yAleatorioHelic[0] < -300) {

		printf(">> ENTREI 0 \n");
		yMovimentoHelic[0] = 0;
		helicopteroY[0] = 200;
		helicoptero[0] = false;

	}
	// 
	if (yAleatorioHelic[0] < -300) {
		yMovimentoHelic[0] = 0;
		int aleatorio0 = (rand() % 10);

		//SE GERAR NUMERO PAR A RECARGA DE COMBUSTÍVEL APARECERÁ NA ESQUERDA, SE ÍMPAR NA DIREITA
		if (aleatorio0 % 2 == 0) helicopteroX[0] = (rand() % 100) - 180;
		else helicopteroX[0] = (rand() % 150);
	}

	if (helicoptero[0] == false) {
		helicoptero[0] = true;

	}

	////////////////////		HELICOPTERO 1		////////////////////		
	//SE O HELICOPTERO 1 ESTA FORA ELE É CHAMADO
	yAleatorioHelic[1] = helicopteroY[1] + yMovimentoHelic[1];

	if (yAleatorioHelic[1] < -300) {
		printf(">> ENTREI 1 \n");
		yMovimentoHelic[1] = 0;
		helicopteroY[1] = 400;
		helicoptero[1] = false;
	}


	if (yAleatorioHelic[1] < -300) {
		yMovimentoHelic[1] = 0;
		int aleatorio1 = (rand() % 10);

		//SE GERAR NUMERO PAR A RECARGA DE COMBUSTÍVEL APARECERÁ NA ESQUERDA, SE ÍMPAR NA DIREITA
		if (aleatorio1 % 2 == 0) helicopteroX[1] = (rand() % 100) - 180;
		else helicopteroX[1] = (rand() % 150);
	}


	if (helicoptero[1] == false) {
		helicoptero[1] = true;
	}

	////////////////////		HELICOPTERO 2		////////////////////		
	//SE O HELICOPTERO 2 ESTA FORA ELE É CHAMADO
	yAleatorioHelic[2] = helicopteroY[2] + yMovimentoHelic[2];

	if (yAleatorioHelic[2] < -300) {
		printf(">> ENTREI 2 \n");
		yMovimentoHelic[2] = 0;
		helicopteroY[2] = 100;
		helicoptero[2] = false;
	}



	if (yAleatorioHelic[2] < -300) {
		yMovimentoHelic[2] = 0;
		int aleatorio2 = (rand() % 10);

		//SE GERAR NUMERO PAR A RECARGA DE COMBUSTÍVEL APARECERÁ NA ESQUERDA, SE ÍMPAR NA DIREITA
		if (aleatorio2 % 2 == 0) helicopteroX[2] = (rand() % 100) - 180;
		else helicopteroX[2] = (rand() % 150);
	}

	if (helicoptero[2] == false) {
		helicoptero[2] = true;

	}

}



//////////////////////////////			ANIMAR BARCO				////////////////////////////
void animarBarco() {

	//ANIMAÇÃO BARCO 00
	if (barcoEsquerda[0]) {
		barcosX[0] += 5;
		if (barcosX[0] >= 110) {
			barcoEsquerda[0] = false;
		}
	}
	else {
		barcosX[0] -= 5;
		if (barcosX[0] <= -200) {
			barcoEsquerda[0] = true;
		}
	}

	//ANIMAÇÃO BARCO 01
	if (barcoEsquerda[1]) {
		barcosX[1] += 5;
		if (barcosX[1] >= 110) {
			barcoEsquerda[1] = false;
		}
	}
	else {
		barcosX[1] -= 5;
		if (barcosX[1] <= -200) {
			barcoEsquerda[1] = true;
		}
	}

	//ANIMAÇÃO BARCO 02
	if (barcoEsquerda[2]) {
		barcosX[2] += 5;
		if (barcosX[2] >= 110) {
			barcoEsquerda[2] = false;
		}
	}
	else {
		barcosX[2] -= 5;
		if (barcosX[2] <= -200) {
			barcoEsquerda[2] = true;
		}
	}

	//ANIMAÇÃO BARCO 03
	if (barcoEsquerda[3]) {
		barcosX[3] += 5;
		if (barcosX[3] >= 100) {
			barcoEsquerda[3] = false;
		}
	}
	else {
		barcosX[3] -= 5;
		if (barcosX[3] <= -200) {
			barcoEsquerda[3] = true;
		}
	}

	//ANIMAÇÃO BARCO 04
	if (barcoEsquerda[4]) {
		barcosX[4] += 5;
		if (barcosX[4] >= 110) {
			barcoEsquerda[4] = false;
		}
	}
	else {
		barcosX[4] -= 5;
		if (barcosX[4] <= -200) {
			barcoEsquerda[4] = true;
		}
	}

	//ANIMAÇÃO BARCO 05
	if (barcoEsquerda[5]) {
		barcosX[5] += 5;
		if (barcosX[5] >= 100) {
			barcoEsquerda[5] = false;
		}
	}
	else {
		barcosX[5] -= 5;
		if (barcosX[5] <= -200) {
			barcoEsquerda[5] = true;
		}
	}

}


//////////////////////////////			EXECUTAR TIRO				////////////////////////////
void executarTiro() {
	//EXECUTA O TIRO SE BASEANDO NO LADO DO SUBMARINO
	if (tiro == true) {
		tiroY += 90;
		if (tiroY >= 600) {
			tiro = false;
			tiroY = posY;

		}
	}
}

void colisaoPonte() {
	
	if(explodiuPonte == false){
		if (posY >= yAleatorioPonte + 269) {
			explosaoSubmarino = true;
			explodiuPonte == true;
		
		}
	}
}


void colisaoTiroPonte() {
	
	
	if (tiroY >= yAleatorioPonte + 500) {
		
		explodiuPonte = true;
	}
}


//////////////////////////////			COLISAO BARCOS				////////////////////////////
void colisaoBarco() {

	//////////////////					BARCO 00				////////////////////
	if (posX >= barcosX[0] && posX <= barcosX[0] + 125 &&
		posY > yAleatorioBarco[0] + 310 && posY < yAleatorioBarco[0] + 385) {
		barcoEsquerda[0] = true;
		barco[0] = false;
		explosaoSubmarino = true;


	}

	//////////////////					BARCO 01				////////////////////	
	if (posX >= barcosX[1] + 10 && posX < barcosX[1] + 125 &&
		posY > yAleatorioBarco[1] + 310 && posY < yAleatorioBarco[1] + 385) {
		barcoEsquerda[1] = true;
		barco[1] = false;
		explosaoSubmarino = true;
	}

	//////////////////					BARCO 02				////////////////////
	if (posX >= barcosX[2] && posX <= barcosX[2] + 125 &&
		posY > yAleatorioBarco[2] + 310 && posY < yAleatorioBarco[2] + 385) {
		barcoEsquerda[2] = true;
		barco[2] = false;
		explosaoSubmarino = true;
	}



}


void colisaoHelicoptero() {


	//////////////////					HELICÓPTERO 00				////////////////////
	if (posX >= helicopteroX[0] && posX <= helicopteroX[0] + 125 &&
		posY > yAleatorioHelic[0] + 310 && posY < yAleatorioHelic[0] + 385) {
		helicopteroEsquerda[0] = true;
		//helicopteroX[0] = -220;
		helicoptero[0] = false;
		explosaoSubmarino = true;
	}

	//////////////////					HELICÓPTERO 01				////////////////////	
	if (posX >= helicopteroX[1] + 10 && posX < helicopteroX[1] + 125 &&
		posY > yAleatorioHelic[1] + 310 && posY < yAleatorioHelic[1] + 385) {
		helicopteroEsquerda[1] = true;
		//helicopteroX[1] = -220;
		helicoptero[1] = false;
		explosaoSubmarino = true;
	}


	//////////////////					HELICÓPTERO 02				////////////////////
	if (posX >= helicopteroX[2] && posX <= helicopteroX[2] + 125 &&
		posY > yAleatorioHelic[2] + 310 && posY < yAleatorioHelic[2] + 385) {
		helicopteroEsquerda[2] = true;
		//helicopteroX[2] = -220;
		helicoptero[2] = false;
		explosaoSubmarino = true;
	}

}


void colisaoParede() {

	if (posX - 30 <= -200 || posX >= 200) {

		explosaoSubmarino = true;
		barrafinal = false;
	}
}

void colisaoTiroBarco() {

	if (tiro == true) {

		// ESQUERDA   /// DIREITA
		if (tiroX >= barcosX[0] + 30 && tiroX - 80 <= barcosX[0] &&
			tiroY - 300 >= yAleatorioBarco[0]) {
			printf("***********PEW**************");
			//barcosX[0] = -200;
			placar += 30;

			yMovimentoBarco[0] = 0;
			barcosY[0] = 750;

			barco[0] = false;
		}


		if (tiroX >= barcosX[1] + 30 && tiroX - 80 <= barcosX[1] &&
			tiroY - 300 >= yAleatorioBarco[1]) {
			printf("***********PEW**************");

			//barcosX[1] = -200;
			placar += 30;

			yMovimentoBarco[1] = 0;
			barcosY[1] = 500;

			barco[1] = false;
		}

		if (tiroX >= barcosX[2] + 30 && tiroX - 80 <= barcosX[2] &&
			tiroY - 300 >= yAleatorioBarco[2]) {
			printf("***********PEW**************");

			//barcosX[2] = -200;
			yMovimentoBarco[2] = 0;
			barcosY[2] = 250;

			placar += 30;
			barco[2] = false;
		}
	}
}

void colisaoTiroHelicoptero() {


	if (tiro == true) {
		// ESQUERDA   /// DIREITA
		if (tiroX >= helicopteroX[0] + 45 && tiroX - 80 <= helicopteroX[0] &&
			tiroY - 300 >= yAleatorioHelic[0]) {
			yMovimentoHelic[0] = 0;
			helicopteroY[0] = 200;

			placar += 30;
			helicoptero[0] = false;
		}

		if (tiroX >= helicopteroX[1] + 45 && tiroX - 80 <= helicopteroX[1] &&
			tiroY - 300 >= yAleatorioHelic[1]) {
			helicopteroY[1] = 300;
			yMovimentoHelic[1] = 0;
			placar += 30;
			helicoptero[1] = false;
		}

		if (tiroX >= helicopteroX[2] + 45 && tiroX - 80 <= helicopteroX[2] &&
			tiroY - 300 >= yAleatorioHelic[2]) {
			helicopteroY[2] = 250;
			yMovimentoHelic[2] = 0;
			placar += 30;
			helicoptero[2] = false;
		}
	}


}


//////////////////////////////			PERDEU				////////////////////////////
void Perdeu() {
	//SE PERDER UMA VIDA
	if (perdeu == true) {
		perdeu = false;
		vidas--;
		contador = 0;
		contador1 = 0;
		contador2 = 0;

		//barcoesquerda = true;

		barco[0] = true;
		barco[1] = true;
		barco[2] = true;

		helicopteroX[0] = -200;
		helicopteroX[1] = -150;
		helicopteroX[2] = -100;


		helicopteroY[0] = 900;
		helicopteroY[1] = 500;
		helicopteroY[2] = 100;

		yMovimentoHelic[0] = 0;
		yMovimentoHelic[1] = 0;
		yMovimentoHelic[2] = 0;


		barcosX[0] = -200;
		barcosX[1] = -150;
		barcosX[2] = -100;


		barcosY[0] = 800;
		barcosY[1] = 200;
		barcosY[2] = 100;

		yMovimentoBarco[0] = 0;
		yMovimentoBarco[1] = 0;
		yMovimentoBarco[2] = 0;

		barraCombustivel = 60;

		if (vidas == 0) morreu = true;
	}
}

//////////////////////////////			MORREU				////////////////////////////
void Morreu() {
	if (morreu == true) {
		if (placar > pontuacaomaxima) pontuacaomaxima = placar;

		helicopteroX[0] = -200;
		helicopteroX[1] = -150;
		helicopteroX[2] = -100;


		helicopteroY[0] = 900;
		helicopteroY[1] = 500;
		helicopteroY[2] = 100;

		yMovimentoHelic[0] = 0;
		yMovimentoHelic[1] = 0;
		yMovimentoHelic[2] = 0;

		barcosX[0] = -200;
		barcosX[1] = -150;
		barcosX[2] = -100;


		barcosY[0] = 800;
		barcosY[1] = 200;
		barcosY[2] = 100;

		yMovimentoBarco[0] = 0;
		yMovimentoBarco[1] = 0;
		yMovimentoBarco[2] = 0;



		rodando = false;
		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex2f(-150, 100);
		glVertex2f(150, 100);
		glVertex2f(150, -100);
		glVertex2f(-150, -100);
		glEnd();
		glColor3f(1, 0, 0);
		DesenhaTexto((char*)"GAME OVER", -70, 0, GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

//////////////////////////////			DESENHA O RESTANTE			////////////////////////////
void desenhar() {
	if (menu == true) {
		if (opcaoSelecionada == 0) {
			switch (opcaomenu) {
			case 1:
				DesenhaIcone(47);
				break;
			case 2:
				DesenhaIcone(6);
				break;
			case 3:
				DesenhaIcone(-35);
				break;
			default:
				printf("W.O.");
				break;
			}
		}


		glColor3f(1, 1, 1);
		char string[50];
		sprintf_s(string, "Pontuacao maxima: %d", pontuacaomaxima);
		DesenhaTexto(string, -390, 230, GLUT_BITMAP_8_BY_13);
		DesenhaTexto((char*)"RIVER RAID", -30, 180, GLUT_BITMAP_TIMES_ROMAN_24);


		if (opcaoSelecionada == 0) {
			DesenhaTexto((char*)"- Use as setas para mover - ", -50, 110, GLUT_BITMAP_HELVETICA_12);
			if (animaMenu == true) DesenhaTexto((char*)"- Tecle 0 para selecionar - ", -48, 80, GLUT_BITMAP_HELVETICA_12);
			DesenhaTexto((char*)"- Iniciar jogo", -40, 40, GLUT_BITMAP_HELVETICA_18);
			DesenhaTexto((char*)"- Regras do jogo", -40, 0, GLUT_BITMAP_HELVETICA_18);
			DesenhaTexto((char*)"- Controles", -40, -40, GLUT_BITMAP_HELVETICA_18);
		}

		if (opcaoSelecionada == 2) {
			if (animaMenu == true) DesenhaTexto((char*)"- Tecle 0 para voltar - ", -48, 80, GLUT_BITMAP_HELVETICA_12);

			DesenhaHelicoptero(-175, -130);
			glColor3f(1, 1, 1);
			DesenhaTexto((char*)" - 30 Pontos ao destruir. - Colidindo morre.", -80, 25, GLUT_BITMAP_8_BY_13);


			DesenhaBarco(-170, -195);
			glColor3f(1, 1, 1);

			
			DesenhaTexto((char*)" - 20 Pontos ao destruir. - Colidindo morre.", -80, -45, GLUT_BITMAP_8_BY_13);

			glPushMatrix();
			glTranslatef(-100, -320, 0);
			DesenhaCombustivel();
			glPopMatrix();
			glColor3f(1, 1, 1);
			DesenhaTexto((char*)" - Recarrega o combustível", -80, -135, GLUT_BITMAP_8_BY_13);

			glColor3f(1, 1, 1);
			DesenhaTexto((char*)" * Colidindo com as paredes morre.", -80, -200, GLUT_BITMAP_8_BY_13);

		}
		if (opcaoSelecionada == 3) {
			if (animaMenu == true) DesenhaTexto((char*)"- Tecle 0 para voltar - ", -48, 80, GLUT_BITMAP_HELVETICA_12);
			DesenhaTexto((char*)"0", -80, 30, GLUT_BITMAP_TIMES_ROMAN_24);
			DesenhaTexto((char*)" - Atira", -40, 34, GLUT_BITMAP_9_BY_15);

			DesenhaTexto((char*)"W", -80, 0, GLUT_BITMAP_TIMES_ROMAN_24);
			DesenhaTexto((char*)" - Acima", -40, 4, GLUT_BITMAP_9_BY_15);

			DesenhaTexto((char*)"A", -80, -30, GLUT_BITMAP_TIMES_ROMAN_24);
			DesenhaTexto((char*)" - Esquerda", -40, -26, GLUT_BITMAP_9_BY_15);

			DesenhaTexto((char*)"S", -80, -60, GLUT_BITMAP_TIMES_ROMAN_24);
			DesenhaTexto((char*)" - Abaixo", -40, -56, GLUT_BITMAP_9_BY_15);

			DesenhaTexto((char*)"D", -80, -90, GLUT_BITMAP_TIMES_ROMAN_24);
			DesenhaTexto((char*)" - Direita", -40, -86, GLUT_BITMAP_9_BY_15);

			DesenhaTexto((char*)"P", -80, -120, GLUT_BITMAP_TIMES_ROMAN_24);
			DesenhaTexto((char*)" - Pause", -40, -118, GLUT_BITMAP_9_BY_15);


		}

		DesenhaTexto((char*)"BRENDA MOURA", -380, -240, GLUT_BITMAP_9_BY_15);
		DesenhaTexto((char*)"IFC VIDEIRA", 280, -240, GLUT_BITMAP_9_BY_15);
	}
	else {

		DesenhaCenario();
		animarCenario();
		DesenhaBala();
		DesenhaAviao();


		if (explosaoSubmarino == true) DesenhaExplosao();

		//SE PERDER UMA VIDA
		glColor3f(0, 0, 0);
		if (pausado == false && rodando == false && combustivel == false && morreu == false && explosaoSubmarino == false) {
			DesenhaTexto((char*)"Tecle 0 para Continuar!", -100, 0, GLUT_BITMAP_TIMES_ROMAN_24);
		}
		//SE PAUSAR
		glColor3f(0, 0, 0);
		if (pausado && rodando == false) {
			DesenhaTexto((char*)"PAUSE", -20, 20, GLUT_BITMAP_TIMES_ROMAN_24);
			DesenhaTexto((char*)"Tecle P para Continuar!", -100, 0, GLUT_BITMAP_TIMES_ROMAN_24);
		}
		//SE PERDER UMA VIDA
		Perdeu();
		//SE ACABAR AS VIDAS
		Morreu();
	}
}
void animacao(int valor) {
	if (menu == true) {
		contador1++;
		if (contador1 % 5 == 0) {
			if (animaMenu == false) animaMenu = true;
			else animaMenu = false;
		}

	}
	else {
		//SE O JOGO ESTÁ ATIVO
		if (rodando) {

			animarCombustivel();

			executarTiro();


			animarBarco();
			animarHelicoptero();

			colisaoParede();
			colisaoBarco();
			colisaoPonte();
			colisaoTiroPonte();
			colisaoHelicoptero();
			colisaoTiroBarco();
			colisaoTiroHelicoptero();

		}

		//QUANDO O AVIÃO MORRE
		if (explosaoSubmarino == true) {
			rodando = false;
			if (cor == false) cor = true;
			else cor = false;
			contador2++;

			if (contador2 == 20) {
				perdeu = true;
				explosaoSubmarino = false;
			}
		}
	}

	glutPostRedisplay();
	glutTimerFunc(velocidade, animacao, 1);
}
void keyboard(unsigned char tecla, int x, int y) {
	if (pausado == false) {
		if (tecla == 'w' || tecla == 'W') {
			posY += 10;
			tiroY += 10;
		}
		if (tecla == 's' || tecla == 'S') {
			posY -= 10;
			tiroY -= 10;
			if (posY < 100) {
				posY = 100;
				tiroY = 100;
			}

		}
		if (tecla == 'a' || tecla == 'A') {
			posX -= 20;				//SE DESLOCA PARA OS LADOS
			tiroX -= 20;   //// faz o tiro acompanhar o avião


		}
		if (tecla == 'd' || tecla == 'D') {
			posX += 20;			 // SE DESLOCA PARA OS LADOS
			tiroX += 20;  //// faz o tiro acompanhar o avião
		}
	}

	if (tecla == '0') {
		if (morreu == true) {
			menu = true;
			morreu = false;
			opcaoSelecionada = 0;
			return;
		}
		if (menu == true) {
			if (opcaomenu == 1 && opcaoSelecionada == 0) {
				opcaoSelecionada = 1;
				menu = false;
				vidas = 3;
				rodando = true;
				placar = 0;
				posX = 0;
				posY = 100;
				tiroX = 0;
				tiroY = 100;
				return;
			}
			if (opcaoSelecionada == 3 || opcaoSelecionada == 2) {
				opcaoSelecionada = 0;
				opcaomenu = 1;
			}
			if (opcaomenu == 2) opcaoSelecionada = 2;
			if (opcaomenu == 3) opcaoSelecionada = 3;
			return;
		}
		if (rodando == false && pausado == false) {
			rodando = true;
			return;
		}
		if (tiro == false) tiro = true;
	}

	if (tecla == 'p' || tecla == 'P') {
		if (pausado) {
			pausado = false;
			rodando = true;
		}
		else {
			pausado = true;
			rodando = false;
		}
	}

	glutPostRedisplay();
}
void SpecialInput(int key, int x, int y) {
	if (key == GLUT_KEY_UP) {
		if (opcaomenu > 1 && opcaoSelecionada == 0) opcaomenu--;
	}
	if (key == GLUT_KEY_DOWN) {
		if (opcaomenu < 3 && opcaoSelecionada == 0) opcaomenu++;
	}
	glutPostRedisplay();
}

void display() {
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	if (menu == true) glClearColor(0, 0, 0, 1);
	else glClearColor(0.000, 0.000, 0.804,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(janela_largura / 2, janela_altura / 2, 0);
	glViewport(0, 0, janela_largura, janela_altura);
	desenhar();
	glutSwapBuffers();
}
void tela(GLsizei w, GLsizei h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, janela_largura, 0, janela_altura);
	glMatrixMode(GL_MODELVIEW);
}
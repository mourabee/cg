// RotacaoObjetos.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>



#define PI 3.1415926535898
#define janela_altura 400;
#define janela_largura 600;


void display(void);
void tela(GLsizei w, GLsizei h);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // quantidade de buffer de cores e que o padrao de cores é RGB ou RGBA
   //glutFullScreen();  // full screen
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100); // posicao inicial da janela
    glutCreateWindow("rotacao");   /// cria a janela

    glutReshapeFunc(&tela); //
    glutDisplayFunc(display);
    glutMainLoop();

    //init();

    return 0;
}



void desenhar() {


    glPushMatrix();
    glTranslatef(100, 0, 0);

    GLfloat circ_pnt = 100;
    GLfloat angulo, raioFundoX = 200.0f, raioFundoY = 200.0f;


    //////////////// CIRCULO FUNDO //////////////////////
    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++) {

        if (i < circ_pnt) {
            glColor3f(0.255, 0.412, 0.882);
        }

        angulo = (2 * PI * i) / circ_pnt;

        //coordenada X             |
        glVertex2f(cos(angulo) * raioFundoX, sin(angulo) * raioFundoY);
        printf("%f    %f\n", cos(angulo) * raioFundoX, sin(angulo) * raioFundoY);
        glColor3f(1.0, 1.0, 1.0);
    }
    glEnd();

    glPopMatrix();


    //////////////// CIRCULO FUNDO //////////////////////



    GLfloat raioFundo2X = 180.0f, raioFundo2Y = 180.0f;

    glPushMatrix();
    glTranslatef(100, 0, 0);

    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++) {

        if (i < circ_pnt) {
            glColor3f(0.686, 0.933, 0.933);
        }

        angulo = (2 * PI * i) / circ_pnt;

        //coordenada X             |
        glVertex2f(cos(angulo) * raioFundo2X, sin(angulo) * raioFundo2Y);
        printf("%f    %f\n", cos(angulo) * raioFundo2X, sin(angulo) * raioFundo2Y);
        glColor3f(1.0, 1.0, 1.0);
    }
    glEnd();

    glPopMatrix();





    //GLfloat circ_pnt = 100;

    GLfloat ang, raioX = 50.0f, raioY = 70.0f;

    /////////OVO 1/////////////////

    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++) {

        if (i < circ_pnt / 20) {
            glColor3f(1.0, 1.0, 0.0);
        }
        else {
            glColor3f(1.0, 1.0, 1.0);

        }

        ang = (2 * PI * i) / circ_pnt;

        //coordenada X             |
        glVertex2f(cos(ang) * raioX, sin(ang) * raioY);
        printf("%f    %f\n", cos(ang) * raioX, sin(ang) * raioY);
        glColor3f(1.0, 1.0, 1.0);
    }
    glEnd();

    glPushMatrix(); //empilho na memoria ram a matriz de modelagem



    ///////////////// OVO 2 //////////////////////
    glTranslatef(100, 0, 0); //desloquei a matriz em 150  (x pra direit
    glColor3f(0, 1.0, 0);

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++) {
        if (i < circ_pnt / 20) {
            glColor3f(0.0, 0.0, 1.0);
        }
        else {
            glColor3f(1.0, 1.0, 1.0);

        }


        ang = (2 * PI * i) / circ_pnt;

        //coordenada X             |
        glVertex2f(cos(ang) * raioX, sin(ang) * raioY);
        printf("%f    %f\n", cos(ang) * raioX, sin(ang) * raioY);
    }
    glEnd();

    //////////////// OVO 3 //////////////////////
    glTranslatef(100, 0, 0);
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++) {

        if (i < circ_pnt / 20) {
            glColor3f(1.0, 0.0, 0.0);
        }
        else {
            glColor3f(1.0, 1.0, 1.0);

        }


        ang = (2 * PI * i) / circ_pnt;

        //coordenada X             |
        glVertex2f(cos(ang) * raioX, sin(ang) * raioY);
        printf("%f    %f\n", cos(ang) * raioX, sin(ang) * raioY);
    }
    glEnd();


    //////////////// CESTA //////////////////////
    glColor3f(0.255, 0.412, 0.882);
    glBegin(GL_POLYGON);
    glVertex2i(-300, -10);
    glVertex2i(100, -10);
    glVertex2i(0, -80);
    glColor3f(0.000, 0.749, 1.000);
    glVertex2i(-200, -80);

    glEnd();


    ////////////////ARCO CESTA ////////////////

    GLfloat circulo_pnt = 100;
    GLfloat raioArcoX = 180.0f, raioArcoY = 180.0f;

    glLineWidth(4.5);
    glTranslatef(-100, -25, 0);

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < circulo_pnt / 2; i++) {
        if (i < circ_pnt / 10) {
            glColor3f(0.255, 0.412, 0.882);
        }
        else {
            //glColor3f(1.0, 1.0, 1.0);

        }
        ang = (2 * PI * i) / circulo_pnt;

        //coordenada X             |
        glVertex2f(cos(ang) * raioArcoX, sin(ang) * raioArcoY);
        printf("%f    %f\n", cos(ang) * raioArcoX, sin(ang) * raioArcoY);
    }
    glEnd();





    /**********************************************************************/
                            // FACE //
    /**********************************************************************/

            //////////// OLHO ESQUERDO 1 /////////////////////
    glPushMatrix();
    GLfloat raioOlho1X = 5.0f, raioOlho1Y = 5.0f;

    glTranslatef(-120, 50, 0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++) {
        ang = (2 * PI * i) / circ_pnt;
        //coordenada X             |
        glVertex2f(cos(ang) * raioOlho1X, sin(ang) * raioOlho1Y);
        printf("%f    %f\n", cos(ang) * raioOlho1X, sin(ang) * raioOlho1Y);
    }
    glEnd();
    glPopMatrix();


    //////////// OLHO DIREITO 1 /////////////////////
    glPushMatrix();
    GLfloat raioOlho2X = 5.0f, raioOlho2Y = 5.0f;

    glTranslatef(-80, 50, 0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++) {
        ang = (2 * PI * i) / circ_pnt;
        //coordenada X             |
        glVertex2f(cos(ang) * raioOlho2X, sin(ang) * raioOlho2Y);
        printf("%f    %f\n", cos(ang) * raioOlho2X, sin(ang) * raioOlho2Y);
    }
    glEnd();
    glPopMatrix();


    //////////// BOCA /////////////////////
    glPushMatrix();
    GLfloat raioBoca1X = 5.0f, raioBoca1Y = 5.0f;

    glTranslatef(-100, 30, 0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt/2; i++) {
        ang = (2 * PI * i) / circ_pnt;
        //coordenada X             |
        glVertex2f(cos(ang) * raioBoca1X, sin(ang) * raioBoca1Y);
        printf("%f    %f\n", cos(ang) * raioBoca1X, sin(ang) * raioBoca1Y);
    }
    glEnd();
    glPopMatrix();

    /**********************************************************************/
                            // FACE //
    /**********************************************************************/

            //////////// OLHO ESQUERDO 1 /////////////////////
    glPushMatrix();
    GLfloat raioOlhoX = 5.0f, raioOlhoY = 5.0f;

    glTranslatef(120, 50, 0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++) {
        ang = (2 * PI * i) / circ_pnt;
        //coordenada X             |
        glVertex2f(cos(ang) * raioOlhoX, sin(ang) * raioOlhoY);
        printf("%f    %f\n", cos(ang) * raioOlhoX, sin(ang) * raioOlhoY);
    }
    glEnd();
    glPopMatrix();


    //////////// OLHO DIREITO 1 /////////////////////
    glPushMatrix();
    GLfloat raioOlho3X = 5.0f, raioOlho3Y = 5.0f;

    glTranslatef(80, 50, 0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++) {
        ang = (2 * PI * i) / circ_pnt;
        //coordenada X             |
        glVertex2f(cos(ang) * raioOlho3X, sin(ang) * raioOlho3Y);
        printf("%f    %f\n", cos(ang) * raioOlho3X, sin(ang) * raioOlho3Y);
    }
    glEnd();
    glPopMatrix();


    //////////// BOCA /////////////////////
    glPushMatrix();
    GLfloat raioBocaX = 5.0f, raioBocaY = 5.0f;

    glTranslatef(100, 30, 0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt / 2; i++) {
        ang = (2 * PI * i) / circ_pnt;
        //coordenada X             |
        glVertex2f(cos(ang) * raioBocaX, sin(ang) * raioBocaY);
        printf("%f    %f\n", cos(ang) * raioBocaX, sin(ang) * raioBocaY);
    }
    glEnd();
    glPopMatrix();




    /**********************************************************************/
                            //LACINHO 1 //
    /**********************************************************************/
        //////////// BOLINHA /////////////////////
    GLfloat raioLacoX = 5.0f, raioLacoY = 5.0f;

    glTranslatef(100, 100, 0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++) {
        ang = (2 * PI * i) / circ_pnt;
        //coordenada X             |
        glVertex2f(cos(ang) * raioLacoX, sin(ang) * raioLacoY);
        printf("%f    %f\n", cos(ang) * raioLacoX, sin(ang) * raioLacoY);
    }
    glEnd();

    //////////// PARTE ESQUERDA LACO /////////////////////
    GLfloat raioLacoEsquerdoX = 11.0f, raioLacoDireitoY = 8.0f;
    glTranslatef(-15, 0, 0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++) {

        ang = (2 * PI * i) / circ_pnt;

        //coordenada X             |
        glVertex2f(cos(ang) * raioLacoEsquerdoX, sin(ang) * raioLacoDireitoY);
        printf("%f    %f\n", cos(ang) * raioLacoEsquerdoX, sin(ang) * raioLacoDireitoY);
    }
    glEnd();

    //////////// PARTE DIREITA LACO /////////////////////
    glTranslatef(30, 0, 0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++) {
        ang = (2 * PI * i) / circ_pnt;
        //coordenada X             |
        glVertex2f(cos(ang) * raioLacoEsquerdoX, sin(ang) * raioLacoDireitoY);
        printf("%f    %f\n", cos(ang) * raioLacoEsquerdoX, sin(ang) * raioLacoDireitoY);
    }
    glEnd();

    /**********************************************************************/
                                //LACINHO 2 //
    /**********************************************************************/

    //////////// BOLINHA2 /////////////////////
    GLfloat raioLaco2X = 5.0f, raioLaco2Y = 5.0f;

    glTranslatef(-115, 0, 0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++) {
        ang = (2 * PI * i) / circ_pnt;
        //coordenada X             |
        glVertex2f(cos(ang) * raioLaco2X, sin(ang) * raioLaco2Y);
        printf("%f    %f\n", cos(ang) * raioLaco2X, sin(ang) * raioLaco2Y);
    }
    glEnd();

    //////////// PARTE ESQUERDA LACO2 /////////////////////
    GLfloat raioLacoEsquerdo2X = 11.0f, raioLacoDireito2Y = 8.0f;
    glTranslatef(-15, 0, 0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++) {

        ang = (2 * PI * i) / circ_pnt;

        //coordenada X             |
        glVertex2f(cos(ang) * raioLacoEsquerdo2X, sin(ang) * raioLacoDireito2Y);
        printf("%f    %f\n", cos(ang) * raioLacoEsquerdo2X, sin(ang) * raioLacoDireito2Y);
    }
    glEnd();

    //////////// PARTE DIREITA LACO2 /////////////////////
    glTranslatef(30, 0, 0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++) {
        ang = (2 * PI * i) / circ_pnt;
        //coordenada X             |
        glVertex2f(cos(ang) * raioLacoEsquerdoX, sin(ang) * raioLacoDireitoY);
        printf("%f    %f\n", cos(ang) * raioLacoEsquerdoX, sin(ang) * raioLacoDireitoY);
    }
    glEnd();

    /**********************************************************************/
                                //LACINHO 3 //
    /**********************************************************************/

    //////////// BOLINHA3 /////////////////////
    GLfloat raioLaco3X = 5.0f, raioLaco3Y = 5.0f;

    glTranslatef(-115, 0, 0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++) {
        ang = (2 * PI * i) / circ_pnt;
        //coordenada X             |
        glVertex2f(cos(ang) * raioLaco3X, sin(ang) * raioLaco3Y);
        printf("%f    %f\n", cos(ang) * raioLaco3X, sin(ang) * raioLaco3Y);
    }
    glEnd();

    //////////// PARTE ESQUERDA LACO3 /////////////////////
    GLfloat raioLacoEsquerdo3X = 11.0f, raioLacoDireito3Y = 8.0f;
    glTranslatef(-15, 0, 0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++) {

        ang = (2 * PI * i) / circ_pnt;

        //coordenada X             |
        glVertex2f(cos(ang) * raioLacoEsquerdo3X, sin(ang) * raioLacoDireito3Y);
        printf("%f    %f\n", cos(ang) * raioLacoEsquerdo3X, sin(ang) * raioLacoDireito3Y);
    }
    glEnd();

    //////////// PARTE DIREITA LACO3 /////////////////////
    glTranslatef(30, 0, 0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < circ_pnt; i++) {
        ang = (2 * PI * i) / circ_pnt;
        //coordenada X             |
        glVertex2f(cos(ang) * raioLacoEsquerdoX, sin(ang) * raioLacoDireitoY);
        printf("%f    %f\n", cos(ang) * raioLacoEsquerdoX, sin(ang) * raioLacoDireitoY);
    }
    glEnd();

    glPopMatrix();


}



void display() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glClearColor(0.690f, 0.878f, 0.902f, 0.0f); //cor do fundo
    glClear(GL_COLOR_BUFFER_BIT); //EXECUTA LIMPEZA


    //local onde o desenho acontece
    glTranslatef(600 / 2, 400 / 2, 0.0f);

    glViewport(0, 0, 600, 400);
    desenhar();

    glFlush();
}

void tela(GLsizei w, GLsizei h) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 600, 0, 400);

    glMatrixMode(GL_MODELVIEW);
}
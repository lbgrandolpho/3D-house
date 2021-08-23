#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

float posX=0.0,posY=0.0,posZ=0.0;
float transX=0.0,transY=0.0,transZ=0.0;

void esc(unsigned char key, int x, int y) {

    if(key == 27)
        exit(0);
}

void movimento(int key, int x, int y) {

    switch (key) {
    
    case GLUT_KEY_RIGHT:
        posY += 0.5;
        break;

    case GLUT_KEY_LEFT:
        posY -= 0.5;
        break;

    case GLUT_KEY_UP:
        posX += 0.5;
        break;

    case GLUT_KEY_DOWN:
        posX -= 0.5;
        break;

    case GLUT_KEY_F1:
        transZ += 0.5;
        break;

    case GLUT_KEY_F2:
        transZ -= 0.5;
        break;

    case GLUT_KEY_F3:
        transY += 0.5;
        break;

    case GLUT_KEY_F4:
        transY -= 0.5;
        break;

    case GLUT_KEY_F5:
        transX += 0.5;
        break;

    case GLUT_KEY_F6:
        transX -= 0.5;
        break;

    case GLUT_KEY_F7:
        transX = 0.0;
        transY = 0.0;
        transZ = 0.0;
        break;

    default:
        break;
    }
    glutPostRedisplay();
}

void desenho() {

    if (posX==360)
      posX=0;

    if (posY==360)
        posY=0;    

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glColor3ub(255, 0, 0);
    glPushMatrix();

        glRotatef(posX,1.0,0.0,0.0);
        glRotatef(posY,0.0,1.0,0.0);
        glTranslatef(transX, transY, transZ);
		
        //casa base
        glPushMatrix();
            glutSolidCube(2);
            glTranslatef(0., 0., -2.);
            glScalef(3., 1., 1.);
            glutSolidCube(2.);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(2.9, -1+.3725, -4.);
            glScalef(.2, .75, -2);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(2, -1+.3725, -4.9);
            glScalef(-2, .75, .2);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-2.9, -1+.3725, -4.);
            glScalef(-.2, .75, -2);
            glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-2, -1+.3725, -4.9);
            glScalef(2, .75, .2);
            glutSolidCube(1);
        glPopMatrix();

        //chão
        glColor3ub(117, 0, 0);
        glBegin(GL_QUADS);
            glVertex3f(3, -1, -3);
            glVertex3f(3, -1, -5);
            glVertex3f(-3, -1, -5);
            glVertex3f(-3, -1, -3);
        glEnd();

        //toldo
        glColor3ub(40, 0, 60);
        glBegin(GL_QUADS);
            glVertex3f(3, 1, -3);
            glVertex3f(3, 0.7, -5);
            glVertex3f(-3, 0.7, -5);
            glVertex3f(-3, 1, -3);

            glVertex3f(3, 0.7, -5);
            glVertex3f(3, 0.5, -5);
            glVertex3f(-3, 0.5, -5);
            glVertex3f(-3, 0.7, -5);
        glEnd();

        //telhado
        glColor3ub(255,105,0);
        glBegin(GL_TRIANGLES);
            glVertex3f(0, 2, 0);
            glVertex3f(-1, 1, 1);
            glVertex3f(1, 1, 1);
        glEnd();

        glBegin(GL_TRIANGLES);
            glVertex3f(2, 2, -2);
            glVertex3f(3, 1, -1);
            glVertex3f(3, 1, -3);
        glEnd();

        glBegin(GL_TRIANGLES);
            glVertex3f(-2, 2, -2);
            glVertex3f(-3, 1, -3);
            glVertex3f(-3, 1, -1);
        glEnd();

        glBegin(GL_QUADS);
            glVertex3f(-2, 2, -2);
            glVertex3f(-3, 1, -1);
            glVertex3f(3, 1, -1);
            glVertex3f(2, 2, -2);

            glVertex3f(2, 2, -2);
            glVertex3f(3, 1, -3);
            glVertex3f(-3, 1, -3);
            glVertex3f(-2, 2, -2);

            glVertex3f(0, 2, 0);
            glVertex3f(1, 1, 1);
            glVertex3f(1, 1, -1);
            glVertex3f(0, 2, -2);

            glVertex3f(0, 2, 0);
            glVertex3f(0, 2, -2);
            glVertex3f(-1, 1, -1);
            glVertex3f(-1, 1, 1);
        glEnd();

        //portas
        glColor3ub(70, 25, 10);
        glBegin(GL_QUADS);
            glVertex3f(-0.3, -1, 1.01);
            glVertex3f(0.3, -1, 1.01);
            glVertex3f(0.3, 0, 1.01);
            glVertex3f(-0.3, 0, 1.01);

            glVertex3f(-1, -1, -3.01);
            glVertex3f(-2.2, -1, -3.01);
            glVertex3f(-2.2, 0.2, -3.01);
            glVertex3f(-1, 0.2, -3.01);
        glEnd();

        //janelas
        glColor3ub(0, 120, 255);
        glPushMatrix();
            glTranslatef(0.751, 0, 0);
            glutSolidCube(0.5);
            glTranslatef(-1.502, 0, 0);
            glutSolidCube(0.5);
        glPopMatrix();

        glBegin(GL_QUADS);
            glVertex3f(2, 0.5, -3.01);
            glVertex3f(2, -0.5, -3.01);
            glVertex3f(0, -0.5, -3.01);
            glVertex3f(0, 0.5, -3.01);
        glEnd();

        //janela circular
        glColor3ub(0, 120, 255);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 20; i++) {
            float x = i * 2 * M_PI / 20;
            glVertex3f(0 + cos(x) * 0.25, 0.5 + sin(x) * 0.25, 1.01);
        }
        glEnd();

        glColor3ub(0, 0, 0);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 20; i++) {
            float x = i * 2 * M_PI / 20;
            glVertex3f(0 + cos(x) * 0.25, 0.5 + sin(x) * 0.25, 1.02);
        }
        glEnd();

        //maçaneta
        glPushMatrix();
            glColor3ub(100, 100, 0);            
            glTranslatef(0.2,-0.5,1.05);
            glutSolidSphere(0.05, 20, 20);
        glPopMatrix();

        //garagem
        glColor3ub(70, 70, 70);
        glBegin(GL_QUADS);
            glVertex3f(1.25, -1, -0.99);
            glVertex3f(2.75, -1, -0.99);
            glVertex3f(2.75, 0.5, -0.99);
            glVertex3f(1.25, 0.5, -0.99);
        glEnd();

        //linhas
        glColor3ub(0, 0, 0);
        glBegin(GL_LINES);
            glVertex3f(1.01, 0, 0.25);
            glVertex3f(1.01, 0, -0.25);

            glVertex3f(1.01, 0.25, 0);
            glVertex3f(1.01, -0.25, 0);

            glVertex3f(-1.01, 0, 0.25);
            glVertex3f(-1.01, 0, -0.25);

            glVertex3f(-1.01, 0.25, 0);
            glVertex3f(-1.01, -0.25, 0);

            glVertex3f(0, 2, 0);
            glVertex3f(-1, 1, 1);

            glVertex3f(0, 2, 0);
            glVertex3f(1, 1, 1);

            glVertex3f(0, 0.75, 1.02);
            glVertex3f(0, 0.25, 1.02);

            glVertex3f(-0.25, 0.5, 1.02);
            glVertex3f(0.25, 0.5, 1.02);

            glVertex3f(1.25, -1, -0.98);
            glVertex3f(1.25, 0.5, -0.98);

            glVertex3f(1.25, 0.5, -0.98);
            glVertex3f(2.75, 0.5, -0.98);

            glVertex3f(2.75, 0.5, -0.98);
            glVertex3f(2.75, -1, -0.98);

            glVertex3f(-0.3, -1, 1.02);
            glVertex3f(-0.3, 0, 1.02);

            glVertex3f(-0.3, 0, 1.02);
            glVertex3f(0.3, 0, 1.02);

            glVertex3f(0.3, 0, 1.02);
            glVertex3f(0.3, -1, 1.02);

            glVertex3f(1.25, 0.2, -0.98);
            glVertex3f(2.75, 0.2, -0.98);

            glVertex3f(1.25, -0.1, -0.98);
            glVertex3f(2.75, -0.1, -0.98);

            glVertex3f(1.25, -0.4, -0.98);
            glVertex3f(2.75, -0.4, -0.98);

            glVertex3f(1.25, -0.7, -0.98);
            glVertex3f(2.75, -0.7, -0.98);

            glVertex3f(1.01, 0.25, 0.25);
            glVertex3f(1.01, 0.25, -0.25);

            glVertex3f(1.01, 0.25, -0.25);
            glVertex3f(1.01, -0.25, -0.25);

            glVertex3f(1.01, -0.25, -0.25);
            glVertex3f(1.01, -0.25, 0.25);

            glVertex3f(1.01, -0.25, 0.25);
            glVertex3f(1.01, 0.25, 0.25);

            glVertex3f(-1.01, 0.25, -0.25);
            glVertex3f(-1.01, 0.25, 0.25);

            glVertex3f(-1.01, 0.25, 0.25);
            glVertex3f(-1.01, -0.25, 0.25);

            glVertex3f(-1.01, -0.25, 0.25);
            glVertex3f(-1.01, -0.25, -0.25);

            glVertex3f(-1.01, -0.25, -0.25);
            glVertex3f(-1.01, 0.25, -0.25);

            glVertex3f(-1, 1, 1);
            glVertex3f(1, 1, 1);

            glVertex3f(1, 1, 1);           
            glVertex3f(1, 1, -1);

            glVertex3f(1, 1, -1);
            glVertex3f(3, 1, -1);

            glVertex3f(3, 1, -1);
            glVertex3f(3, 1, -3);

            glVertex3f(3, 1, -3);
            glVertex3f(-3, 1, -3);

            glVertex3f(-3, 1, -3);
            glVertex3f(-3, 1, -1);

            glVertex3f(-3, 1, -1);
            glVertex3f(-1, 1, -1);

            glVertex3f(-1, 1, -1);
            glVertex3f(-1, 1, 1);

            glVertex3f(0, 2, 0);
            glVertex3f(0, 2, -2);

            glVertex3f(0, 2.01, -2);
            glVertex3f(1, 1, -0.99);

            glVertex3f(0, 2.01, -2);
            glVertex3f(-1, 1, -0.99);

            glVertex3f(-2, 2.01, -2);
            glVertex3f(-3, 1, -1);

            glVertex3f(-2, 2.01, -2);
            glVertex3f(-3, 1, -3);

            glVertex3f(2, 2.01, -2);
            glVertex3f(3, 1, -1);

            glVertex3f(2, 2.01, -2);
            glVertex3f(3, 1, -3);

            glVertex3f(-2, 2.01, -2);
            glVertex3f(2, 2.01, -2);

            glVertex3f(2, 0.5, -3.02);
            glVertex3f(2, -0.5, -3.02);

            glVertex3f(2, -0.5, -3.02);
            glVertex3f(0, -0.5, -3.02);

            glVertex3f(0, -0.5, -3.02);
            glVertex3f(0, 0.5, -3.02);

            glVertex3f(0, 0.5, -3.02);
            glVertex3f(2, 0.5, -3.02);

            glVertex3f(1.33, 0.5, -3.02);
            glVertex3f(1.33, -0.5, -3.02);
            
            glVertex3f(0.67, 0.5, -3.02);
            glVertex3f(0.67, -0.5, -3.02);

            glVertex3f(-1, -1, -3.02);
            glVertex3f(-1, 0.2, -3.02);

            glVertex3f(-1, 0.2, -3.02);
            glVertex3f(-2.2, 0.2, -3.02);

            glVertex3f(-2.2, 0.2, -3.02);
            glVertex3f(-2.2, -1, -3.02);

            glVertex3f(-1.6, 0.2, -3.02);
            glVertex3f(-1.6, -1, -3.02);

            glVertex3f(-1, 1, 1);
            glVertex3f(-1, -1, 1);

            glVertex3f(1, 1, 1);
            glVertex3f(1, -1, 1);

            glVertex3f(1.01, 1, -0.99);
            glVertex3f(1.01, -1, -0.99);

            glVertex3f(3, 1, -1);
            glVertex3f(3, -1, -1);

            glVertex3f(3, 1, -3);
            glVertex3f(3, -0.25, -3);

            glVertex3f(3, -0.25, -3);
            glVertex3f(3, -0.25, -5);

            glVertex3f(3, -0.25, -5);
            glVertex3f(1, -0.25, -5);

            glVertex3f(3, -0.25, -5);
            glVertex3f(3, -1, -5);

            glVertex3f(1, -0.25, -5);
            glVertex3f(1, -1, -5);

            glVertex3f(1, -0.25, -4.8);
            glVertex3f(1, -1, -4.8);

            glVertex3f(2.79, -0.25, -4.79);
            glVertex3f(2.79, -1, -4.79);

            glVertex3f(2.79, -0.25, -3.01);
            glVertex3f(2.79, -1, -3.01);

            glVertex3f(2.8, -0.25, -3);
            glVertex3f(2.8, -0.25, -4.8);

            glVertex3f(2.8, -0.25, -4.8);
            glVertex3f(1, -0.25, -4.8);

            glVertex3f(3, -0.24, -3.01);
            glVertex3f(2.8, -0.24, -3.01);

            glVertex3f(1, -0.25, -5);
            glVertex3f(1, -0.25, -4.8);

            glVertex3f(-3, -0.25, -3);
            glVertex3f(-3, -0.25, -5);

            glVertex3f(-3, -0.25, -5);
            glVertex3f(-1, -0.25, -5);

            glVertex3f(-1, -0.25, -5);
            glVertex3f(-1, -0.25, -4.8);

            glVertex3f(-1, -0.25, -4.8);
            glVertex3f(-2.8, -0.25, -4.8);

            glVertex3f(-2.8, -0.25, -4.8);
            glVertex3f(-2.8, -0.25, -3);

            glVertex3f(-2.8, -0.24, -3.01);
            glVertex3f(-3, -0.24, -3.01);

            glVertex3f(-2.79, -0.25, -3.01);
            glVertex3f(-2.79, -1, -3.01);

            glVertex3f(-2.79, -0.25, -4.79);
            glVertex3f(-2.79, -1, -4.79);

            glVertex3f(-1, -0.25, -4.8);
            glVertex3f(-1, -1, -4.8);

            glVertex3f(-1, -0.25, -5);
            glVertex3f(-1, -1, -5);

            glVertex3f(-3, -0.25, -5);
            glVertex3f(-3, -1, -5);

            glVertex3f(-3, 1, -3);
            glVertex3f(-3, -0.25, -3);

            glVertex3f(-3, 1, -1);
            glVertex3f(-3, -1, -1);

            glVertex3f(-1.01, 1, -0.99);
            glVertex3f(-1.01, -1, -0.99);

            glVertex3f(3, 0.7, -5);
            glVertex3f(-3, 0.7, -5);
        glEnd();

    glPopMatrix();

    glFlush();

}

void inicio(){

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45,1,4,20);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	
    gluLookAt(0.0,0.0,10.0,0.0,0.0,0.0,0.0,1.0,0.0);
}

void main(int argc, char **argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Casa 3D");

    glutDisplayFunc(desenho);
    glutKeyboardFunc(esc);
    glutSpecialFunc(movimento);

    inicio();
    glutMainLoop();

}
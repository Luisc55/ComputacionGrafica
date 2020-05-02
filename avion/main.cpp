#include <GL/glut.h>
#include <cmath>

#if defined(LINUX) || defined(WIN32)
using namespace std;
#endif


void dibujar();
void proyeccion();
void nombre();



//teclado
float pos_x = 0;

//menu
static int window;


void proyeccion(){
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-40,40,-40,40);
}
void dibujar() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(2.0);

}
void nombre(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,1.0,0.5);
    glLineWidth(3.0);

    //Cuerpo
    glBegin(GL_LINE_STRIP);

    glVertex2i(10,0);
    glVertex2i(-1,0);
    glVertex2i(-10,4);
    glVertex2i(2,5);
    glVertex2i(10,5);
    glVertex2i(10,0);

    glEnd();



    glFlush();
}


void teclado(int tecla, int x, int y){
    switch(tecla){
        case GLUT_KEY_LEFT:
            pos_x = pos_x - 1;
            glutPostRedisplay();
            break;

        case GLUT_KEY_RIGHT:
            pos_x = pos_x + 1;
            glutPostRedisplay();
            break;
    }
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    window = glutCreateWindow("avion en OpenGL");

    proyeccion();
    dibujar();
    nombre();


    glClearColor(1.0,1.0,1.0,0.0);
    glutDisplayFunc(dibujar);
    glutSpecialFunc(teclado);

    glutMainLoop();
    return EXIT_SUCCESS;
}

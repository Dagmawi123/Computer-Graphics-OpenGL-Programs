#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


void display();
void reshape(int,int);
void timer(int);
void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(200,100);
    glutInitWindowSize(500,500);

    glutCreateWindow("CS489 Window");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,2);
    init();

    glutMainLoop();

}
float x_pos=-15.0;
bool isMovingRight=true;
void display(){
   glClear(GL_COLOR_BUFFER_BIT);//clearing the frame buffer
    glLoadIdentity();
    glTranslatef(0,0,x_pos);
   // glPointSize(10.0);

    glBegin(GL_POLYGON);

//Points
//    glVertex2f(5,5);
//    glVertex2f(-5,-5);

//triangle
   // glVertex2f(0,5);
   // glVertex2f(-4,-5);
   // glVertex2f(4,-5);

//Rectangle
   // glColor3f(1.0,0,0);
    glVertex3f(0,1.0,0);
    //glColor3f(0,1.0,0);
    glVertex3f(0,-1.0,0);
    //glColor3f(0,0,1.0);
    glVertex3f(2,-1,0);
    glVertex3f(2,1.0,0);



    glEnd();
    glutSwapBuffers();
   // glFlush();
}

void reshape(int w,int h){
    glViewport(0,0,(GLsizei)w,(GLsizei)h);

    glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
       // gluOrtho2D(-10,10,-10,10);
        gluPerspective(60,1,2.0,50.0);
        glMatrixMode(GL_MODELVIEW);
}
void timer(int a){
    if(x_pos<-5&&isMovingRight)
    x_pos+=0.15;
    else if(x_pos>-15&&!isMovingRight){
        x_pos-=0.15;
            }
            else if(x_pos>=-5&&isMovingRight)
                isMovingRight=false;
            else if(x_pos<=-15&&!isMovingRight)
            isMovingRight=true;
//switch (isMovingRight){
//case true :
//    if(x_pos<8)
//        x_pos+=0.15;
//    else
//        isMovingRight=false;
//    break;
//
//case false:
//     if(x_pos>-10)
//        x_pos-=0.15;
//    else
//        isMovingRight=true;
//    break;
//}
    glutPostRedisplay();
      glutTimerFunc(1000/60,timer,2);

}

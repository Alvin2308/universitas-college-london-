#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>

const double PI = 3.141592653589793;
int i;

void init(void);
void tampil(void);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouseMotion(int x, int y);

float a = 1.0;
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false, tembok = true;
int is_depth;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("Aldy Alvharo Tarigan - 672018383");
    init();
    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    //GLfloat light_position0[] = { 100.0,100.0,-350.0,0.0 };
    //glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
    glMatrixMode(GL_PROJECTION);
    //glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);

}
void lingkaran(int jari2, int jumlah_titik, int x_tengah, int y_tengah) {

    glBegin(GL_POLYGON);
    for (i = 0; i <= 360; i++) {
        float sudut = i * (2 * PI / jumlah_titik);
        float x = x_tengah + jari2 * cos(sudut);
        float y = y_tengah + jari2 * sin(sudut);
        glVertex2f(x, y);
    }
    glEnd();
}
void cylinder(float alas, float up, float height)
{
    float i;
    glPushMatrix();
    glRotatef(90, 90, 1, 0);
    for (i = 0; i <= height; i += alas / 24)
    {
        glTranslatef(0.0, 0.0, alas / 24);
        glutSolidTorus(alas, alas - ((i * (alas - up)) / height), 16, 16);
    }
    glPopMatrix();
    glEnd();
}
void balok(double panjang, double lebar, double tinggi) {
    glScalef(panjang, tinggi, lebar);
    glutSolidCube(1);
}
void balok_depan_kiri()
{
    if (tembok) {
        glPushMatrix();
        glTranslatef(-650, -100, 300);
        jendela1();
        glPopMatrix();
        glEnd();
        //depan
        glBegin(GL_QUADS);
        glColor3ub(200, 200, 200);
        glVertex3f(-400.0, -150.0, 80.0);
        glVertex3f(-400.0, 150.0, 80.0);
        glVertex3f(10.0, 150.0, 80.0);
        glVertex3f(10.0, -150.0, 80.0);
        glEnd();
    }
    //belakang
    glBegin(GL_QUADS);
    glColor3ub(200, 200, 200);
    glVertex3f(-400.0, -150.0, -90.0);
    glVertex3f(-400.0, 150.0, -90.0);
    glVertex3f(10.0, 150.0, -90.0);
    glVertex3f(10.0, -150.0, -90.0);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3ub(200, 200, 200);
    glVertex3f(9.9, 150.0, 80.0);
    glVertex3f(9.9, -150.0, 80.0);
    glVertex3f(9.9, -150.0, -90.0);
    glVertex3f(9.9, 150.0, -90.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3ub(200, 200, 200);
    glVertex3f(-400, 150.0, 80.0);
    glVertex3f(-400, -150.0, 80.0);
    glVertex3f(-400, -150.0, -90.0);
    glVertex3f(-400, 150.0, -90.0);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3ub(200, 200, 200);
    glVertex3f(-400, -150.0, 80.0);
    glVertex3f(9.9, -150.0, 80.0);
    glVertex3f(9.9, -150.0, -90.0);
    glVertex3f(-400, -150.0, -90.0);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3ub(200, 200, 200);
    glVertex3f(-400, 150.0, 80.0);
    glVertex3f(9.9, 150.0, 80.0);
    glVertex3f(9.9, 150.0, -90.0);
    glVertex3f(-400, 150.0, -90.0);
    glEnd();
}
void base_depan()
{
    glPushMatrix();
    glTranslatef(0, 55, 0);
    glColor3ub(200, 200, 200);
    balok(55, 75, 4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -35, 0);
    glColor3ub(200, 200, 200);
    balok(55, 75, 8);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -37, 0);
    glColor3ub(200, 200, 200);
    balok(60, 80, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 10, 0);
    glColor3ub(200, 200, 200);
    balok(50, 70, 90);
    glPopMatrix();
    glEnd();
}
void lantai()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 255, 0);
    glVertex3f(-1000, -25.1, 500);
    glVertex3f(1000, -25.1, 500);
    glVertex3f(1000, -25.1, -1800);
    glVertex3f(-1000, -25.1, -1800);
    glEnd();
}
void alas_depan()
{
    glPushMatrix();//alas depan
    glColor3ub(200, 200, 200);
    balok(430, 75, 33);
    glPopMatrix();
    glEnd();

    glPushMatrix();//alas depan
    glTranslatef(0, 22, 73);
    glColor3ub(200, 200, 200);
    balok(170, 70, 80);
    glPopMatrix();
    glEnd();

}
void tangadepan()
{
    //tiang kiri
    glBegin(GL_QUADS);//depan
    glColor3ub(255, 255, 255);
    glVertex3f(-180, -25, 170);
    glVertex3f(-180, -20, 170);
    glVertex3f(-100, -20, 170);
    glVertex3f(-100, -25, 170);
    //belakang
    glVertex3f(-180, -25, 160);
    glVertex3f(-180, -20, 160);
    glVertex3f(-100, -20, 160);
    glVertex3f(-100, -25, 160);
    //atas
    glColor3ub(200, 200, 200);
    glVertex3f(-180, -20, 160);
    glVertex3f(-180, -20, 170);
    glVertex3f(-100, -20, 170);
    glVertex3f(-100, -20, 160);
    //kanan
    glVertex3f(-180, -25, 160);
    glVertex3f(-180, -25, 170);
    glVertex3f(-100, -25, 170);
    glVertex3f(-100, -25, 160);
    glEnd();
}
void tangga_depan()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    tangadepan();
    glTranslatef(0, 5, -10);
    tangadepan();
    glTranslatef(0, 5, -10);
    tangadepan();
    glTranslatef(0, 5, -10);
    tangadepan();
    glTranslatef(0, 5, -10);
    tangadepan();
    glTranslatef(0, 5, -10);
    tangadepan();
    glTranslatef(0, 5, -10);
    tangadepan();
    glPopMatrix();
    glEnd();
}
void tanggautama()
{
    //tiang kiri
    glBegin(GL_QUADS);//depan
    glColor3ub(255, 255, 255);
    glVertex3f(-85, 20, 30);
    glVertex3f(-85, 11, 30);
    glVertex3f(85, 11, 30);
    glVertex3f(85, 20, 30);
    //belakang
    glVertex3f(-85, 20, 10);
    glVertex3f(-85, 11, 10);
    glVertex3f(85, 11, 10);
    glVertex3f(85, 20, 10);
    //atas
    glColor3ub(200, 200, 200);
    glVertex3f(-85, 11, 10);
    glVertex3f(-85, 11, 30);
    glVertex3f(85, 11, 30);
    glVertex3f(85, 11, 10);
    //kanan
    glVertex3f(-85, 20, 10);
    glVertex3f(-85, 20, 30);
    glVertex3f(85, 20, 30);
    glVertex3f(85, 20, 10);
    glEnd();
}
void tangga_utama()
{
    glPushMatrix();
    glTranslatef(0, 0, 0);
    tanggautama();
    glTranslatef(0, 9, -10);
    tanggautama();
    glTranslatef(0, 9, -10);
    tanggautama();
    glTranslatef(0, 9, -10);
    tanggautama();
    glTranslatef(0, 9, -10);
    tanggautama();
    glTranslatef(0, 9, -10);
    tanggautama();
    glTranslatef(0, 9, -10);
    tanggautama();
    glTranslatef(0, 9, -10);
    tanggautama();
    glTranslatef(0, 9, -10);
    tanggautama();
    glTranslatef(0, 9, -10);
    tanggautama();
    glTranslatef(0, 9, -10);
    tanggautama();
    glTranslatef(0, 9, -10);
    tanggautama();
    glPopMatrix();
    glEnd();
}
void samping()
{
    glPushMatrix();
    glColor3ub(255, 255, 255);
    glTranslatef(-175, 50, -25);
    balok(180, 130, 150);
    glPopMatrix();
    glEnd();

    glPushMatrix();//atas
    glColor3ub(200, 200, 200);
    glTranslatef(-175, 121, -25);
    balok(185, 135, 10);
    glPopMatrix();
    glEnd();

    glPushMatrix();//atas
    glColor3ub(200, 200, 200);
    glTranslatef(-175, 126, -25);
    balok(190, 140, 5);
    glPopMatrix();
    glEnd();

    glPushMatrix();//bawah
    glTranslatef(-175, -20, -25);
    glColor3ub(200, 200, 200);
    balok(185, 135, 7);
    glPopMatrix();

    glPushMatrix();//bawah
    glColor3ub(200, 200, 200);
    glTranslatef(-175, -22, -25);
    balok(190, 140, 5);
    glPopMatrix();
}
void lampu()
{
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0, 100, 0);
    balok(4, 4, 30);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(255, 255, 0);
    glTranslatef(0, 120, 0);
    glutSolidSphere(7, 20, 16);
    glPopMatrix();
    glEnd();
}
void lantaiatas()
{
    glPushMatrix();
    glColor3ub(200, 200, 200);
    glTranslatef(0, 55, -160);
    balok(530, 135, 155);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glTranslatef(0, 135, -165);
    balok(530, 125, 7);
    glPopMatrix();
    glEnd();

}
void pilar()
{
    glPushMatrix();
    glColor3ub(169 ,169 ,169);
    glTranslatef(0, 270, -110);
    cylinder(5, 5, 130);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(169, 169, 169);
    glTranslatef(0, 270, -110);
    balok(23, 23, 10);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(169, 169, 169);
    glTranslatef(0, 143, -110);
    balok(23, 23, 10);
    glPopMatrix();
    glEnd();

}
void pilar_depan()
{
    glPushMatrix();
    glTranslatef(-250, 0, -10);//depan
    pilar();
    glTranslatef(55.5, 0, 0);//depan
    pilar(); glTranslatef(55.5, 0, 0);//depan
    pilar(); glTranslatef(55.5, 0, 0);//depan
    pilar(); glTranslatef(55.5, 0, 0);//depan
    pilar(); glTranslatef(55.5, 0, 0);//depan
    pilar(); glTranslatef(55.5, 0, 0);//depan
    pilar(); glTranslatef(55.5, 0, 0);//depan
    pilar(); glTranslatef(55.5, 0, 0);//depan
    pilar(); glTranslatef(55.5, 0, 0);//depan
    pilar();
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glTranslatef(-250, 0, -60);//samping kiri
    pilar();
    glTranslatef(0, 0, -50);//samping kiri
    pilar();
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glTranslatef(250, 0, -60);//samping kanan
    pilar();
    glTranslatef(0, 0, -50);//samping kanan
    pilar();
    glPopMatrix();
    glEnd();
}

void atap()
{
    glPushMatrix();//atas
    glColor3ub(200, 200, 200);
    glTranslatef(0, 280, -165);
    balok(530, 125, 10);
    glPopMatrix();

    glPushMatrix();//bawah
    glColor3ub(200, 200, 200);
    glTranslatef(0, 285, -165);
    balok(550, 125, 5);
    glPopMatrix();
    glEnd();

    glPushMatrix();//belakang
    glColor3ub(200, 200, 200);
    glTranslatef(0, 130, -310);
    balok(560, 170, 310);
    glPopMatrix();
    glEnd();

    //atap kiri
    glBegin(GL_QUADS);//atas
    glColor3ub(200, 200, 200);
    glVertex3f(0, 450, -130);
    glVertex3f(0, 450, -110);
    glVertex3f(-260, 290, -110);
    glVertex3f(-260, 290, -130);
    //bawah
    glColor3ub(255, 255, 255);
    glVertex3f(0, 430, -130);
    glVertex3f(0, 430, -110);
    glVertex3f(-230, 290, -110);
    glVertex3f(-230, 290, -130);
    //depan
    glColor3ub(200, 200, 200);
    glVertex3f(0, 430, -130);
    glVertex3f(0, 450, -130);
    glVertex3f(-260, 290, -130);
    glVertex3f(-230, 290, -130);
    //belakang
    glColor3ub(200, 200, 200);
    glVertex3f(0, 430, -110);
    glVertex3f(0, 450, -110);
    glVertex3f(-260, 290, -110);
    glVertex3f(-230, 290, -110);
    glEnd();

    //atap kiri
    glBegin(GL_QUADS);//atas
    glColor3ub(200, 200, 200);
    glVertex3f(0, 450, -130);
    glVertex3f(0, 450, -110);
    glVertex3f(260, 290, -110);
    glVertex3f(260, 290, -130);
    //bawah
    glColor3ub(255, 255, 255);
    glVertex3f(0, 430, -130);
    glVertex3f(0, 430, -110);
    glVertex3f(230, 290, -110);
    glVertex3f(230, 290, -130);
    //depan
    glColor3ub(200, 200, 200);
    glVertex3f(0, 430, -130);
    glVertex3f(0, 450, -130);
    glVertex3f(260, 290, -130);
    glVertex3f(230, 290, -130);
    //belakang
    glColor3ub(200, 200, 200);
    glVertex3f(0, 430, -110);
    glVertex3f(0, 450, -110);
    glVertex3f(260, 290, -110);
    glVertex3f(230, 290, -110);
    glEnd();

    glPushMatrix();//bawah
    glColor3ub(255, 255, 255);
    glTranslatef(0, 299, -120);
    balok(460, 18.9, 18.9);
    glPopMatrix();

    //segitiga depan
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex3f(-230, 290, -131);
    glVertex3f(0, 440, -131);
    glVertex3f(230, 290, -131);
    glEnd();
    glBegin(GL_QUADS);//belakang kiri
    glColor3ub(255, 255, 255);
    glVertex3f(0, 440, -400);
    glVertex3f(0, 440, -130);
    glVertex3f(-260, 285, -130);
    glVertex3f(-260, 285, -400);
    //belakang kanan
    glColor3ub(200, 200, 200);
    glVertex3f(0, 440, -400);
    glVertex3f(0, 440, -130);
    glVertex3f(260, 285, -130);
    glVertex3f(260, 285, -400);
    glEnd();
    glBegin(GL_POLYGON);//segitiga belakang
    glColor3ub(200, 200, 200);
    glVertex3f(-260, 285, -400);
    glVertex3f(0, 440, -400);
    glVertex3f(260, 285, -400);
    glEnd();



    glPushMatrix();//bulat atas
    glColor3ub(255, 255, 255);
    glTranslatef(0, 420, -250);
    glutSolidSphere(100, 20, 16);
    glColor3ub(0, 255, 0);
    glTranslatef(0, 120, 0);
    cylinder(10, 10, 30);
    //cone atas
    glColor3ub(250, 250, 250);
    glTranslatef(0, 3, 0);
    glRotatef(90, -90, 1, 0);
    glutSolidCone(20, 30, 10, 10);
    glPopMatrix();
    glEnd();

    //tiang
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0, 470, -120);
    balok(7, 7, 80);
    glPopMatrix();
    glEnd();
}

void lantai_kelas() {
    glPushMatrix();
    glColor3ub(255 ,228 ,225);
    balok(425, 150, 5);
    glPopMatrix();
    glEnd();
}

void bingkai()
{
    glPushMatrix();
    glColor3ub(160, 82, 45);
    balok(5, 5, 70);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(160, 82, 45);
    glTranslatef(20, 30, 0);
    balok(50, 5, 5);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(160, 82, 45);
    glTranslatef(40, 0, 0);
    balok(5, 5, 70);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(160, 82, 45);
    glTranslatef(20, -30, 0);
    balok(50, 5, 5);
    glPopMatrix();
    glEnd();

    glPushMatrix();//foto
    glColor3ub(127 ,255 ,212);
    glTranslatef(25, 0, -0.5);
    balok(38, 5, 65);
    glPopMatrix();
    glEnd();
}
void tv() {
    //TV
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);
    balok(100, 5, 70);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0,-25,10);
    balok(8, 8, 8);
    glPopMatrix();
    glEnd();
    

}
void loker() {

    glPushMatrix();
    glColor3ub(139, 69, 19);
    balok(140, 30, 5);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glTranslatef(0, -100, 0);
    glColor3ub(139, 69, 19);
    balok(140, 30, 5);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glTranslatef(0, -70, 0);
    glColor3ub(139, 69, 19);
    balok(140, 30, 5);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glTranslatef(0, -40, 0);
    glColor3ub(139, 69, 19);
    balok(140, 30, 5);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(128 ,0 ,0);
    glTranslatef(-70,-50,0);
    balok(5, 30, 100);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(128, 0, 0);
    glTranslatef(70, -50, 0);
    balok(5, 30, 100);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(128, 0, 0);
    glTranslatef(-35, -50, 0);
    balok(5, 30, 100);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(128, 0, 0);
    glTranslatef(-10, -50, 0);
    balok(5, 30, 100);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(128, 0, 0);
    glTranslatef(15, -50, 0);
    balok(5, 30, 100);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(128, 0, 0);
    glTranslatef(45, -50, 0);
    balok(5, 30, 100);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(210 ,105 ,30);
    glTranslatef(0, -50, -15);
    balok(140, 4, 100);
    glPopMatrix();
    glEnd();

}
void meja() {
    glPushMatrix();
    glColor3ub(160, 82, 45);
    balok(80, 60, 5);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(160, 82, 45);
    glTranslatef(-30,-20,15);
    balok(5, 5, 40);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(160, 82, 45);
    glTranslatef(-30, -20, -15);
    balok(5, 5, 40);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(160, 82, 45);
    glTranslatef(30, -20, 15);
    balok(5, 5, 40);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(160, 82, 45);
    glTranslatef(30, -20, -15);
    balok(5, 5, 40);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glTranslatef(0, -20, 60);
    balok(30, 30, 5);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(160, 82, 45);
    glTranslatef(-10, -10, 70);
    balok(4, 4, 60);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(160, 82, 45);
    glTranslatef(10, -10, 70);
    balok(4, 4, 60);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(160, 82, 45);
    glTranslatef(-10, -30, 50);
    balok(4, 4, 20);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(160, 82, 45);
    glTranslatef(10, -30, 50);
    balok(4, 4, 20);
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glColor3ub(160, 82, 45);
    glTranslatef(0, 10, 70);
    balok(30, 4, 15);
    glPopMatrix();
    glEnd();
}
void universitas()
{
    glPushMatrix();
    lantai();
    glPopMatrix();
    glEnd();

    glPushMatrix();//depan
    glTranslatef(-240, 15, 135);//kiri
    base_depan();
    glTranslatef(130, 0, 0);//kiri tengah
    base_depan();
    glTranslatef(220, 0, 0);//kanan tengah
    base_depan();
    glTranslatef(130, 0, 0);//karna
    base_depan();
    glPopMatrix();
    glEnd();

    glPushMatrix();//kiri belakang
    glTranslatef(-240, 15, 65);
    base_depan();
    glTranslatef(480, 0, 0);
    base_depan();
    glPopMatrix();
    glEnd();

    glPushMatrix();//tangga kiri
    glTranslatef(-35, 0, 0);
    tangga_depan();
    glPopMatrix();
    glEnd();

    glPushMatrix();//tangga kanan
    glTranslatef(315, 0, 0);
    tangga_depan();
    glPopMatrix();
    glEnd();

    glPushMatrix();//alas depan
    glTranslatef(0, -6, 65);
    alas_depan();
    glPopMatrix();
    glEnd();

    glPushMatrix();//samping kiri
    glTranslatef(0, 0, -10);
    samping();
    glPopMatrix();
    glEnd();

    glPushMatrix();//samping kanan
    glTranslatef(350, 0, -10);
    samping();
    glPopMatrix();
    glEnd();

    glPushMatrix();
    tangga_utama();
    glPopMatrix();
    glEnd();

    glPushMatrix();
    lantaiatas();
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glTranslatef(-110, -15, 140);
    lampu();
    glTranslatef(220, 0, 0);
    lampu();
    glPopMatrix();
    glEnd();

    glPushMatrix();
    pilar_depan();
    glPopMatrix();
    glEnd();

    glPushMatrix();
    atap();
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glTranslatef(-650, 150, -390);
    bingkai();
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glTranslatef(-630, 30, -330);
    meja();
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glTranslatef(-530, 30, -330);
    meja();
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glTranslatef(-300, 85, -320);
    glRotatef(-90, 0, 1, 0);
    loker();
    glPopMatrix();
    glEnd();
    
    glPushMatrix();
    glTranslatef(-290, 130, -310);
    balok_depan_kiri();
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glTranslatef(-430, 30, -330);
    meja();
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glTranslatef(-350, 150, -390);
    bingkai();
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glTranslatef(-470, -20, -310);
    lantai_kelas();
    glPopMatrix();
    glEnd();

    glPushMatrix();
    glTranslatef(-480, 100, -390);
    tv();
    glPopMatrix();
    glEnd();

    
}
void tampil(void)
{
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gluLookAt(0.0f, 150.0f, 2000.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 0, 1, 0);
    glRotatef(yrot, 1, 0, 0);
    universitas();

    glEnd();
    glPopMatrix();
    glutSwapBuffers();

}


void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'W':
    case 'w':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'S':
    case 's':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'D':
    case 'd':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 'A':
    case 'a':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case 'Q':
    case 'q':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    case '1':
        if (tembok) {
            tembok = false;
        }
        else {
            tembok = true;
        }
        break;
    }
    tampil();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = xrot = x;
        ydiff = yrot = y;
    }
    else {
        mouseDown = false;
    }
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        xrot = x;
        yrot = y;

        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 5000.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
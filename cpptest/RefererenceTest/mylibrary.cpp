#include <stdio.h>
#include <iostream>
#include "Myheader.h"
using namespace std;

class Point // Class Ű���� + �̸� (private: public: ������� �ʿ�, ���� �Լ�)
{
private:

    int x; //�⺻�������� �����ڴ� private, class Point �ȿ����� ��� ����
    int y;

   // Point(int x=0, int y=0) : x(x),y(y){} //initailizer ���
public:

    Point(int x=0, int y=0) :x(x) // ������
    {
       // this->x = y; this->y = y;
        this->y = y;
    }
    int X() { return x; }
    int Y() { return y; }
    void SetX(int x) {this->x = x;}
    void SetY(int y) { this->y = y;}

    double distance(Point p) //Point p ���� �Ÿ�
    {
        int x2 = (x - p.x) * (x - p.x);
        int y2 = (y - p.y) * (y - p.y);
        return sqrt(x2 + y2);
    }
};

class Point3D :public Point //2D point class��� 
{
private:
    int z; //z�� �߰�
public:
    Point3D(int x = 0, int y = 0) : Point(x, y)
    {
        this->z = z;
    }
    int Z() { return z;}
    void SetZ(int z) {this->z = z;} 

    double distance(Point3D p) //Point3D p ���� �Ÿ�
    {
        int x2 = (X() - p.X()) * (X() - p.X());
        int y2 = (Y() - p.Y()) * (Y() - p.Y());
        int z2 = (z - p.z) * (z - p.z);
        return sqrt(x2 + y2 + z2);
    }
};


int main()
{
    //cout << "Hello C plus world!\n\n";
    //int a, b;
    //a = 10;
    //b = 20;
    //cout << "�ʱⰪ�� a = " << a << ", b =" << b << endl;
    //swapValue(a, b);
    //cout << "�����(swapValue)�� a = " << a << ", b =" << b << endl;
    //swapRef(a, b);//referenceŸ�Կ� ȣ��
    //printf("�����(swapRef:ref)�� a = %d, b= %d \n\n", a, b);
    //swapRef(&a, &b);//������Ÿ�Կ� ȣ��
    //printf("�����(swapRef:������)�� a = %d, b= %d \n\n", a, b);
    Point p1; //p(0,0) struct --> typedef --->���
    Point p2(10, 20);
    Point* p3 = new Point(20,30); //�����Ҵ�
    //cout<<"�� �� p1("
    printf("Point class ������ ���� �Ҵ� : p3(%d, %d)\n\n", p3->X(), p3->Y());//������Ÿ������ �Ҵ���� ������ ȭ��ǥ
    printf("�� �� p1(%d,%d)�� p2(%d,%d)�� �Ÿ��� %f �Դϴ�.\n", p1.X(), p1.Y(), p2.X(), p2.Y(), p1.distance(p2));

    Point3D pp1; //p(0,0) struct --> typedef --->���
    Point3D pp2(10, 20);
    Point3D* pp3 = new Point3D(40, 50, 60); //�����Ҵ�
 
    printf("Point3D class ������ ���� �Ҵ� : p3(%d, %d)\n\n", pp3->X(), pp3->Y(),pp3->Z());//������Ÿ������ �Ҵ���� ������ ȭ��ǥ
    printf("�� �� p1(%d,%d)�� p2(%d,%d)�� �Ÿ��� %f �Դϴ�.\n", 
        pp3->X(), pp3->Y(),pp3->Z(), pp2.X(), pp2.Y(),pp2.Z(), pp2.distance(*pp3));



//void swapRef(int& a, int& b) //�����͸� ������� ����
//{
//    int c = a;
//    a = b; b = c;
//
//}

//void swapRef(int* a, int* b) //�����͸� ���
//{
//    int c = *a;
//    *a = *b; *b = c;
//
//}

//void swapValue(int a, int b)
//{
//    int c = a;
//    a = b; b = c;
//
//}
//
//void swapRef(int& a, int& b) //�����͸� ������� ����
//{
//    int c = a;
//    a = b; b = c;
//
//}
//void swapRef(int* a, int* b) //�����͸� ���
//{
//    int c = *a;
//    *a = *b; *b = c;
//
//}


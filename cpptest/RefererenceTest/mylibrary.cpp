#include <stdio.h>
#include <iostream>
#include "Myheader.h"
using namespace std;

class Point // Class 키워드 + 이름 (private: public: 멤버변수 필요, 내부 함수)
{
private:

    int x; //기본접근제어 지시자는 private, class Point 안에서만 사용 가능
    int y;

   // Point(int x=0, int y=0) : x(x),y(y){} //initailizer 사용
public:

    Point(int x=0, int y=0) :x(x) // 생성자
    {
       // this->x = y; this->y = y;
        this->y = y;
    }
    int X() { return x; }
    int Y() { return y; }
    void SetX(int x) {this->x = x;}
    void SetY(int y) { this->y = y;}

    double distance(Point p) //Point p 와의 거리
    {
        int x2 = (x - p.x) * (x - p.x);
        int y2 = (y - p.y) * (y - p.y);
        return sqrt(x2 + y2);
    }
};

class Point3D :public Point //2D point class상속 
{
private:
    int z; //z축 추가
public:
    Point3D(int x = 0, int y = 0) : Point(x, y)
    {
        this->z = z;
    }
    int Z() { return z;}
    void SetZ(int z) {this->z = z;} 

    double distance(Point3D p) //Point3D p 와의 거리
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
    //cout << "초기값은 a = " << a << ", b =" << b << endl;
    //swapValue(a, b);
    //cout << "결과값(swapValue)은 a = " << a << ", b =" << b << endl;
    //swapRef(a, b);//reference타입에 호출
    //printf("결과값(swapRef:ref)은 a = %d, b= %d \n\n", a, b);
    //swapRef(&a, &b);//포인터타입에 호출
    //printf("결과값(swapRef:포인터)은 a = %d, b= %d \n\n", a, b);
    Point p1; //p(0,0) struct --> typedef --->사용
    Point p2(10, 20);
    Point* p3 = new Point(20,30); //동적할당
    //cout<<"두 점 p1("
    printf("Point class 변수의 동적 할당 : p3(%d, %d)\n\n", p3->X(), p3->Y());//포인터타입으로 할당받을 때에는 화살표
    printf("두 점 p1(%d,%d)과 p2(%d,%d)의 거리는 %f 입니다.\n", p1.X(), p1.Y(), p2.X(), p2.Y(), p1.distance(p2));

    Point3D pp1; //p(0,0) struct --> typedef --->사용
    Point3D pp2(10, 20);
    Point3D* pp3 = new Point3D(40, 50, 60); //동적할당
 
    printf("Point3D class 변수의 동적 할당 : p3(%d, %d)\n\n", pp3->X(), pp3->Y(),pp3->Z());//포인터타입으로 할당받을 때에는 화살표
    printf("두 점 p1(%d,%d)과 p2(%d,%d)의 거리는 %f 입니다.\n", 
        pp3->X(), pp3->Y(),pp3->Z(), pp2.X(), pp2.Y(),pp2.Z(), pp2.distance(*pp3));



//void swapRef(int& a, int& b) //포인터를 사용하지 않음
//{
//    int c = a;
//    a = b; b = c;
//
//}

//void swapRef(int* a, int* b) //포인터를 사용
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
//void swapRef(int& a, int& b) //포인터를 사용하지 않음
//{
//    int c = a;
//    a = b; b = c;
//
//}
//void swapRef(int* a, int* b) //포인터를 사용
//{
//    int c = *a;
//    *a = *b; *b = c;
//
//}


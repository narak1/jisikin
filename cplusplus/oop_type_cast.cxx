#include <iostream>
using namespace std;

class shape{
   private:
   int x, y;
   int height;
   int width;
   float area;
   float grith;
   public:
   shape(){}
   shape(int x, int y, int height, int width) :x(x), y(y), height(height), width(width){}
   void setx(int x){ this->x = x; }
   void sety(int y){ this->y = y; }
   void setheight(int height){ this->height = height; }
   void setwidth(int width){ this->width = width; }
   void setarea(float area){ this->area = area; }
   void setgrith(float grith){
      this->grith = grith;
   }
   int getx(){ return x; }
   int gety(){ return y; }
   int getheight(){ return height; }
   int getwidth(){ return width; }
   float getarea(){ return area; }
   float getgrith(){ return grith; }
   void print()
   {
      cout << "==================================" << endl;
      cout << "시작 x,y : " << x << ", " << y << endl;
   }
};
class rectangle :public shape{
   public:
   rectangle(){}
   rectangle(int x, int y, int height, int width) : shape(x, y, height, width){}
   void getarea()
   {
      setarea((float)getwidth() *getheight());
      setgrith((float)getwidth() * 2 + (float)getheight() * 2);
   }
   void print()
   {
      shape::print();
      cout << "가로 세로 : " << getwidth() << ", " << getheight() << endl;
      cout << "넓이 : " << shape::getarea() << endl;
      cout << "둘레 : " << shape::getgrith() << endl;
   }
};
class circle : public shape{
   public:
   circle(){}
   circle(int x, int y, int rad) : shape(x, y, rad, 0){}
   void getarea()
   {
      float pi = 3.14;
      setarea((float)getheight()*getheight()*pi);
      setgrith((float)getheight() * 2 * pi);
   }
   void print()
   {
      shape::print();
      cout << "반지름 : " << getheight() << endl;
      cout << "넓이 : " << shape::getarea() << endl;
      cout << "둘레 : " << shape::getgrith() << endl;
   }
};

main()
{
	shape myfig(10, 15, 20, 30);

	cout << "== Shape ==" << endl;
	myfig.print();

	cout << "== Rectangle ==" << endl;
	rectangle *myrec = (rectangle *) &myfig;
	myrec->getarea();
	myrec->print();

	cout << "== Circle ==" << endl;
	circle *mycir = (circle *) &myfig;
	mycir->getarea();
	mycir->print();
}

#include <iostream>
using namespace std;

class Boonsoo {
   int ja;
   int mo;
public:
   void set(int j, int m) { ja= j; mo = m; }
   int get_ja() { return ja; }
   int get_mo() { return mo; }
   void Add(Boonsoo* b) {
      // 두 개의 분수를 통분하여 더하는 코드 작성
      this->ja = this->ja * b->mo + this->mo * b->ja;
      this->mo *= b->mo;
   }
   void print() {
      cout << ja << "/" << mo << endl; }
};

Boonsoo * boonMult(Boonsoo &one, Boonsoo & two)
{
	Boonsoo *c = new Boonsoo;
	int ja = one.get_ja() * two.get_ja();
	int mo = one.get_mo() * two.get_mo();
	c->set(ja, mo);
	return c;
}

int main() {
    Boonsoo boonA, boonB;
    boonA.set(2,3);
    boonB.set(3,5);
    boonA.print();
    boonB.print();
    Boonsoo * boonC = boonMult(boonA, boonB);
    boonC->print();
    delete boonC;
    boonA.Add( & boonB);
    boonA.print();
}



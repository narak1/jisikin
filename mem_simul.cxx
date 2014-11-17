#include <iostream>
using namespace std;
 
class Basememory
{
    char *mem;
protected:
    Basememory(int size) { mem = new char[size]; }
    char getMem(int pos) { return mem[pos]; }
    void setMem(int pos, char data) { mem[pos] = data; }
};
 
class ROM : public Basememory
{
public:
    ROM(int size, char x[], int n) : Basememory(size)
    { for(int i=0; i<n; i++) setMem(i,x[i]); }
    char read(int pos) { return getMem(pos); }
};
 
class RAM : public Basememory
{
public:
    RAM(int size) : Basememory(size) { }
    char read(int pos) { return getMem(pos); }
    void write(int pos, char data) { setMem(pos, data); }
};
int main()
{
    char x[5] = {'G', 'O', 'O', 'D', '!' };
    ROM biosROM(1024*10, x, 5); 
    RAM mainMemory(1024*1024); 
 
    for(int k=0; k<5; k++)
        mainMemory.write(k, biosROM.read(k));
    for(int k=0; k<5; k++)
        cout << mainMemory.read(k);
	cout << endl;
    return 0;
}

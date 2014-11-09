#include <iostream>
using namespace std;
class kkk{
private:
 static int a[2][2];
 static int b[2][2];
public:
 static void in();
 static int re();
};
int kkk::a[2][2]={0};
int kkk::b[2][2]={0};
void kkk::in(){
 cout<<"입력하세요 : ";
for(int i=0; i<2; i++)
 {
  for(int j=0; j<2; j++)
  {
   cin>>a[i][j];
  }
  }
 cout<<"결과: "<< kkk::re() <<endl;
}
int kkk::re()
{
 int d;
 d=a[0][0]*a[1][1] - a[0][1]*a[1][0];
 cout << "d=" << d << endl;
 if( d == 0 )
 	return 0;
 b[0][0]= a[1][1]/d;
 b[0][1]= -a[0][1]/d;
 b[1][0]= -a[1][0]/d;
 b[1][1]= a[0][0]/d;
 for (int i=0; i<2; i++)
 {
  for (int j=0; j<2; j++)
  {
   cout <<b[i][j]<<endl;
  }
  cout<<endl;
 }
 return 1;
}
int main()
{
 kkk::in();
 return 0;
}

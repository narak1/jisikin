#include<stdio.h>
#define MAX_DEGREE 80
class CPoly
{
private:
 
public:
 int m_degree;//변수 선언
 float m_coef[MAX_DEGREE];
 CPoly(void);
 ~CPoly(void);
 void read();//함수 선언
 void print();
 friend CPoly add(CPoly a, CPoly b);
 friend CPoly sub(CPoly a, CPoly b);
 friend CPoly mult(CPoly a, float k);
};

#define MAX(a, b) (((a)>(b))?(a):(b))
CPoly::CPoly(void)//셍성자 합수
{
 m_degree = 0;
 for(int i=0;i<MAX_DEGREE;i++)
  m_coef[i] = 0.0f;
}

CPoly::~CPoly(void)
{
}
void CPoly::read()
{
 printf("다항식의 최고 차수를 입력하시오: ");
 scanf("%d", &m_degree);
 printf("각 항의 계수를 입력하시오 (총 %d개): ", m_degree+1);
 for(int i=0;i<=m_degree;i++)
  scanf("%f", &m_coef[i]);
}
void CPoly::print()
{
 printf("\n");
 printf("다항식: ");
 for(int i=m_degree;i>=0;i--){
  if(m_degree!=0)
  {
   printf("%.2f x %d", m_coef[i], i);
   if(i!=0)
   {
    printf(" + ");
   }
  }
  else
  {
  }
 }
 printf("\n");
}
//객체의 합
CPoly add(CPoly a, CPoly b)
{
 printf("a다항식과 b다항식의 합:  ");
 CPoly c;
 int Apo=a.m_degree, Bpo=b.m_degree, Cpo=MAX(a.m_degree, b.m_degree);
 int degree_a=a.m_degree;
 int degree_b=b.m_degree;
 c.m_degree=MAX(a.m_degree, b.m_degree);
 
 //while문
 //1.a>b  ==> 객체a의 정보를 전달
 //2.a=b  ==> 두 객체의 정보를 더하여 전달
 //3.a<b  ==> 객체b의 내용 전달
 //둘다 0보다 작아지면 중단
 while(Apo >= 0 && Bpo >= 0)
 {  
  if(degree_a>degree_b)
  {
   c.m_coef[Cpo--]=a.m_coef[Apo--];
   degree_a--;
  }
  else if(degree_a==degree_b)
  {
   c.m_coef[Cpo--]=a.m_coef[Apo--]+b.m_coef[Bpo--];
   degree_a--; degree_b--;
  }
  else
  {
   c.m_coef[Cpo--]=b.m_coef[Bpo--];
   degree_b--;
  }
 }
 return c;
}
//객체의 차
CPoly sub(CPoly a, CPoly b)
{
 printf("a다항식과 b다항식의 차:  ");
 
 int a_p=a.m_degree, b_p=b.m_degree, c_p=MAX(a.m_degree, b.m_degree);//최고 차수 저장
 int degree_a=a.m_degree;
 int degree_b=b.m_degree;
 //결과를 저장할 다항식 객체 생성
 //객체c의 최고 차수 설정
 CPoly c;
 c.m_degree=MAX(a.m_degree, b.m_degree);
 //while문
 //1.a>b  ==> 객체a의 정보를 전달
 //2.a=b  ==> 객체a의 정보에서 b의 정보를 뺌
 //3.a<b  ==> -를 붙여줌
 //둘다 0보다 작아지면 중단
 while(a_p>=0 && b_p>=0)
 {
  if(degree_a>degree_b)
  {
   c.m_coef[c_p--]=a.m_coef[a_p--];
   degree_a--;
  }
  else if(degree_a==degree_b)
  {
   c.m_coef[c_p--]=a.m_coef[a_p--]-b.m_coef[b_p--];
   degree_a--; degree_b--;
  }
  else
  {
   c.m_coef[c_p--] =0 - b.m_coef[b_p--];
   degree_b--;
  }
 }
 return c;
}
//객체의 곱
CPoly mult(CPoly a, float k)
{
 printf("다항식 a와 상수 k의 곱:    ");
 //결과 객체 생성
 //객체c의 최고 차수 설정
 CPoly c;
 c.m_degree = a.m_degree;
 //for문
 //객체 a의 정보에 k를 곱
 for(int i=a.m_degree; i>=0;i--)
 {
  c.m_coef[i]=a.m_coef[i] * k;
 }
 return c;
}
 
 
int main()
{
 float k;//mult함수 변수
 CPoly a, b, c;//객체 생성
 a.read();//객체a에 내용 입력
 a.print();//객체a 출력
 b.read();//객체b 내용 입력
 b.print();//객체b 출력
 c = add(a, b);//객체c에 a와 b의 합 저장
 c.print();//c 출력
 c = sub(a, b);//객체c에 a와 b의 차 저장
 c.print();//c 출력
 printf("k를 입력하시오 : ");
 scanf("%f", &k);//상수k를 입력
 c = mult(a, k);//객체c에 객체a와 상수k의 곱을 저장
 c.print();//객체c 출력
}



#include<stdio.h>
#define MAX_DEGREE 80
class CPoly
{
private:
 
public:
 int m_degree;//���� ����
 float m_coef[MAX_DEGREE];
 CPoly(void);
 ~CPoly(void);
 void read();//�Լ� ����
 void print();
 friend CPoly add(CPoly a, CPoly b);
 friend CPoly sub(CPoly a, CPoly b);
 friend CPoly mult(CPoly a, float k);
};

#define MAX(a, b) (((a)>(b))?(a):(b))
CPoly::CPoly(void)//�ļ��� �ռ�
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
 printf("���׽��� �ְ� ������ �Է��Ͻÿ�: ");
 scanf("%d", &m_degree);
 printf("�� ���� ����� �Է��Ͻÿ� (�� %d��): ", m_degree+1);
 for(int i=0;i<=m_degree;i++)
  scanf("%f", &m_coef[i]);
}
void CPoly::print()
{
 printf("\n");
 printf("���׽�: ");
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
//��ü�� ��
CPoly add(CPoly a, CPoly b)
{
 printf("a���׽İ� b���׽��� ��:  ");
 CPoly c;
 int Apo=a.m_degree, Bpo=b.m_degree, Cpo=MAX(a.m_degree, b.m_degree);
 int degree_a=a.m_degree;
 int degree_b=b.m_degree;
 c.m_degree=MAX(a.m_degree, b.m_degree);
 
 //while��
 //1.a>b  ==> ��üa�� ������ ����
 //2.a=b  ==> �� ��ü�� ������ ���Ͽ� ����
 //3.a<b  ==> ��üb�� ���� ����
 //�Ѵ� 0���� �۾����� �ߴ�
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
//��ü�� ��
CPoly sub(CPoly a, CPoly b)
{
 printf("a���׽İ� b���׽��� ��:  ");
 
 int a_p=a.m_degree, b_p=b.m_degree, c_p=MAX(a.m_degree, b.m_degree);//�ְ� ���� ����
 int degree_a=a.m_degree;
 int degree_b=b.m_degree;
 //����� ������ ���׽� ��ü ����
 //��üc�� �ְ� ���� ����
 CPoly c;
 c.m_degree=MAX(a.m_degree, b.m_degree);
 //while��
 //1.a>b  ==> ��üa�� ������ ����
 //2.a=b  ==> ��üa�� �������� b�� ������ ��
 //3.a<b  ==> -�� �ٿ���
 //�Ѵ� 0���� �۾����� �ߴ�
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
//��ü�� ��
CPoly mult(CPoly a, float k)
{
 printf("���׽� a�� ��� k�� ��:    ");
 //��� ��ü ����
 //��üc�� �ְ� ���� ����
 CPoly c;
 c.m_degree = a.m_degree;
 //for��
 //��ü a�� ������ k�� ��
 for(int i=a.m_degree; i>=0;i--)
 {
  c.m_coef[i]=a.m_coef[i] * k;
 }
 return c;
}
 
 
int main()
{
 float k;//mult�Լ� ����
 CPoly a, b, c;//��ü ����
 a.read();//��üa�� ���� �Է�
 a.print();//��üa ���
 b.read();//��üb ���� �Է�
 b.print();//��üb ���
 c = add(a, b);//��üc�� a�� b�� �� ����
 c.print();//c ���
 c = sub(a, b);//��üc�� a�� b�� �� ����
 c.print();//c ���
 printf("k�� �Է��Ͻÿ� : ");
 scanf("%f", &k);//���k�� �Է�
 c = mult(a, k);//��üc�� ��üa�� ���k�� ���� ����
 c.print();//��üc ���
}



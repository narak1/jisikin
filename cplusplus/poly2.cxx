#include <iostream>
using namespace std;
#define MAX_TERMS 101
struct Poly {
 float coef; //���� �����  ����
 int expon; //���� ���� ������ ����
}terms[MAX_TERMS]={0}, termsum[MAX_TERMS]={0};
// ������ �� ���׽��� ������ �迭, ��� ���׽��� ������ �迭 ����
void attach(float coef, int expon, int avail); //�����ؼ� ���� �׵��� �����ϴ� �Լ�
void poly_multi(int As, int Ae, int Bs, int Be, int avail); //2���� ���׽��� �����ϴ� �Լ�
void poly_ResultSum(int Cs, int Ce, int *su);
//�����ؼ� ���� �׵��� ���� �������� ���ؼ� ���������� �����ϴ� �Լ�
/* ���� �Լ� ���� */
int main()
{
 
 int i=0,j=0;
 
 int Count; // �ι��� ���׽��� ���� ���� ����
    int FAs=0, FAe=0, FBs=0, FBe=0, FCs=0, FCe=0;
}


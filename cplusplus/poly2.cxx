#include <iostream>
using namespace std;
#define MAX_TERMS 101
struct Poly {
 float coef; //항의 계수를  변수
 int expon; //항의 지수 저장할 변수
}terms[MAX_TERMS]={0}, termsum[MAX_TERMS]={0};
// 연산을 할 다항식을 저장할 배열, 결과 다항식을 저장할 배열 선언
void attach(float coef, int expon, int avail); //곱셈해서 나온 항들을 저장하는 함수
void poly_multi(int As, int Ae, int Bs, int Be, int avail); //2개의 다항식을 곱셈하는 함수
void poly_ResultSum(int Cs, int Ce, int *su);
//곱셈해서 나온 항들을 같은 차수끼리 더해서 최종적으로 저장하는 함수
/* 메인 함수 시작 */
int main()
{
 
 int i=0,j=0;
 
 int Count; // 두번재 다항식의 항의 개수 저장
    int FAs=0, FAe=0, FBs=0, FBe=0, FCs=0, FCe=0;
}


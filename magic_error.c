int main()
{
 int h[100][100];
 int x,y,a,b,i,j;
 printf("마방진 크기 입력");
 scanf("%d",&a);
 x=0;
 y=a/2;
 h[x][y]=1;
 b=2;
 for(i=1;i<a*a;i++)
 {
  if(i%a==0)
  {
   if(x<a-1)
   {
    h[x+1][y]=b;
    x=x+1;
    b++;
   }
   else
   {
    h[0][y]=b;
    x=0;
    b++;
   }
  }
  else
  {
   if(x=0)
   {
    h[a-1][y+1]=b;
    x=a-1;y=y+1;
    b++;
   }
   else if(y=a-1)
   {
    h[x-1][0]=b;
    x=x-1;y=0;
    b++;
   }
   else
   {
    h[x-1][y+1]=b;
    x=x-1;y=y+1;
    b++;
   }
  }
 }
 for(i=0;i<a;i++)
 {
  for(j=0;j<a;j++)
  {printf(" %2d ",h[i][j]);}
  printf("\n");
 }


}

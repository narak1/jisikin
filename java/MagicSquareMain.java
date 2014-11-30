import java.util.Scanner;

public class MagicSquareMain  {
 public static void main(String[] args){

  int get=0;

  System.out.println("odd number enter");

  Scanner scan = new Scanner(System.in);
  get = scan.nextInt();

  if(get%2==0) {
   System.out.println("error...");
   return;
  }

  int [][]arr = new int[get][get];

  int i=0;
  int j=get/2;
  int count=0;

  arr[i][j] = ++count;
  for(count=2; count<=get*get; ++count)
  {
      i--;
      j--;

   if(i<0)
    i=get-1;

   if(j<0)
    j=get-1;

   if(arr[i][j]==0)
    arr[i][j]=count;
   else {
   	++i;
   	++j;
    i++;
    if( i>=get )
    	i -= get;
    if( j==get )
    	j = 0;
    arr[i][j]=count;
   }
  }

  for(i=0; i<get; i++)
  {
   for(j=0; j<get; j++)
   {
    System.out.print(arr[i][j]+"\t");
   }
   System.out.println();
  }
 }
 }

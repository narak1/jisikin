public class Matrix
{
public static void main(String[] args)
{
	int[][] matrixA = {{35, 28, 73}, {25, 32, 69}, {97, 56, 23}, {45, 97, 15}};
	int[][] matrixB = {{125, 28, 56, 34}, {32, 69, 57, 56}, {59, 45, 33, 45}};
	int[][] matrixR;

	System.out.println("matrixA=");
	prettyPrint(matrixA);
	System.out.println("matrixB=");
	prettyPrint(matrixB);

	matrixR = multiplyMatrix(matrixA, matrixB);
	System.out.println("AB=");
	prettyPrint(matrixR);
}

public static void prettyPrint (int[][] m)
{
	for(int i = 0; i < m.length; i++) {
		for(int j = 0; j < m[i].length; j++) {
			System.out.print(m[i][j]+" ");
		}
		System.out.println();
	}
}

public static int[][] multiplyMatrix(int[][] ma, int[][] mb)
{
	int ra = ma.length;
	int ca = ma[0].length;
	int rb = mb.length;
	int cb = mb[0].length;

	if (ca != rb) { throw new RuntimeException("Illegal matrix dimensions."); }

	int[][] mc = new int[ra][cb];
	for(int i = 0; i < ra; i++) {
		for(int j = 0; j < cb; j++) {
			for(int k=0; k < ca; k++) {
				mc[i][j] += (ma[i][k] * mb[k][j]);
			}
		}
	}
	return mc;
}
}

class lcmgcd
{
	public static int calc_gcd(int n1, int n2)
	{
		int r = n2 % n1;
		while( r != 0 )
		{
			n2 = n1;
			n1 = r;
			r = n2 % n1;
		}

		return n1;
	}

	public static int calc_lcm(int n1, int n2)
	{
		int g = calc_gcd(n1, n2);
		return n1 * n2 / g;
	}

	public static void main(String[] args)
	{
		for( int i=0 ; i<args.length ; i++ )
		{
			System.out.println("args[" + i + "] = " + args[i]);
		}

		if( args.length != 2 )
		{
			System.out.println("only two argument need!");
			return;
		}

		int num1, num2, num_gcd, num_lcm;

		num1 = Integer.parseInt(args[0]);
		num2 = Integer.parseInt(args[1]);

		num_gcd = calc_gcd(num1, num2);
		num_lcm = calc_lcm(num1, num2);

		System.out.println("num1=" + num1 + ", num2=" + num2 + ".");
		System.out.println("GCD=" + num_gcd + ", LCM=" + num_lcm + ".");
	}
}

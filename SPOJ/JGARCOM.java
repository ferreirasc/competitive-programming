import java.util.Scanner;

class garcom
{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		int n, lat, copo, quebrado=0, i=0;
		n = input.nextInt();
		if(n>100 || n<1)System.exit(0);
			while(i<n)
			{
				lat=input.nextInt();
				copo=input.nextInt();
				if(lat<0 || lat>100 || copo<0 || copo>100)System.exit(0);
				if(lat>copo)quebrado=quebrado+copo;
				i++;
			}
		System.out.println(quebrado);
	}
}
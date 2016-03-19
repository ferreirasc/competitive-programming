import java.util.Scanner;

class CFATORES
{
	public static void main(String args[])
	{
		int N, soma, i, auxN, flag, auxI;
		Scanner in = new Scanner(System.in);
		do
		{
			soma = flag = 0;
			N = in.nextInt();
			if(N==0)break;
			auxN = N;
				for(i=2;N>1;)
				{
					auxI = i;
					if(N % i == 0)
					{
						N /= i;
						if(flag == 0)soma++;
						flag = 1;
						i = auxI;
					}
					else
					{
						flag = 0;
						i++;
					}
				}
			System.out.println(auxN + " : " + soma);
		}while(true);
	}
}

import java.io.*;
import java.util.*;

public class R151D2C
{
	static int n,k;
	static int a[];

	static void show(int n,int k)
	{
		int cnt=0;
		for(int i=n-1; i>=0; i--)
		{
			for(int j=i; j>=0; j--)
			{
				System.out.print(n-i);
				for(int u=n-1; u>i; u--)
					System.out.print(" "+a[u]);
				System.out.println(" "+a[j]);
				cnt++;
				if(cnt==k)
					return;
			}
		}
	}

	static public void main(String[] args)
	{
		Scanner jin=new Scanner(System.in);
		int n,k;
		n=jin.nextInt();
		k=jin.nextInt();
		a=new int[n];
		for(int i=0; i<n; i++)
			a[i]=jin.nextInt();
		Arrays.sort(a);
		show(n,k);
	}
}

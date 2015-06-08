import java.io.*;
import java.util.*;

public class R151D2B
{
	public static void main(String[] args)
	{
		Scanner cin=new Scanner(System.in);
		int n;
		while(cin.hasNext())
		{
			n=cin.nextInt();
			int s=0;
			for(int i=0; i<n; i++)
			{
				int x;
				x=cin.nextInt();
				s+=x;
			}
			int ret=n-1;
			if((s%n)==0)
				ret++;
			System.out.println(ret);
		}
	}
}

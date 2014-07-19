import java.io.*;
import java.util.*;

public class R151D2A {

	static int[] ans=new int[100];

	public static void main(String[] args) {
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext()) {
			int n=cin.nextInt();
			if(n<=2)
				System.out.println("-1");
			else
			{
				for(int i=0; i<n; i++)
					System.out.print((n-i)+" ");
			}
		}
	}
}

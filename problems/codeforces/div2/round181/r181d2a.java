import java.io.*;
import java.util.*;

public class R181D2A {

	public static void main(String []args) throws Exception{
		new gao().hugao();
	}

}

class gao {

	Scanner in=new Scanner(System.in);
	List<Integer> li;
	List<Integer> ll;

	void hugao() throws Exception{
		int n=in.nextInt();
		int ze=0,tag=0,y=0;
		li=new ArrayList<Integer>();
		ll=new ArrayList<Integer>();
		for(int i=0; i<n; i++) {
			int x=in.nextInt();
			if(x==0) 
				ze++;
			else if(x<0) {
				if(tag==0) {
					y=x;
					tag=1;
				}
				else
					ll.add(x);
			}
			else
				li.add(x);
		}
		int z=ll.size();
		if((ll.size()&1)>0)
			z--;
		System.out.println(1+" "+y);
		System.out.print(li.size()+z);
		for(int x:li)
			System.out.print(" "+x);
		for(int i=0; i<z; i++)
			System.out.print(" "+ll.get(i));
		System.out.println("");
		System.out.print(ze+ll.size()-z);
		for(int i=0; i<ze; i++)
			System.out.print(" "+0);
		for(int i=z; i<ll.size(); i++)
			System.out.print(" "+ll.get(i));
		System.out.println("");
	}
}

import java.io.*;
import java.util.*;

public class R151D2D {

	Scanner in=new Scanner(System.in);

	void print(String str) {
		System.out.print(str);
	}

	void println(String str) {
		System.out.println(str);
	}

	void run() {
		int n=in.nextInt(),m=in.nextInt();
		int col[]=new int[n];
		for(int i=0; i<n; i++)
			col[i]=in.nextInt();
		Map<Integer, Set<Integer>> mp=new TreeMap<Integer, Set<Integer>>();
		for(int i=0; i<n; i++)
		{
			if(mp.containsKey(col[i])) continue;
			mp.put(col[i],new HashSet<Integer>());
		}
		for(int i=0; i<m; i++)
		{
			int x=in.nextInt()-1,y=in.nextInt()-1;
			if(col[x]==col[y]) continue;
			mp.get(col[x]).add(col[y]);
			mp.get(col[y]).add(col[x]);
		}
		int ret=-1,rc=-1;
		for(int i:mp.keySet())
		{
			if(mp.get(i).size()>ret)
			{
				ret=mp.get(i).size();
				rc=i;
			}
		}
		println(Integer.toString(rc));
	}

	static public void main(String[] args) throws Exception {
		new R151D2D().run();
	}
}

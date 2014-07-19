import java.io.*;
import java.util.*;

public class R181D2B {

	public static void main(String[] args) throws Exception{
		new gao().hugao();
	}

}

class gao {

	Scanner in=new Scanner(System.in);

	int tag[],m,n,vis[];

	List<List<Integer>> li;
	List<List<Integer>> ret;
	List<Integer> ll;

	int dfs(int w,int p,int c) {
		if(ll.size()>3) return 0;
		vis[w]=1;
		ll.add(w);
		for(int t:li.get(w)) {
			if(t==p) continue;
			if(vis[t]==1) continue;
			if(tag[t]==1) continue;
			if(dfs(t,w,c+1)==0) {
				return 0;
			}
		}
		return 1;
	}

	public void hugao() throws Exception{

		n=in.nextInt();
		m=in.nextInt();
		tag=new int[n];
		vis=new int[n];
		for(int i=0; i<n; i++) {
			tag[i]=0;
			vis[i]=0;
		}

		li=new ArrayList<List<Integer>>();
		ret=new ArrayList<List<Integer>>();

		for(int i=0; i<n; i++)
			li.add(new ArrayList<Integer>());
		for(int i=0; i<m; i++) {
			int x=in.nextInt(),y=in.nextInt();
			x--;
			y--;
			li.get(x).add(y);
			li.get(y).add(x);
		}

		for(int i=0; i<n; i++)
			if(tag[i]==0) {
				ll=new ArrayList<Integer>();
				for(int j=0; j<n; j++)
					vis[j]=0;
				if(dfs(i,-1,0)==0) {
					System.out.println(-1);
					return;
				}
	//			System.out.println(ll.size()+"=>");
				if(ll.size()>3) {
					System.out.println(-1);
					return;
				}
				if(ll.size()>1) {
					for(int x:ll)
						tag[x]=1;
					ret.add(ll);
				}
			}
		if(ret.size()>n/3) {
			System.out.println(-1);
			return;
		}
		List<Integer> l=new ArrayList<Integer>();
		for(int i=0; i<n; i++)
			if(tag[i]==0)
				l.add(i);
		int i=0;
		for(List<Integer> now:ret) {
			for(int x:now) {
				System.out.print((x+1)+" ");
			}
			if(now.size()<3) {
				System.out.print((l.get(i++)+1)+" ");
			}
			System.out.println("");
		}
		for(; i<l.size(); i+=3)
			System.out.println((l.get(i)+1)+" "+(l.get(i+1)+1)+" "+(l.get(i+2)+1));
	}

}

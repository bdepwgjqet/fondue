import java.io.*;
import java.util.*;

public class R151D2E {

	Scanner in=new Scanner(System.in);
	PrintWriter out=new PrintWriter(System.out);

	int[] id,pa,ret;
	List<Integer>[] tr;
	List<int[]>[] q;

	Map<Integer, Set<Integer>> gao(int w,int p,int l) {
		Map<Integer, Set<Integer>> mp=new TreeMap<Integer, Set<Integer>>();
		Set<Integer> st=new HashSet<Integer>();
		st.add(id[w]);
		for(int i: tr[w]){
			if(i==p) continue;
			mp=merge(mp,gao(i,w,l+1));
		}
		mp.put(l,st);
		for(int[] i: q[w])
			if(mp.containsKey(i[0]+l))
				ret[i[1]]=mp.get(i[0]+l).size();
		return mp;
	}

	Set<Integer> merge(Set<Integer> a,Set<Integer> b) {
		if(a==null) return b;
		if(b==null) return a;
		if(a.size()>b.size()) return merge(b,a);
		for(int i:a)
			b.add(i);
		return b;
	}

	Map<Integer, Set<Integer>> merge(Map<Integer, Set<Integer>> a,Map<Integer, Set<Integer>> b)
	{
		if(a.size()>b.size())
			return merge(b,a);
		for(int i:a.keySet()) {
			b.put(i,merge(a.get(i),b.get(i)));
		}
		return b;
	}

	void run() {
		int n=in.nextInt(),m;
		id=new int[n];
		pa=new int[n];
		tr=new List[n];
		Map<String,Integer> name=new HashMap<String,Integer>();
		for(int i=0; i<n; i++)
			tr[i]=new ArrayList<Integer>();
		for(int i=0; i<n; i++) {
			String s=in.next();
			int x=in.nextInt();
			if(!name.containsKey(s))
				name.put(s,name.size());
			id[i]=name.get(s);
			pa[i]=x-1;
			if(pa[i]>=0)
				tr[pa[i]].add(i);
		}

		m=in.nextInt();
		ret=new int[m];
		q=new List[n];
		for(int i=0; i<n; i++)
			q[i]=new ArrayList<int[]>();
		for(int i=0; i<m; i++) {
			int x=in.nextInt(),y=in.nextInt();
			q[x-1].add(new int[]{y,i});
		}

		for(int i=0; i<n; i++)
			if(pa[i]==-1)
				gao(i,-1,0);
		for(int i=0; i<m; i++)
			out.println(ret[i]);
		out.flush();
	}

	static public void main(String[] args) throws Exception{
		new R151D2E().run();
	}
}

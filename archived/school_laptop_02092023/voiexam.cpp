#include<bits/stdc++.h>

using namespace std;
#define int long long
struct myEdge{
	int u, v, cap, flow;
	string s;
};
struct Flow{
	int n, s, t, d[12005], ptr[12005];
	vector<int> edge[12005];
	vector<myEdge> edgelist;
	Flow(int _n, int _s, int _t){
		n = _n;
		s = _s;
		t = _t;
	}
	void addEdge(int u, int v, int c, string s){
		edge[u].push_back(edgelist.size()); edgelist.push_back(myEdge({u,v,c,0,s}));
		edge[v].push_back(edgelist.size()); edgelist.push_back(myEdge({v,u,0,0,""}));
	}
	int bfs(){
		queue<int> q;
		for (int i = 1; i <= n; i++) d[i] = -1;
		d[s] = 0;
		q.push(s);
		while (q.size()){
			int u = q.front(); q.pop();
			for (int id: edge[u]){
				auto& it = edgelist[id];
				if (d[it.v]==-1&&it.flow<it.cap) d[it.v] = d[u] + 1, q.push(it.v); 
			}
		}
		return d[t]!=-1;
	}
	int dfs(int u, int val){
		if (!val) return 0;
		if (u==t) return val;
		for (; ptr[u] < edge[u].size(); ptr[u]++){
			int id = edge[u][ptr[u]];
			auto &it =  edgelist[id], &it_rev = edgelist[id^1];
			if (d[it.v]!=d[u]+1) continue;
			int new_val = dfs(it.v,min(val,it.cap-it.flow));
			if (!new_val) continue;
			it.flow += new_val;
			it_rev.flow -= new_val;
			return new_val;
		}
		return 0;
	}
	int maxFlow(){
		int res = 0;
		while (bfs()){
			for (int i = 1; i<= n; i++) ptr[i] =0;
			while (true){
				int val = dfs(s,1e9);
				if (!val) break;
				res += val;
			}
		}
		return res;
	}
	void trace(){
		queue<int> q;
		q.push(s);
		while (q.size()){
			int u = q.front(); q.pop();
			for (int id: edge[u]){
				auto& it = edgelist[id];
				if (it.flow==1){
					cout << it.s;
					q.push(it.v);
				}
			}
		}
	}
};

int calc(int a, char c, int b){
	if (c=='+') return a+b;
	if (c=='-') return a-b;
	if (c=='*') return a*b;
	if (c=='/') return a/b;
	return -1;
}
template<class T, class P>
string calc2(T a, char c, P b){
	stringstream ss;
	ss << '(' << a << c << b << ')';
	return string(ss.str());
}
int n;
string s;
vector<int> v[2005];
vector<string> v2[2005];

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1, x[5], c[5]; i<= n; i++){
		cin >> s;
		int cnt = 0;
		x[0] = 0;
		for (char ch: s){
			if (ch>='0'&&ch<='9'){
				x[cnt] = x[cnt]*10 + ch-'0'; 
			} else {
				c[cnt] = ch;
				cnt++;
				x[cnt] = 0;
			}
		}		
		if (cnt==1){
			v[i].push_back(calc(x[0],c[0],x[1]));
			v2[i].push_back(calc2(x[0],c[0],x[1]));
		} else if (cnt==2){
			v[i].push_back(calc(calc(x[0],c[0],x[1]),c[1],x[2]));
			v[i].push_back(calc(x[0],c[0],calc(x[1],c[1],x[2])));
			v2[i].push_back(calc2(calc2(x[0],c[0],x[1]),c[1],x[2]));
			v2[i].push_back(calc2(x[0],c[0],calc2(x[1],c[1],x[2])));
		} else {
			v[i].push_back(calc(calc(calc(x[0],c[0],x[1]),c[1],x[2]),c[2],x[3])); //((ab)c)d
			v[i].push_back(calc(calc(x[0],c[0],calc(x[1],c[1],x[2])),c[2],x[3])); //(a(bc))d
			v[i].push_back(calc(x[0],c[0],calc(calc(x[1],c[1],x[2]),c[2],x[3]))); //a((bc)d)
			v[i].push_back(calc(x[0],c[0],calc(x[1],c[1],calc(x[2],c[2],x[3])))); //a(b(cd))
			v[i].push_back(calc(calc(x[0],c[0],x[1]),c[1],calc(x[2],c[2],x[3]))); //(ab)(cd)
			v2[i].push_back(calc2(calc2(calc2(x[0],c[0],x[1]),c[1],x[2]),c[2],x[3])); 
			v2[i].push_back(calc2(calc2(x[0],c[0],calc2(x[1],c[1],x[2])),c[2],x[3])); 
			v2[i].push_back(calc2(x[0],c[0],calc2(calc2(x[1],c[1],x[2]),c[2],x[3]))); 
			v2[i].push_back(calc2(x[0],c[0],calc2(x[1],c[1],calc2(x[2],c[2],x[3])))); 
			v2[i].push_back(calc2(calc2(x[0],c[0],x[1]),c[1],calc2(x[2],c[2],x[3]))); 
		}
	}
//	for (int i = 1; i<= n; i++){
//		for (int x: v[i]) cout << x << " ";
//		cout << "\n";
//	}
	map<int,int> mp;
	for (int i = 1; i <= n; i++){
		for (int x: v[i]) if (!mp[x]) mp[x] = mp.size();
		//for (int x: v[i]) if (!mp.count(x)) mp[x] = mp.size();
		//mp[x] = mp.size()... in my computer mp[x] is accessed so mp.size() return 1 then assign to LHS
		//but in JUDGE or C++ online mp.size() still is 0. maybe mp[x] is waiting (for RHS) to be accessed
	}
	int m = mp.size();
	Flow graph(n+m+2,n+m+1,n+m+2);
	for (int u = 1; u <= n; u++){
		for (int i = 0; i < v[u].size(); i++){
			int nv = mp[v[u][i]];
			string s = v2[u][i] + "\n";
			graph.addEdge(u,n+nv,1,s);
		}
	}
	for (int i = 1; i<= n; i++) graph.addEdge(n+m+1,i,1,"");
	for (int i = 1; i <= m; i++) graph.addEdge(n+i,n+m+2,1,"");
	int cnt = graph.maxFlow(); 
	if (cnt<n){
		cout << "NO SOLUTION\n";
		return 0;
	}
	graph.trace();
	
	
	return 0;
}

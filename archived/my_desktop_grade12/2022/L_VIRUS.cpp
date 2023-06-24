#include<bits/stdc++.h>

using namespace std;
int nTrie, to[2000005][2], cnt[2000005], p[2000005];
struct AC{
	vector<string> strList;
	int root;
	bool builded;
	void reset(){
		root = ++nTrie;
		builded = false;
		strList.clear();
	}
	AC(){
		reset();
	}	
	void push(string& s){
		assert(!builded);
		strList.push_back(s);
		int u = root;
		for (char c: s){
			c -= '0';
			if (to[u][c]==0) to[u][c] = ++nTrie;
			u = to[u][c];
		}
		cnt[u]++;
	}
	void build(){
		builded = true;
		queue<int> q;
		q.push(root);
		while (!q.empty()){
			int u = q.front(); q.pop();
			for (int c = 0; c < 2; c++) if (to[u][c]){
				int v = to[u][c], k = p[u];
				while (k&&to[k][c]==0) k = p[k];
				p[v] = (k==0?root:to[k][c]);
				q.push(v);
				cnt[v] += cnt[p[v]];
			}
		}
	}
	void print(){
		queue<int> q;
		q.push(root);
		vector<int> vec;
		while (!q.empty()){
			int u = q.front(); q.pop();
			vec.push_back(u);
			for (int c = 0; c < 2; c++) if (to[u][c]){
				cout << u << " " << to[u][c] << " " << c << "\n";
				q.push(to[u][c]);
			}
		}
		for (int x: vec) cout << "count[" << x << "] = " << cnt[x] << "    pi[" << x << "] = " << p[x] << "\n";
		
	}
	long long count(string& s){
		int k = root;
		long long res = 0;
		for (char c: s){
			c -= '0';
			while (k&&to[k][c]==0) k = p[k];
			k = (k==0?root:to[k][c]);
			res += cnt[k];
		}
		return res;
	}
};

struct forestOfAC{
	vector<AC> ACList;
	forestOfAC(){
		for (int i =0; i < 20; i++) ACList.push_back(AC());
	}
	void push(string& s){
		for (int i = 0; i < 20; i++) if (!ACList[i].builded){
			ACList[i].push(s);
			for (int j =0; j < i; j++){
				for (auto s: ACList[j].strList) ACList[i].push(s);
				ACList[j].reset(); 
			}
			ACList[i].build();
			break;
		}
	}
	long long query(string& s){
		long long res = 0;
		for (int i = 0; i < 20; i++) if (ACList[i].builded) res += ACList[i].count(s);
		return res;
	}
};

int main(){
//	AC tmp = AC();
//	tmp.push("1011");
//	tmp.push("111");
//	tmp.push("11");
//	tmp.build();
//	tmp.print();
//	cout << tmp.count("10111");
	
//	forestOfAC tmp = forestOfAC();
//	tmp.push("1011");
//	cout << tmp.query("10111") << "\n";
//	tmp.push("111");	
//	cout << tmp.query("10111") << "\n";
//	tmp.push("11");
//	cout << tmp.query("10111") << "\n";
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int q; cin >> q;
	forestOfAC x = forestOfAC();
	while (q--){
		int op;
		string s;
		cin >> op >> s;
		if (op){
			cout << x.query(s) << "\n"; 
		} else x.push(s);
	}
	
	return 0;
}

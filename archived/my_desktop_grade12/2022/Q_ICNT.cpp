#include<bits/stdc++.h>

using namespace std;

int n, q, a[100005];
const int INF = 1e9+1;

int to[32000005][2], nTrie, cnt[32000005];
struct myOrderedSet{ //trie
	int root;
	myOrderedSet(){
		root = ++nTrie;
	}	
	void push(int x){
		int u = root;
		for (int i = 31; i >= 0; i--){
			bool c = (x>>i&1);
			if (to[u][c]==0) to[u][c] = ++nTrie;
			u = to[u][c];
			cnt[u]++;
		}
	}
	void del(int x){
		int u = root;
		for (int i = 31; i >= 0; i--){
			bool c = (x>>i&1);
			u = to[u][c];
			cnt[u]--;
		}
	}
	int query(int x){ //less
		int u = root, res = 0;
		for (int i = 31; i >= 0; i--){
			bool c = (x>>i&1);
			if (c&&to[u][0]) res += cnt[to[u][0]];
			if (to[u][c]==0||cnt[to[u][c]]==0) return res;
			u = to[u][c];
		}
		return res;
	}
};

myOrderedSet val[100005];
struct BIT{
	BIT(){
	}
	void push(int x, int y){
		y += 1e9;
		for (; x <= n; x += x&-x) val[x].push(y);
	}
	void del(int x, int y){
		y += 1e9;
		for (; x <= n; x += x&-x) val[x].del(y);
	}
	int query(int x, int y){ //less or equal x, less than y
		y += 1e9;
		int res = 0;
		for (; x > 0; x -= x&-x) res += val[x].query(y);
		return res;
	}
	
};

int main(){
//	n = 100;
//	BIT x = BIT();
//	x.push(1,4);
//	x.push(1,2);
//	x.push(2,2);
//	x.del(1,4);
//	cout << x.query(2,5);
//	myOrderedSet x = myOrderedSet();
//	x.push(12);
//	x.push(9);
//	x.push(13);
//	x.del(12);
//	cout << x.query(13);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	BIT x = BIT();
	long long res = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		res += x.query(i,INF)-x.query(i,a[i]+1);
		x.push(i,a[i]);
	}
	long long sum = 0;
	cin >> q;
	while (q--){
		int i, s;
		cin >> i >> s;
		int val = abs(s+sum)%(2000000001)-1e9;
		res -= x.query(i-1,INF)-x.query(i-1,a[i]+1);
		res -= x.query(n,a[i])-x.query(i,a[i]);
		x.del(i,a[i]); a[i] += val; x.push(i,a[i]);
		res += x.query(i-1,INF)-x.query(i-1,a[i]+1);
		res += x.query(n,a[i])-x.query(i,a[i]);
		cout << res << "\n";
		sum += res;
	}
	
	
	return 0;
}

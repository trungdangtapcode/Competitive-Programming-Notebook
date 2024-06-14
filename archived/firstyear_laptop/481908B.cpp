#include<bits/stdc++.h>

using namespace std;
const int maxN = 31*2e5+5;
int q, cnt[maxN], to[maxN][2], ntrie = 1;
void add(int x){
	int u = 1;
	cnt[1]++;
	for (int i = 30; i >= 0; i--){
		int c = (x>>i)&1;
		if (to[u][c]==0) to[u][c] = ++ntrie;
		u = to[u][c];
		cnt[u]++;
	}
}
void del(int x){
	int u = 1;
	cnt[1]--;
	for (int i = 30; i >= 0; i--){
		int c = (x>>i)&1;
		u = to[u][c];
		cnt[u]--;
	}
}
int query(int x){
	int u = 1;
	int res = 0;
	for (int i = 30; i >= 0; i--){
		int c = (x>>i)&1;
		if (to[u][c^1]==0||cnt[to[u][c^1]]==0){
			u = to[u][c];
			res = res*2;
		} else {
			u = to[u][c^1];
			res = res*2+1;
		}
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	add(0);
	cin >> q;
	while (q--){
		char c;
		int x;
		cin >> c >> x;
		if (c=='+'){
			add(x);
		} else if (c=='-'){
			del(x);
		} else {
			cout << query(x) << "\n";
		}
	}
	
	return 0;
}

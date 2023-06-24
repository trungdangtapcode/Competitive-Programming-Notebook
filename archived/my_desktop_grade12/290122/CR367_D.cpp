#include<bits/stdc++.h>

using namespace std;

int to[30*200000+5][2], cnt, va[30*200000+5], q, x;
char c;
void them(int x){
	int u = 0;
	for (int i = 30; i >= 0; i--){
		bool c = (1<<i)&x;
		if (to[u][c]==0) to[u][c] = ++cnt;
		u = to[u][c];
		va[u]++;
	}
}
void del(int x){
	int u = 0;
	for (int i = 30; i >= 0; i--){
		bool c = (1<<i)&x;
		u = to[u][c];
		va[u]--;
	}
}
int findd(int x){
	int u = 0, res = 0;
	for (int i = 30; i >= 0; i--){
		bool c = (1<<i)&x; c ^= 1;
		if (to[u][c]!=0&&va[to[u][c]]!=0) u = to[u][c], res = (res<<1) + 1;
		else u = to[u][c^1], res = (res<<1);
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> q;
	while (q--){
		cin >> c >> x;
		if (c=='+'){
			them(x);
		} else if (c=='-'){
			del(x);
		} else {
			cout << findd(x) << "\n";
		}
	}
	
	return 0;
}

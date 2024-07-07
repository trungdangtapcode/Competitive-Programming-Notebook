#include<bits/stdc++.h>

using namespace std;
#define int long long
int s, n, a[10];
int f1(){
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum = 3*sum+a[i];
	}
	return sum;
}
void f2(int x){
	for (int i = n-1; i >= 0; i--){
		a[i] = x%3;
		x /= 3;
	}
}
int peg(int c){
	int res =0;
	if (c==1) res += s;
	for (int i = 0; i < n; i++){
		if (a[i]==c){
			res += (1ll<<i);
		}
	} 
	return res;
}
int getf(int c){
	for (int i = 0; i < n; i++){
		if (a[i]==c) return i;
	}
	return n+1;
}
void print(){
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << ":\n";
	for (int c = 0; c< 3; c++){
		for (int i = 0; i < n; i++) if (a[i]==c)
			cout << (1ll<<i) << " ";
		cout << "\n";
	}
}
void solve(){
	cin >> s >> n;
	queue<int> q;
	for (int i = 0; i < n; i++) a[i] = 0;
	q.push(f1());
	unordered_map<int,int> mp;
	mp[f1()] = 0;
	while (q.size()){
		int u = q.front();
		q.pop();
		f2(u);
//		print();
		if (peg(0)==peg(1)&&peg(2)==0){
			cout << mp[u] << "\n";
			return;
		}
		//1
//		int idx0 = getf(0), idx1 = getf(1), idx2 = getf(2);
		for (int i = 0; i < 3; i++) for (int j = 0; j< 3; j++) if (i!=j){
			int i0 = getf(i), i1 = getf(j);
			if (i0<i1){
				a[i0] = j;
				int v = f1();
				if (!mp.count(v)){
					mp[v] = mp[u]+1;
					q.push(v);
				}
			}
			f2(u);
		}
	}
	cout << -1 << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}


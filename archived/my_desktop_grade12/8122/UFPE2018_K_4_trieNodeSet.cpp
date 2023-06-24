#include<bits/stdc++.h>
//ACed

using namespace std;

set<int> st[1000005], leaf[1000005];
string v[100005];
int to[1000005][26], cnt, n;

void them(string s, int idx){
	int u = 0;
	for (char c: s){
		if (to[u][c-'a']==0) to[u][c-'a'] = ++cnt;
		u = to[u][c-'a'];
		st[u].insert(idx);
	}
	leaf[u].insert(idx);
}
void del(string s, int idx){
	int u = 0;
	for (char c: s){
		u = to[u][c-'a'];
		st[u].erase(idx);
	}
	leaf[u].erase(idx);
}
bool find1(string s, int l, int r){ //subarray la tien to => tim leaf
	int u = 0;
	for (char c: s){
		if (to[u][c-'a']==0) return false;
		u = to[u][c-'a'];
		auto it = leaf[u].lower_bound(l);
		if (it!=leaf[u].end()&&*it<=r) return true;
	}
	return false;
}
bool find2(string s, int l, int r){ //prefix la s => chay den tan cung s la ok 
	int u = 0;
	for (char c: s){
		if (to[u][c-'a']==0) return false;
		u = to[u][c-'a'];
		auto it = st[u].lower_bound(l);
		if (it==st[u].end()||*it>r) return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 1; i <= n; i++) them(v[i],i);
	int q; cin >> q;
	while (q--){
		int t, l, r; string s;
		cin >> t;
		if (t==1){
			cin >> l >> s;
			del(v[l],l);
			them(v[l]=s,l);
		} else if (t==2){
			cin >> l >> r >> s;
			cout << (find1(s,l,r)?"Y\n":"N\n");
		} else {
			cin >> l >> r >> s;
			cout << (find2(s,l,r)?"Y\n":"N\n");
		}
	}
	
	return 0;
}

#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5, maxA = 2e6;
set<int> st;
int n, q;
int val[4*maxA+5];
set<int> pos[maxA+5];
typedef pair<int,int> ii;
//set<ii> debug;
void updt_it(int k, int l, int r, int u, int x){
	if (l>u||r<u) return;
	if (l==r){
		val[k] = x;
	}	
	int m = (l+r)/2;
	updt_it(2*k,l,m,u,x);
	updt_it(2*k+1,m+1,r,u,x);
	val[k] = min(val[2*k],val[2*k+1]);
}
int gett_it(int k, int l, int r, int u, int v){
	if (u>r||v<l) return 1e9;
	if (u<=l&&r<=v){
		return val[k];
	}
	int m = (l+r)/2;
	return min(gett_it(2*k,l,m,u,v),gett_it(2*k+1,m+1,r,u,v));
	
}
void updt1(int x, int y){
//	debug.insert({x,y});
}
void updt2(int x, int y){
//	debug.erase({x,y});
	for (; x >0 ; x -= x&-x) val[x].erase(y);
}
int gett(int x){
	
}
void pushset(int u){
	if (st.count(u)) return;
	auto itr = st.lower_bound(u);
	auto itl = itr;
	itl--;
	int l = *itl, r= *itr;
	int dl = u-l, dr = r-u;
	updt2(r-l,l+1);
	updt1(dl,l+1);
	updt1(dr,u+1);
	st.insert(u);
}
void popset(int u){
	if (!st.count(u)) return;
	auto itr = st.lower_bound(u);
	auto itl = itr;
	itr++;
	itl--;
	int l = *itl, r= *itr;
	int dl = u-l, dr = r-u;
	updt2(dl,l+1);
	updt2(dr,u+1);
	updt1(r-l,l+1);
	st.erase(u);
}
int noway(){
	auto it = st.end();
	it--;
	it--;
//	for (int x: st) cout << x << " "; cout << "\n";
	return (*it)+1;
}

void solve(){
	cin >> n;
//	rs();
	for (int i = 1; i <= n; i++){
		int a; cin >> a;
		pushset(a);
	}
	cin >> q;
	for (int i = 1; i <= q; i++){
		char op;
		int x;
		cin >> op >> x;
		if (op=='+'){
			pushset(x);
		} else if (op=='-'){
			popset(x);
		} else {
			cout << min(gett(x+1),noway()) << " ";
		}
	}
	cout << "\n";
	vector<int> vec;
	for (int x: st) vec.push_back(x);
	for (int x: vec){
//		cout << x << "s => \n";
		if (x==0||x==maxA+1) continue;
		popset(x);
//		for (int y: st) cout << y << " "; cout << "\n";
	}
//	for (auto it: debug){
//		cout << it.first << "l pos =" << it.second << "\n";
//	}
//	cout << gett(100) << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	st.insert(0);
	st.insert(maxA+1);
	updt1(maxA+1,1);
	int t; cin >> t;
	while (t--)
	solve();
}


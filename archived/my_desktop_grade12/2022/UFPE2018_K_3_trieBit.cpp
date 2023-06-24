#include<bits/stdc++.h>
//trie + bit

using namespace std;
int n;
typedef pair<char,int> ii;
string v[100005];
vector<array<int,2>> to;
int cnt, val[400005];
vector<int> d, isLeaf;

vector<bool> string2bit(string s){
	vector<bool> res;
	for (char c: s){
		c -= 'a';
		for (int i = 16; i > 0; i/=2) res.push_back(i&c);
	}
	return res;
}

void them(int p, string s0){
	auto s = string2bit(s0);
	int u = p;
	for (bool c: s){
		if (to[u][c]==0) to.push_back({0,0}), d.push_back(0), isLeaf.push_back(0), to[u][c] = ++cnt;
		u = to[u][c];
		d[u]++;	
	}
	isLeaf[u]++;
}
void del(int p, string s0){
	auto s = string2bit(s0);
	int u = p;
	for (char c: s){
		u = to[u][c];
		d[u]--;	
	}
	isLeaf[u]--;
}
bool tim(int p, string s0, int mode){
	auto s = string2bit(s0);
	if (mode){ //1: tim Leaf (trie tien to cua s)
		int u = p;
		for (char c: s){
			if (to[u][c]==0) return false;
			u = to[u][c];
			if (d[u]==0) return false;
			if (isLeaf[u]) return true;
		}
		return false;
	} else { //0: tim s thuoc trie (s la tien to cua trie)
		int u = p;
		for (char c: s){
			if (to[u][c]==0) return false;
			u = to[u][c];
			if (d[u]==0) return false;
		}
		return true;
	}
}

void updt(int k, int l, int r, int u, string ns, string os){
	if (l>u||r<u) return;
	if (l==r){
		if (val[k]==0) to.push_back({}), d.push_back(0), isLeaf.push_back(0), val[k] = ++cnt;
		them(val[k],ns);
		del(val[k],os);
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,u,ns,os);
	updt(2*k+1,m+1,r,u,ns,os);
	if (val[k]==0) to.push_back({}), d.push_back(0), isLeaf.push_back(0), val[k] = ++cnt;
	them(val[k],ns);
	del(val[k],os);
}
bool gett(int k, int l, int r, int u, int v, string s, int mode){
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v){
		if (val[k]==0) while (true);
		return tim(val[k],s,mode);
	}
	int m = (l+r)/2;
	if (gett(2*k,l,m,u,v,s,mode)) return true;
	return gett(2*k+1,m+1,r,u,v,s,mode);
}

main(){
	to.push_back({0,0}); d.push_back(0); isLeaf.push_back(0);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
//	vector<bool> tmp = string2bit("zbz");
//	for (auto it: tmp) cout << it;
	
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> v[i];
		updt(1,1,n,i,v[i],"");
	}
//	cout << tim(val[1],"adc",1);
//	cout << gett(1,1,n,1,2,"aaac",1);
//	cout << gett(1,1,n,1,3,"a",0);
//	cout << tim(val[1],"a",0);

	int q; cin >> q;
	while (q--){
		int t, l, r;
		string s;
		cin >> t;
		if (t==1){
			cin >> l >> s;
			updt(1,1,n,l,s,v[l]);
			v[l] = s;
		} else if (t==2){
			cin >> l >> r >> s;
			cout << (gett(1,1,n,l,r,s,1)?"Y\n":"N\n");
		} else {
			cin >> l >> r >> s;
			cout << (gett(1,1,n,l,r,s,0)?"Y\n":"N\n");
		}
	}	
			
	return 0;
}

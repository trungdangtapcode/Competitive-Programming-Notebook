#include<bits/stdc++.h>

using namespace std;
int n;
string v[200005];
map<char,int> to[8600005];
int cnt, val[800005], d[4600005];
int isLeaf[4600005];

void them(int p, string s){
	int u = p;
	for (char c: s){
		if (to[u][c-'a']==0) to[u][c-'a'] = ++cnt;
		if (cnt>4e6+6e5) while (true);
		u = to[u][c-'a'];
		d[u]++;	
	}
	isLeaf[u]++;
}
void del(int p, string s){
	int u = p;
	for (char c: s){
		u = to[u][c-'a'];
		if (u==0) while (true);
		d[u]--;	
	}
	isLeaf[u]--;
}
bool tim(int p, string s, int mode){
	if (mode){ //1: tim Leaf (trie tien to cua s)
		int u = p;
		for (char c: s){
			if (to[u][c-'a']==0) return false;
			u = to[u][c-'a'];
			if (d[u]==0) return false;
			if (isLeaf[u]) return true;
		}
		return false;
	} else { //0: tim s thuoc trie (s la tien to cua trie)
		int u = p;
		for (char c: s){
			if (to[u][c-'a']==0) return false;
			u = to[u][c-'a'];
			if (d[u]==0) return false;
		}
		return true;
	}
}


void updt(int k, int l, int r, int u, string ns, string os){
	if (l>u||r<u) return;
	if (l==r){
		if (val[k]==0) val[k] = ++cnt;
//		if (cnt>4e6+6e5) while (true);
		them(val[k],ns);
		del(val[k],os);
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,u,ns,os);
	updt(2*k+1,m+1,r,u,ns,os);
	if (val[k]==0) val[k] = ++cnt;
//	if (cnt>4e6+6e5) while (true);
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
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> v[i];
		updt(1,1,n,i,v[i],"");
	}
	if (n>1e5) while (true);
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
		if (cnt>4e6) while (true);
	}	
			
	return 0;
}

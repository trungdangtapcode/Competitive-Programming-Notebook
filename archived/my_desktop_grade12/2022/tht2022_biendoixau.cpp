#include<bits/stdc++.h>

using namespace std;

struct node{
	char f[26];
	bool check;
	node(){
		clear();
	}
	node operator+(const node& x){
		node res;
		for (int i = 0; i < 26; i++) res.f[i] = x.f[f[i]];
		res.check = (*this).check||x.check;
		return res;
	}
	node& operator+=(const node& x){
		*this = *this + x;
		return *this; 
	}
	void clear(){
		for (int i = 0; i < 26; i++) f[i] = i;
		check = 0;
	}
} lazy[4000005];
int n;
string s;

void down(int k){
	if (lazy[k].check==0) return;
	lazy[2*k] += lazy[k];
	lazy[2*k+1] += lazy[k];
	lazy[k].clear();
}
void updt(int k, int l, int r, int u, int v, const node& val){
	if (l>v||u>r) return;
	if (u<=l&&r<=v){
		lazy[k] += val;
		return;
	}
	down(k);
	int m = (l+r)/2;
	updt(2*k,l,m,u,v,val);
	updt(2*k+1,m+1,r,u,v,val);
}
char gett(int k, int l, int r, int u){
	if (u>r||u<l) return -1;
	if (l==r) return lazy[k].f[0];
	down(k);
	int m = (l+r)/2;
	return max(gett(2*k,l,m,u),gett(2*k+1,m+1,r,u));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s;
	n = s.length();
	s = "$" + s;
	for (int i = 1; i <= n; i++){
		node tmp;
		tmp.f[0] = s[i]-'a';
		tmp.check = 1;
		updt(1,1,n,i,i,tmp);
	}
	int q; cin >>q;
	while (q--){
		int x, y;
		char a, b;
		cin >> x >> y >> a >> b;
		x++; y++;
		node tmp;
		tmp.f[a-'a'] = b-'a';
		tmp.check = 1;
		updt(1,1,n,x,y,tmp);
	}
	for (int i = 1; i <= n; i++) cout << (char)(gett(1,1,n,i)+'a'); cout << "\n";
	
	return 0;
}

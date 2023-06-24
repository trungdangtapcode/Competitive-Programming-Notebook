#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include "windows.h"
#include "psapi.h"
#include <unistd.h>
#include <ios>
#include <iostream>
#include <fstream>

using namespace std;
using namespace __gnu_pbds;
#define int long long
const int p = 1e9+7;
const int base = 29;
int n;
string v[100005];
map<int,int> val1[4000005], val2[4000005];

void updt(int k, int l, int r, int u, string ns, string os){
	if (l>u||r<u) return;
	if (l==r){
		int tmp = 0;
		for (int i = 0; i < ns.length(); i++) tmp = (base*tmp+ns[i]-'a'+1)%p, val1[k][tmp]++;
		val2[k][tmp]++;
		tmp = 0;
		for (int i = 0; i < os.length(); i++) tmp = (base*tmp+os[i]-'a'+1)%p, val1[k][tmp]--;
		val2[k][tmp]--;
		return;
	}
	int m = (l+r)/2;
	updt(2*k,l,m,u,ns,os);
	updt(2*k+1,m+1,r,u,ns,os);
	int tmp = 0;
	for (int i = 0; i < ns.length(); i++) tmp = (base*tmp+ns[i]-'a'+1)%p, val1[k][tmp]++;
	val2[k][tmp]++;
	tmp = 0;
	for (int i = 0; i < os.length(); i++) tmp = (base*tmp+os[i]-'a'+1)%p, val1[k][tmp]--;
	val2[k][tmp]--;
}
bool gett1(int k, int l, int r, int u, int v, int x){
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v){
		if (!val1[k].count(x)) return false;
		return val1[k][x];
	}
	int m = (l+r)/2;
	if (gett1(2*k,l,m,u,v,x)) return true;
	return gett1(2*k+1,m+1,r,u,v,x);
}
bool gett2(int k, int l, int r, int u, int v, int x){
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v){
		if (!val2[k].count(x)) return false;
		return val2[k][x];
	}
	int m = (l+r)/2;
	if (gett2(2*k,l,m,u,v,x)) return true;
	return gett2(2*k+1,m+1,r,u,v,x);
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> v[i];
		updt(1,1,n,i,v[i],"");
	}
	
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
			int tmp = 0;
			for (int i = 0; i < s.length(); i++){
				tmp = (base*tmp+s[i]-'a'+1)%p;
				if (gett2(1,1,n,l,r,tmp)){
					cout << "Y\n";
					break;
				}
				if (i==s.length()-1) cout << "N\n";
			}
		} else {
			cin >> l >> r >> s;
			int tmp = 0;
			for (int i = 0; i < s.length(); i++) tmp = (base*tmp+s[i]-'a'+1)%p;
			cout << (gett1(1,1,n,l,r,tmp)?"Y\n":"N\n");
		}
		
	}
	
			
	return 0;
}

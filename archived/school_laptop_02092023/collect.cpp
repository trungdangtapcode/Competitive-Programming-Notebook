#include<bits/stdc++.h>

using namespace std;
int k, cur_z, cur_s, cur_m, nz, ns, nm, from_z[100005], from_s[100005], from_m[100005], to_z[100005], to_s[100005], to_m[100005];
int d[205];
int idx(int x, int y, int z){
	return x*25+y*5+z;
\
}
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
iii inv(int x){
	return {x/25,{x/5%5,x%5}};
}
int main(){
	cin >> k;
	cin >> cur_z >> cur_s >> cur_m >> nz >> ns >> nm; 
	int cnt = 0;
	while (cin >> from_z[cnt] >> from_s[cnt] >> from_m[cnt] >> to_z[cnt] >> to_s[cnt] >> to_m[cnt]){
		cnt++;
		if (from_z[cnt-1]==-1){
			cnt--;
			break;
		}		
	}
	int u = idx(cur_z,cur_s,cur_m);
	for (int i = 0; i <= idx(4,4,4); i++) d[i] = 1e9;
	d[u] = 0;
	queue<int> q;
	q.push(u);
	while (q.size()){
		int u = q.front(); q.pop();
		int uz = inv(u).first, us = inv(u).second.first, um = inv(u).second.second;
//		cout << uz << " " << us << " " << um << "\n"; 
		if (d[u]==k||uz>=nz&&us>=ns&&um>=nm) continue;
		for (int i = 0; i < cnt; i++){
			if (uz<from_z[i]||us<from_s[i]||um<from_m[i]) continue;
			int vz = uz - from_z[i] + to_z[i], vs = us - from_s[i] + to_s[i], vm = um - from_m[i] + to_m[i];
			if (vz>4||vs>4||vm>4) continue;
			int v = idx(vz,vs,vm);
			if (d[v]>d[u]+1){
				d[v] = d[u]+1;
				q.push(v);
			}
		}
	}
	int res =0;
	for (int i = nz; i <= 4; i++) for (int j = ns; j <= 4; j++) for (int k = nm; k <= 4; k++) if (d[idx(i,j,k)]!=1e9){
		res++;
	}
	cout  << ""<< (res==0?-1:res) << "\n";
	for (int i = nz; i <= 4; i++) for (int j = ns; j <= 4; j++) for (int k = nm; k <= 4; k++) if (d[idx(i,j,k)]!=1e9){
		cout << i << " " << j << " " << k << " " << d[idx(i,j,k)] << "\n";
	}
 
	
	return 0;
}

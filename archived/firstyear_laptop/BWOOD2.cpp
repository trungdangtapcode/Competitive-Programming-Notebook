#include<bits/stdc++.h>

using namespace std;
const int T = 150, maxN = 2e3+5;
int n, m, rmn[T+5], rmx[T+5], mx[maxN][T+5], mn[maxN][T+5], cnt[maxN][T+5];
string s[maxN];
map<char,int> mp;
int idx(char c){
	if (mp.count(c)) return mp[c];
	return mp[c] = mp.size();
}
int main(){
	cin >> n >> m;
	for (int i = 0; i < T; i++) rmn[i] = 1e9, rmx[i] = -1e9;
	for (int i = 1;i <= n; i++){
		cin >> s[i];
		s[i] = " " + s[i];
		for (int j = 0; j < T; j++) mn[i][j] = 1e9, mx[i][j] = -1e9;
		for (int j = 1; j <= m; j++){
			int id = idx(s[i][j]);
			mn[i][id] =  min(mn[i][id],j);
			mx[i][id] =  max(mx[i][id],j);
			cnt[i][id]++;		
			rmn[id] = min(rmn[id],i);
			rmx[id] = max(rmx[id],i);
		}
	}	
	int cntRec = 0, cntConvex = 0;
	for (int i = 0; i < T; i++){
		if (rmn[i]==1e9) continue;
		bool isConvex = 1, isRec = 1, dec = 0;
		int curmn = 1e9, curmx = -1e9;
		for (int j = rmn[i]; j <= rmx[i]; j++){
			if (mx[j][i]-mn[j][i]+1!=cnt[j][i]) isConvex = isRec = 0;
			if (curmn<mn[j][i]||curmx>mx[j][i]) dec = 1;
			if ((curmn>mn[j][i]||curmx<mx[j][i])&&dec) isConvex = 0;
			if (curmn!=mn[j][i]&&curmn!=1e9||curmx!=mx[j][i]&&curmx!=-1e9) isRec = 0;
			curmn = mn[j][i], curmx = mx[j][i];
		}
		cntRec += isRec;
		cntConvex += isConvex;
	}
	assert(cntRec<=cntConvex);
//	cout << cntConvex << "\n";
	cout << min(cntRec+1,cntConvex);
//	cout << cntRec << " " << cntConvex << "\n";
	
	return 0;
}

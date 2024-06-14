#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const int maxN = 1e5+5;
int n, rmq[maxN][20], a[maxN], pref[maxN];
vector<int> pos[maxN];
int query(int i, int j){
	int h = __lg(j-i+1);
	return rmq[i][h]&rmq[j-(1<<h)+1][h];
}
vector<int> vec;
int calc(int v, int p, int l, int r){ //count l <= pos[p^v][] <= r
	int vall = pref[p-1]^v;
	int val = lower_bound(vec.begin(),vec.end(),vall)-vec.begin();
//	cout << p << " " << l << " " << r  << " " << bitset<5>(vall)<< "\n";
	if (vec[val]!=vall) return 0;
//	cout << p << " " << l << " " << r  << " " << bitset<5>(vall)<< "hi\n";
	int pl = lower_bound(pos[val].begin(),pos[val].end(),l)-pos[val].begin();
	int pr = upper_bound(pos[val].begin(),pos[val].end(),r)-pos[val].begin()-1;
	return pr-pl+1;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++){
		pref[i] = a[i]^pref[i-1];
//		cout << bitset<5>(a[i]) << " " << bitset<5>(pref[i]) << "\n";
		rmq[i][0] = a[i];
		vec.push_back(pref[i]);
	}	
	vec.push_back(0);
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for (int i = 0; i <= n; i++){
		int tmp = lower_bound(vec.begin(),vec.end(),pref[i])-vec.begin();
		pos[tmp].push_back(i);
	}
	for (int b = 1; b < 20; b++){
		for (int i = 1; i <= n-(1<<b)+1; i++) rmq[i][b] = rmq[i][b-1]&rmq[i+(1<<(b-1))][b-1];
	}
	long long res = 0;
	for (int i = 1; i <= n; i++){
		int tmp = a[i];
		int j = i;
		while (j<=n){
			int l = j, r = n, m, cur = j;
			while (l<=r){
				m = (l+r)/2;
				if (query(i,m)==tmp){
					l = m+1;
					cur = m;
				} else r = m-1;
			}
//			cout << i << ".." << cur << " " << bitset<5>(query(i,cur)) << "\n";
			res += calc(tmp,i,j,cur);
			j = cur+1;
			tmp = query(i,j);
		}
//		break;
	}
	cout << res;
	return 0;
}

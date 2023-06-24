#include <bits/stdc++.h>

using namespace std;

int n, m, m1, m2, k, minDol[200005], minPur[200005];
long long int s, dol[200005], pur[200005], sum1[200005], sum2[200005];
vector<pair<long long int,int>> t1, t2;
const long long int INF = 1e15;

int check(int x){ //resT1
	int d = dol[minDol[x]];
	int p = pur[minPur[x]];
	
	for (int i = 0; i <= min(m1,k); i++) if (k-i<=m2){
		if (sum1[i]*d+sum2[k-i]*p<=s) return i;
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	//input
	cin >> n >> m >> k >> s;
	dol[0] = pur[0] = INF; minDol[0] = minPur[0] = 0;
	for (int i = 1; i <= n; i++){
		cin >> dol[i];
		if (dol[minDol[i-1]]>dol[i]) minDol[i] = i;
		else minDol[i] = minDol[i-1];
	}
	for (int i = 1; i <= n; i++){
		cin >> pur[i];
		if (pur[minPur[i-1]]>pur[i]) minPur[i] = i;
		else minPur[i] = minPur[i-1];
	}
	for (int i = 1; i <= m; i++){
		int x; long long int y;
		cin >> x >> y;
		if (x==1){
			t1.push_back({y,i});
		} else t2.push_back({y,i});
	}
	sort(t1.begin(),t1.end());
	sort(t2.begin(),t2.end());
	m1 = t1.size();
	m2 = t2.size();
	sum1[0] = sum2[0] = 0;
	for (int i = 1; i <= m1; i++) sum1[i] = sum1[i-1]+t1[i-1].first;
	for (int i = 1; i <= m2; i++) sum2[i] = sum2[i-1]+t2[i-1].first;
	
	int low = 1, high = n, mid, res = -1, resT1 = -1, resT2 = -1;
	while (low<=high){
		mid = (low+high)/2;
		if (check(mid)!=-1){
			res = mid;
			resT1 = check(mid);
			resT2 = k - resT1; //vl dau co mua het m mon dau ma m-resT1
			high = mid - 1;
		} else low = mid + 1;
	}
	
	cout << res << '\n';
	if (res!=-1){
		for (int i = 0; i < resT1; i++) cout << t1[i].second << " " << minDol[res] << '\n';
		for (int i = 0; i < resT2; i++) cout << t2[i].second << " " << minPur[res] << '\n';
	}
//	for (int i = 1; i <= m1; i++) cout << sum1[i] << " "; cout << endl;
//	for (int i = 1; i <= m2; i++) cout << sum2[i] << " "; cout << endl;
	
	return 0;
}

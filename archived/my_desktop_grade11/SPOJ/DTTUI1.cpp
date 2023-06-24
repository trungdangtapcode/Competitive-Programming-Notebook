#include <bits/stdc++.h>

using namespace std;
typedef pair<long long int, long long int> pll;
int n, n1, n2;
long long int m;
vector <pll> a1, a2;
vector <pll> cnt1, cnt2;

void dequy1(long long int sumFirst, long long int sumSecond, int k){
	if (sumFirst>=m) return;
	if (k>=n1){
		cnt1.push_back({sumFirst,sumSecond});
		return;
	}
	dequy1(sumFirst,sumSecond,k+1);
	dequy1(sumFirst+a1[k].first,sumSecond+a1[k].second,k+1);
}
void dequy2(long long int sumFirst, long long int sumSecond, int k){
	if (sumFirst>=m) return;
	if (k>=n2){
		cnt2.push_back({sumFirst,sumSecond});
		return;
	}
	dequy2(sumFirst,sumSecond,k+1);
	dequy2(sumFirst+a2[k].first,sumSecond+a2[k].second,k+1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	n1 = n/2;
	n2 = n-n1;
	for (int i = 0; i < n1; i++){
		long long int x, y;
		cin >> x >> y;
		a1.push_back({x,y});
	}
	for (int i = 0; i < n2; i++){
		long long int x, y;
		cin >> x >> y;
		a2.push_back({x,y});
	}
	dequy1(0,0,0);
	dequy2(0,0,0);
	sort(cnt1.begin(),cnt1.end());
	sort(cnt2.begin(),cnt2.end());
	long long int res = 0, cnt2MAX = 0, cnt1MAX = 0;
	int j = 0;
	for (int i = cnt1.size()-1; i >= 0; i--){
		cnt1MAX = max(cnt1MAX,cnt1[i].second);
		//cout << cnt1[i].first << "=" << cnt1[i].second << endl;
		while (j<cnt2.size()&&cnt1[i].first+cnt2[j].first<=m){
			//res = max(res,cnt1[i].second+cnt2[j].second);
			//cout << cnt1[i].second + cnt2[j].second << " - " << cnt1[i].first+cnt2[j].first << endl;
			cnt2MAX = max(cnt2MAX,cnt2[j].second);
			j++;	
		}
		if (cnt1[i].first+cnt2[j].first<=m)res = max(res,cnt1[i].second+cnt2MAX);
	}
	//for (int i = cnt2.size()-1; i >= 0; i--) cout << cnt2[i].first << "=" << cnt2[i].second << endl;
	cout << res;
	
	return 0;
}

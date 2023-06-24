#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, end_point[200005], res2[200005];
long long int k, res;
ii a[200005];
vector<int> up, down;
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n ; i++) cin >> a[i].first, a[i].second = i;
	for (int i = 0, t; i < n; i++){
		cin >> t;
		if (t==1){
			up.push_back(a[i].first);
		} else down.push_back(a[i].first);
		end_point[i] = a[i].first + t*k;
	}
	sort(up.begin(),up.end());
	for (auto it: down){
		int pos2 = lower_bound(up.begin(),up.end(),it)-up.begin()-1;
		int pos1 = upper_bound(up.begin(),up.end(),it-2*k)-up.begin();
		res += pos2 - pos1 + 1;
	}
	cout << res << '\n';
	sort(a,a+n);
	sort(end_point,end_point+n); //a end
	for (int i = 0; i < n; i++){
		res2[a[i].second] = end_point[i];
	}
	for (int i = 0; i < n; i++) cout << res2[i] << ' ';
	
	return 0;
}

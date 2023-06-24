#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n;
vector<ii> a;
vector<int> a1,a2,a0;

int main(){
	freopen("AVG.INP","r",stdin);
	freopen("AVG.OUT","w",stdout);
	
	int t; cin >> t;
	while (t--){
		cin >> n;
		a.assign(n,ii());
		a1.assign(n,0);
		a2.assign(n,0);
		a0.assign(n,0);
		for (int i = 0; i < n; i++){
			cin >> a[i].first;
			a[i].second = i;
			a0[i] = a[i].first;
		}
		sort(a.begin(),a.end());
		for (int i = 0; i < n; i++) a1[i] = a[i].first, a2[i] = a[i].second;
		long long int res = 0;
		for (int i = 0; i < n; i++){
			for (int j = i+2; j < n; j++) if ((a0[i]+a0[j])%2==0){
	//			int x = (a[i].first+a[j].first)/2;
				int x = (a0[i]+a0[j])/2;
				int pos1_min = lower_bound(a1.begin(),a1.end(),x)-a1.begin();
				int pos1_max = upper_bound(a1.begin(),a1.end(),x)-a1.begin();
				int pos2_min = upper_bound(a2.begin()+pos1_min,a2.begin()+pos1_max,i)-a2.begin();
				int pos2_max = lower_bound(a2.begin()+pos1_min,a2.begin()+pos1_max,j)-a2.begin();
				res += pos2_max-pos2_min;
			}
		}
		cout << res << '\n';
	}
	
	
	return 0;
}

#include<bits/stdc++.h>

using namespace std;
int n, a[100005], cnt[100005], x, b;
multiset<int> s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
		if (a[i]>=n) continue;
		cnt[(a[i]-i+n)%n]++;
	}
	for (int i = 0; i < n; i++){
		s.insert(n-cnt[i]+i);
	}
//	cout << (*s.begin()) << endl;
	
	int q; cin >> q;
	while (q--){
		cin >> x >> b; x--; b--;
		int tmp = (a[x]-x+n)%n, ntmp = (b-x+n)%n;
		
		if (a[x]<n){ //illegal tmp
			s.erase(s.find(n-cnt[tmp]+tmp));
			cnt[tmp]--;
			s.insert(n-cnt[tmp]+tmp);
		}
		
		if (b<n){ //illegal new_tmp
			s.erase(s.find(n-cnt[ntmp]+ntmp));
			cnt[ntmp]++;
			s.insert(n-cnt[ntmp]+ntmp);
		}
		
		a[x] = b;
		cout << *s.begin() << "\n";
	}
		
	
	
	
	return 0;
}

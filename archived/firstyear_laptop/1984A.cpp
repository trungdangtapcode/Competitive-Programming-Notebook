#include<bits/stdc++.h>

using namespace std;
const int maxN = 55;
int n;
pair<int,int> a[maxN];
void solve(){
	cin >> n;
	string s(n,'R');
	for (int i = 1; i <= n; i++){
		cin >> a[i].first;
		a[i].second = i-1;
	}
	sort(a+1,a+n+1);
	if (a[1].first==a[n].first){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	bool check = 1;
	for (int i = 1; i < n; i++) if (a[i].first==a[i+1].first){
		s[a[i].second] = 'B';
		check = 0;
		break;
	}
	if (check){
	    s[a[1].second] = 'B';
	}
	cout << s << "\n";
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
	int t; cin >> t;
	while (t--)
	solve();
}


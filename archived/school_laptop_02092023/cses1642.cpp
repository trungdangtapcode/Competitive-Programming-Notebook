#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, x;
vector<int> a;
map<int,ii> m;
int main(){
	cin >> n >> x;
	a.assign(n,0);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++) if (m.count(x-a[i]-a[j])){
			cout << i+1 << " " << j+1 << " " << m[x-a[i]-a[j]].first+1 << " " << m[x-a[i]-a[j]].second+1 << "\n";
			return 0;
		}
		for (int j = 0; j < i; j++) m[a[i]+a[j]] = {i,j};
	}
	cout << "IMPOSSIBLE";
	
	return 0;
}

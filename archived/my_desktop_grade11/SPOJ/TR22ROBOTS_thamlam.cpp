#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> eb;
vector <eb> a;
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++){
		long long int x, l;
		cin >> x >> l;
		a.push_back({x+l,x-l});
	}
	sort(a.begin(),a.end());
	
	int result = 0;
	long long int last = -1e9;
	for (int i = 0; i < n; i++){
		if (a[i].second>=last&&a[i].first>last){
			last = a[i].first;
			result++;
		}
	}
	cout << result;
	//cout << dp[n-1];
		
	return 0;
}

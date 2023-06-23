#include<bits/stdc++.h>

using namespace std;
int n, x, cnt[500005];
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> n >> x;
	for (int i = 0, a; i < n; i++){
		cin >> a;
		cnt[a]++;
	}
	for (int i = 1; i < x; i++){
		if (cnt[i]%(i+1)){
			cout << "No";
			return 0;
		}
		cnt[i+1] += cnt[i]/(i+1);
	}
	cout << "Yes";
	
	return 0;
}

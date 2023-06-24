#include <bits/stdc++.h>

using namespace std;
int cnt[505], x, n, inp;
long long int res = 0;

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	cin >> n >> x;
	for (int i = 0; i < n; i++){
		cin >> inp;
		cnt[inp]++;
		if (x-inp*inp>500||x-inp*inp<0) continue;
		res += cnt[x-inp*inp];
	};
	cout << res;
	
	return 0;
}

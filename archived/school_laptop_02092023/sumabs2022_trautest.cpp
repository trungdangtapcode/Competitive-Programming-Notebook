#include<bits/stdc++.h>

using namespace std;

int n, k;

int main(){
	cin >> n >> k;
	vector<int> v;
	int res = 0;
	for (int i = 1; i <= n; i++) v.push_back(i);
	do {
		int sum = 0;
		for (int i = 1; i <= n; i++) sum += abs(v[i-1]-i);
		if (sum==k){
			res++;
			for (int i: v) cout << i << " "; cout << endl;
		}
	} while (next_permutation(v.begin(),v.end()));
	cout << res;
	
	return 0;
}

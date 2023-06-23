#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, a[100005], sum, res = 1e9;
deque<int> d;
main(){
	freopen("input.txt","r",stdin);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
	}
	sum = (sum+1)/2;
	d.push_back(1);
	for (int i = 1, j =0, cur = 0; i <= n; i++){
		while (j<n&&cur-a[d.front()]<sum){
			cur += a[++j];
			while (d.size()&&a[d.back()]>=a[j]) d.pop_back();
			d.push_back(j);
		}
		if (cur-a[d.front()]>=sum) res = min(res,j-i);
		cur -= a[i];
		if (d.front()<=i) d.pop_front();
	}
	cout << res;
	return 0;
}

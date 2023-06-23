#include<bits/stdc++.h>

using namespace std;
vector<long long int> a;
int n;
long long int ll, hh, sum;
int main(){
	cin >> n >> ll >> hh;
	a.assign(n+2,0);
	for (int i = 0; i < n+2; i++){
		cin >> a[i];
		sum += a[i];
	};
	sort(a.begin(),a.end());
	long long int res = 0, l = sum-hh, h = sum-ll;
//	cout << "[" << l << "," << h << "]\n";
//	for (int i =0; i < n+2; i++) cout << a[i] <<" "; cout << endl;
	// sum - (ai + aj) <= hh => sum-ll >= (ai + aj) >= sum-hh
	for (int i = 0; i < n+2; i++){
		int pos1 = lower_bound(a.begin(),a.end(),l-a[i])-a.begin();
		int pos2 = upper_bound(a.begin(),a.end(),h-a[i])-a.begin()-1;
//		cout << i << " -> " << pos1 << " " << pos2 << endl;	
		res += pos2 - pos1 + 1;
		if (a[i]+a[i]>=l&&a[i]+a[i]<=h) res--;
	}
	cout << res/2;
	
	return 0;
}

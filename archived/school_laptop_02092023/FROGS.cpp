#include<bits/stdc++.h>
using namespace std;
int n, a[1000005], res[1000005], jump[1000005];
vector<int> q;
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> jump[i];
	a[n+1] = 1e9;
	q.push_back(1e9);
	for (int i = n; i >= 1; i--){
		while (q.back()<=a[i]) q.pop_back();
		q.push_back(a[i]);
		res[i] = q[max((int)q.size()-1-jump[i],0)];
	} 
	for (int i = 1; i <= n; i++) cout << (res[i]==1e9?-1:res[i]) << " ";
	return 0;
}

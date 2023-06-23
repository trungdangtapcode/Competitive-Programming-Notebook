#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, a[100005];
int f(int x){
	int res = 0, cur = 0;
	for (int i = 1; i <= n; i++){
		if (a[i]>=x) cur++;
		else if (cur) res++, cur = 0;
	} 
	if (cur) res++;
	return res;
}

main(){
	freopen("input.txt","r",stdin);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= 10; i++){
		cout << i << " " << f(i) << "\n";
	}
	
	return 0;
}

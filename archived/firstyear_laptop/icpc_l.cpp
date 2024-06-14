#include<bits/stdc++.h>

using namespace std;
int spf[5000006], tmp, a, b;
const int mod = 998244353;
main(){
	for (int i = 1; i <= 5e6; i++){
		spf[i] = i;
	}
	for (int i = 2; i <= 5e6; i++) if (spf[i]==i){
		for (int j = i*2; j <= 5e6; j+= i) spf[j] = i;
	}
//	for (int i = 1; i <= 10; i++) cout << i << " " << spf[i] << "\n";
	cin >> a >> b;
	tmp = a;
	vector<int> ua;
	while (tmp>1){
		int u = spf[tmp];
		while (tmp%u==0) tmp /= u;
		ua.push_back(u);
	}
	long long res = 0;
	for (int i = 1; i <= b; i++){
		tmp = i;
		vector<int> ui;
		while (tmp>1){
			int u = spf[tmp];
			while (tmp%u==0) tmp /= u;
			ui.push_back(u);
		}	
		for (int x: ua) ui.push_back(x);
		sort(ui.begin(),ui.end());
		ui.erase(unique(ui.begin(),ui.end()),ui.end());
		long long cur = 1ll*a*i;
		for (int x: ui){
			cur = cur/x*(x-1);
		} 
		(res += cur)%= mod;
	}
	cout << res%mod;
	
	return 0;
}

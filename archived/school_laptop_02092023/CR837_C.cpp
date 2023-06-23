#include<bits/stdc++.h>

using namespace std;

bool p[1000005];
int n;
vector<int> prime;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 2; i <= 1e6; i++) p[i] = 1;
	for (int i = 2; i*i <= 1e6; i++) if (p[i]) for (int j = i*i; j <= 1e6; j+=i) p[j] = 0;
	for (int i = 2; i <= 1e6; i++) if (p[i]) prime.push_back(i);
		
	int t; cin >> t;
	while (t--){
		cin >> n;
		bool res = 0;
		set<int> s;
		for (int i = 0, a; i < n; i++){
			cin >> a; 
			for (int j = 0; prime[j]*prime[j]<=a; j++) if (a%prime[j]==0){
				if (s.find(prime[j])!=s.end()) res = true;
				else s.insert(prime[j]);
				while (a%prime[j]==0) a/=prime[j];
			}
			if (a>1){
				if (s.find(a)!=s.end()) res = true;
				else s.insert(a);
			}
		}
		cout << (res?"YES\n":"NO\n");
	}
	
	return 0;
}

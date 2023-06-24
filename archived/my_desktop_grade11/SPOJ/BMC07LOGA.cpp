#include <bits/stdc++.h>

using namespace std;
//bool isPrime[1e6+10];

map<int,int> cnt;
void addit(long long int n){
	int dem;
    for(int i = 2; i <= n; i++){
        dem = 0;
        while(n % i == 0){
            ++dem;
            n /= i;
        }
        cnt[i] += dem;
    }
}
void solve(){
	cnt.clear();
	long long int x, a, b;
    cin >> a >> b >> x;
    addit(x);
    
    long long int logit = 0, p =1;
    if (a==1) {cout << -1 << endl; return;}
    for (int i = 0; i <= log(b)/log(a); i++){
		if (p<b){
			p *= a;
			logit++;
		}
	}
	if (p!=b) {cout << -1 << endl; return;}
    addit(logit);
    for (auto& it: cnt){
    	if (it.second!=0) cout << it.second << " ";
	}
	cout << endl;
	for (auto& it: cnt){
    	if (it.second!=0) cout << it.first << " ";
	}
	cout << endl;
    
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
//	memset(isPrime, true, sizeof(isPrime));
//    for (int p = 2; p  <= 1e6; p++)
//    {
//        if (isPrime[p] == true)
//        {
//            for (int i = p * p; i <= 1e6; i += p)
//                isPrime[i] = false;
//        }
//    }
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}

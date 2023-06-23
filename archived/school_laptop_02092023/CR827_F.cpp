#include<bits/stdc++.h>

using namespace std;
int q, k, d;
string x;
long long int cnt[5];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> q;
		cnt[1] = cnt[2] = 0;
		bool nyes = false, nno = false;
		while (q--){
			cin >> d >> k >> x;
			for (char c: x){
				if (d==2&&c!='a') nyes = true;
				if (d==1&&c!='a') nno = true;
				cnt[d] += k;
			}
			cout << (nyes||(!nno&&cnt[1]<cnt[2])?"YES\n":"NO\n");
		}
	}
	
	return 0;
}

//		for (int i = 'a'; i <= 'z'; i++) cnt[1][i-'a'] = cnt[2][i-'a'] = 0;

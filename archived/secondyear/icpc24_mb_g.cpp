#include<bits/stdc++.h>

using namespace std;
const int maxN = 5e5+5;
int n, f[maxN], posone[maxN], numone, pref[maxN];
string s;
int calc(int k){
	int pos = 1, ans = 0;
	while (1){
		int l = pos+1, r = numone, m, res = -1;
		while (l<=r){
			m = (l+r)>>1;
			if (pref[posone[m]]-pref[posone[pos]]>=k){
				r = m-1;
				res = m;
			} else l = m+1;
		}
//		cout << res << "\n";
//		if (pref[posone[numone]]-pref[posone[res]]<k) break;
		if (res!=-1){
			pos = res;
			ans++;
		} else {
			break;
		}
	}
	if (ans<=1) return -1;
	return ans*(k+1)-1;
}

void solve(){
	cin >> n >> s;
//	s.clear();
//	for (int i = 0; i < n; i++) s.push_back((rand()%2)+'0');
//	cout << s << "\n";
	s = "1" + s + "1";
	for (int i = 0; i <= n+1; i++){
		if (s[i]=='1'){
			++posone[++numone] = i;
		}
	}
	pref[0] = 0;
	for (int i = 1; i <= n+1; i++) pref[i] = pref[i-1]+(s[i]=='0');
	int res = 0;
	for (char c: s) res += c=='1';
	res -= 2;
	for (int i = 1; i <= n; i++) res = max(res,calc(i));
	cout << res << "\n";
//	cout <<  " = "<<calc(3) << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	solve();
}


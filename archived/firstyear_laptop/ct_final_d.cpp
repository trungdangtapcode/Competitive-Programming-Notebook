#include<bits/stdc++.h>

using namespace std;
#define int long long
int s, n;
int f(int x){
	return (1ll<<x)-1;
}
void solve(){
	cin >> s >> n;
	if ((1ll<<n)-1<s||s%2==0){
		cout << -1 << "\n";
		return;
	}
	int t = (((1ll<<n)-1)&(~s))>>1;
	cout << bitset<10>(s) << " + " << bitset<10>(t) << " = " << bitset<10>(s+t) << "_" << n << "\n";
	assert((t&(s+t))==0&&s+2*t==(1ll<<n)-1);
//	t = 6, n = 3;
	long long res = 0, cnt = 0,last = 0;
	for (int i = n-1; i >= 0; i--){
		int c = t>>i&1;
		if (c){
//			int cnt0 =0;
//			for (int j = i; j >= 0; j--) cnt0 += ((t>>j&1)==0);
//			cout << i << ".\n";
//			res += f(i)+1+f(cnt0);
//			if (i>0&&(t>>(i-1)&1)){
//				res += f(i)+1+f(i-1)+1; 
//				i--;
//			} else {
//				res += f(i)+1+f(i);
//			}
			cnt++;
			
		}
		if (!c){
			int cnt0 =0;
			for (int j = i; j >= 0; j--) cnt0 += ((t>>j&1)==0);
//			if (cnt) res += f(i+1)+f(cnt)+f(cnt0);
//			if (cnt) res += f(i+1)+
			if (cnt%2){
				for (int j = 0; j < cnt; j++) res += f(i+1+j)+1;
				res += f(i+1);
			} else {
				for (int j = 0; j < cnt; j++) res += f(i+1+j)+1;
			}
			last = cnt;
			cnt = 0;
		}
	}
	if (cnt){
		if (last%2==0) res += f(cnt);
		else res-= f(cnt);
	}
//	if (cnt) res += f(cnt);
	cout << res << "\n";
//	for (int i = n-1; i >= 0; i--){
//		if (s>>i&1){
//			if (cnt) res += 1ll<<cnt;
//		} else {
//			cnt++;
//		}
//	}
//	cout << (res?res-1:0) << "\n";
//	cout << f(5)*2+f(2)+f(1)*2+f(3) << "\n";
//	cout << f(5)+f(2)+f(4)+f(1)+f(1) << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}


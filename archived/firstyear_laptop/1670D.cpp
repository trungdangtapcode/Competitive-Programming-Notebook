//https://media.discordapp.net/attachments/1030096023328149509/1231997262662729828/image.png?ex=6638fddc&is=662688dc&hm=cecae819622dffac12fae4f2671f96fede0d86456f6a53994d954015d2754580&=&format=webp&quality=lossless&width=1440&height=405
#include<bits/stdc++.h>

using namespace std;
#define int long long
int n;
bool check(int x){
	int tmp = 3*(x/3)*(x/3) + (x%3)*(x/3*2+1);
	return x*x-tmp>=n;
}
void solve(){
	cin >> n;
	int l = 0, r = 1e6, res, m;
	while (l<=r){
		m = (l+r)/2;
		if (check(m)){
			res = m;
			r = m-1;
		} else l = m+1;
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}


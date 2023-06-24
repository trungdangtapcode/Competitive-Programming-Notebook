#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;
int memo[61][2][2][2][10005];
long long l, r;
int k;

int f(int pos, bool la, bool br, bool ab, int rem){
	if (pos<0) return rem==0&&ab; //quen a < b (&&ab) =))
	int& res = memo[pos][la][br][ab][rem];
	if (res!=-1) return res;
	res = 0;
	int mina = (la?0:(l>>pos)&1), maxb = (br?1:(r>>pos)&1);
	for (int a = mina; a <= 1; a++) for (int b = 0; b <= maxb; b++){
		if (a>b&&!ab) continue;
		(res += f(pos-1,la||((l>>pos)&1)<a,br||b<((r>>pos)&1),ab||a<b
			,(( (((a^b)-(a&b))*(1ll<<pos)) + rem )%k+k)%k))%=mod;
	}
//	cout << pos << " " << la << " " << br << " " << ab << " " << rem << " = " << res << "\n";
	return res;
}

int main(){
	memset(memo,-1,sizeof(memo));
	cin >> l >> r >> k;	
//	cout << bitset<4>(l) << " " << bitset<4>(r) << "\n";
	cout << f(60,0,0,0,0);
	return 0;
}

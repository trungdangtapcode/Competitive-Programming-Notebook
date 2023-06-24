#include <bits/stdc++.h>

using namespace std;

int n, m, cnt1, cnt2;
int fact[2000006], inNum[2000006], inFact[2000006];
const int p = 1e9+7;

int nCr(int n, int r){
	if (r<0||r>n) return 0;
	return 1ll*fact[n]*inFact[n-r]%p*inFact[r]%p;
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	fact[0] = fact[1] = inNum[0] = inNum[1] = inFact[0] = inFact[1] = 1;
	for (int i = 2; i <= 2e6; i++){
		fact[i] = 1ll*fact[i-1]*i%p;
		inNum[i] = 1ll*inNum[p%i]*(p-p/i)%p;
		inFact[i] = 1ll*inFact[i-1]*inNum[i]%p;
	}
	
	//cnt1 + 2*cnt2 = n		//+ 1
	//2*cnt1 + cnt2 = m
	//cnt1 = (2*m-n)/3
	//cnt2 = (2*n-m)/3
	cin >> n >> m;
	if ((2*m-n)%3||(2*n-m)%3){
		cout << 0 << '\n';
		return 0;
	}
	cnt1 = (2*m-n)/3;
	cnt2 = (2*n-m)/3;
	cout << nCr(cnt1+cnt2,cnt1);
	
	
	return 0;
}

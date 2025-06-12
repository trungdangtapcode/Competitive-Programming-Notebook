#include<bits/stdc++.h>

//sum i*x!/(x-i)!*(n-i-1)! with i = 1 to x
//hint: the answer is x*n!/((n-x)(n-x+1))
//=>
//sum of i*(n-i)!/(x-i)! with i = 1 to x
//hint: the answer is (n+1)!/((n-x+1)(n-x+2)*(x-1)!)
//
//Prove:
//sum of i*(n-i)!/(x-i)! with i = 1 to x
//sum of i*(n-x+x-i)!/(x-i)! with i = 1 to x
//sum of (x-j)*(n-x+j)!/j! with j = 0 to x-1
//[sum of x*(n-x+j)!/j! with j = 0 to x-1] - [sum of (n-x+j)!/(j-1)!  with j = 0 to x-1]
//
//J = [sum of x*(n-x+j)!/j! with j = 0 to x-1] - [sum of (n-x+j)!/(j-1)!  with j = 1 to x-1]
// = [sum of x*(n-x+j)!/j! with j = 0 to x-1] - [sum of (n-x+1+j-1)!/(j-1)!  with j = 1 to x-1]
// = [sum of x*(n-x+j)!/j! with j = 0 to x-1] - [sum of (n-x+1+j)!/(j)!  with j = 0 to x-2]
//
//(ii+aa)!/ii! <0..nn>   
//(i-1+a+1)!/(i-1) <1..n>
//nn = n-1
//aa = a+1
//(n+a+1)!/((n-1)!(a+2)) = (nn+aa+1)!/nn!/(aa+1)
//[sum of (i+a)!/i! with i = 0 to n] = (n+a+1)!/n!/(a+1) = C(n+a+1,n)*(a+1)!/(a+1) = C(n+a+1,n)*a!
//=> J =  C(n,x-1)*(n-x)!*x - C(n,x-2)*(n-x+1)!
//= C(n,x-1)*(n-x)!*x - C(n-1,x-2)*(n-x+1)!
//= (n+1)!/((n-x+1)(n-x+2)*(x-1)!)
// https://pastebin.com/75wuTfNA

using namespace std;

const int maxN = 2e6+5, mod=998244353;
int n, inv[maxN], fact[maxN], k;
int f[maxN], g[maxN], a[maxN];

// sum(i*A(x,i)*[dead zone]*(n-x-1)!)
// f[mask] count dead zone of mask
// g[mask] count father of mask
// then g[mask] is answer that AND is mask' (mask \in mask') but not mul [dead zone] yet
// subtract to make g[mask] not duplicate
void precompute(){
	fact[0] = fact[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i <= 2e6; i++){
		fact[i] = 1ll*fact[i-1]*i%mod;
		inv[i] = 1ll*inv[mod%i]*(mod-mod/i)%mod;
		// a(p-b)%mod
		// = (ap-ab)%mod
		// = -ab%mod
		// = p-(ab%mod)
	}
}

void solve(){
	cin >> n >> k;
	int fullmask = (1<<k)-1, sum = fullmask;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sum &= a[i];
	}
	if (sum!=0){
		cout << 1ll*n*fact[n]%mod <<'\n';
		return;
	}
	
	for (int mask = 0; mask < (1<<k); mask++) f[mask] = g[mask] = 0;
	
	for (int i = 1; i <= n; i++) f[a[i]]++, g[a[i]]++;
	for (int i = 0; i < k; i++) for (int mask = 0; mask < (1<<k); mask++){
		if (mask>>i&1){
			f[mask] += f[mask^(1<<i)];
		} else {
			g[mask] += g[mask^(1<<i)];
		}
	}
	
	for (int mask = 0; mask < (1<<k); mask++){
		int x = g[mask];
		g[mask] = 1ll*fact[n]*inv[n-x]%mod*inv[n-x+1]%mod*x%mod;
	}
	
	for (int i = 0; i < k; i++) for (int mask = 0; mask < (1<<k); mask++){
		if ((mask>>i&1)==0){
			g[mask] -= g[mask^(1<<i)];
			g[mask] += mod;
			g[mask] %= mod;
		} 
	}
	
	int res = 0;
	for (int mask = 1; mask < (1<<k); mask++){
		res += 1ll*g[mask]*f[mask^fullmask]%mod;
		res %= mod;
	}
	cout << res << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	precompute();
	int t; cin >> t;
	while (t--)
	solve();
}


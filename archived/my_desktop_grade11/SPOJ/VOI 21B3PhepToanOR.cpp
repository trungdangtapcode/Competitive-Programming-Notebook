#include <bits/stdc++.h>
#define fix cout << "fixed" << endl;

using namespace std;
int n, k, l, r;
int a[1000005];
long long int fact[1000005], factIn[1000005], numIn[1000005], p = 1e9 + 7;
int cnt[(1<<20)+5];
long long int dp[(1<<21)+5];

long long int ncr(int n, int r){
	if (r>n) return 0;
	return fact[n]*factIn[n-r]%p*factIn[r]%p;
}

int main(){
	
	fact[0] = factIn[0] = numIn[0] = 1;
	fact[1] = factIn[1] = numIn[1] = 1;
	for (int i = 2; i <= 1e6; i++){
		fact[i] = fact[i-1]*i%p;
		numIn[i] = numIn[p%i]*(p-p/i)%p;
		factIn[i] = factIn[i-1]*numIn[i]%p;
	}
	
	cin >> n >> k >> l >> r;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for(int i = 0;i < 20; ++i) for(int mask = 0; mask < (1<<20); ++mask){
		if(mask & (1<<i))
			cnt[mask] += cnt[mask^(1<<i)];
	}
//	for (int i=0;i<20;++i)
//    	for (int mask=0;mask<(1<<20);++mask)
//            if ( ((mask >> i) & 1) == 0) cnt[mask+(1<<i)]+=cnt[mask];
	for (int i=0;i<(1<<20);++i){
    	long long int sign= (__builtin_popcount(i)%2==0?-1:1);
     	//dp[i]=ncr(cnt[i],k)*sign; //AC nhung kho hieu (hack buoc) voi viec dang xuli tren modula
     	//if (dp[i]<0) dp[i] += p;
     	dp[i]=(ncr(cnt[i],k)*sign+p*p)%p;
	}

    for (int i = 0;i < 20; ++i) for(int mask = 0; mask < (1<<20); ++mask){
		if (mask & (1<<i))
    		dp[mask] = (dp[mask]+dp[mask^(1<<i)]+ p*p)%p;
//    		dp[mask] = (dp[mask]+dp[mask^(1<<i)]);  //AC nhung kho... nhung nhanh hon dc may giay
    }
//    for (int i=0;i<20;++i){
//        for (int mask=0;mask<(1<<20);++mask) if ( ((mask >> i) & 1) == 0){
//            int nmask=mask+(1<<i);
//            dp[nmask] = (dp[nmask]+dp[mask]+p*p)%p;
//        }
//    }
    //fix;
	
	long long int res = 0;
    for (int i=l;i<=r;++i) if (i%3==0)
    {
     	if (__builtin_popcount(i)%2==1) res = (res + dp[i])%p;
		else res = (res - dp[i] + p*p)%p; 
		//res = (res + abs(dp[i]))%p;
    }
    cout<<res; //doc ban clean
	
	return 0;
}

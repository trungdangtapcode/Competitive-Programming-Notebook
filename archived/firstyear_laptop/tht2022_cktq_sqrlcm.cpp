#include <bits/stdc++.h>
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("unroll-loops")
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd()% (h - l + 1);
}
const int maxN = 1e6+5, mod = 1e9+7;
int n, pos, p[maxN*10], a[maxN], lcm_cnt[maxN*10];
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> pos;
    assert(n<=1e6);
//	n = 1e6, pos = 1;
//    for (int i = 1; i <= n; i++) a[i] = Rand(5e6,1e7);
//    a[1] = 1;
    for (int i = 1;i <= n; i++) cin >> a[i];
    p[0] = p[1] = 1;
    for (int i = 2; i*i <= 1e7; i++) if (p[i]==0){
        for (int j = i*i; j <= 1e7; j+=i) p[j] = i; //prime divisor
    }
    for (int i = 1; i <= 1e7; i++) if (p[i]==0) p[i] = i;
    for (int i = 1; i <= n; i++){
    	assert(a[i]<=1e7);
        int tmp = a[i];
        while (tmp>1){
            int d = p[tmp], cnt = 0;
            while (tmp%d==0) tmp /= d, cnt++;
            lcm_cnt[d] = max(lcm_cnt[d],cnt);
        }
    }
    long long res = 1;
    for (int i = 2; i <= 1e7; i++){
        if (lcm_cnt[i]<2) continue;
        int cnt = 0;
        while (a[pos]%i==0) a[pos] /= i, cnt++;
        for (int j = cnt+2; j <= lcm_cnt[i]; j+=2) res = res*i%mod*i%mod;
    }
    cout  << res;

    return 0;
}


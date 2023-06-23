#include <bits/stdc++.h>

#pragma GCC optimize(3)
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

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 1;

int n, m;

template <class T>
inline void in(T &x)
{
    register T c = getchar();
    x = 0;
    T neg = 0;
    for (; ((c < 48 || c>57) && c != '-'); c = getchar());
    if (c == '-') { neg = 1; c = getchar(); }
    for (; c > 47 && c < 58; c = getchar()) { x = (x << 1) + (x << 3) + c - 48; }
    if (neg) x = -x;
}
template <typename T> void Write(T x) {if (x > 9) Write(x/10); putchar(x%10+48);}
template <typename T> void write(T x) {if (x < 0) {putchar('-'); x = -x;} Write(x);}

struct f{
	long long dp[55][100005], n = 100000, m = 50;
	constexpr f(){
		for (int i=1; i<=n; i++) dp[1][i]=1;
	    for (int i=2; i<=m; i++)
	        for (int j=1; j<=n; j++)
	            for (int k=j; k<=n; k+=j)
	            dp[i][j]+=dp[i-1][k];
//	    for (int i=1; i<=n; i++) kq+=f[m][i];
	}
};

int main() {
    in(n);
    in(m);

    
//    write(ans%MOD);

    return 0;
}


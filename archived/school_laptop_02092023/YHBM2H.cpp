#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, a[16];
unsigned long long power(unsigned long long x,unsigned long long y,unsigned long long z)
{
    if (!y) return 1;
    unsigned long long r=power(x,y/2,z);
    r=r*r%z;
    if (y%2) r=r*x%z;
    return r;
}
int probablyPrime(unsigned long long n,int iteration)
{
    if (n<3) return n==2;
    if (n%2==0) return 0;

    unsigned long long s=n-1,p=0;
    while (s%2==0) s/=2, p++;

    while (iteration--)
    {
        unsigned long long x=power(sqrt(rand()%(n-1)+1),s,n);

        for (int i=1;i<=p;i++)
        {
            unsigned long long pre=x;
            x=x*x%n;
            if (x==1 && pre!=1 && pre!=n-1) return 0;
        }

        if (x!=1) return 0;
    }

    return 1;
}

main(){
	
	cin >> n;
	int res = -1;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int mask = 0; mask < (1<<n); mask++){
		int sum = 0;
		for (int i = 0; i < n; i++) if (mask&(1<<i)) sum += a[i];
		if (probablyPrime(sum,20)) res = max(res,sum);
	}
	cout << res;
	
	return 0;
}

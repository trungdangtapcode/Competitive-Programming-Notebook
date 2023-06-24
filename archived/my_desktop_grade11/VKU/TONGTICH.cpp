#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
map<int,int> cnt;
int n, p;

ii bezout(long long int a, long long int b){ //RTE when product
    long long int x1 = 0, x2 = 1, y1 = 1, y2 = 0, x = 0, y = 0, r = 0, q = 0;
    if (b == 0){
        return {1,0};
	}
    while(b > 0){
        q = a/b;
        r = a - b * q;
        x = x2 - x1 * q;
        y = y2 - y1 * q;

        a = b; b = r;
        x2 = x1; x1 = x;
        y2 = y1; y1 = y;
    }
    return {x2,y2};
}
int inv(int x){
	ii res = bezout(x,p);
	return (res.first%p+p)%p;
}
int main(){
	cin >> n >> p;
	long long int res = 0;
	for (int i = 0, a; i < n; i++){
		cin >> a;
		a = ((a-1)%p+p)%p;
		if (__gcd(a,p)!=1) continue;
		res += cnt[inv(a)];
		cnt[a]++;
	}
	cout << res;
	return 0;	
}

#include <bits/stdc++.h>
#define fix cout << "fixed "  << endl;

using namespace std;
int delta = 18, maxIndex = 1e5;
long long int baseK = 1;
double sumLog[100000];
long long int fac[100000];
string p;
double logP;
long long int modP;

const double esilon = 1e-2;
bool sosanh(double a, double b){
	return (abs(a-b) <= esilon);
}

long long int invertIt(long long int x, long long int p){
	long long int y = p - 2;
    long long int res = 1; 
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1; 
        x = (x * x) % p;
    }
    return res%p;
}

int mod(string num, long long int a)
{
    long long int res = 0;
    for (int i = 0; i < num.length(); i++)
        res = (res * 10 + (int)num[i] - '0') % a;
    return res;
}

bool myEqual(int i, int j){
	return (sosanh(sumLog[j]-sumLog[i-1],logP)&&fac[j]*invertIt(fac[i-1],baseK)%baseK==modP);
}


int main(){
	for (int i = 1; i <= 31; i++) baseK = baseK*2; baseK--; //baseK is prime. a^-1 = a^p-2(mod p)
	
	cin >> p; 
	int l = p.length();
	if (l <= delta) delta = l;
	logP = log(stoll(p.substr(0,delta)))/log(10)+(l-delta);
	modP = mod(p,baseK);
	
	sumLog[0] = 0; 
	for (int i = 1; i <= maxIndex; i++) sumLog[i] = sumLog[i-1] + log(i)/log(10);
	
	fac[0] = 1;
	for (int i = 1; i < maxIndex; i++) fac[i] = fac[i-1]*i%baseK;
	
	int res = 1e6, ans; 
	for (int i = 1; i <= maxIndex; i++) {
        int l = 0, r = i + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            double cur = sumLog[i] - sumLog[mid-1];
            if (cur <= logP)
                r = mid;
            else
                l = mid;
        }
        for (int j = max(r - 10, 1); j <= min(r + 10, i); ++ j) {
            if (myEqual(j,i))
                if (res > j)
                    res = j, ans = i;
        }
    }
    cout << res << " " << ans;
}
//#include <bits/stdc++.h>
//#define F first
//#define S second
//#define eb emplace_back
//#define bit(x, i) (((x) >> (i)) & 1)
//#define sz(x) ((int)x.size())
//
//using namespace std;
//using ll = long long;
//
//const int inf = 1061109567;
//const ll INF = 4557430888798830399;
//const int MOD = 1e9 + 7;
//
//string s;
//int p = 0, logp, res = inf, ans;
//double prefix[100005];
//int fact[100005], inv[100005];
//
//int dc(int a, int b) {
//    int c = 1;
//    for (; b; b >>= 1, a = (ll)a * a % MOD)
//        if (b & 1)
//            c = (ll)c * a % MOD;
//    return c;
//}
//
//int get(int x, int y) {
//    return (ll)fact[y] * inv[x-1] % MOD;
//}
//
//int main() {
//    cin.tie(0)->sync_with_stdio(0);
//    #define Task ""
//    if (fopen(Task".in", "r")) {
//        freopen(Task".in", "r", stdin);
//        freopen(Task".out", "w", stdout);
//    }
//    cin >> s;
//    for (auto ch : s)
//        p = ((ll)p * 10 + ch - '0') % MOD;
//    fact[0] = 1;
//    for (int i = 1; i <= 1e5; ++ i)
//        fact[i] = (ll)fact[i-1] * i % MOD;
//    inv[100000] = dc(fact[100000], MOD - 2);
//    for (int i = 1e5 - 1; i >= 0; -- i)
//        inv[i] = (ll)inv[i+1] * (i + 1) % MOD;
//    logp = s.size();
//    for (int x = 1; x <= 1e5; ++ x) {
//        prefix[x] = prefix[x-1] + log10(x);
//        int l = 0, r = x + 1;
//        while (r - l > 1) {
//            int mid = (l + r) >> 1;
//            double cur = prefix[x] - prefix[mid-1];
//            if (cur <= logp)
//                r = mid;
//            else
//                l = mid;
//        }
//        for (int j = max(r - 10, 1); j <= min(r + 10, x); ++ j) {
//            if (get(j, x) == p)
//                if (res > j)
//                    res = j, ans = x;
//        }
//    }
//    cout << res << " " << ans << "\n";
//    return 0;
//}
//
//// Written by Kazama Hoang ^^

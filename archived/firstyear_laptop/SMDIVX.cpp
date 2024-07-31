#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
struct bignum
{
    vector<int> d;
    void operator = (ll x)
    {
        d.clear();
        do d.push_back(x % 10);
        while (x /= 10);
    }

    bignum (ll x)
    {
        (*this) = x;
    }

    bignum ()
    {
        d.assign(1, 0);
    }

    void push_back(int x)
    {
        d.push_back(x);
    }

    void clear()
    {
        d.clear();
    }

    int size() const
    {
        return d.size();
    }

    void resize(int s)
    {
        d.resize(s);
    }

    const int &operator [] (int x) const { return d[x]; }
          int &operator [] (int x)       { return d[x]; }

    void fix()
    {
        for (int i = 0; i < d.size(); ++i)
        {
            if (d[i] >= 10)
            {
                if (i + 1 == d.size())
                    d.push_back(0);

                d[i + 1] += d[i] / 10;
                d[i] %= 10;
            }

            while (d[i] < 0)
            {
                d[i + 1] -= 1;
                d[i] += 10;
            }
        }

        while ((d.size() > 1) && (d.back() == 0)) d.pop_back();;
    }

    friend istream &operator >> (istream &cin, bignum &a)
    {
        string s;
        cin >> s;

        a.clear();
        for (; s.size(); s.pop_back())
            a.push_back(s.back() - '0');

        return cin;
    }

    friend ostream &operator << (ostream &cout, const bignum &a)
    {
        for (int i = a.size() - 1; i >= 0; --i)
            cout << a[i];

        return cout;
    }
};

/// Bignum vs Bignum
    void operator += (bignum &a, const bignum &b)
    {
        a.resize(max(a.size(), b.size()));
        for (int i = 0; i < b.size(); ++i)
            a[i] += b[i];

        a.fix();
    }

    /// a >= b required
    void operator -= (bignum &a, const bignum &b)
    {
        a.resize(max(a.size(), b.size()));
        for (int i = 0; i < b.size(); ++i)
            a[i] -= b[i];

        a.fix();
    }

    void operator *= (bignum &a, const bignum &b)
    {
        bignum c;
        c.resize(a.size() + b.size());
        for (int i = 0; i < a.size(); ++i)
            for (int j = 0; j < b.size(); ++j)
                c[i + j] += a[i] * b[j];

        c.fix();
        a = c;
    }

    bignum operator + (bignum a, const bignum &b)
    {
        a += b;
        return a;
    }

    bignum operator - (bignum a, const bignum &b)
    {
        a -= b;
        return a;
    }

    bignum operator * (bignum a, const bignum &b)
    {
        a *= b;
        return a;
    }
    
    bool operator == (const bignum &a, const bignum &b){
    	if (a.size()!=b.size()) return false;
    	for (int i = a.size() - 1; i >= 0; --i)
            if (a[i]!=b[i]) return false;
        return true;
	}
    bool operator < (bignum a, bignum b)
    {
        a.resize(max(a.size(), b.size()));
        b.resize(max(a.size(), b.size()));
        for (int i = a.size() - 1; i >= 0; --i)
        {
            if (a[i]==b[i]) continue;
            if (a[i]<b[i]) return true;
            if (a[i]>b[i]) return false;
        }

        return false;
    }
    bool operator > (const bignum &a, const bignum &b){
    	return !(a<b);
	}
	bool operator <= (const bignum &a, const bignum &b){
		return a==b||a<b;
	}
	bool operator >= (const bignum &a, const bignum &b){
		return a==b||a>b;
	}
/// Bignum vs Bignum

/// Bignum vs Number
    void operator += (bignum &a, ll x)
    {
        a += bignum(x);
    }

    void operator -= (bignum &a, ll x)
    {
        a -= bignum(x);
    }

    void operator *= (bignum &a, ll x)
    {
        a *= bignum(x);
    }

    void operator /= (bignum &a, ll x)
    {
        ll rem = 0;
        for (int i = a.size() - 1; i >= 0; --i)
        {
            rem = (10 * rem + a[i]);
            a[i] = rem / x;
            rem %= x;
        }

        a.fix();
    }
    
    ll operator % (bignum a, ll x)
    {
        ll res = 0;
        for (int i = a.size() - 1; i >= 0; --i)
        {
            res = (10 * res + a[i])%x;
        }

        return res;
    }

    bignum operator + (bignum a, ll x)
    {
        a += x;
        return a;
    }

    bignum operator - (bignum a, ll x)
    {
        a -= x;
        return a;
    }

    bignum operator * (bignum a, ll x)
    {
        a *= x;
        return a;
    }

    bignum operator / (bignum a, ll x)
    {
        a /= x;
        return a;
    }

bignum getpow(bignum a, ll n){
	bignum res = bignum(1);
	while (n>0){
		if (n%2) res *= a;
		n /= 2;
		a *= a;
	}
	return res;
}
ll x, n;
void solve(){
	cin >> n >> x;
	bignum base = getpow(bignum(10), n-1);
	bignum res = (base + x - 1)/x*x;
	if (res>=base*10){
		cout << "-1\n";
	} else {
		cout << res << "\n";
	}
	
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}


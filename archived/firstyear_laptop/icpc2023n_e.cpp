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
long long n;
const long long p = 987654321;
int power(int a, int n){
	int res = 1;
	a %= p;
	while (n){
		if (n%2) (res *= a)%=p;
		n /= 2;
		(a *= a)%=p;
	}
	return res;
} 
int inv(int a){
	return power(a,p-2);
}

main(){
//	cout << inv(2)*2%p << "\n";
	cin >> n;
	bignum x = bignum(n);
	bignum y = bignum(p);
//	cout << x*3*1000*1000*1000*1000*1000*1000*1000*1000*1000*1000*1000*1000*1000*1000*1000*1000*1000 << "\n";
//	n%= p;
//	cout << ((1 + (n*n%p*(n+1)%p*(n+1)%p*inv(24)%p) - n*(n+1)%p*(2*n+1)%p*inv(6)%p + 17*inv(12)%p*n%p*(n+1)%p-3*n%p)%p+p)%p; 
	bignum t = ((x*x*(x+1)*(x+1)+34*x*(x+1))/24 + 1 - x*(x+1)*(2*x+1)/6 - 3*x);
	cout << t-t/p*p;
	return 0;
}

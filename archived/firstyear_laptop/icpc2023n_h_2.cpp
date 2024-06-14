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

int n, m;
bignum f[105][10005], k;
bool check[105];
const int inf = 1e19;
main(){
	cin >> n >> m >> k;
	k -= 1;
//	cout << inf*5 << "\n";
	f[1][0] = 1;
	f[2][0] += 1;
	f[2][2] -= 1;
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= m; j++){
			(f[i][j] = f[i][j]+f[i][j-1]);
		};
		for (int j = 0; j <= m; j++){
			f[i+1][j] = f[i+1][j]+f[i][j];
			f[i+1][j+i+1] = f[i+1][j+i+1]-f[i][j];
		}
	}
	cout << f[n][m] << '\n';
//	if (k >= f[n][m]){
//		cout << -1;
//		return 0;
//	}
	vector<int> res;
//	cout << f[2][1] << "--\n";
	int pref = 0;
	for (int i = 1; i < n; i++){
		int greater = 0;
		for (int j = 1; j <= n; j++){
			if (check[j]){
				greater++;
				continue;
			}
			int cur = (i-1-greater)*0+(j-1-greater) + pref;	
			if (cur>m){
				cout << -1;
				return 0;
			};
			if (k>=f[n-i][m-cur]){
				k -= f[n-i][m-cur];
			} else {
//				cout << j << "... \n";
				pref = cur;
				res.push_back(j);
				check[j] = 1;
				break;
			}
		}
	}
	for (int x: res) cout << x << " ";
	for (int i = 1; i <= n; i++) if (!check[i]) cout << i << " ";
	return 0;	
}

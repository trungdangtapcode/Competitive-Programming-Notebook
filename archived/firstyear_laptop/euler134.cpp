#include<bits/stdc++.h>

using namespace std;

template<class integer>
inline integer to_int(const string& s, size_t* idx = 0, int base = 10) {
    size_t n = s.size(), i = idx ? *idx : 0; bool sign = false; integer x = 0;
    if (s[i] == '-')
        ++i, sign = true;
    function<int(char)> char_to_digit = [&](char c) {
        static const int d[] = {'a'-10,'0'}; 
        return tolower(c)-d[isdigit(c)]; };
    while (i < n)
        x *= base, x += char_to_digit(s[i++]);
    if (idx)
        *idx = i; 
    return sign ? -x : x; }
 
template<class integer>
inline string to_string(integer x, int base = 10) {
    bool sign = false; string s;
    if (x < 0)
        x = -x, sign = true;
    function<char(int)> digit_to_char = [](int d) {
        static const char c[] = {'a'-10,'0'};
        return c[d < 10]+d; };
    do 
        s += digit_to_char(x%base), x /= base;
    while (x > 0); 
    if (sign)
        s += '-';
    reverse(s.begin(),s.end());
    return s; }
 
template<class integer>
inline istream& read(istream& is, integer& x) {
    string s; is >> s, x = to_int<integer>(s); return is; }
 
template<class integer>
inline ostream& write(ostream& os, integer x) { return os << to_string(x); }
 
using  lll =   signed __int128; 
using ulll = unsigned __int128;
 
inline istream& operator>>(istream& is,  lll &x) { return  read(is,x); }
inline istream& operator>>(istream& is, ulll &x) { return  read(is,x); }
inline ostream& operator<<(ostream& os,  lll  x) { return write(os,x); }
inline ostream& operator<<(ostream& os, ulll  x) { return write(os,x); }

#define int __int128

const int maxN = 1.2e6+6;
int n, p[maxN], seg[maxN], l, r;
vector<int> prime;

int abs(int x){
	return (x<0?-x:x);
}

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
int s(int x){
	int p = 1;
	while (p<=x) p*= 10;
	return p;
}
// return the smallest 10^k bigger than x
// e.g. tens(456) = 1000 => "a 1 followed by as many 0s as x has digits"
unsigned int tens(unsigned int x)
{
  unsigned int result = 1;
  while (result <= x)
    result *= 10;
  return result;
}

// when you are too lazy to type and your CPU is too fast ...
// no, seriously: quite useful for verifying small solutions
int bruteForce(unsigned int smallPrime, unsigned int largePrime)
{
  // solve x == 0 mod largePrime
  // and   x == smallPrime mod tens(smallPrime)

  // find 10^k with the minimum amount of zeros
  auto shift = tens(smallPrime);

  // start with smallest possible value
  auto result = shift + smallPrime;
  // is it a multiple of b ?
  while (result % largePrime != 0)
    result += shift; // no, keep going ...

  return result;
}

// extended Euclidean algorithm
struct ExtendedGcd
{
  // this typedef allows me to switch easily between int and int
  typedef int Number;

  // find solutions x and y (so-called Bezout coefficients)
  ExtendedGcd(Number a, Number b)
  {
    // iterative algorithm from https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
    Number s = 0, lastS = 1;
    Number t = 1, lastT = 0;
    Number r = b, lastR = a; // remainder
    while (r != 0)
    {
      Number quotient = lastR / r;
      Number tmp;
      tmp = lastR; lastR = r; r = tmp - quotient * r;
      tmp = lastS; lastS = s; s = tmp - quotient * s;
      tmp = lastT; lastT = t; t = tmp - quotient * t;
    }

    // fill members
    gcd = lastR;
    x   = lastS;
    y   = lastT;
  }

  // Bezout coefficients
  Number x;
  Number y;
  // just in case we need it, too ...
  Number gcd;
};

// use Chinese Remainder Theorem
int chineseRemainderTheorem(int smallPrime, int largePrime)
{
  // solve x == 0 mod largePrime
  // and   x == smallPrime mod tens(smallPrime)
  // e.g. Wolfram Alpha "x = 0 mod 23, x = 19 mod 100" => 1219
  auto modulo1 = largePrime;
  auto modulo2 = tens(smallPrime);

  // apply extended Euclidean algorithm
  ExtendedGcd gcd(modulo1, modulo2);

  //int result = 0 * gcd.y * modulo2 + (int)smallPrime * gcd.x * modulo1;
  // => multiplying by zero cancels half of the equation
  auto result = smallPrime * gcd.x * modulo1;

  // reduce to smallest solution
  auto product = modulo1 * modulo2;
  result %= (int)product; // make sure it's a signed modulo
  // "too small" ?
  while (result < 0)
    result += product;

  return result;
}

void solve(){
	cin >> l >> r;
	for (int i = l; i <= r+200; i++) seg[i-l] = 1;
	for (int p: prime){
		for (int j = (l+p-1)/p*p; j <= r+200; j += p){
			if (j==p) continue;
			seg[j-l] = 0;
		}
	}
	vector<int> vec;
	for (int i = l; i <= r+200; i++) if (seg[i-l]){
		vec.push_back(i);
	}
	int res = 0;
//	cout << chineseRemainderTheorem(100000037, 100000039) << "\n";
	for (int i = 1; i < (int)vec.size(); i++){
		int p1 = vec[i-1], p2 = vec[i];
		if (p1<5 or p1>r) continue;
//		cout << bruteForce(p1,p2) << "\n";
//		cout << p1 << " " << p2 << " " << s(p1) << "\n";
//		int g = __gcd(p2, s(p1));
//		int a = p2/g, b = -s(p1)/g, c = p1/g;
		int x, y, z;
		find_any_solution(p2, -s(p1), p1, x, y, z);
		int tmp = -y/p2;
//		cout << tmp << "\n";
		y += tmp*p2;
		x += tmp*s(p1);
		if (y<0){
			y += p2;
			x += s(p1);
		}
		res += x*p2;
//		res += chineseRemainderTheorem(p1,p2);
//		cout << (int)1e27 << "\n";
//		assert(res<1e27);
//		break;
//		cout << x << " " << y << " " << z << " = " << x*p2<< "\n";
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	#endif
	for (int i = 2; i <= 1e5; i++) p[i] = 1;
//	for (int i = 2; i*i <= 1e5; i++) if (p[i])
//		for (int j = i*i; j <= 1e5; j+=i) p[j] = 0;
//	for (int i = 2; i <= 1e5; i++) if (p[i]) prime.push_back(i);
	for (int i = 2; i <= 1e5; i++) if (p[i]){
//		if (i<100) cout << i << "\n";
		prime.push_back(i);
		for (int j = i*i; j <= 1e5; j+=i) p[j] = 0;
	}
	int t; cin >> t;
	while (t--)
	solve();
}


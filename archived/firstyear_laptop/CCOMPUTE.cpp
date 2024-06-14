#include<bits/stdc++.h>

using namespace std;
#define int long long
struct fraction{
	int a = 0, b = 0, c = 0, d = 0; // (ax+b)/(cx+d)
	fraction(int _a = 0, int _b = 0, int _c = 0, int _d = 0){
		a = _a; b = _b; c = _c; d = _d;
		
	}
	bool hasX(){
		return (a||c);
	}
	void simple(){
		int u = __gcd(__gcd(a,b),__gcd(c,d));
		a /= u; b /= u; c /= u; d /= u;
	}
	fraction operator+(fraction other){
		fraction res(
			a*other.d + c*other.b + other.a*d + other.c*b,
			b*other.d + d*other.b,
			other.d*c + d*other.c,
			other.d*d);
		res.simple();
		return res;
	}
	fraction operator-(fraction other){
		fraction res(
			a*other.d - c*other.b - other.a*d + other.c*b,
			b*other.d - d*other.b,
			other.d*c + d*other.c,
			other.d*d);
		res.simple();
		return res;
	}
	fraction operator*(fraction other){
		fraction res(
			a*other.b + other.a*b,
			b*other.b,
			c*other.d + other.c*d,
			other.d*d);
		res.simple();
		return res;
	}
	fraction trans(){
		fraction res = *this;
		swap(res.a,res.c);
		swap(res.b,res.d);
		return res;
	}
	fraction operator/(fraction other){
		return (*this)*other.trans();
	}
	void print(){
		cout << "(" << a << "x + " << b << ")/(" << c << "x + " << d << ")\n";
	}
}; 
bool isOperator(char c){
	return (c=='+'||c=='-'||c=='/'||c=='*');
}
stack<fraction> st;
fraction doOperator(char c){
	fraction b = st.top(); st.pop();
	fraction a = st.top(); st.pop();
	if (c=='+') return a + b;
	if (c=='-') return a - b;
	if (c=='*') return a * b;
	if (c=='/') return a / b;
}
string inp, s;
main(){
	getline(cin, inp);
	stringstream ss(inp);
	string tmp;
	while (ss>>tmp){
		assert(tmp.size()==1);
		char c = tmp[0];
		s.push_back(c);
	}
	for (int i = 0; i < s.length(); i++){
		char c = s[i];
		fraction cur;
		if (isOperator(c)){
			cur = doOperator(c);
		} else {
			if (c=='X') cur = fraction(1,0,0,1);
			else cur = fraction(0,c-'0',0,1);
		}
		st.push(cur);
	}
	assert(st.size()==1);
//	st.top().print();
	fraction cur = st.top();
	assert(cur.d||cur.c);
//	assert(!(cur.a!=0&&cur.b==0&&cur.c==0&&cur.d!=0)); //&&a==0&&b==1
	if (!cur.hasX()){
		if (cur.b==0) cout << "multiple\n";
		else cout << "none\n";
	} else {
		if (cur.a==0&&cur.b==0) cout << "multiple\n";
		else if (cur.a==0&&cur.b!=0){
			cout << "none\n";
		} else if (cur.b==0&&cur.d==0){
			cout << "none\n";
		} else {
			assert(cur.a*cur.d-cur.b*cur.c);
			int a = -cur.b, b = cur.a;
			int u = __gcd(a,b);
			a /= u; b /= u;
			if (b<0) b *= -1, a *= -1;
			cout << a << " " << b << "\n";
		}
	}
	
	return 0;
}

//https://pastebin.com/nA4VSyhY

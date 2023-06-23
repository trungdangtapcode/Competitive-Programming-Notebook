#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll l, q, k, d, sotram;
ll f(ll x, ll d, ll k){
	ll cnt = x/k, r = x%k;
	cout << cnt << "," << cnt+(r>2*d) << " ";
	if (cnt>0&&k>2*d) return max({r-d,min(k,x)-d,(k-2*d)*cnt+max(r-2*d,0ll)+d});
	else return max(r-d,min(k,x)-d);
//	return (k-2*d)*cnt+max(r-2*d,0ll)+(cnt+(r>=d)>0)*d;
}

int main(){
	cin >> l >> q >> k >> d;
	if (k<d){
		cout << -1;
		return 0;
	}
	map<ll,ll> hieu;
	ll last = q;
	sotram = l/d;
	for (int i = 0; i < sotram;){
		ll x = 1, r = x%k;
//		ll tmp = q/(q/k);
//		tmp = (tmp/k);
//		x = max(x,tmp);
//		x = max(x,k/(2*d));
		//farthest k*x that q/(k*x) == q/k == number of times
//		x = min(x,sotram-i);
		q = f(q,d*x,k*x);
		hieu[last-q]++;
		cout << q << " hieu: " << last-q<< endl;
		last = q;
		if (q<0){
			cout << -1;
			return 0;
		}
		i+=x;
	}
	q = f(q,l%d,k);
	if (q<0){
		cout << -1;
		return 0;
	}
	for (auto it: hieu){
		cout << it.first << ": " << it.second << endl;
	}
	cout << q;
	
	return 0;
}


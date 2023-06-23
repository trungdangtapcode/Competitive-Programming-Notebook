#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll l, q, k, d, sotram;
ll f(ll x, ll d, ll k){
	ll cnt = x/k, r = x%k;
	if (cnt>0&&k>2*d) return max({r-d,min(k,x)-d,(k-2*d)*cnt+max(r-2*d,0ll)+d});
	else return max(r-d,min(k,x)-d);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> l >> q >> k >> d;
	sotram = l/d;
	for (int i = 0; i < sotram;){
		ll tmp = f(q,d,k);
		if (tmp<0){
			cout << -1;
			return 0;
		}
		ll x = q-tmp;
		ll l = 1, h = 1e9, m, ans = 1;
		while (l<=h){
			m = (l+h)/2;
			if (f(q-x*m,d,k)>=0&&q-x*m-f(q-x*m,d,k)==x){
				ans = max(ans,m);
				l = m+1;
			} else h = m-1;
		}
		
		
		ans = min(ans,sotram-i);
		i += ans;
		q -= ans*x;
//		cout << q << endl;
	}
	q = f(q,l%d,k);
	if (q<0){
		cout << -1;
		return 0;
	}
	cout << q;
	
	return 0;
}


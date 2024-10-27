#include<bits/stdc++.h>

#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
#define int long long
const int N = 1e5 +5;

int mod;
int block_size = 3000;

string str;
int mp[N];
int n, Q, a[N];
long long s[N], res[N];

int f[N];
vector<int> comp;

int powmod(long long a, int b){
	long long ans = 1;
	while(b){
		if(b & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}

int inv(int x){
	return powmod(x, mod - 2);
}

#define ii pair<int,int>
#define iii pair<ii,int>
iii tv[N];

int cmp(iii a, iii b){
	int x = a.first.first / block_size;
	if(x != b.first.first / block_size){
		return x < b.first.first / block_size;
	}
	return (x&1 ? a.first.second < b.first.second
		: a.first.second > b.first.second);
}

long long sol_psum[N];
int sol_pcnt[N];
void sol5(){
	//sum[l..r] - cnt[l..r]*(l-1)
	for (int i = 1; i <= n; i++){
		int csum = 0, ccnt = 0;
		if (str[i-1]=='0'||str[i-1]=='5'){
			csum += i;
			ccnt++;
		}
		sol_psum[i] = sol_psum[i-1]+csum;	
		sol_pcnt[i] = sol_pcnt[i-1]+ccnt;
	}
	cin >> Q;
	for (int i = 1; i <= Q; i++){
		int l, r; cin >> l >> r;
		cout << sol_psum[r]-sol_psum[l-1]-1ll*(l-1)*(sol_pcnt[r]-sol_pcnt[l-1]) << "\n";
	}
}
void sol2(){
	//sum[l..r] - cnt[l..r]*(l-1)
	for (int i = 1; i <= n; i++){
		int csum = 0, ccnt = 0;
		if (str[i-1]=='2'||str[i-1]=='4'||str[i-1]=='6'||str[i-1]=='8'||str[i-1]=='0'){
			csum += i;
			ccnt++;
		}
		sol_psum[i] = sol_psum[i-1]+csum;	
		sol_pcnt[i] = sol_pcnt[i-1]+ccnt;
	}
	cin >> Q;
	for (int i = 1; i <= Q; i++){
		int l, r; cin >> l >> r;
		cout << sol_psum[r]-sol_psum[l-1]-1ll*(l-1)*(sol_pcnt[r]-sol_pcnt[l-1]) << "\n";
	}
}


void solve(){
	cin >> mod;
	cin >> str;
	n = str.size();
	
	if(mod == 2) return sol2(), void();
	if(mod == 5) return sol5(), void();	
	
	int tmp = 0;
	For(i,1,n){
		a[i] = (str[i-1] - '0');
		tmp = (tmp * 10 + a[i]) % mod;
		s[i] = (inv(powmod(10, i)) * tmp) % mod;
//		cout << s[i] << " ";
		comp.push_back(s[i]);
	}
	
	cin >> Q;
	For(i,0,Q-1){
		int l, r;
		cin >> l >> r;
		l--;
		tv[i] = iii(ii(l, r), i);
	}

	block_size = sqrt(n);
	sort(tv, tv + Q, cmp);
		
	
	comp.push_back(0);
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	For(i,0,n) f[i] = 
		lower_bound(comp.begin(), comp.end(), s[i]) - comp.begin() + 1;
//	For(i,0,n) cout << f[i] << " "; cout << "\n";
	
	long long ans = 0;
	int l = 0, r = -1;		
	For(i,0,Q-1){
		while(r < tv[i].first.second){
			ans += mp[f[r+1]];
			mp[f[++r]]++;
		}
		while(l > tv[i].first.first){
			ans += mp[f[l-1]];
			mp[f[--l]]++;
		}
		while(r > tv[i].first.second){
			mp[f[r--]]--;
			ans -= mp[f[r+1]];
		}
		while(l < tv[i].first.first){
			mp[f[l++]]--;
			ans -= mp[f[l-1]];
		}
		res[tv[i].second] = ans;
	}
	for (int i = 0;i < Q; i++){
		cout << res[i] << "\n";
	}
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	solve();
}


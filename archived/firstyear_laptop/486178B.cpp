#include<bits/stdc++.h>

using namespace std;
const int maxN = 5e6+5;
bool p[maxN];
int q, l, r;
int vec[maxN/2], sz;
int sqr3(int x){
	return x*x*x;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	p[0] = p[1] = 1;
	for (int i = 2; i*i <= 5e6; i++) if(!p[i]){
		for (int j = i*i; j <= 5e6; j += i) p[j] = 1;
	}
	for (int i = 2; i <= 5e6; i++) if (!p[i]) vec[sz++] = i;
	cin >> l >> r;
		long long res = 0;
		for (int i = 0, jl = sz-1, jr = sz-1; ; i++){
			jl = lower_bound(vec,vec+sz,(l+vec[i]-1)/vec[i])-vec-1;
			jr = upper_bound(vec,vec+sz,r/vec[i])-vec-1;
//			while (jr>-1&&vec[jr]*vec[i]>r) jr--;
//			while (jl>-1&&vec[jl]*vec[i]>=l) jl--;
//			cout << i << " " << jl << ".." << jr << "\n";
//			cout << vec[i] << " " << vec[jl] << ".." << vec[jr] << "\n";
			assert(jl<=jr);
			if (jr<=i) break;
			res += jr-max(jl,i);
		}
		for (int i = 0; sqr3(vec[i]) <= r; i++){
//			cout << i << " " << sqr3(vec[i]) << "\n";
			if (sqr3(vec[i])>=l) res++;
		}
//		cout << res << "\n";
	cin >> q;
	while (q--){
//		cin >> l >> r;
		long long res = 0;
		for (int i = 0, jl = sz-1, jr = sz-1; ; i++){
			jl = lower_bound(vec,vec+sz,(l+vec[i]-1)/vec[i])-vec-1;
			jr = upper_bound(vec,vec+sz,r/vec[i])-vec-1;
//			while (jr>-1&&vec[jr]*vec[i]>r) jr--;
//			while (jl>-1&&vec[jl]*vec[i]>=l) jl--;
//			cout << i << " " << jl << ".." << jr << "\n";
//			cout << vec[i] << " " << vec[jl] << ".." << vec[jr] << "\n";
			assert(jl<=jr);
			if (jr<=i) break;
			res += jr-max(jl,i);
		}
		for (int i = 0; sqr3(vec[i]) <= r; i++){
//			cout << i << " " << sqr3(vec[i]) << "\n";
			if (sqr3(vec[i])>=l) res++;
		}
//		cout << res << "\n";
	}
	return 0;
}

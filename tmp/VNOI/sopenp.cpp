#include<bits/stdc++.h>

using namespace std;
const int maxN = (1<<20)+5;
int n, l, u, a[maxN], cntl[maxN], cntr[maxN];

main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> l >> u;
    vector<int> v;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    long long res = 0;
    for (int i = 1; i <= n; i++) a[i] = lower_bound(v.begin(),v.end(),a[i])-v.begin();
    for (int i = 1, jl = 1, jr = 1, numl = 0, numr = 0; i <= n; i++){
        if (++cntl[a[i]]==1) numl++;
        if (++cntr[a[i]]==1) numr++;
        while (numl>u) if (--cntl[a[jl++]]==0) numl--;
        while (numr>=l) if (--cntr[a[jr++]]==0) numr--; 
        if (++cntr[a[--jr]]==1) numr++;
        // cout << jl << ".." << jr << " " << numl << " " << numr << "\n";
        if (numl<=u&&numr>=l) res += (jr-jl+1); 
    }
    cout << res << "\n";

    return 0;
}
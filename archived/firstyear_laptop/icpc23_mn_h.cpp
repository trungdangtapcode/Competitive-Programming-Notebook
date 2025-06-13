#include<bits/stdc++.h>

using namespace std;
#define int long long
int a, b, c, d;
map<int,int> mpl, mpr, mpb, mpd;
void duoi(int a){
    for (int i = 2; i*i <= a; i++) if (a%i==0){
        int cur = 0;
        while (a%i==0) cur++, a /= i;
        if (mpl.count(i)) mpl[i] = max(mpl[i],cur);
        else mpl[i] = cur;
    }
    if (a!=1){
        int i = a, cur = 1;
        if (mpl.count(i)) mpl[i] = max(mpl[i],cur);
        else mpl[i] = cur;
    }
}
void tren(int a){
    for (int i = 2; i*i <= a; i++) if (a%i==0){
        int cur = 0;
        while (a%i==0) cur++, a /= i;
        if (mpr.count(i)) mpr[i] = min(mpr[i],cur);
        else mpr[i] = cur;
    }
    if (a!=1){
        int i = a, cur = 1;
        if (mpr.count(i)) mpr[i] = min(mpr[i],cur);
        else mpr[i] = cur;
    }
}
void mb(int a){
    for (int i = 2; i*i <= a; i++) if (a%i==0){
        int cur = 0;
        while (a%i==0) cur++, a /= i;
        mpb[i] = cur;
    }
    if (a!=1){
        int i = a, cur = 1;
        mpb[i] = cur;
    }
}
void md(int a){
    for (int i = 2; i*i <= a; i++) if (a%i==0){
        int cur = 0;
        while (a%i==0) cur++, a /= i;
        mpd[i] = cur;
    }
    if (a!=1){
        int i = a, cur = 1;
        mpd[i] = cur;
    }
}

main(){
    cin >> a >> b >> c >> d;
    duoi(a);
//    duoi(d);
//    tren(b);
    tren(c);
    mb(b);
    md(d);
    for (auto it: mpl){
        int x = it.first, y = it.second;
        if (!mpr.count(x)) {
            cout << -1;
            return 0;
        };
    }
    int res = 2e9;
    for (auto it: mpr){
        int x = it.first, y = it.second, tmp = mpl[x];
//        if (!mpb.count(x)) mpb[x] = 1e9;
        mpd[x];
//        cout << x << " " << mpl[x] << ".." << y << "\n";
//        if (tmp>y){
//            cout << -1;
//            return 0;
//        }
//        for (int i = 0; i < tmp; i++) res *= x;
    }
    for (auto it: mpb){
        int xb = it.first, yb = it.second-1;
        for (auto it: mpd){
            int xd = it.first, yd = it.second+1;
//            cout << xb << " " << yb << " " << xd << " " << yd << "\n";
            int cur = 1;
            if (!mpr.count(xd)) continue;
//            if (!mpr.count(xb)) for (int i = 0; i < yb; i++) cur *= xb;
            for (auto it: mpr){
                int x = it.first, y = it.second, tmp = mpl[x];
                if (x==xb) y = min(y,yb);
                if (x==xd) tmp = max(tmp,yd);
                if (y<tmp) cur = 0;
                for (int i = 0; i < tmp; i++) cur *= x;
//                cout << x << " -> " << tmp << ".." << y << "\n";
            }
            if (cur){
//                cout << cur << "s\n";
                res = min(res,cur);
            }
        }
    }
    cout  << (res==2e9?-1:res);


    return 0;
}

#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000 + 5;

unsigned char par[MAXN];

struct FastInput {
    static const int SZ = 1 << 20;
    int idx = 0, size = 0;
    char buf[SZ];

    inline char getChar() {
        if (idx >= size) {
            size = fread(buf, 1, SZ, stdin);
            idx = 0;
            if (size == 0) return 0;
        }
        return buf[idx++];
    }

    inline int nextInt() {
        char c;
        do c = getChar(); while (c <= ' ');

        int x = 0;
        while (c > ' ') {
            x = x * 10 + c - '0';
            c = getChar();
        }
        return x;
    }

    inline void skipSpace() {
        while (buf[idx] <= ' ') getChar();
    }
};

FastInput in;

inline bool solveOne() {
    int n = in.nextInt();
    int k = in.nextInt();

    if (k == 0 || k >= n) {
        int hasOne = 0;

        for (int i = 0; i < n; ++i) {
            char c = in.getChar();
            while (c <= ' ') c = in.getChar();
            hasOne |= c & 1;
        }

        return hasOne == 0;
    }

    if (k <= 64) {
        uint64_t mask = 0;
        int r = 0;

        for (int i = 0; i < n; ++i) {
            char c = in.getChar();
            while (c <= ' ') c = in.getChar();

            if (c & 1) mask ^= 1ULL << r;

            ++r;
            if (r == k) r = 0;
        }

        return mask == 0;
    }

    memset(par, 0, k);

    int odd = 0;
    int r = 0;

    for (int i = 0; i < n; ++i) {
        char c = in.getChar();
        while (c <= ' ') c = in.getChar();

        if (c & 1) {
            int old = par[r];
            par[r] ^= 1;
            odd += par[r] - old;
        }

        ++r;
        if (r == k) r = 0;
    }

    return odd == 0;
}

int main() {
#ifdef JESSIE
    freopen("input.txt", "r", stdin);
#endif

    int t = in.nextInt();

    string out;
    out.reserve(t * 4);

    while (t--) {
        out += solveOne() ? "YES\n" : "NO\n";
    }

    fwrite(out.data(), 1, out.size(), stdout);
}

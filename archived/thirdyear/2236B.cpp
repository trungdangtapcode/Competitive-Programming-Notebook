#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt")

#include <bits/stdc++.h>
#include <immintrin.h>
#include <x86intrin.h>

using namespace std;

//#pragma GCC optimize("Ofast,unroll-loops")
//
//#include <bits/stdc++.h>
//using namespace std;

const int MAXN = 200000 + 5;
const uint64_t BYTE_LSB = 0x0101010101010101ULL;

alignas(32) unsigned char acc[MAXN];

struct FastInput {
    vector<char> buf;
    char *p;

    FastInput() {
        buf.reserve(1 << 20);

        char tmp[1 << 20];
        size_t len;

        while ((len = fread(tmp, 1, sizeof(tmp), stdin)) > 0) {
            buf.insert(buf.end(), tmp, tmp + len);
        }

        buf.push_back(0);
        p = buf.data();
    }

    inline int nextInt() {
        while (*p <= ' ') ++p;

        int x = 0;
        while (*p > ' ') {
            x = x * 10 + (*p - '0');
            ++p;
        }

        return x;
    }

    inline char* nextString(int n) {
        while (*p <= ' ') ++p;

        char* res = p;
        p += n;

        return res;
    }
};

inline uint64_t load64(const char* p) {
    uint64_t x;
    memcpy(&x, p, 8);
    return x;
}

inline bool noOne(const char* s, int len) {
    return memchr(s, '1', len) == nullptr;
}

inline bool parityAllEven(const char* s, int n) {
    uint64_t x = 0;
    int i = 0;

    for (; i + 8 <= n; i += 8) {
        x ^= load64(s + i);
    }

    uint64_t bits = x & BYTE_LSB;
    int parity = __builtin_parityll(bits);

    for (; i < n; ++i) {
        parity ^= s[i] & 1;
    }

    return parity == 0;
}

uint64_t smallTable[8][8][256];
int nextResidue[8][8];

void buildSmallTable() {
    for (int k = 2; k < 8; ++k) {
        for (int r = 0; r < k; ++r) {
            nextResidue[k][r] = (r + 8) % k;

            for (int bits = 0; bits < 256; ++bits) {
                uint64_t mask = 0;
                int cur = r;

                for (int b = 0; b < 8; ++b) {
                    if ((bits >> b) & 1) {
                        mask ^= 1ULL << cur;
                    }

                    ++cur;
                    if (cur == k) cur = 0;
                }

                smallTable[k][r][bits] = mask;
            }
        }
    }
}

inline bool solveSmallK(const char* s, int n, int k) {
    if (k == 1) {
        return parityAllEven(s, n);
    }

    uint64_t mask = 0;
    int r = 0;
    int i = 0;

    if (k < 8) {
        for (; i + 8 <= n; i += 8) {
            uint64_t x = load64(s + i);
            int bits = _pext_u64(x, BYTE_LSB);

            mask ^= smallTable[k][r][bits];
            r = nextResidue[k][r];
        }
    } else {
        for (; i + 8 <= n; i += 8) {
            uint64_t x = load64(s + i);
            uint64_t bits = _pext_u64(x, BYTE_LSB);

            if (r + 8 <= k) {
                mask ^= bits << r;
                r += 8;
                if (r == k) r = 0;
            } else {
                int first = k - r;

                mask ^= (bits & ((1ULL << first) - 1)) << r;
                mask ^= bits >> first;

                r = 8 - first;
            }
        }
    }

    for (; i < n; ++i) {
        if (s[i] & 1) {
            mask ^= 1ULL << r;
        }

        ++r;
        if (r == k) r = 0;
    }

    return mask == 0;
}

inline void xorBlock(unsigned char* dst, const char* src, int len) {
    int i = 0;

    for (; i + 32 <= len; i += 32) {
        __m256i a = _mm256_loadu_si256((const __m256i*)(dst + i));
        __m256i b = _mm256_loadu_si256((const __m256i*)(src + i));
        a = _mm256_xor_si256(a, b);
        _mm256_storeu_si256((__m256i*)(dst + i), a);
    }

    for (; i + 8 <= len; i += 8) {
        uint64_t a, b;

        memcpy(&a, dst + i, 8);
        memcpy(&b, src + i, 8);

        a ^= b;

        memcpy(dst + i, &a, 8);
    }

    for (; i < len; ++i) {
        dst[i] ^= src[i];
    }
}

inline bool lowBitsZero(const unsigned char* a, int len) {
    int i = 0;

    __m256i one = _mm256_set1_epi8(1);
    __m256i any = _mm256_setzero_si256();

    for (; i + 32 <= len; i += 32) {
        __m256i x = _mm256_loadu_si256((const __m256i*)(a + i));
        x = _mm256_and_si256(x, one);
        any = _mm256_or_si256(any, x);
    }

    if (!_mm256_testz_si256(any, any)) {
        return false;
    }

    uint64_t rem = 0;

    for (; i + 8 <= len; i += 8) {
        uint64_t x;
        memcpy(&x, a + i, 8);
        rem |= x & BYTE_LSB;
    }

    if (rem) return false;

    for (; i < len; ++i) {
        if (a[i] & 1) return false;
    }

    return true;
}

inline bool solveLargeK(const char* s, int n, int k) {
    if (k >= n) {
        return noOne(s, n);
    }

    if (k * 2 > n) {
        int m = n - k;

        if (memcmp(s, s + k, m) != 0) {
            return false;
        }

        return noOne(s + m, k - m);
    }

    memcpy(acc, s, k);

    int pos = k;

    while (pos + k <= n) {
        xorBlock(acc, s + pos, k);
        pos += k;
    }

    if (pos < n) {
        xorBlock(acc, s + pos, n - pos);
    }

    return lowBitsZero(acc, k);
}

int main() {
#ifdef JESSIE
    freopen("input.txt", "r", stdin);
#endif

    FastInput in;
    buildSmallTable();

    int t = in.nextInt();

    string out;
    out.reserve(t * 4);

    while (t--) {
        int n = in.nextInt();
        int k = in.nextInt();
        char* s = in.nextString(n);

        bool ok;

        if (k == 0) {
            ok = noOne(s, n);
        } else if (k <= 64) {
            ok = solveSmallK(s, n, k);
        } else {
            ok = solveLargeK(s, n, k);
        }

        out += ok ? "YES\n" : "NO\n";
    }

    fwrite(out.data(), 1, out.size(), stdout);

    return 0;
}

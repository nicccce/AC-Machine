#include<bits/stdc++.h>

#define N 2000979
#define M 31
#define LL long long
#define pii pair<int, int> 
#define pll pair<LL, LL>
#define fi first
#define se second
#define pb push_back
#define lbd lower_bound
#define ubd upper_bound
#define IO ios :: sync_with_stdio(false), cin.tie(0)

using namespace std;

const LL INF = 10000000000000000LL;

__int128 n, k, a, b; 

void read(__int128 &x) {
    char c = getchar(); __int128 f = 1;
    while (c < '0' || c > '9') {if (c == '-') f=-1; c =getchar(); }
    x = 0; 
    while (c >= '0' && c <= '9') {x = (x * 10 + c - '0'); c = getchar(); }
    x = x*f;
}
void write(__int128 x) {
    if (x > 9) write(x/10);
    putchar(x%10 + '0');
}
bool check(__int128 x) {
    __int128 ans = 0; 
    for (__int128 d = 1; d < min((__int128)200000000, n); d ++) {
        __int128 res = (x - a*d*d - 2*b*d)/(2*a*d);
        if (x - a*d*d - 2*b*d <= 0) break;
        res = min(res, n-d); 
        res = max(res, (__int128)0); 
        ans += res;
        if (ans >= k) return 1;
    }
    // write(ans); 
    // puts("");
    return (ans >= k);
}
__int128 gcd(__int128 a, __int128 b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    IO;
    read(n); read(k); read(a); read(b);
    __int128 l = 1, r = (__int128)ULLONG_MAX; 
    while (l < r) {
        __int128 mid = (l+r) / 2;
        if (check(mid)) r = mid;
        else l = mid+1; 
    }
    __int128 g = gcd(r, a); 
    r/=g; a/=g;
    write(r); putchar(' '); write(a); 
    return 0;
}
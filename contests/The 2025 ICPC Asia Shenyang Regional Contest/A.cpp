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

unsigned long long n, k, a, b; 

void read(unsigned long long &x) {
    char c = getchar(); unsigned long long f = 1;
    while (c < '0' || c > '9') {if (c == '-') f=-1; c =getchar(); }
    x = 0; 
    while (c >= '0' && c <= '9') {x = (x * 10 + c - '0'); c = getchar(); }
    x = x*f;
}
void write(unsigned long long x) {
    if (x > 9) write(x/10);
    putchar(x%10 + '0');
}
bool check(unsigned long long x) {
    unsigned long long ans = 0; 
    // unsigned long long d = 0;
    // while (++d<n)
    // {
    //     unsigned long long res = (x - a*d*d - 2*b*d)/(2*a*d);
    //     if (x - a*d*d - 2*b*d <= 0) break;
    //     res = min(res, n-d); 
    //     res = max(res, (unsigned long long)0); 
    //     ans += res;
    //     if (ans >= k) return 1;
    // }
    
    for (unsigned long long d = 1; d < min((unsigned long long)20000000, n); d ++) {
        unsigned long long res = (x - a*d*d - 2*b*d)/(2*a*d);
        if (x - a*d*d - 2*b*d <= 0) break;
        res = min(res, n-d); 
        res = max(res, (unsigned long long)0); 
        ans += res;
        if (ans >= k) return 1;
    }

    return (ans >= k);
}
unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    IO;
    read(n); read(k); read(a); read(b);
    unsigned long long l = 1, r = (unsigned long long)ULLONG_MAX; 
    while (l < r) {
        unsigned long long mid = l + (r - l) / 2;
        if (check(mid)) r = mid;
        else l = mid+1; 
    }
    unsigned long long g = gcd(r, a); 
    r/=g; a/=g;
    cout<<r<<' '<<a;
    return 0;
}
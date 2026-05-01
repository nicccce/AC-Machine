#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>

using namespace std;

const unsigned int MOD = 998244353;
// 内存对齐，使得 SIMD 指令读取内存效率最大化
// Memory alignment forces maximum efficiency for AVX vector read/writes
unsigned int dp1[200005] __attribute__((aligned(32)));
unsigned int dp2[200005] __attribute__((aligned(32)));

int main() {
    // 提升 I/O 流性能
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    int m = n / 2;
    unsigned int *src = dp1;
    unsigned int *dst = dp2;
    
    // 1. O(1) 闭式解析：越过一半的无效 DP 区间
    // Analytical bypass mapping exactly halfway through the heaviest items
    src[0] = 1;
    unsigned int p2 = 1;
    for (int w = m + 1; w <= n; ++w) {
        src[w] = p2;
        p2 = p2 * 2;
        if (p2 >= MOD) p2 -= MOD;
    }
    
    // 2. 无分支向量化 DP：处理余下部分
    // Branchless Vectorized DP for the remaining items
    for (int k = m; k >= 1; --k) {
        int limit = n - k;
        
        // Block 1: 空间足够但重量还未达到物品本身 (w < k)
        // Space sufficient but item weight not even reached
        for (int w = 0; w < k; ++w) {
            dst[w] = src[w];
        }
        
        // Block 2: 空间足够，存在背包装入的转移可能 (w <= limit)
        // Accommodating capacities allowing subset transitions
        for (int w = k; w <= limit; ++w) {
            unsigned int sum = src[w] + src[w - k];
            dst[w] = sum >= MOD ? sum - MOD : sum;
        }
        
        // Block 3: 背包无法装入当前物品，分支宇宙翻倍 (w > limit)
        // Insufficient capacity, combinatorial parallel configurations double
        for (int w = limit + 1; w <= n; ++w) {
            unsigned int a2 = src[w] * 2;
            if (a2 >= MOD) a2 -= MOD;
            
            unsigned int sum = a2 + src[w - k];
            dst[w] = sum >= MOD ? sum - MOD : sum;
        }
        
        // 交替滚动数组 Swap buffer pointers
        unsigned int *tmp = src;
        src = dst;
        dst = tmp;
    }
    
    // 3. 输出打印结果 Formatted output
    for (int i = 0; i <= n; ++i) {
        cout << src[i] << (i == n ? "" : " ");
    }
    cout << "\n";
    
    return 0;
}
#pragma GCC optimize("O3,unroll-loops")

#include <iostream>
#include <emmintrin.h> // 兼容全平台的 128-bit SSE2 硬件指令集
#include <cstring>

using namespace std;

const int MOD = 998244353;
// 按16字节内存对齐，确保 SSE2 加载速度最大化
// Memory aligned to 16 bytes maximizing 128-bit SIMD load throughput
alignas(16) int src[200064];

void solve() {
    int n;
    // EC-Final 必定有多组测试用例，切记使用 while(cin)
    // CRITICAL: Handle Multiple Test Cases dynamically
    while (cin >> n) {
        // 清理旧宇宙状态 Reset previous universes array data
        memset(src, 0, sizeof(int) * (n + 1));
        int m = n / 2;
        
        // 1. O(N) 临界折半降维打击 (Half-Domain Analytical Bypass)
        src[0] = 1;
        int p2 = 1;
        for (int w = m + 1; w <= n; ++w) {
            src[w] = p2;
            p2 = p2 * 2;
            if (p2 >= MOD) p2 -= MOD;
        }
        
        // SSE2 常量寄存器掩码
        __m128i v_mod = _mm_set1_epi32(MOD);
        __m128i v_mod_minus_1 = _mm_set1_epi32(MOD - 1);
        
        // 2. 无分支带符号向量化 DP (Branchless SSE2 In-Place Backwards DP)
        for (int k = m; k >= 16; --k) {
            int limit = n - k;
            int w = n;
            
            // Block 1: 空间不足装不下，组合翻倍并与前面转移相加
            for (; w >= limit + 16; w -= 16) {
                __m128i a1 = _mm_loadu_si128((__m128i*)&src[w - 3]);
                __m128i a2 = _mm_loadu_si128((__m128i*)&src[w - 7]);
                __m128i a3 = _mm_loadu_si128((__m128i*)&src[w - 11]);
                __m128i a4 = _mm_loadu_si128((__m128i*)&src[w - 15]);
                
                __m128i b1 = _mm_loadu_si128((__m128i*)&src[w - k - 3]);
                __m128i b2 = _mm_loadu_si128((__m128i*)&src[w - k - 7]);
                __m128i b3 = _mm_loadu_si128((__m128i*)&src[w - k - 11]);
                __m128i b4 = _mm_loadu_si128((__m128i*)&src[w - k - 15]);
                
                // 无分支 a*2 取模运算
                __m128i a1_2 = _mm_add_epi32(a1, a1);
                a1_2 = _mm_sub_epi32(a1_2, _mm_and_si128(_mm_cmpgt_epi32(a1_2, v_mod_minus_1), v_mod));
                // 无分支 sum 取模运算
                __m128i sum1 = _mm_add_epi32(a1_2, b1);
                _mm_storeu_si128((__m128i*)&src[w - 3], _mm_sub_epi32(sum1, _mm_and_si128(_mm_cmpgt_epi32(sum1, v_mod_minus_1), v_mod)));
                
                __m128i a2_2 = _mm_add_epi32(a2, a2);
                a2_2 = _mm_sub_epi32(a2_2, _mm_and_si128(_mm_cmpgt_epi32(a2_2, v_mod_minus_1), v_mod));
                __m128i sum2 = _mm_add_epi32(a2_2, b2);
                _mm_storeu_si128((__m128i*)&src[w - 7], _mm_sub_epi32(sum2, _mm_and_si128(_mm_cmpgt_epi32(sum2, v_mod_minus_1), v_mod)));
                
                __m128i a3_2 = _mm_add_epi32(a3, a3);
                a3_2 = _mm_sub_epi32(a3_2, _mm_and_si128(_mm_cmpgt_epi32(a3_2, v_mod_minus_1), v_mod));
                __m128i sum3 = _mm_add_epi32(a3_2, b3);
                _mm_storeu_si128((__m128i*)&src[w - 11], _mm_sub_epi32(sum3, _mm_and_si128(_mm_cmpgt_epi32(sum3, v_mod_minus_1), v_mod)));
                
                __m128i a4_2 = _mm_add_epi32(a4, a4);
                a4_2 = _mm_sub_epi32(a4_2, _mm_and_si128(_mm_cmpgt_epi32(a4_2, v_mod_minus_1), v_mod));
                __m128i sum4 = _mm_add_epi32(a4_2, b4);
                _mm_storeu_si128((__m128i*)&src[w - 15], _mm_sub_epi32(sum4, _mm_and_si128(_mm_cmpgt_epi32(sum4, v_mod_minus_1), v_mod)));
            }
            // 处理不足 16 个的零头标量
            for (; w > limit; --w) {
                int a2 = src[w] << 1;
                a2 = a2 >= MOD ? a2 - MOD : a2;
                int sum = a2 + src[w - k];
                src[w] = sum >= MOD ? sum - MOD : sum;
            }
            
            // Block 2: 空间足够装下，按正常背包相加转移
            for (; w >= k + 15; w -= 16) {
                __m128i a1 = _mm_loadu_si128((__m128i*)&src[w - 3]);
                __m128i a2 = _mm_loadu_si128((__m128i*)&src[w - 7]);
                __m128i a3 = _mm_loadu_si128((__m128i*)&src[w - 11]);
                __m128i a4 = _mm_loadu_si128((__m128i*)&src[w - 15]);
                
                __m128i b1 = _mm_loadu_si128((__m128i*)&src[w - k - 3]);
                __m128i b2 = _mm_loadu_si128((__m128i*)&src[w - k - 7]);
                __m128i b3 = _mm_loadu_si128((__m128i*)&src[w - k - 11]);
                __m128i b4 = _mm_loadu_si128((__m128i*)&src[w - k - 15]);
                
                __m128i sum1 = _mm_add_epi32(a1, b1);
                _mm_storeu_si128((__m128i*)&src[w - 3], _mm_sub_epi32(sum1, _mm_and_si128(_mm_cmpgt_epi32(sum1, v_mod_minus_1), v_mod)));
                
                __m128i sum2 = _mm_add_epi32(a2, b2);
                _mm_storeu_si128((__m128i*)&src[w - 7], _mm_sub_epi32(sum2, _mm_and_si128(_mm_cmpgt_epi32(sum2, v_mod_minus_1), v_mod)));
                
                __m128i sum3 = _mm_add_epi32(a3, b3);
                _mm_storeu_si128((__m128i*)&src[w - 11], _mm_sub_epi32(sum3, _mm_and_si128(_mm_cmpgt_epi32(sum3, v_mod_minus_1), v_mod)));
                
                __m128i sum4 = _mm_add_epi32(a4, b4);
                _mm_storeu_si128((__m128i*)&src[w - 15], _mm_sub_epi32(sum4, _mm_and_si128(_mm_cmpgt_epi32(sum4, v_mod_minus_1), v_mod)));
            }
            // 处理不足 16 个的零头标量
            for (; w >= k; --w) {
                int sum = src[w] + src[w - k];
                src[w] = sum >= MOD ? sum - MOD : sum;
            }
        }
        
        // 末尾清理，处理不足构建 16 寄存器宽度的极小物品循环
        for (int k = min(m, 15); k >= 1; --k) {
            int limit = n - k;
            for (int w = n; w > limit; --w) {
                int a2 = src[w] << 1;
                a2 = a2 >= MOD ? a2 - MOD : a2;
                int sum = a2 + src[w - k];
                src[w] = sum >= MOD ? sum - MOD : sum;
            }
            for (int w = limit; w >= k; --w) {
                int sum = src[w] + src[w - k];
                src[w] = sum >= MOD ? sum - MOD : sum;
            }
        }
        
        // 3. 最终打印格式化输出 Formatted Standard Output
        for (int i = 0; i <= n; ++i) {
            cout << src[i] << (i == n ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    // 关闭 I/O 同步，最大化吞吐性能 Disable synchronization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
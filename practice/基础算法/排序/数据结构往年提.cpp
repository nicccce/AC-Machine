#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <random>

using namespace std;

int getCharType(char c) {
    if (isalpha(c)) return 0;
    if (isdigit(c)) return 1;
    return 2;
}
int partitionByCounting(vector<char>& R) {
    int n = R.size();
    int swapCount = 0;
    
    // 1. 统计各类字符数量
    int cnt[3] = {0, 0, 0};
    for (char c : R) {
        cnt[getCharType(c)]++;
    }
    
    // 2. 计算每个分区的起始位置
    int boundaries[4];
    boundaries[0] = 0;                     // 字母区起始
    boundaries[1] = cnt[0];                // 数字区起始
    boundaries[2] = cnt[0] + cnt[1];       // 其他区起始
    boundaries[3] = n;                     // 结束
    
    // 3. 创建目标位置映射
    vector<int> target(n, 0);
    int pos[3] = {0, cnt[0], cnt[0] + cnt[1]};  // 每个分区的下一个放置位置
    
    for (int i = 0; i < n; i++) {
        int type = getCharType(R[i]);
        target[i] = pos[type];
        pos[type]++;
    }
    
    // 4. 环交换
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] && target[i] != i) {
            int cycle_start = i;
            char curr = R[i];
            int curr_pos = i;
            int cycle_length = 0;
            
            do {
                visited[curr_pos] = true;
                
                // 找到当前元素应该去的位置
                int next_pos = target[curr_pos];
                
                // 保存下一个元素
                char next_char = R[next_pos];
                
                // 交换
                R[next_pos] = curr;
                swapCount++;
                
                // 继续处理被换出来的元素
                curr = next_char;
                curr_pos = next_pos;
                cycle_length++;
                
            } while (curr_pos != cycle_start);
            
            // 环的交换次数应该是 cycle_length - 1
            // 但我们计算了cycle_length次，需要调整
            swapCount--;  // 因为最后一次交换实际上不需要
        }
        visited[i] = true;
    }
    
    return swapCount;
}

int threeWayPartition(vector<char>& R) {
    int swapCount = 0, n = R.size();
    int low = 0, mid = 0, high = n - 1;
    
    while (mid <= high) {
        int type = getCharType(R[mid]);
        if (type == 0) {
            if (mid != low) {
                swap(R[low], R[mid]);
                swapCount++;
            }
            low++; mid++;
        } else if (type == 1) {
            mid++;
        } else {
            if (mid != high) {
                swap(R[mid], R[high]);
                swapCount++;
            }
            high--;
        }
    }
    return swapCount;
}

string generateRandomString(int length) {
    static const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;:,.<>?";
    static mt19937 rng(random_device{}());
    uniform_int_distribution<size_t> dist(0, chars.size() - 1);
    
    string result;
    for (int i = 0; i < length; i++) {
        result += chars[dist(rng)];
    }
    return result;
}

int main() {
    cout << "比较两种算法的交换次数，只显示交换次数不同的情况：\n" << endl;
    int differentCount = 0;
    
    for (int i = 0; i < 10; i++) {
        // string s = "1*a";
        string s = generateRandomString(100);
        vector<char> arr1(s.begin(), s.end());
        vector<char> arr2(s.begin(), s.end());
        
        int swaps1 = partitionByCounting(arr1);
        int swaps2 = threeWayPartition(arr2);
        
        if (swaps1 != swaps2) {
            differentCount++;
            
            // 统计字符分布
            int cnt[3] = {0, 0, 0};
            for (char c : s) cnt[getCharType(c)]++;
            
            cout << "字符串 " << differentCount << ":" << endl;
            cout << "  原始字符串: " << s << endl;
            cout << "  算法1交换次数: " << swaps1 << endl;
            cout << "  算法2交换次数: " << swaps2 << endl;
            cout << "  差值: " << swaps2 - swaps1 << endl;
            cout << "  字符分布: 字母=" << cnt[0] << ", 数字=" << cnt[1] 
                 << ", 其他=" << cnt[2] << endl << endl;
        }
    }
    
    cout << "测试完成。交换次数不同的字符串数量: " << differentCount << "/100" << endl;
    
    return 0;
}
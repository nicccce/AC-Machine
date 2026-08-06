#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
int main() {
    uint8_t arr[4] = {0x0F, 0xF0, 0x12, 0x34};
    uint32_t* p16 = (uint32_t*)arr;

    cout<<std::hex<<*p16<<endl;

    return 0;
}
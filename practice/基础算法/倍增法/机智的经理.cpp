#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        long long  k;
        cin >> n >> m >> k;
        vector<int> P(n);
        for (int i = 0; i < n; i++) {
            cin >> P[i];
        }
        int count = 0;
        int left = 0;
        vector<int> temp;
        while (left < n) {
            temp.clear();
            long long sum=0;
            int maxRight=left;
            // int pre_a=0;

            for(int right=left;right<n;right++){
                auto loca=lower_bound(temp.begin(),temp.end(),P[right]);
                temp.insert(loca,P[right]);
                
                int a=min(m,(int)temp.size()/2);
                long long tempSum=0;

                 for (int i = 0; i < a; i++) {
                    long long d = temp[temp.size() - 1 - i] - temp[i];
                    tempSum += d * d;
                    if (tempSum > k) {
                    break;
                    }
                }
                if (tempSum > k) {
                    break;
                }
                // if(a>pre_a){
                //     int i=a-1;
                //     long long d = temp[temp.size() - 1 - i] - temp[i];
                //     sum+=d*d;
                //     pre_a=a;
                // }
                maxRight = right;
            }
            count++;
            left=maxRight+1;
        }
        cout << count <<endl;
    }
    return 0;
}
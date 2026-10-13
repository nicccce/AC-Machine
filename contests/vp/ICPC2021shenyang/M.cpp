#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string str;
    cin >> str;
    int n = str.length();
    str = "#" + str;
    int head = 1, best = 1;
    cout << 1 << " " << 1 << endl;
    for(int i = 2; i <= n; i++){
        if(str[i] > str[best]){
            head = i - (best - head);
            best = i;
        }
        else if(str[i] == str[best]) best++;
        else best = head;
        cout << head << " " << i << "  best = " << best << endl;
    }

	return 0;
}


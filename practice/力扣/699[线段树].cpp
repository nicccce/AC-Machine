// https://leetcode.cn/problems/the-skyline-problem/solutions/872710/tian-ji-xian-wen-ti-by-leetcode-solution-ozse/?envType=problem-list-v2&envId=segment-tree
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int long long
class Solution {
public:
#define lc index<<1
#define rc index<<1|1
vector<int> w;
struct node{
    int l, r; // 左、右边界
    long long sum; // 区间和
    long long lazy; // 用于懒标记
}; // 线段树数组，一般需要开4倍空间
vector<node> seg_tree;
// 构造线段树
inline void build_tree(int index, int l, int r){
    seg_tree[index] = {l,r,w[l],0};
    if(l == r){ // 是叶子则返回
        return;
    }
    int mid = (l+r)>>1; // 非叶子则裂开(÷2上取整)
    build_tree(lc, l, mid); // 左子树深入
    build_tree(rc, mid+1, r); // 右子树深入
    // 子节点的sum值求和即为父节点的sum值
    seg_tree[index].sum = max(seg_tree[lc].sum, seg_tree[rc].sum); 
}

// 单点修改
// 对now_index位置上的元素+num（第一个index用于从根向下递归，初始传入值为1）
inline void update_one(int index, int now_index, int num){ 
    // 是叶子则修改
    if((seg_tree[index].l==now_index) && (seg_tree[index].r==now_index)){
        seg_tree[index].sum = max(seg_tree[index].sum, num);
        return;
    }
    int mid = (seg_tree[index].l+seg_tree[index].r)>>1; // 非叶子则裂开
    if(now_index <= mid){
        update_one(lc, now_index, num);
    }
    if(now_index > mid){
        update_one(rc, now_index, num);
    }
    // 向上更新
    seg_tree[index].sum = max(seg_tree[lc].sum, seg_tree[rc].sum);
}

// 区间修改（懒标记法）
inline void pushdown(int index){ // 向下更新
    if(seg_tree[index].lazy){ // 如果该节点有标记，进行深入操作
        seg_tree[lc].sum = max(seg_tree[lc].sum, seg_tree[index].lazy);
        seg_tree[rc].sum = max(seg_tree[rc].sum, seg_tree[index].lazy);
        seg_tree[lc].lazy = max(seg_tree[lc].lazy, seg_tree[index].lazy);
        seg_tree[rc].lazy = max(seg_tree[rc].lazy, seg_tree[index].lazy);
        seg_tree[index].lazy = 0; // 该节点取消懒标记
    }
}
inline void update_interval(int index, int x, int y, int k){
    // 完全覆盖该区间
    if((x<=seg_tree[index].l) && (y>=seg_tree[index].r)){
        // 该父节点需要增加的数量=叶子节点数（区间长度）*k
        seg_tree[index].sum = max(seg_tree[index].sum, k);
        seg_tree[index].lazy = max(seg_tree[index].lazy, k); // 设置懒标记，暂且停止深入更新子节点
        return;
    }
    // 不完全覆盖则裂开
    int mid = (seg_tree[index].l+seg_tree[index].r)>>1;
    // 重点步骤！
    pushdown(index);
    if(x <= mid){
        update_interval(lc, x, y, k);
    }
    if(y > mid){
        update_interval(rc, x, y, k);
    }
    // 向上更新
    seg_tree[index].sum = max(seg_tree[lc].sum, seg_tree[rc].sum);
}

// 区间求和
inline long long part_sum(int index, int x, int y){
    // 完全覆盖该区间
    if((x<=seg_tree[index].l) && (y>=seg_tree[index].r)){
        return seg_tree[index].sum;
    }
    int mid = (seg_tree[index].l+seg_tree[index].r)>>1;
    pushdown(index);
    long long ans_sum = 0;
    // 不完全覆盖则裂开
    if(x <= mid){
        ans_sum = max(ans_sum, part_sum(lc, x, y));
    }
    if(y > mid){
        ans_sum = max(ans_sum, part_sum(rc, x, y));
    }
    return ans_sum;
}
#undef int
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> allnums;
        for(auto &it:positions){
            allnums.push_back(it[0]);
            allnums.push_back(it[0]+it[1]-1);
        }
        sort(allnums.begin(), allnums.end());
        allnums.erase(unique(allnums.begin(), allnums.end()), allnums.end());
        int m=allnums.size();
        map<int,int> mp;
        for(int i=0;i<m;i++){
            mp[allnums[i]]=i+1;
        }
        w.resize(m+2);
        seg_tree.resize((m+2)*4);
        build_tree(1, 1, m);
        vector<int> res;
        for(auto &it:positions){
            int mx=part_sum(1,mp[it[0]],mp[it[0]+it[1]-1]);
            update_interval(1,mp[it[0]],mp[it[0]+it[1]-1],mx+it[1]);
            res.push_back(seg_tree[1].sum);
        }
        return res;
    }
};

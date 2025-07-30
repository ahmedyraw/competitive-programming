/*
Prefix Sum and Partial Sum

    2 Types of Range Queries:
        1- Static: array and queries without update.
            Prefix Sum, Partial Sum, Sparse Table, SQRT Decomposition, Mo Algorithm
        2- Dynamic: array and queries with update.
            Segment Tree, Fenwick Trees (Binary Indexed Trees), Treaps/Splay Trees, SQRT Decomposition, Heavy-Light Decomposition, Mo Algorithm

    Prefix Sum
        use1: given array, L and R, find subarray sum
            ps[0] = arr[0];
            for(int i=1; i<n; ++i) ps[i] = ps[i-1] + arr[i];
            --l; --r;
            if(l==0) sum = ps[r];
            else sum = ps[r] - ps[l-1];
        use2: given array, L and R, find subarray product
            ps[0] = arr[0];
            for(int i=1; i<n; ++i) ps[i] = ps[i-1] * arr[i];
            --l; --r;
            if(l==0) product = ps[r];
            else product = ps[r] / ps[l-1];
        use3: given array, L and R, find subarray XOR
            ps[0] = arr[0];
            for(int i=1; i<n; ++i) ps[i] = ps[i-1] ^ arr[i];
            --l; --r;
            if(l==0) xor = ps[r];
            else xor = ps[r] ^ ps[l-1];
        hint
            
    Partial Sum (Coordinate Compression)
        use: given array and all static range updates, find the final array
        arr[N] = {}; par[N] = {};
        ll l, r, val; cin >> l >> r >> val;
        par[l] += val;
        par[r+1] -= val;
        cout << arr[i] + par[i] << ' ';
*/

//problem link:
//https://codeforces.com/group/wNS3GwuHOE/contest/435607/problem/E
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6 + 1;
ll a[N];
ll par[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,q; cin >> n >> q;
    for(int i=0; i<n; ++i) cin >> a[i];
    ll l,r,v;

    //partial sum algorithm
    while(q--) {
        cin >> l >> r >> v;
        --l; --r;
        par[l] += v;
        par[r+1] -= v;
    }

    //prefix sum for partial sum array
    for(int i=0; i<n; ++i) {
        par[i] += par[i-1];
    }

    //print each element + partial sum element
    for(int i=0; i<n; ++i) {
        cout << a[i] + par[i] << ' ';
    }
    
    return 0;
}
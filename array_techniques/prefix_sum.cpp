/*
Prefix Sum

1. Types of Range Queries:
    a) Static (No Updates)
       - Array remains fixed during all queries.
       - Typical data structures/techniques:
         Prefix Sum, Partial Sum, Sparse Table, SQRT Decomposition, Mo Algorithm.

    b) Dynamic (With Updates)
       - Array can be updated between queries.
       - Typical data structures/techniques:
         Segment Tree, Fenwick Tree (BIT), Treaps/Splay Trees, SQRT Decomposition,
         Heavy-Light Decomposition, Mo Algorithm with modifications.

2. Offline Queries:

    - Offline queries mean all queries are known upfront before answering any.
    - This allows you to reorder, batch, or preprocess queries efficiently.
    - Offline queries can be:
      
      * Static + Offline:
        - Array fixed, queries known in advance.
        - Use prefix sums, sparse tables, or Mo’s algorithm for fast processing.
      
      * Dynamic + Offline:
        - Array can be updated; all updates and queries known upfront.
        - Use advanced techniques like Mo’s algorithm with modifications or persistent data structures.
        
    - Offline techniques cannot be used when queries must be answered immediately (online queries).

3. Prefix Sum Variants and Usage:

   Given an array arr of size n:

   Use1: Subarray Sum ( + )
     - Build prefix sum array ps:
       ps[0] = arr[0];
       for (int i = 1; i < n; ++i)
           ps[i] = ps[i-1] + arr[i];
     - Query sum in [L, R]:
       --l; --r;  // zero-based indexing
       if (l == 0) sum = ps[r];
       else sum = ps[r] - ps[l-1];

   Use2: Subarray Product ( * )
     - Build prefix product array ps:
       ps[0] = arr[0];
       for (int i = 1; i < n; ++i)
           ps[i] = ps[i-1] * arr[i];
     - Query product in [L, R]:
       --l; --r;
       if (l == 0) product = ps[r];
       else product = ps[r] / ps[l-1]; // Careful with zeros and integer division.

   Use3: Subarray XOR ( ^ )
     - Build prefix XOR array ps:
       ps[0] = arr[0];
       for (int i = 1; i < n; ++i)
           ps[i] = ps[i-1] ^ arr[i];
     - Query XOR in [L, R]:
       --l; --r;
       if (l == 0) xor_val = ps[r];
       else xor_val = ps[r] ^ ps[l-1];

4. Prefix computations on bitwise OR operations:

   - Bitwise OR is NOT invertible like + or ^.
   - You cannot do:
       prefixOR[r] | prefixOR[l-1] 
     to get OR in [l, r].
   - This is because OR accumulates bits irreversibly; bits once set in prefixOR[l-1] can't be "removed" by ORing.
   
   To answer range OR queries:
   - Use Sparse Table or Segment Tree (static or dynamic respectively).
   - Prefix OR arrays only help for queries starting at index 0.

*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5+5;
ll arr[N], ps[N];

int main() {

    int q; cin >> q;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }


    int l,r;
    ll ans = 0;
    
    //sum
    ps[0] = arr[0];
    for(int i=1;i<N;i++) {
        ps[i] = ps[i-1] + arr[i-1];
    }
    
    while(q--) {
        cin >> l >> r;
        --l; --r;
        if(l==0) {
            ans = ps[r];
        } else {
            ans = ps[r] - ps[l-1];
        }
    }
    
    //xor
    ps[0] = arr[0];
    for(int i=1;i<N;i++) {
        ps[i] = ps[i-1] ^ arr[i-1];
    }
    
    while(q--) {
        cin >> l >> r;
        --l; --r;
        if(l==0) {
            ans = ps[r];
        } else {
            ans = ps[r] ^ ps[l-1];
        }
    }
    
    return 0;
}
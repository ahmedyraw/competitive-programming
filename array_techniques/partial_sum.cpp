/*
Partial Sum (Difference Array) Technique

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

3. Partial Sum Variants and Usage:

    Purpose:
        Given an initial array and multiple static range updates** (no interleaved queries),
        efficiently apply all updates and then output the final array.
        (add/subtract the value to the range based on queries)

    Key Idea:
        - Instead of updating every element in [L, R] for each query (which is O(n*q)),
            use a difference array (par[]) to mark increments and decrements at boundaries.
        - After all updates are applied to par[], take the prefix sum of par[] to get the
            total increment at each index.
        - Finally, add this to the original array to get the updated array.

    Algorithm:

        Given:
            - Original array: arr[N]
            - Create difference array: par[N+1] initialized with 0

        (Add +) For each update (L, R, val):
            par[L] += val;
            par[R+1] -= val;

        (Subtract -) For each update (L, R, val):
            par[L] += -val;
            par[R+1] -= -val;

        (XOR ^) For each update (L, R, val):
            par[L] ^= val;
            par[R+1] ^= val;

        (ADD + Subtract -) After processing all updates:
            for i = 1 to N-1:
            par[i] += par[i-1];

        (XOR ^)After processing all updates:
            for i = 1 to N-1:
            par[i] ^= par[i-1];

        Then:
            (ADD + Subtract -) updated_arr[i] = arr[i] + par[i];
            (XOR ^) updated_arr[i] = arr[i] ^ par[i];
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5+5;
ll arr[N], par[N];

int main() {

    //Input
    for(int i=0; i<N; i++) cin >> arr[i];

    //Queries
    int q; cin >> q;
    ll l, r, v;

    //Input queries and implement difference array par updates
    while(q--) {
        cin >> l >> r >> v;
        par[l] += v;
        par[r+1] -= v;
    }

    //Prefix sum on difference array par
    for(int i=1; i<N; i++) {
        par[i] += par[i-1];
    }

    //Answer: new array after updates arr[i] + par[i]
    for(int i=0; i<N; i++) {
        cout << arr[i] + par[i] << " ";
    }
    
    return 0;
}
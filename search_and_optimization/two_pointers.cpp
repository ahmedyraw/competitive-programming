/*
Two Pointers Method
-------------------
Definition:
- Technique where two indices (pointers) traverse arrays/lists to solve problems efficiently without nested loops.

Time Complexity:
- O(n + m) for arrays of length n and m.

Uses:
- Merging sorted arrays
- Finding pairs with a given sum
- Sliding window problems
- Counting elements under certain constraints
- Removing duplicates in sorted arrays

Algorithm Template:
1. Initialize pointers i, j (usually at start or ends).
2. Move one or both pointers based on comparison/condition.
3. Stop when one pointer goes out of range.

Template:
while (i < n && j < m) {
    if (condition) {
        // process i
        i++;
    } else {
        // process j
        j++;
    }
}
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
Merge Two Sorted Arrays:
- Compare front elements of both arrays, push smaller to result, move its pointer.
*/
namespace MergeTwoSortedArrays {
    const int N = 1e5+5;
    int n, m;
    ll a[N], b[N];

    void solve() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> n >> m;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<m; i++) cin >> b[i];

        int p1=0, p2=0;
        while(p1<n || p2<m) {
            if(p1>=n) {
                for(int i=p2; i<m; i++)
                    cout << b[i] << ' ';
                break;
            }
            if(p2>=m) {
                for(int i=p1; i<n; i++)
                    cout << a[i] << ' ';
                break;
            }
            if(a[p1] < b[p2]) {
                cout << a[p1++] << ' ';
            } else {
                cout << b[p2++] << ' ';
            }
        }
    }
}

/*
Number of Smaller Elements (Binary Search version):
- For each b[j], count how many elements in a[] are smaller.
*/
namespace NumberOfSmaller {
    const int N = 1e5+5;
    int n, m;
    ll a[N], b[N];

    void solve() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> n >> m;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<m; i++) {
            cin >> b[i];
            cout << lower_bound(a, a+n, b[i]) - a << ' ';
        }
    }
}

int main() {
    // MergeTwoSortedArrays::solve();
    // NumberOfSmaller::solve();
    return 0;
}
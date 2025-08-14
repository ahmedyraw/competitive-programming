/*
Binary Search in C++
====================

Definition:
-----------
Binary search is an efficient algorithm for finding the position of a target
element in a sorted sequence by repeatedly halving the search range.

Complexity:
-----------
- Time: O(log n) per query
- Space: O(1) extra memory

Summary:
--------
- Works only on sorted data (ascending order here).
- Can be used for exact searches, finding bounds, counting elements in a range,
  and solving monotonic equations.
- Common in competitive programming for fast query-based problems.

Hints:
------
- Always ensure the array is sorted before searching.
- Use `l + (r - l) / 2` to avoid integer overflow in midpoint calculation.
- Handle cases where the target is smaller than all elements or larger than all elements.
- STL shortcuts:
    * `lower_bound(begin, end, x)`  → first index where value ≥ x
    * `upper_bound(begin, end, x)`  → first index where value > x

Functions in this file:
-----------------------
1) binarySearch(a, x)       → exact match index (or n+1 if not found)
2) closestLeft(a, x)        → index of largest value ≤ x (or n+1 if none)
3) closestRight(a, x)       → index of smallest value ≥ x (or n+1 if none)
4) countInRange(a, L, R)    → number of elements in [L, R]
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
int n, k;
ll arr[N], value;

// -------------------------------------------------------------
// 1) Exact match search
// -------------------------------------------------------------
ll binarySearch(ll x) {
    int mid, l = 0, r = n - 1;
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// -------------------------------------------------------------
// 2) Closest to left using upper_bound
// -------------------------------------------------------------
int closestLeft(ll x) {
    int idx = upper_bound(arr, arr + n, x) - arr;
    if (idx == 0) return -1;
    return idx - 1;
}

// -------------------------------------------------------------
// 3) Closest to right using lower_bound
// -------------------------------------------------------------
int closestRight(ll x) {
    int idx = lower_bound(arr, arr + n, x) - arr;
    if (idx == n) return -1;
    return idx;
}

// -------------------------------------------------------------
// 4) Count numbers in range [L, R]
// -------------------------------------------------------------
int countInRange(int L, int R) {
    int left_idx = lower_bound(arr, arr + n, L) - arr;
    int right_idx = upper_bound(arr, arr + n, R) - arr;

    if (left_idx == n) return 0;

    if (right_idx == n) --right_idx;
    else if (arr[right_idx] > R) --right_idx;

    return right_idx - left_idx + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
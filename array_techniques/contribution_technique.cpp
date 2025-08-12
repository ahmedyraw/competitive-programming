/*
Contribution Technique

    Purpose:
    --------
    Efficiently solve problems related to subarrays, especially counting how many subarrays
    satisfy certain conditions or computing sums/statistics over subarrays.

    Core Idea:
    ----------
    - Avoid explicitly checking every subarray (which is often O(n²) or O(n³)).
    - Use prefix sums to represent subarray sums as differences of prefix sums.
    - Maintain a frequency map of prefix sums seen so far.
    - For each prefix sum, calculate how many previous prefix sums can pair with it
      to satisfy the problem's condition.
    - Increment counts accordingly, often achieving O(n) or O(n log n) complexity.

    Why use it?
    -----------
    - Naive solutions that check all subarrays are too slow.
    - The technique efficiently counts subarrays matching criteria like:
        • Sum equals X
        • Sum divisible by a number
        • Problems related to maximum subarray sums (Kadane’s algorithm is related)

    Example:
    --------
    Count subarrays whose sum equals X.

    - Let ps[i] = sum(arr[0..i])
    - Subarray sum arr[l..r] = ps[r] - ps[l-1]
    - For fixed r, count how many l satisfy ps[r] - ps[l-1] = X
    - Rearranged: ps[l-1] = ps[r] - X
    - Use a frequency map to count occurrences of ps[l-1] as you iterate

    Complexity:
    -----------
    - Usually O(n) with hash maps (unordered_map)
    - Sometimes O(n log n) with balanced trees (map)

    Notes:
    ------
    - Often combined with prefix sums, coordinate compression, Kadane’s algorithm.
    - Works well with large sums and constraints due to prefix sum hashing.
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5+5;
ll arr[N], ps[N];

int main() {

    int n; cin >> n;
    ll x; cin >> x;

    for(int i = 0; i < n; i++) cin >> arr[i];

    ps[0] = arr[0];
    for(int i = 1; i < n; i++) ps[i] = ps[i-1] + arr[i];

    // ps[i] - ps[w] = x --> ps[w] = ps[i] - x
    // We search for prefix sums equal to (ps[i] - x) in previously seen prefix sums.

    map<ll, ll> frq;
    ll ans = 0;

    // Count empty prefix sum occurrence for subarrays starting at index 0
    // When l = 0
    ++frq[0];

    for(int i = 0; i < n; ++i) {
        ll searchValue = ps[i] - x;
        ans += frq[searchValue];  // Add how many prefix sums match the required value, **seen so far**
        ++frq[ps[i]];             // Register current prefix sum
    }

    cout << ans << '\n';

    return 0;
}
/*
Sliding Window Technique
------------------------
Definition:
- A method to maintain and update information about a subarray (window) that moves
  across the array, expanding or shrinking based on a condition.
- Maintain a left (l) and right (r) pointer to represent a subarray (segment).
- Move pointers to maintain certain sum constraints.

Time Complexity:
- O(n) for all problems here (each pointer moves at most n times).

Uses:
- Finding longest/shortest subarray meeting sum constraints.
- Counting segments with sum ≤ or ≥ a given value.
- Problems involving sliding window sums.

General Template:
sum = 0, l = 0
for r in [0..n-1]:
    sum += a[r]
    while condition fails:
        sum -= a[l++]
    // process segment info
*/

/* A. Segment with Small Sum
   Find longest subarray with sum ≤ s.
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

namespace LongestSmallSum {
    const int N = 1e5+5;
    int n;
    ll sum, s, a[N];

    void solve() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> n >> s;
        for (int i = 0; i < n; i++) cin >> a[i];

        int ans = 0, l = 0;
        for (int r = 0; r < n; r++) {
            sum += a[r];
            while (sum > s) sum -= a[l++];
            ans = max(ans, r - l + 1);
        }
        cout << ans << '\n';
    }
}

/* B. Segment with Big Sum
   Find shortest subarray with sum ≥ s.
   (Two slightly different implementations shown)
*/

namespace ShortestBigSum {
    const int N = 1e5+5;
    int n;
    ll sum, s, a[N];

    void solve() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> n >> s;
        for (int i = 0; i < n; i++) cin >> a[i];

        int ans = INT_MAX, l = 0;
        for (int r = 0; r < n; r++) {
            sum += a[r];
            while (sum >= s) {
                ans = min(ans, r - l + 1);
                sum -= a[l++];
            }
        }
        cout << (ans == INT_MAX ? -1 : ans) << '\n';
    }
}

/* C. Number of Segments with Small Sum
   Count subarrays with sum ≤ s.
*/
namespace CountSmallSum {
    const int N = 1e5+5;
    int n;
    ll sum, s, a[N];

    void solve() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> n >> s;
        for (int i = 0; i < n; i++) cin >> a[i];

        ll l = 0, cnt = 0;
        for (ll r = 0; r < n; r++) {
            sum += a[r];
            while (sum > s && l <= r) sum -= a[l++];
            cnt += (r - l + 1);
        }
        cout << cnt << '\n';
    }
}

/* D. Number of Segments with Big Sum
   Count subarrays with sum ≥ s.
*/
namespace CountBigSum {
    const int N = 1e5+5;
    int n;
    ll sum, s, a[N];

    void solve() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> n >> s;
        for (int i = 0; i < n; i++) cin >> a[i];

        ll l = 0, cnt = 0;
        for (ll r = 0; r < n; r++) {
            sum += a[r];
            while (sum >= s && l <= r) sum -= a[l++];
            cnt += (r - l + 1);
        }
        ll total = 1LL * n * (n + 1) / 2;
        cout << total - cnt << '\n';
    }
}

int main() {
    // Uncomment to run:
    // LongestSmallSum::solve();
    // ShortestBigSum::solve();
    // CountSmallSum::solve();
    // CountBigSum::solve();
    return 0;
}
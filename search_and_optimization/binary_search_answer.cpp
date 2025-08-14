/*
Binary Search for Answer — Template
====================================================================

Pattern:
- We have a monotone function f(x) that returns 1 if x is "good", 0 if "bad".
- If x is good → all numbers > x are good.
- Goal: find minimum good number (or maximum depending on problem).

Steps:
1. Set l = initial bad number, r = initial good number.
2. While l and r are not adjacent (integer) OR for fixed iterations (real numbers):
    a. m = l + (r-l)/2
    b. If f(m) is good → r = m
    c. Else → l = m
3. Return r (min good) or l/r depending on problem.
4. For real numbers, stop after fixed iterations or precision.

Notes:
- Complexity: O(log(Range) * T(f)) for integers, O(log(Range/eps) * T(f)) for real numbers.
- T(f) = complexity of function f(x).
- Works for:
  * Summation equations
  * Maximum median
  * Minimum square side length for rectangles
  * Rope cutting / max length
*/

// ==================== Binary Search for Answer Template ====================
// Pattern:
// - Function f(x) returns 1 if x is "good", 0 if "bad"
// - Monotone: if x is good → x+1, x+2, ... are good
// - Goal: find minimum good (or maximum depending on problem)
// - Integer numbers → l, r adjacent
// - Real numbers → loop fixed iterations or until precision reached
// ============================================================================

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;


// ---------------- Sample 1: Summation Equation ----------------
namespace Summation {
    __int128 read() {
        __int128 x = 0, f = 1;
        char ch = getchar();
        while (ch < '0' || ch > '9') {
            if (ch == '-') f = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9') {
            x = x * 10 + ch - '0';
            ch = getchar();
        }
        return x * f;
    }

    void print(__int128 x) {
        if (x < 0) { putchar('-'); x = -x; }
        if (x > 9) print(x / 10);
        putchar(x % 10 + '0');
    }

    bool cmp(__int128 x, __int128 y) { return x > y; }

    //F(x)
    bool can(__int128 mid, __int128 n) {
        __int128 sum = mid * (mid+1) / 2;
        return sum <= n;
    }

    void solve() {
        __int128 n = read(), ans=LLONG_MIN;
        __int128 l=1, r=n, mid;
        while (l<=r) {
            mid = l+(r-l)/2;
            if(can(mid, n)) {
                l = mid+1;
                if(cmp(mid, ans)) ans = mid;
            } else {
                r = mid-1;
            }
        }
        print(ans);
        putchar('\n');
    }
}

// ---------------- Sample 2: Maximum Median ----------------
namespace MaxMedian {
    const int N = 2e5 + 5;
    ll a[N], n, k;

    //F(x)
    bool can(ll mid) {
        ll sum=0;
        for(int i=n/2; i<n; ++i) {
            if(a[i]<mid) sum += mid - a[i];
        }
        return sum<=k;
    }

    void solve() {
        cin >> n >> k;
        for(int i=0; i<n; i++) cin >> a[i];
        sort(a, a+n);
        ll mid, l=a[n/2], r=a[n/2]+k, ans=a[n/2];
        while(l<=r) {
            mid = l+(r-l)/2;
            if(can(mid)) {
                ans = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        cout << ans << '\n';
    }
}

// ---------------- Sample 3: Minimum side length of square ----------------
namespace MinSquare {
    ll w, h, n;

    //F(x)
    ll can(ll m) {
        ll siz = (m/h) * (m/w);
        return siz >= n;
    }

    void solve() {
        cin >> w >> h >> n;
        ll ans = LLONG_MAX, m, l = 0, r = 1;
        while(!can(r)) r*=2;
        while(l<=r) {
            m = l+(r-l)/2;
            if(can(m)) r = m;
            else l = m;
        }
        cout << r << '\n';
    }
}

// ---------------- Sample 4: Ropes (real numbers) ----------------
namespace Ropes {
    const int N = 1e5+5;
    int n, k;
    ld a[N];

    //F(x)
    bool can(ld m) {
        ld sum = 0;
        for(int i=0; i<n; ++i) sum += floor(a[i]/m);
        return sum >= k;
    }

    void solve() {
        cin >> n >> k;
        for(int i=0; i<n; ++i) cin >> a[i];
        ld l=0, r=1e8, m;
        int iterations = 100;
        while(iterations-- && l<=r) {
            m = l+(r-l)/2;
            if(can(m)) l = m;
            else r = m;
        }
        cout << fixed << setprecision(20) << l << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Call the sample you want to test:
    // Summation::solve();
    // MaxMedian::solve();
    // MinSquare::solve();
    // Ropes::solve();

    return 0;
}
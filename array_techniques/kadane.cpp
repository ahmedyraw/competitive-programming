/*
Kadane's Algorithm

    Purpose:
    --------
    Find the maximum sum of a contiguous subarray within a one-dimensional array of numbers.
    This problem is a classic in dynamic programming and is often asked in competitive programming.

    Key Idea:
    ---------
    - Iterate through the array while maintaining a running sum of the current subarray.
    - If the running sum becomes negative, reset it to zero because any subarray starting with a negative sum 
      will not help maximize the total sum.
    - Keep track of the maximum sum encountered so far.

    Complexity:
    -----------
    - Time: O(n), where n is the length of the array.
    - Space: O(1) additional space.

    Variants:
    ---------
    1) Basic Kadane:
        - Returns the maximum subarray sum.
        - Resets sum to zero when it becomes negative.

    2) Kadane with prefix sums and minimum prefix:
        - Keeps track of the minimum prefix sum to calculate the max subarray sum as current_sum - min_prefix_sum.
        - Can handle arrays with all negative numbers by initializing ans with LLONG_MIN.

    3) Extended Kadane:
        - Returns not only the max sum, but also the starting and ending indices of the subarray.
        - Keeps temporary start index updated when sum resets.

    Example:
    --------
    Input:  [1, 2, -6, 10, -5, 50, -1]
    Output: Max sum = 54 (from subarray [10, -5, 50, -1])
    Indices: 3 to 6

    Usage:
    ------
    Useful in problems involving:
    - Maximum subarray sums
    - Maximum profit with at most one transaction
    - Variations involving circular arrays, k-constrained subarrays, etc.
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll kadane1() {//O(n) Kadane Algorithm for finding maximum sub-array sum

    int n; cin >> n;
    
    ll sum = 0, ans = LLONG_MIN, mn = 0LL;
    
    for(int i=0; i<n; ++i) {
        ll a; cin >> a;
        sum += a;
        ans = max(ans, sum-mn);
        mn = min(mn, sum);
    }
    
    return ans;
}

ll kadane2(const std::vector<ll>& v) {
    
    ll sum = 0, ans = LLONG_MIN;

    for(auto i : v) {
        sum += i;
        
        if(sum > ans) {
            ans = sum;
        }
        
        if(sum < 0LL) sum = 0LL;
    }
    
    return ans;
}

tuple<ll, int, int> extendedKadaneWithIndices(const std::vector<ll>& v) {

    int n = v.size();
    ll sum = 0, ans = LLONG_MIN;
    int temp=0, l=0, r=-1;

    for(int i=0; i<n; ++i) {
        sum += v[i];
        
        if(sum > ans) {
            ans = sum;
            l = temp;
            r = i;
        }
        
        if(sum < 0LL) {
            sum = 0LL;
            temp = i+1;
        }
    }
    
    return {ans,l,r};
}

//Reference Problem:
//https://cses.fi/problemset/task/1643
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> v = {1,2,-6,10,-5,50,-1};
    auto [ans,l,r] = extendedKadaneWithIndices(v);
    cout << ans << '\n';
    cout << l << ' ' << r << '\n';
    
    return 0;
}
/*
Kadane Algorithm
    use: Find the maximum sum of a contiguous subarray within a one-dimensional array of numbers.
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//problem link:
//https://cses.fi/problemset/task/1643

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> v = {1,2,-6,10,-5,50,-1};
    auto [ans,l,r] = extendedKadaneWithIndices(v);
    cout << ans << '\n';
    cout << l << ' ' << r << '\n';
    
    return 0;
}
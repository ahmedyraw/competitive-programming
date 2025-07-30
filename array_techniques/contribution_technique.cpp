/*
Contribution Technique
    use: solve problem related to sub-arrays.
    use: It revolves around the idea of counting how many subarrays
    contribute to a certain result by preprocessing
    and using prefix sums and frequency maps, instead of explicitly checking every subarray.
    example: count sub-arrays that's satisfy the condition.
    hint: How many previous prefix sums could combine with the current one to give me the answer I need?
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all() st.begin(), st.end();

//problem link:
//https://cses.fi/problemset/task/1661
void sol1() {//O(n^3)
    int n,x; cin >> n >> x;
    ll arr[n];
    
    for(int i=0; i<n; ++i) cin >> arr[i];
    
    ll ans = 0;
    for(int i=0; i<n; ++i) {
        for(int j=i; j<n; ++j) {
            ll sum = 0;
            for(int k=i; k<=j; ++k) {
                sum += arr[k];
            }
            if(sum == x) {
                ++ans;
            }
        }
    }
    
    cout << ans;
}

//problem link:
//https://cses.fi/problemset/task/1661
void sol2() {//O(n^2)
    int n,x; cin >> n >> x;
    ll arr[n], ps[n];
    
    for(int i=0; i<n; ++i) cin >> arr[i];
    
    ll ans = 0;
    
    ps[0] = arr[0];
    for(int i=1; i<n; ++i) {
        ps[i] = ps[i-1] + arr[i];
    }
    
    for(int i=0; i<n; ++i) {
        for(int j=i; j<n; ++j) {
            ll sum = 0;
            if(i==0) sum = ps[j];
            else sum = ps[j] - ps[i-1];

            if(sum == x) {
                ++ans;
            }
        }
    }
    
    cout <<  ans;
}

//problem link:
//https://cses.fi/problemset/task/1661
void sol3() {//O(n) using contribution technique
    int n,x; cin >> n >> x;
    ll arr[n], ps[n];
    
    for(int i=0; i<n; ++i) cin >> arr[i];
    
    ll ans = 0;
    map<ll,ll> freq;
    
    ps[0] = arr[0];
    for(int i=1; i<n; ++i) {
        ps[i] = ps[i-1] + arr[i];
    }

    ++freq[0];
    for(int i=0; i<n; ++i) {
        ll searchValue = ps[i] - x;// ps[r] - ps[l-1] == x so ps[l+1] == ps[r] - x so you are searching for ps[r] - x
        ans+=freq[searchValue];
        ++freq[ps[i]];
    }
    
    cout <<  ans;
}

//problem link:
//https://cses.fi/problemset/task/1661
void sol4() {//O(n) using contribution technique

    int n, x; cin >> n >> x;
    
    ll ans = 0, sum = 0;
    map<ll,ll> freq;

    ++freq[0];
    for(int i=0; i<n; ++i) {
        ll a; cin >> a;
        sum += a;
        ll searchValue = sum - x;
        ans+=freq[searchValue];
        ++freq[sum];
    }
    
    cout << ans;
}

//problem link:
//https://cses.fi/problemset/task/1643
void sol5() {//O(n) Kadane Algorithm for finding maximum sub-array sum

    int n; cin >> n;
    
    ll sum = 0, ans = LLONG_MIN, mn = 0LL;
    
    for(int i=0; i<n; ++i) {
        ll a; cin >> a;
        sum += a;
        ans = max(ans, sum-mn);
        mn = min(mn, sum);
    }
    
    cout << ans;
}

//problem link:
//https://cses.fi/problemset/task/1662
void sol6() {

    int n; cin >> n;
    ll arr[n], ps[n];
    map<ll,ll> freq;
    ll ans = 0;

    for(int i=0; i<n; ++i) cin >> arr[i];

    ps[0] = (((arr[0]%n)+n)%n);
    for(int i=1; i<n; ++i) {
        ps[i] = ps[i-1] + arr[i];
        ps[i] = (((ps[i]%n)+n)%n);
    }

    ++freq[0];
    
    for(int i=0; i<n; ++i) {
        ll searchValue = ps[i];// ps[r] - ps[l-1] == 0 so ps[r] == ps[l-1] so you are searching for the same prefix
        ans+=freq[searchValue];
        ++freq[ps[i]];
    }
    
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // sol1();
    // sol2();
    // sol3();
    // sol4();
    // sol5();
    // sol6();
    
    return 0;
}
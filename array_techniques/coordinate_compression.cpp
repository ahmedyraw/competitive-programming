/*
Coordinate Compression

    Why coordinate compression?
    ---------------------------
    When dealing with frequency counts or indexing based on array values, 
    using a direct array is efficient if the values are small or moderate (e.g., up to 1e5 or 1e6).
    - Access and update operations on such arrays take O(1) time.

    But if the values are large (e.g., up to 1e18), 
    using a direct array is impossible due to memory constraints.
    Instead, one might use a map (like std::map or std::unordered_map),
    but map operations take O(log n) time, which may be slower.

    Coordinate compression bridges this gap by:
    - Mapping large values into a smaller continuous range [0..k-1],
      where k is the number of unique values (usually <= n).
    - Then frequency/count arrays or other data structures can be used efficiently.

    Examples:
    1) Original array: {1, 5, 7, 9} 
       Compressed:      {0, 1, 2, 3}

    2) Original array: {1, 1, 5, 15, 17, 17}
       Compressed:      {0, 0, 1,  2,  3,  3}

    Key insight:
    - The exact values are replaced by their ranks or positions after sorting unique elements.
    - The differences between values are not important — only their relative order.

    How to create the compression array?
    ------------------------------------
    Suppose problem array: {1, 2, 1, 3, 1, 5}
    Sorted array:           {1, 1, 1, 2, 3, 5}
    Unique values:          {1, 2, 3, 5}
    
    Assign each original element an ID equal to how many unique numbers are smaller:
    Compressed array:       {0, 1, 0, 2, 0, 3}

    Another concrete example:
    -------------------------
    int arr[] = {10, 50, 30, 50, 10, 30};
    
    vector<int> v(arr,arr+n) // original values
    sort(v.begin(), v.end());                 // v = {10, 10, 30, 30, 50, 50}
    v.erase(unique(v.begin(), v.end()), v.end()); // v = {10, 30, 50}
    
    // Replace each arr[i] by its compressed id (index in v)
    for (int i = 0; i < n; ++i) {
        arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
    }
    // arr becomes: {0, 2, 1, 2, 0, 1}

    // Now, arr holds compressed indices, and v holds the original values for reference.

    Summary:
    --------
    - Use coordinate compression when original values are large but count of distinct values is small.
    - It allows usage of arrays and efficient algorithms where otherwise maps or trees would be required.
    - Typically involves sorting unique values and mapping original values to their rank.
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct coordinateCompression {
private:
    vector<ll> init;
    
    void compress(vector<ll>& v) {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }
    
public:
    coordinateCompression(vector<ll>& v) {
        init = v;
        compress(init);
    }

    //return index
    ll index(ll val) {
        return lower_bound(init.begin(), init.end(), val) - init.begin();
    }

    //return value
    ll initVal(int index) {
        return init[index];
    }
};

//problem link:
//https://codeforces.com/group/9QrbarK7qH/contest/449618/problem/C
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    ll l[n], r[n];
    vector<ll> idx;

    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        idx.push_back(l[i]);
        idx.push_back(r[i]);
    }

    coordinateCompression cc(idx);

    for(int i = 0; i < n; i++) {
        l[i] = cc.index(l[i]);
        r[i] = cc.index(r[i]);
    }

    //partial sum array
    int par[n + n + 1] = {};//2n

    //partial sum algorithm
    for(int i = 0; i < n; i++) {
        ++par[l[i]];
        --par[r[i] + 1];
    }

    //prefix sum on partial sum
    for(int i = 1; i < n+n+1; i++) {
        par[i] += par[i-1];
    }

    //print the maximum element in the whole range
    cout << *max_element(par, par+n+n+1) << '\n';
    
    return 0;
}
/*
n = 3
l r
5 8
2 4
3 9

l = {5, 2 ,3}
r = {8, 4, 9}
idx = {5, 8, 2, 4, 3, 9}

init = {2,3,4,5,8,9} (idx sorted)
init = {2,3,4,5,8,9} (unique)

l = {3, 0, 1}
r = {4, 2, 5}

partial sum array size should be 2n+1 since n represent pairs the +1 for partial sum algorithm
now consider each input line as query of l and r
then apply partial sum

0 0 0 0 0 0 0
0 0 0 1 0 -1 0
1 0 0 0 0 -1 0
1 1 0 0 0 -1 -1

finally apply prefix sum on partial sum array
1 1 0 0 0 -1 -1
1 2 2 2 2 1 0

answer = max element
*/
/*
Coordinate Compression
    frequency:
        array: if the array size is e5 or e6 that is okay
            increment op and access op O(1)
        map: if e18 (long long) you should use map here
            increment op and access op O(log(n))
            
        use: but what if you want to use array for frequency with
        large numbers such as e18? use coordinate compression!

        example1: {1, 5, 7, 9} equal {1, 2, 3, 4}
        example2: {1, 1, 5, 15, 17, 17} equal {1, 1, 2, 3, 4, 4}

        the n (array size) in question = e5 or e6 and numbers range e18,
        so the maximum difference is <= e5 or e6

        the differences are not important!

        how to create compression array?
        example:
        problem array: {1,2,1,3,1,5}
        sorted array: {1,1,1,2,3,5}
        give id for each number that represent how many number are less than it
        compression array: {0,0,0,1,2,3}
        unique compression array: {0,1,2,3}
        now how can we know many numbers are less using the index

        int arr[] = {10,50,30,50,10,30};

        vector<int> v = {10,50,30,50,10,30};//original values
        sort(v.begin(), v.end());// {10,10,30,30,50,50}

        v.erase(unique(v.begin(), v.end()), v.end());// {10,30,50}
        //The bellow loop will assign elements of arr[i] by there id {0,1,2}
        //arr = {0,2,1,2,0,1}
        for(int i=0; i<7; ++i) {
            arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
        }

        for(auto i : arr) {//compressed 
            cout << i << " " << v[i] << endl;
        }

        //arr -> id or index of the original value in v
        //v   -> value
*/

//problem link:
//https://codeforces.com/group/9QrbarK7qH/contest/449618/problem/C
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
    
        ll index(ll val) {
            return lower_bound(init.begin(), init.end(), val) - init.begin();
        }
    
        ll initVal(int index) {
                return init[index];
        }
};

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
/*
Frequency Array
    1- Array for known set
        int freq[N] = {}; ++freq[element];
    2- Map for unknown set
        map<int>mp; ++mp[element];
        
    can be used for:
    1- digits [0-9] arr[10]
    2- small chars [a-z] arr[26]
    3- capital chars [A-Z] arr[26]
    4- mixed-case letters [a-Z] arr[52]
    5- strings (with map)

    hints:
    don't forget to assign freq array by 0, arr = {} or make it global 
    for chars arr[ch-'a'] or arr[ch-'A'], i+'a' or i+'A'
    you can accept number as chars ex: 1230 as '1' '2' '3' '0'
*/

//problem link:
//https://codeforces.com/group/3nQaj5GMG5/contest/372026/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int freq[26] = {};
    int n, k; cin >> n >> k;
    string s; cin >> s;
    bool vis[n] = {};

    for (int i = 0; i < n; i++) ++freq[s[i] - 'a'];

    for(int i=0; i<26; ++i) {
        if(k < 1) break;
        if(freq[i] > k) {
            freq[i] -= k;
            k = 0;
        } else {
            k -= freq[i];
            freq[i] = 0;
        }
    }

    for(int i = n-1; i>=0; --i) {
        if(freq[s[i]-'a']) {
            --freq[s[i]-'a'];
        }
        else
            vis[i] = true;
    }

    for(int i=0; i<n; ++i) {
        if(!vis[i])
            cout << s[i];
    }
    
    return 0;
}
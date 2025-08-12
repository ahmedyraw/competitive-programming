/*
Frequency Array
    use: frequency array counts how many times each possible value appears in your input.
        1- array for known set or small range
            int freq[N] = {}; ++freq[element];
        2- map or unordered_map for unknown set or large range
            map<int>mp; ++mp[element];
        
    can be used for:
        1- digits [0-9] arr[10]
        2- small chars [a-z] arr[26]
        3- capital chars [A-Z] arr[26]
        4- mixed-case letters [a-Z] arr[52]
        5- strings (with map or unordered_map)

    hints:
        1- don't forget to assign freq array by 0, arr = {} or make it global 
        2- for chars arr[ch-'a'] or arr[ch-'A'], i+'a' or i+'A'
        3- you can accept number as chars ex: 1230 as '1' '2' '3' '0'
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;
int freq[N];//Global all values assigned to 0 by default

int main() {


    int num;
    for(int i=0; i<N; i++) {
        cin >> num;
        ++freq[num];
    }
    
    int frq[26]={0};//Local all values assigned to 0
    string s; cin >> s;
    for(int i=0; i<s.length(); i++) {
        frq[s[i]-'a']++;
        //or
        frq[s[i]-'A']++;
    }
    for(int i=0; i<26; i++) {
        cout << char(i+'a') << '\n';
        //or
        cout << char(i+'A') << '\n';
    }

    string arr[N];
    map<string, int> mp;
    unordered_map<string, int> omp;
    for(int i=0; i<N; ++i) {
        cin >> arr[i];
        ++mp[arr[i]];
        // or
        ++omp[arr[i]];
    }
    
    return 0;
}
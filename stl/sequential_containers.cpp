/*
STL Containers:
    1- Sequential Containers
        (array, vector, deque)
        Access: support random access, all elements accessed by index
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all() v.begin(), v.end()

bool compareFun(int& a, int& b) {
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //c-array
        const int N = 5;
        int arr[N];
        
        //call by value
        for(int i=0; i<N; i++) cin >> arr[i];
        //call by reference
        for(auto &it : arr) cin >> it;
        for(int i=0; i<N; i++) scanf("%d", (arr+i));
        for(int i=0; i<N; i++) scanf("%d", &arr[i]);

        //Algorithm Header for STL
        sort(arr, arr+N);//asc
        sort(arr, arr+N, greater<int>());//desc
        reverse(begin(arr), end(arr));
        
        binary_search(arr, arr+N, 9);
        lower_bound(arr, arr+N, 9);
        upper_bound(arr, arr+N, 9);
        equal_range(arr, arr+N, 9);
        
        min_element(arr, arr+N);
        max_element(arr, arr+N);
        minmax_element(arr, arr+N);

    //vector
        //Constructors
        vector<int> v1;//default, use: push_back
        vector<int> v2 = {1,2,6};//initializer list
        vector<int> v3(N);//size, use: default value = 0
        vector<int> v4(N, 5);//fill
        vector<int> v6(v2);//copy, but the same STL container
        vector<int> v7(arr, arr+3);//range, any STL container

        //Vector methods
        vector<int> v;
        
            //Size::int::boolean::void
            v.size();
            v.empty();
            v.swap(v2);
            
            //Access::referenceToElement
            v[0];
            v.at(0);
            v.front();
            v.back();

            //Assignment
            // v.assign({1,2,7});  // initializer list
            // v.assign(N, 5); // N values = 5
            // v.assign(arr, arr+3);   //range
            
            //Insertion::void::iteratorToInsertedElement(insert)
            v.push_back(5);
            v.emplace_back(5);
            // v.insert(v.begin(), {1,2,9});   //postion + initializer list
            // v.insert(v.begin(), 1); //postion + value
            // v.insert(v.begin(), N, 1);  //postion + N values = 1
            // v.insert(v.begin(), arr, arr+3);    //postion + range
            
            //Deletion::void::iteratorToNextElement(erase)
            v.pop_back();
            v.erase(v.begin());//position
            v.erase(v.begin(), v.end());//range
            v.clear();
            
            //Iterators
            v.begin();
            v.end();
            v.rbegin();
            v.rend();

    //Example1: make vector unique, sol 1:sort, 2:unique
    //unique: delete adjacent duplicates in sequence
    sort(all(v));
    v.erase(unique(v.begin(), v.end()), v.end());
    v.erase(unique(all(v)), v.end());

    //Example2: sort using custom compare function
    sort(all(v), compareFun);
    
    //Deque
        //Same Constructors as Vector

        //Deque methods
        deque<int> d;
            //Same as vector, with this additional methods
            d.push_front(5);
            d.emplace_front(5);
            d.pop_front();

    //Array-Class
        //Constructors
        array<int, N> a, a1;
        for(int i=0; i<N; i++) cin >> a[i];

        //Methods
            //Size
            a.size();
            a.empty();
            a.swap(a1);

            //Access
            a[0];
            a.at(0);
            a.front();
            a.back();

            //modify
            a.fill(10);

    //Example: 2 dimensional array
    vector<array<int, N>> va;
    
    return 0;
}
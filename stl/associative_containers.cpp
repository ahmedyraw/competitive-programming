/*
STL Containers:
    3- Associative Containers
        (set, map, multiset, multimap)
        (unordered_set, unordered_map, unordered_multiset, unordered_multimap)
        Set Access: Iterate over all set, doesn't support random access X
        Map Access: support random access + Iterate over all elements
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //set & multiset
        //Properties
        //Fastest STL in insert, delete and search: log(n)
        //Built on self-balancing binary search trees (Red-Black trees)
            //Balanced binary search trees: AVL, Red-Black trees, Splay tree, Treaps tree, B-Trees and Scapegoat
            //Each node has only 2 children
            //Left side: smaller than root, Right side: larger than root
            //Height = O(log N) (largest element)
        //Set: Unique elements, Multiset: Not-Unique
        //Sorted - asc
        //Doesn't support random access X
        //Set vs Multiset: uniqueness is only different
        //Multiset vs Priority_Queue: Multiset you can print it
        //Multiset vs Priority_Queue: Multiset you can delete any element, while Priority_Queue you can only pop the top
        //Min element = *s.begin(), Max element = *--s.end() or *s.rbegin()

        //Constructor
        set<int> s1;    //default
        set<int> s2({1,2,3});    //initializer list
        set<int> s3(s1.begin(), s1.end());    //range
        set<int> s(s1);    //copy

        //Methods
            //Size
            s.size();
            s.empty();
            s.swap(s1);
    
            //Search & Access
            s.count(1);    //  count the value in set (0 or 1 | 0 - N for multi)
            s.find(1);    //  iterator, check (it != s.end())
            s.lower_bound(1);    //  iterator to first element >= 1 or s.end()
            s.upper_bound(1);    //  iterator to first element > 1 or s.end()
            s.equal_range(1);    //  pair<lower_bound(1), upper_bound(1)>
                //Examples
                auto lb = s.lower_bound(25);  // First ≥ 25 → 30
                auto ub = s.upper_bound(30);  // First > 30  → 40
                auto [eq_start, eq_end] = s.equal_range(30); // {30, 40}
            
            //Insertion (iterator indicates position, bool indicates if the element is inserted)
            s.insert(2);    //pair<iterator, bool>
            s.insert(s.begin(),2);    //iterator
            s.emplace(2);    //pair<iterator, bool>
            s.emplace_hint(s.begin(),2);    //iterator
                //Examples:
                auto it1 = s.emplace_hint(s.begin(), 5);
                auto [it2, inserted] = s.emplace(10);
    
            //Deletion
            s.erase(3);    //size_t (0 or 1 | 0 - N for multi)
                //Example1
                size_t c = s.erase(1);
                cout << "Removed = " <<  c << endl;
                //Example2: delete one element in multi not all
                if(s.erase(1) > 0) {
                    auto ite = s.find(3);
                    if(ite != s.end())
                        s.erase(ite); /*or*/ s.erase(s.find(3));
                }
                    
            s.erase(it1);    //iterator ( iterator to the next element after the erased one)
                //Example1
                auto it = s.find(1);
                if(it != s.end())
                    s.erase(it);
                //Example2
                int len = s.size();
                s.erase(it, it1);
                if(s.size() < len) {    //Check if anything was actually deleted
                    
                }

    //map & multimap
        //Dictionary {key, value} 
        //Support Random Access
        //Sorted
        //Have the same constructors and methods as set & multiset

    //unordered_set & unordered_map & unordered_multiset & unordered_multimap)
        //Hash Table based (instead of red-black trees).
        //Average time complexity: O(1) for insert, find, erase, etc. (but worst-case O(n) due to collisions).
        //Not ordered -> Elements are not sorted.
        //Faster than their ordered counterparts (on average).
        //Have the same constructors and methods as ordered containers
    
    return 0;
}
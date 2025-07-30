/*
STL Containers:
    2- Adapter Containers
        (stack, queue, priority_queue)
        Stack & Priority Queue Access: one element by top()
        Queue Access: two element by front() or back()
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 5;
    int arr[N];

    //stack LIFO
        //Constructor
        stack<int> st1;   //default
        stack<int> st(st1);   //copy

        //Methods
        //Access
        st.top();   //Last added element

        //Size
        st.size();
        st.empty();
        st.swap(st1);

        //Modify
        st.push(3);
        st.emplace(6);
        st.pop();   //pop last added element

    //queue FIFO/LILO
        //Constructor
        queue<int> q1;    //default
        queue<int> q(q1);   //copy

        //Methods
            //Size
            q.size();
            q.empty();
            q.swap(q1);

            //Access
            q.front();
            q.back();

            //Modify
            q.push(3);
            q.emplace(7);
            q.pop();    //pop first added element

    //priority_queue
        //Properties
            //A max-heap by default: the largest element is always on top.
            //A max-heap by default

        //Constructor
        priority_queue<int> pq1;    //default: max-heap
        priority_queue<int, vector<int>, less<int>> pq2;    //default: max-heap
        priority_queue<int, vector<int>, greater<int>> pq3;    //default: min-heap
        priority_queue<int> pq4(arr, arr + N);    //range
        priority_queue<int> pq5(pq1); //copy
        priority_queue<int> pq6; //copy

        //Methods
            //Access
            pq6.top();    //O(1)

            //Size
            pq6.size();
            pq6.empty();
            pq6.swap(pq1);

            //Modify
            pq6.push(3);    //log(n)
            pq6.emplace(6);    //log(n)
            pq6.pop();

        //Exmaple:
            priority_queue<int> pq;
            pq.push(3);
            pq.push(50);
            pq.push(10);

            cout << pq.top() << '\n';   //50

            pq.pop();

            cout << pq.top() << '\n';   //10

    return 0;
}
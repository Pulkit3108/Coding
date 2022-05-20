#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T = 1;
    // cin>>T;
    while (T--)
    {
        int x, y;
        cin >> x >> y;
        // ---------------------------------------------------- MISC ----------------------------------------------------
        // Max
        cout << max(x, y) << endl;
        // Min
        cout << min(x, y) << endl;
        ;
        // Swap
        swap(x, y);
        // Lambda Function
        auto func = [](int x, int y)
        { return x + y; };
        // Pair
        pair<int, int> p;
        p = make_pair(x, y);
        p = {x, y};
        cout << p.first << " " << p.second << endl;

        // --------------------------------------------------- VECTOR ---------------------------------------------------
        vector<int> v;
        // Input
        v.push_back(x);
        // Binary Search
        cout << binary_search(v.begin(), v.end(), x) << endl;
        // Lower Bound
        cout << lower_bound(v.begin(), v.end(), x) - v.begin() << endl;
        // Upper Bound
        cout << upper_bound(v.begin(), v.end(), x) - v.begin() << endl;
        // Reverse
        reverse(v.begin(), v.end());
        // Capacity
        cout << v.capacity() << endl;
        // Rotate
        rotate(v.begin(), v.begin() + 1, v.end());
        // Sort
        sort(v.begin(), v.end());
        // Size
        cout << v.size() << endl;
        // Element At Index
        cout << v.at(2) << endl;
        // Front
        cout << v.front() << endl;
        // Back
        cout << v.back() << endl;
        // Pop Back
        v.pop_back();
        // Clear
        v.clear();
        // Vector Pair
        vector<pair<int, int>> vp = {{x, y}};
        // Iterator
        vector<pair<int, int>>::iterator itv;
        // All of
        cout << all_of(v.begin(), v.end(), [](int x)
                       { return x > 0; })
             << endl;
        // Any of
        cout << any_of(v.begin(), v.end(), [](int x)
                       { return x > 0; })
             << endl;
        // None of
        cout << none_of(v.begin(), v.end(), [](int x)
                        { return x > 0; })
             << endl;
        // ---------------------------------------------------- SET ----------------------------------------------------
        set<int> st;            // Sorted
        unordered_set<int> ust; // Not Sorted
        // Insert
        st.insert(x);
        // Iterator
        set<int>::iterator itSet = st.begin();
        // Count
        cout << st.count(x) << endl;
        // Find
        cout << *st.find(x) << endl;
        // Lower Bound
        cout << *st.lower_bound(3) << endl;
        // -------------------------------------------------- MULTISET --------------------------------------------------
        multiset<int> mst;
        // Insert
        mst.insert(x);
        mst.insert(x);
        // Erase All
        mst.erase(x);
        // ---------------------------------------------------- ARRAY ----------------------------------------------------
        int a[2] = {x, y};
        sort(a, a + 2);
        // Minimum Element
        cout << *min_element(a, a + 2) << endl;
        // Maximum Element
        cout << *max_element(a, a + 2) << endl;
        // Sum
        cout << accumulate(a, a + 2, 0) << endl;
        // Count
        cout << count(a, a + 2, x) << endl;
        // Find
        cout << *find(a, a + 2, x) << endl;
        // -------------------------------------------------- ARRAY (STL) --------------------------------------------------
        array<int, 2> arr = {x, y};
        // Size
        cout << arr.size() << endl;
        // Element At Index
        cout << arr.at(2) << endl;
        // Check Empty
        cout << arr.empty() << endl;
        // First Element
        cout << arr.front() << endl;
        // Last Element
        cout << arr.back() << endl;
        // ---------------------------------------------------- STACK ----------------------------------------------------
        stack<int> s;
        // Push
        s.push(x);
        // Top
        cout << s.top() << endl;
        // Pop
        s.pop();
        // Size
        cout << s.size() << endl;
        // Check Empty
        cout << s.empty() << endl;
        // ---------------------------------------------------- QUEUE ----------------------------------------------------
        queue<int> q;
        // Push
        q.push(x);
        // Size
        cout << q.size() << endl;
        // Front
        cout << q.front() << endl;
        // Pop
        q.pop();
        // ------------------------------------------------- PRIORITY QUEUE -------------------------------------------------
        // Max Heap
        priority_queue<int> pqmx;
        // Min Heap
        priority_queue<int, vector<int>, greater<int>> pqmn;
        // Push
        pqmx.push(x);
        // Size
        cout << pqmx.size() << endl;
        // Top
        cout << pqmx.top() << endl;
        // Pop
        pqmx.pop();
        // Check Empty
        cout << pqmx.empty() << endl;
        // ---------------------------------------------------- DEQUE ----------------------------------------------------
        deque<int> d;
        // Insert
        d.push_back(x);
        // Pop Front
        d.pop_front();
        // Element At Index
        cout << d.at(1) << endl;
        // Front
        cout << d.front() << endl;
        // Back
        cout << d.back() << endl;
        // Check Empty
        cout << d.empty() << endl;
        // Size
        cout << d.size() << endl;
        // Erase
        d.erase(d.begin(), d.begin() + 1);
        // ---------------------------------------------------- MAP ----------------------------------------------------
        map<int, int> mp;            // Sorted
        unordered_map<int, int> ump; // Not Sorted
        ump[x] = y;
        mp.insert({x, y});
        // Find
        auto itr = mp.find(3);
        // Erase
        mp.erase(itr);
        // Count
        mp.count(x);
        // ---------------------------------------------------- LIST ----------------------------------------------------
        list<int> l;
        // Push Back
        l.push_back(x);
        // Push Front
        l.push_front(y);
        // Erase
        l.erase(l.begin());
        // Size
        cout << l.size() << endl;
    }
    return 0;
}

// optimizeSearch2dMatrix

#include <bits/stdc++.h>
#define V 4
// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <map>
// #include <set>
// #include <cmath>
// #include <climits>
// #include <queue>
// #include <stack>
// #include <array>
// #include <unordered_map>
// #include <unordered_set>
// #include "TimerClock.h" // For Performance Monitor
using namespace std;
#define dbg(x) cout << #x << " : " << x << "\n";
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    T element;
    while (is >> element)
    {
        vec.push_back(element);
    }
    return is;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, const map<T, S> &m)
{
    cout << "---- Printing Ordered - Map\nKEY\tVALUE\n";
    for (const auto &it : m)
        os << it.first << "\t" << it.second << "\n";
    return os;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, const unordered_map<T, S> &m)
{
    cout << "---- Printing Unordered - Map\nKEY\tVALUE\n";
    for (const auto &it : m)
        os << it.first << "\t" << it.second << "\n";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &s)
{
    os << "[";
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        os << *it;
        if (next(it) != s.end())
            os << ", ";
    }
    os << "]";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &s)
{
    os << "[";
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        os << *it;
        if (next(it) != s.end())
            os << ", ";
    }
    os << "]";
    return os;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<T, S> &p)
{
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int _val) : val(_val), next(nullptr) {}
};
void AddNode_end(ListNode *&head, int value)
{
    ListNode *newNode = new ListNode(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void _showLinkedList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
void vec_linkedlist(ListNode *&head, vector<int> nums)
{
    for (auto it : nums)
    {
        AddNode_end(head, it);
    }
}
// ------------------------------------------------------------------ solve
int travllingSalesmanProblem(int graph[][V], int s)
{
    vector<int> vertex{};
    for (int i = 0; i < V; i++)
    {
        if (i != s)
            vertex.push_back(i);
    }
    dbg(vertex);
    int min_path = INT_MAX;
    do
    {
        int curr_weight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            curr_weight += graph[k][vertex[i]];
            k = vertex[i];
        }
        curr_weight += graph[k][s];
        min_path = min(curr_weight, min_path);
    } while (next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

void solve()
{
    // cout << "working\n";
    int graph[][V] = {{0, 10, 15, 20},
                      {10, 0, 35, 25},
                      {15, 35, 0, 30},
                      {20, 25, 30, 0}};
    int s = 0;
    // cout << "working \n";
    cout << "--------------- result\n";
    cout << travllingSalesmanProblem(graph, s) << endl;
}
// ------------------------------------------------------------------ main
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
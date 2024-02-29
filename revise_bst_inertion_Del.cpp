// insertion deletion and searching in BST

// Major todo
// --- adding a node iterativily
// --- finding a node iterativily
// ---

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <climits>
#include <queue>
#include <stack>
#include <array>
#include <unordered_map>
#include <unordered_set>
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

/*
									// TODO
	- (done) insertion
    - (done) traversal for checking insertion 
    - level order traversal
	- deletion
*/

class node
{
public:
    int data;
    node *right;
    node *left;

    node(int da) : data(da), right(nullptr), left(nullptr) {}
};
void bst_inOrder_helper(node *root)
{
    if (root == nullptr)
        return;
    bst_inOrder_helper(root->left);
    cout << root->data << " ";
    bst_inOrder_helper(root->right);
}
void bst_inOrder_main(node *root)
{
    bst_inOrder_helper(root);
    cout << "\n";
}
node *add_nodeBST(node *&root, int val)
{
    if (root == nullptr)
        return root = new node(val);
    if (root->data < val)
    {
        return add_nodeBST(root->right, val);
    }
    else
        return add_nodeBST(root->left, val);
}
void bst_vec(node *&root, const vector<int> &nums)
{
    for (auto it : nums)
    {
        cout << "adding node : " << it << "\n";
        add_nodeBST(root, it);
    }
}

bool ans(vector<int> nums)
{
    int low = 0;
    int mid = 1;
    int high = 2;
    while (high < (int)nums.size())
    {
        if (high - low + 1 < 3)
        {
            mid++;
            high++;
        }
        else
        {
            if (nums[low] < nums[high] < nums[mid])
                return true;

            dbg(nums[low]);
            dbg(nums[mid]);
            dbg(nums[high]);

            low++;
            mid++;
            high++;
        }
    }
    return false;
}

// --- main execution
void solve()
{
    vector<int> nums = {1, 2, 3, 4};
    // cin >> nums;
    dbg(nums);
    // // cout << *max_element(nums.begin() + 1, nums.begin() + 4) << "\n";
    // node *root = nullptr;
    // cout << "node created \n";
    // bst_vec(root, nums);
    // bst_inOrder_main(root);
    bool answer = ans(nums);
    dbg(answer);
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
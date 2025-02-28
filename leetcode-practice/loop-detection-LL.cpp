// aggressive cows




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
#define dbg(x) cout <<  #x  << " : " << x << "\n";
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {os << "["; for (int i = 0; i < v.size(); ++i) {os << v[i]; if (i != v.size() - 1)os << ", ";} os << "]"; return os;}
template <typename T>
istream& operator>>(istream& is, vector<T>& vec) {T element; while (is >> element) {vec.push_back(element);} return is;}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& m) {cout << "---- Printing Ordered - Map\nKEY\tVALUE\n"; for (const auto& it : m)os << it.first << "\t" << it.second << "\n"; return os;}
template <typename T, typename S>
ostream& operator<<(ostream& os, const unordered_map<T, S>& m) {cout << "---- Printing Unordered - Map\nKEY\tVALUE\n"; for (const auto& it : m)os << it.first << "\t" << it.second << "\n"; return os;}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {os << "["; for (auto it = s.begin(); it != s.end(); ++it) {os << *it; if (next(it) != s.end())os << ", ";} os << "]"; return os;}
template <typename T>
ostream& operator<<(ostream& os, const unordered_set<T>& s) {os << "["; for (auto it = s.begin(); it != s.end(); ++it) {os << *it; if (next(it) != s.end())os << ", ";} os << "]"; return os;}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& p) {os << "(" << p.first << ", " << p.second << ")"; return os;}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::stack<T>& s) {std::stack<T> temp = s; os << "["; while (!temp.empty()) {os << temp.top(); temp.pop(); if (!temp.empty()) {os << ", ";}} os << "]"; return os;}
// --- Linked list
struct ListNode {int val; ListNode * next; ListNode (int _val) : val(_val), next(nullptr) {}};
void AddNode_end(ListNode *&head, int value) {ListNode *newNode = new ListNode(value); if (head == NULL) {head = newNode; return;} ListNode *temp = head; while (temp->next != NULL) {temp = temp->next;} temp->next = newNode;}
void _showLinkedList(ListNode *head) {while (head != NULL) {cout << head->val << " -> "; head = head->next;} cout << "NULL" << endl;}
void vec_linkedlist(ListNode*&head, vector<int> nums ) {for (auto it : nums) {AddNode_end(head, it);}}
// --- tree
class treenode {public: int val; treenode * right ; treenode * left ; treenode(int da ) : val(da), right(nullptr), left(nullptr) {}};
void bst_traversal_inOrder(treenode * root) {if (root == nullptr) {return;} bst_traversal_inOrder(root->left); cout << root->val << " "; bst_traversal_inOrder(root->right);}
void bst_traversal_postOrder(treenode * root) {if (root == nullptr) {return;} bst_traversal_postOrder(root->left); bst_traversal_postOrder(root->right); cout << root->val << " ";}
void bst_traversal_PreOrder(treenode * root) {if (root == nullptr) {return;} cout << root->val << " "; bst_traversal_PreOrder(root->left); bst_traversal_PreOrder(root->right);}
void bst_levelOrder(treenode * root) {if (root == nullptr) {return;} queue<treenode *> q {}; q.push(root); while (!q.empty()) {int lvl_size = q.size(); for (int i = 0; i < lvl_size; ++i) {treenode * temptreenode = q.front(); cout << temptreenode->val << " "; q.pop(); if (temptreenode->left) {q.push(temptreenode->left);} if (temptreenode->right) {q.push(temptreenode->right);}} cout << "\n";}}
treenode * bst_inserttreenode(treenode * root, int d) {if (root == nullptr) {return root = new treenode(d);} if (root->val > d) {root->left = bst_inserttreenode(root->left, d);} else {root->right = bst_inserttreenode(root->right, d);}}
void bst_vector(treenode * &root, vector<int> nums) {for (int it : nums) {root = bst_inserttreenode(root, it);} cout << "nodes added to bst !\n";}
treenode* createBinaryTree(const vector<int>& vec) {if (vec.empty()) {return nullptr;} treenode* root = new treenode(vec[0]); vector<treenode*> nodes; nodes.push_back(root); for (int i = 1; i < vec.size(); ++i) {treenode* node = nullptr; if (vec[i] != -1) {node = new treenode(vec[i]); nodes.push_back(node);} treenode* parent = nodes[(i - 1) / 2]; if (i % 2 == 1) {parent->left = node;} else {parent->right = node;}} return root;}

// ------------------------------------------------------------------ solve

void linkCreation(ListNode * head, int val){

    ListNode * toBeLinkedNode = head;


    while(toBeLinkedNode->val != val){
        toBeLinkedNode = toBeLinkedNode->next;
    }

    


} 



auto answer(vector<int> nums){
    // vector<int> ans {};
    int ans = 0;  


    ListNode * head = nullptr;

    vec_linkedlist(head, nums);

    _showLinkedList(head);






    
    return ans;


}


void solve() {
    vector<int> nums {};
    cin >> nums;
    dbg(nums);
    cout << "-----------------------\n";
    
    auto ans = answer(nums);
    cout << "-----------------------\n";
    dbg(ans);
}
// ------------------------------------------------------------------ main
int main(int argc, char const* argv[]) {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    // cin >> t;
    while (t--) {solve();}
    return 0;
}
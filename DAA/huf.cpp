// #include <iostream>
// #include <vector>
// #include <string>
// #include <queue>

// using namespace std;

// class Node {
// public:
//     int data;
//     Node *left, *right;

//     Node(int d) {
//         data = d;
//         left = NULL;
//         right = NULL;
//     }
// };

// class Comp {
// public:
//     bool operator()(Node *a, Node *b) {
//         return a->data > b->data;
//     }
// };

// class Solution {
// public:
//     void traverse(Node* root, vector<string>& ans, string temp) {
//         if (root->left == NULL && root->right == NULL) {
//             ans.push_back(temp);
//             return;
//         }
//         traverse(root->left, ans, temp + '0');
//         traverse(root->right, ans, temp + '1');
//     }

//     vector<string> Huffman(string s, vector<int> f, int n) {
//         priority_queue<Node*, vector<Node*>, Comp> pq;

//         for (int i = 0; i < n; i++) {
//             Node *temp = new Node(f[i]);
//             pq.push(temp);
//         }

//         while (pq.size() > 1) {
//             Node *left = pq.top(); pq.pop();
//             Node *right = pq.top(); pq.pop();

//             Node *newNode = new Node(left->data + right->data);
//             newNode->left = left;
//             newNode->right = right;
//             pq.push(newNode);
//         }

//         Node *root = pq.top();
//         vector<string> ans;
//         string temp = "";
//         traverse(root, ans, temp);
//         return ans;
//     }
// };

// int main() {
//     string s = "abcdef";
//     vector<int> frequencies = {5, 9, 12, 13, 16, 45};  // Sample frequencies
//     int n = frequencies.size();

//     Solution solution;
//     vector<string> huffmanCodes = solution.Huffman(s, frequencies, n);

//     cout << "Huffman Codes:" << endl;
//     for (int i = 0; i < huffmanCodes.size(); i++) {
//         cout << s[i] << ": " << huffmanCodes[i] << endl;
//     }

//     return 0;
// }
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

class Node {
public:
    int data;
    char ch;
    Node *left, *right;

    Node(int d, char c = '\0') : data(d), ch(c), left(NULL), right(NULL) {}
};

class Comp {
public:
    bool operator()(Node *a, Node *b) {
        return a->data > b->data;
    }
};

class Solution {
public:
    void traverse(Node* root, unordered_map<char, string>& ans, string temp) {
        if (!root->left && !root->right) { // leaf node
            ans[root->ch] = temp;
            return;
        }
        if (root->left) traverse(root->left, ans, temp + '0');
        if (root->right) traverse(root->right, ans, temp + '1');
    }

    unordered_map<char, string> Huffman(string s, vector<int> f, int n) {
        priority_queue<Node*, vector<Node*>, Comp> pq;

        for (int i = 0; i < n; i++) {
            Node *temp = new Node(f[i], s[i]);
            pq.push(temp);
        }

        while (pq.size() > 1) {
            Node *left = pq.top(); pq.pop();
            Node *right = pq.top(); pq.pop();

            Node *newNode = new Node(left->data + right->data);
            newNode->left = left;
            newNode->right = right;
            pq.push(newNode);
        }

        Node *root = pq.top();
        unordered_map<char, string> ans;
        traverse(root, ans, "");
        return ans;
    }
};

int main() {
    string s = "abcdef";
    vector<int> frequencies = {5, 9, 12, 13, 16, 45};  // Sample frequencies
    int n = frequencies.size();

    Solution solution;
    unordered_map<char, string> huffmanCodes = solution.Huffman(s, frequencies, n);

    cout << "Huffman Codes:" << endl;
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << ": " << huffmanCodes[s[i]] << endl;
    }

    return 0;
}

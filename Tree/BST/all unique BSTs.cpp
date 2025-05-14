#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Insert a value into the BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Clone the tree (to avoid shared pointers)
TreeNode* clone(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* newRoot = new TreeNode(root->val);
    newRoot->left = clone(root->left);
    newRoot->right = clone(root->right);
    return newRoot;
}

// Serialize the tree (to compare structure)
string serialize(TreeNode* root) {
    if (!root) return "#";
    return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}

// Print preorder
void preorder(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> elements(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) cin >> elements[i];

    int rootVal = elements[0];
    vector<int> rest(elements.begin() + 1, elements.end());

    sort(rest.begin(), rest.end());

    vector<TreeNode*> allBSTs;
    set<string> seen;

    do {
        TreeNode* root = new TreeNode(rootVal);
        for (int val : rest) {
            insert(root, val);
        }

        string sig = serialize(root);
        if (seen.count(sig) == 0) {
            allBSTs.push_back(clone(root));
            seen.insert(sig);
        }

        // Clean memory of current tree
        delete root;  // optional if cloning
    } while (next_permutation(rest.begin(), rest.end()));

    cout << "Total unique BSTs with root " << rootVal << ": " << allBSTs.size() << endl;

    for (int i = 0; i < allBSTs.size(); ++i) {
        cout << "Tree " << i + 1 << ": ";
        preorder(allBSTs[i]);
        cout << endl;
    }

    return 0;
}

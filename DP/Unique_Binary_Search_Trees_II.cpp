#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    public:
          int val;
          TreeNode *left;
          TreeNode *right;
          TreeNode() : val(0), left(nullptr), right(nullptr) {}
          TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
          TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 vector<TreeNode*>allPossible(int start,int end)
 {

     if(start >end)
       return {0};
     if(start == end)
       return {new TreeNode(start)};  
     vector<TreeNode*>ans;
     for(int i=start;i<=end;i++)//sbko root bnao
     {
         vector<TreeNode*>left = allPossible(start,i-1);//leftPossible nikalo
         vector<TreeNode*>right = allPossible(i+1,end);//rightPossible nikalo
         for(int j=0;j<left.size();j++)//left and right all combination nikalo jo possible ho
         {
             for(int k=0;k<right.size();k++)
             {
                 TreeNode* root = new TreeNode(i);
                 root->left = left[j];
                 root->right = right[k];
                 ans.push_back(root);
             }
         }
     }
     return ans;
 }
 void printTree(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

// Function to print all trees generated
void printTrees(vector<TreeNode*> trees) {
    int count = 1;
    for (TreeNode* tree : trees) {
        cout << "Tree " << count++ << ": ";
        printTree(tree);
        cout << endl;
    }
}
 vector<TreeNode*> generateTrees(int n) {
     if(n == 0)
       return {};
     return allPossible(1,n);  
 }
int main()
{
    int n;
    cout << "Enter the value of n : "<< endl;
    cin >> n;
    vector<TreeNode*>ans = generateTrees(n);
    printTrees(ans);
    return 0;
}
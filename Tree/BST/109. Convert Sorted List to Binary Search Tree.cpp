/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    int getLength(ListNode* &head)
    {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL)
        {
            cnt++;
            temp = temp->next;

        }
        return cnt;

    }
    TreeNode* solve(ListNode* &head,int n)
    {
        if(head == NULL || n <= 0) 
            return NULL;
        //LNR
        TreeNode* LeftSubTree = solve(head,n/2);//L
        TreeNode* root = new TreeNode(head->val);//N  Head mid pe khada hai
        root->left = LeftSubTree;
        head = head->next;//head mid pe khada hai usse aage bdhao
        TreeNode* rightSubTree = solve(head,n-n/2-1);//R
        root->right = rightSubTree;
        return root;   
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n = getLength(head);
        TreeNode* root = solve(head,n);
        return root;
    }
};
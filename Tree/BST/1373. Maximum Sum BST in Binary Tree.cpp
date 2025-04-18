class Info{
    public:
      int minVal;
      int maxVal;
      int sum;
      bool isBST;
      
}; 
class Solution {
public:
    int minCal(int a,int b,int c)
    {
        int minAns = min(a,min(b,c));
        return minAns;
    }
    int maxCal(int a,int b,int c)
    {
        int maxAns = max(a,max(b,c));
        return maxAns;
    }
    Info solve(TreeNode* root,int &sum)
    {
        if(root == NULL)
        {
            Info temp;
            temp.minVal = INT_MAX;
            temp.maxVal = INT_MIN;
            temp.sum = 0;
            temp.isBST = true;
            sum = max(sum,temp.sum);
            return temp;
        }
        Info leftAns = solve(root->left,sum);//L
        Info rightAns = solve(root->right,sum);//R
        //N
        Info currAns;
        currAns.minVal = minCal(leftAns.minVal,rightAns.minVal,root->val);
        currAns.maxVal = maxCal(leftAns.maxVal,rightAns.maxVal,root->val);
        currAns.sum = leftAns.sum + rightAns.sum + root->val;
        currAns.isBST =(root->val > leftAns.maxVal && root->val < rightAns.minVal && leftAns.isBST && rightAns.isBST);
        if(currAns.isBST)
        {
            sum  = max(sum,currAns.sum);
        }
        return currAns;
        

    }
    int maxSumBST(TreeNode* root) {
        int sum = 0;
        Info tree = solve(root,sum);
        return sum;
    }
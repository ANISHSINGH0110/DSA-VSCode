void solve(Node* root,Node* &head)
{
    if(root == NULL)
        return;
    solve(root->right,head);
    root->right = head;
    if(head != NULL)
        head->left = root;
    head = root;
    solve(root->left,head);
}
Node* bToDLL(Node* root) {
    // code here
    Node* head = NULL;
    solve(root,head);
    return head;
}
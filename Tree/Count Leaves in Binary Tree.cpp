int count(Node *root){
    if(root == NULL)
        return 0;
        
    if(root->left == NULL && root->right == NULL)
        return 1;
        
    int ls = count(root->left);
    int rs = count(root->right);
    
    return ls + rs;
}
int countLeaves(Node* root)
{
    return count(root);
}

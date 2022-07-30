vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> res;
    if(root == NULL)
        return res;
    queue<Node*> q;
    queue<Node*> qRev;
    q.push(root);
    qRev.push(root);
    int level = 0;
    while(q.size() > 0) {
        
        int size = q.size();
        for(int i = 0; i < size; i++) {
            
            Node *temp = q.front();
            Node *temp1 = qRev.front();
            q.pop();
            qRev.pop();
            
            if(level % 2 == 0){
                res.push_back(temp1->data);
            }else {
                res.push_back(temp->data);
            }
           
            if(temp1->right != NULL) {
                qRev.push(temp1->right);
            }
            if(temp1->left != NULL) {
                qRev.push(temp1->left);
            }
            
            if(temp->left != NULL) {
                q.push(temp->left);
            }
            if(temp->right != NULL) {
                q.push(temp->right);
            }
        }
        level++;
    }
    return res;
    
}

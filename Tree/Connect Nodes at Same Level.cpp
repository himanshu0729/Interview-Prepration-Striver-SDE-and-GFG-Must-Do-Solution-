    void connect(Node *root)
    {
       queue<Node*> q;
       q.push(root);
       while(q.size() > 0) {
           int n = q.size();
           Node *prev = NULL;
           for(int i = 0; i < n; i++) { // Consider each level
               Node *temp = q.front();
               q.pop();
               temp->nextRight = prev;
               prev = temp;
               
               if(temp->right) 
                   q.push(temp->right);
               if(temp->left)
                   q.push(temp->left);
           }
       }
    }    

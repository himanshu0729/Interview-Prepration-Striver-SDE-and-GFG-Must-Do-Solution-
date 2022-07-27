vector<int> leftView(Node *root)
{
   vector<int> res;
   if(root == NULL)
        return res;
   queue<Node*> q;
   q.push(root);
   while(q.size() > 0) {
       int s = q.size();
       for(int i = 0; i < s; i++) {
            Node *node = q.front();
            q.pop();
            if(i == 0) {
                res.push_back(node->data);
            }
            
            if(node->left != NULL) 
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
       }
   }
   return res;
}

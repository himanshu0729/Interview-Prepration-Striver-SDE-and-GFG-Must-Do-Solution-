    void serial(Node *root, vector<int> &res) {
        
        if(root == NULL){
            res.push_back(-1);
            return;
        }
        
        res.push_back(root->data);
        serial(root->left, res);
        serial(root->right, res);
    }
    vector<int> serialize(Node *root) 
    {
        vector<int> res;
        serial(root, res);
        return res;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
        Node *root = NULL;
        int n = A.size();
        if(n == 0)
            return root;
        
        root = new Node(A[0]);
        stack<pair<Node*, int>> s;
        s.push({root, 1});
        int i = 1;
        
        while(s.size() > 0) {
           pair<Node*, int> &t = s.top();
           int state = t.second;
           Node *temp = t.first;
           
           if(state == 1) {
               t.second++;
               if(A[i] != -1) {
                  Node *newNode = new Node(A[i]);
                  temp->left = newNode;
                  s.push({newNode, 1});
               }
               i++;
           }
           else if(state == 2) {
               t.second++;
               if(A[i] != -1) {
                  Node *newNode = new Node(A[i]);
                  temp->right = newNode;
                  s.push({newNode, 1});
               }
               i++;
           }else{
               s.pop();
           }
       }
       return root;
    }

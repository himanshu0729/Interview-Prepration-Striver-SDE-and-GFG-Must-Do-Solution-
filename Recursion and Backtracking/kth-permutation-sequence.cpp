    string res;
    bool allPermutation(string question, string ans, int &pos, int len)
    {
        if(ans.length() == len){
            pos--;
            if(pos == 0){
                res = ans;
                return true;
            }
            return false;
        }
        for(int i = 0; i < question.length(); i++) {
            string left = question.substr(0, i);
            string right = question.substr(i+1);
            if(allPermutation(left+right, ans+question[i], pos, len))
                return true;
        }
        return false;
    }
    string getPermutation(int n, int k) {
        string ques = "";
        for(int i = 1; i <= n; i++) 
            ques += to_string(i);
        allPermutation(ques, "", k, n);
        return res;
    }

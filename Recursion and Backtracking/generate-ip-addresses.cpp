    bool isValid(int s, int e, string str){
        
        for(int i = s; i <= e; i++){
            if(isdigit(str[i]) == 0)
                return false;
        }
        
        if(str[s] == '0')
            return false;
            
        string sNum = str.substr(s, e-s+1);
        int num = stoi(sNum);
        if(num > 255)
            return false;
        
        return true;
    }
    void allIps(int idx, int dots, string temp, vector<string> &res, string str){
        
        if(idx == str.length() && dots == 4){
            temp = temp.substr(0, temp.length()-1);
            res.push_back(temp);
            return;
        }
        
        if(dots > 4)
            return;
            
        allIps(idx+1, dots+1, temp + str[idx] + ".", res, str);
        if(idx + 2 <= str.length() && isValid(idx, idx+1, str))
            allIps(idx+2, dots+1, temp + str.substr(idx, 2) + ".", res, str);
        if(idx + 3 <= str.length() && isValid(idx, idx+2, str))
            allIps(idx+3, dots+1, temp + str.substr(idx, 3) + ".", res, str);
        
    }
    vector<string> genIp(string &s) {
        
        vector<string> res;
        allIps(0, 0, "", res, s);
        return res;
    }

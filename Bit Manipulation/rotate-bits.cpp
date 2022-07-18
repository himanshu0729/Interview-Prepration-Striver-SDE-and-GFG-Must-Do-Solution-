        vector <int> rotate (int n, int d)
        {
            d = d % 16;
            vector<int> res;
            unsigned short int left = n << d | n >> (16-d);
            unsigned short int right = n >> d | n << (16-d);
            res.push_back(left);
            res.push_back(right);
            return res;
        }

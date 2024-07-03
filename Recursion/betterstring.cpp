 void solve(string ip, string op, set<string>& s) {
        if(ip.length() == 0) {
            s.insert(op);
            return;  // Return after inserting into the set
        }
        string op1 = op;
        string op2 = op;
        op1.push_back(ip[0]);
        
        ip.erase(ip.begin());  // Remove the first character
        
        solve(ip, op1, s);
        solve(ip, op2, s);
    }
    
    string betterString(string str1, string str2) {
        string op = "";
        set<string> s1;
        set<string> s2;
        
        solve(str1, op, s1);
        solve(str2, op, s2);
        
        int cnt1 = s1.size();
        int cnt2 = s2.size();
        
        if(cnt1 >= cnt2) {
            return str1;
        } else {
            return str2;
        }
    }
};
class Solution {
public:
    int myAtoi(string s) {
        //TOOK HELP
        int n = s.length();
        int i = 0;
        int sign = 1;
        

        //Remove white space
        while(i<n and s[i]==' ')
         i++;

        // check for negative number
        if(s[i]=='-'){
            sign = -1;
            i++;
        }

        else if(s[i]=='+') i++;

        // Convert String to Integer

         long long ans = 0;

        while(i<n){

            if(s[i]>='0' and s[i]<='9'){
                ans = ans*10 + (s[i]-'0');

                if(ans>INT_MAX and sign==-1) 
                return INT_MIN;

                else if(ans>INT_MAX and sign == 1) 
                return INT_MAX;

                i++;
            }
            else 
            
            return ans*sign;
        }

        return ans*sign;
    }
};
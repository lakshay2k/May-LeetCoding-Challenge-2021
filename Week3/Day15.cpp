class Solution {
public:
    bool isNumber(string s) {

        /*
        we will be checking these conditions one by one based on the boolean expressions
        1. More than one decimal - check if pointpresnt is true
        2. Decimal after e - check if epresent is true
        3. No number before e - check if numberpresent is false or not
        4. More than one e - check if epresent is true o not.
        */

        bool pointpresent = false;
        bool epresent = false;
        bool numberpresent = false;
        bool numberafterE = true;
        
        for(int i =0;i<s.size();i++)
        {
            if('0'<=s[i] && s[i]<='9')
            {
                numberpresent = true;
                numberafterE = true;
            }
            else if(s[i] == '.')
            {
                if(epresent || pointpresent)
                    return false;
                pointpresent = true;
            }
            else if(s[i] == 'e' || s[i] == 'E')
            {
                if(!numberpresent || epresent)
                    return false;
                numberafterE = false;
                epresent = true;
            }
            else if(s[i] == '-' || s[i] == '+')
            {
                if(i!=0 && s[i-1] !='e')
                    return false;
            }
            else 
                return false;
        }

        return numberpresent && numberafterE;
    }
};

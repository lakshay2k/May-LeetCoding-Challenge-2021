class Solution {
public:
    string toLowerCase(string s) {
        
        //creating the result string for upper case
        string resup = "";
        
        //we will check if the given char lies within the ASCII limits of lowercase and then we will add 32 to bring that character to its uppercase.
        for (auto& c : s)
            resup += c > 64 && c < 91 ? c + 32 : c;
        
        return resup;
    }
};
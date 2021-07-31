class WordFilter {
private:

    //creating map for stroing all combinations of prefix and suffix
    unordered_map<string,int> mymap;
    
public:    
    WordFilter(vector<string>& words) {

        //calculating given number of words
        int total = words.size();
       
        for(int i = 0;i < total; i++)
        {
            string word = words[i];
            int sizeofword = word.size();
            
            //this loop is to take all combinations of prefixes
            for(int j = 1; j <= sizeofword; j++)
            {
                string pre = word.substr(0,j);
                
                //this loop is to take all combinations of suffixes
                for(int k = 0; k < sizeofword; k++)
                {
                    string suf = word.substr(k,sizeofword);
                    mymap[pre + "|" + suf] = i+1;  // we are storing 1 more than index (read till last)
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string temp = prefix + "|" + suffix;
        
        //here we are returning -1 because of default case in which we have return -1 
        // acc to map knowledge , if value is not found in map it returns 0 so doing -1;
        //thats why we stored 1 more than the index prior

        return mymap[temp] - 1;
    }
};

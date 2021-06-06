static unordered_set<string> operators({"+", "-", "*", "/"});

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        //creating stack for storing operands while traversing.
        stack<int> mystack;
        
        //traversing every token from tokens vector
        for(auto t: tokens)
        {
            //we convert the operands into integers
            if(operators.find(t) == operators.end())
                mystack.push(stoi(t));
            //we perform operations based on operators.
            else
            {
                //extracting two elements before operators.
                int y = mystack.top();
                mystack.pop();
                int x = mystack.top();
                mystack.pop();
                
                //storing the result of performed operation in top of stack
                if(t == "+")
                    mystack.push(x+y);
                else if(t=="-")
                    mystack.push(x-y);
                else if(t=="*")
                    mystack.push(x*y);
                else
                    mystack.push(x/y);
            }        
        }
        
        //returning the top of stack which contains total result of all operators
        return mystack.top();
    }
};
class Solution {
   private:
    void generateParentheses(int currIndex, string& s, int closing, int opening,
                             vector<string>& ls, int n) {
        // base cases
        if (opening > n)
            return;  // simply means, if more than half the places are filled
                     // with
                     // (, return back the function call and go to the next line
                     // after that in the returned function call
        if (opening + closing == 2*n && opening == closing) {
            ls.push_back(s);
            return;
        }

        // add an opening '('
        s.push_back('(');
        generateParentheses(currIndex + 1, s, closing, opening + 1, ls, n);
        // backtrack by removing the added '('
        s.pop_back();

        // add a closing only if there are more opeing than closing in the
        // current string s
        if (opening > closing) {
            s.push_back(')');
            generateParentheses(currIndex + 1, s, closing + 1, opening, ls, n);
            // backtrack
            s.pop_back();
        }
    }

   public:
    vector<string> generateParenthesis(int n) {
        // your code goes here
        vector<string> ans;
        // generateParentheses(0, "", 0, 0, ans, n); - can't do this since "" is a string literal, it can't be assigned to a string reference
        string s = "";
        generateParentheses(0, s, 0, 0, ans, n);
        return ans;
    }
};
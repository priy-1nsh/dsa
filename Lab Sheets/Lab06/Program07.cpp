#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodedString(string s)
{

    stack<int> numStack;   // Stack to store repetition counts
    stack<char> charStack; // Stack to store characters

    for (int i = 0; i < s.length(); i++)
    {

        // Case 1: If current character is a digit
        if (isdigit(s[i])) {
            int cnt = s[i] - '0';   // single digit only
            numStack.push(cnt);
        }

        // Case 2: If closing bracket is found
        else if (s[i] == ']')
        {

            string temp = "";

            // Pop characters until '[' is found
            while (!charStack.empty() && charStack.top() != '[')
            {
                temp = charStack.top() + temp;
                charStack.pop();
            }

            // Remove the '[' from stack
            if (!charStack.empty())
                charStack.pop();

            // Get repetition count
            int repeat = numStack.top();
            numStack.pop();

            // Repeat the substring
            string expanded = "";
            for (int j = 0; j < repeat; j++)
            {
                expanded += temp;
            }

            // Push expanded string back into char stack
            for (char c : expanded)
            {
                charStack.push(c);
            }
        }

        // Case 3: If letter or '['
        else
        {
            charStack.push(s[i]);
        }
    }

    // Final result construction
    string result = "";
    while (!charStack.empty())
    {
        result = charStack.top() + result;
        charStack.pop();
    }

    return result;
}

int main()
{
    int N;
    cin >> N; // Size (not strictly needed but required by problem)

    string s;
    cin >> s; // Encoded string

    cout << decodedString(s) << endl;

    return 0;
}

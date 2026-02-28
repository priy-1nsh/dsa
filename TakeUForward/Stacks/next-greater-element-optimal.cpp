class Solution
{
public:
    vector<int> nextLargerElement(vector<int> arr)
    {
        // I have to find the nextLargerElement
        int n = arr.size();
        vector<int> nge(n);
        stack<int> st; // monotonic stack
        for (int i = n - 1; i >= 0; i--)
        {
            // I want the element on the top of the stack to be
            // greater than the current element arr[i]
            // pop the elements out of the stack until either it's
            // empty or elt at the top <= the arr[i]
            while (!st.empty() && st.top() <= arr[i])
            {
                st.pop(); // maintains the top element to be the max in the stack
            }
            if (st.empty())
            {
                // if the stack is empty
                nge[i] = -1; // stack is empty, no elt > arr[i]
            }

            else
            {
                nge[i] = st.top();
                // if the stack is non-empty then the top elt is > arr[i]
            }
            st.push(arr[i]); // push element in the stack
        }
        return nge;
    }
};

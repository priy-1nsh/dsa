class Solution
{
private:
    bool isLeader(vector<int> &arr, int curr, int n)
    {
        for (int i = curr + 1; i < n; i++)
        {
            if (arr[curr] <= arr[i])
                return false;
        }
        return true;
    }

public:
    vector<int> leaders(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> leaders;
        for (int i = 0; i < n - 1; i++)
        {
            if (isLeader(nums, i, n))
            {
                leaders.push_back(nums[i]);
            }
        }
        leaders.push_back(nums[n - 1]); // last element of the array is always the leader
        return leaders;
    }
};

// TC - O(n2) - gives TLE
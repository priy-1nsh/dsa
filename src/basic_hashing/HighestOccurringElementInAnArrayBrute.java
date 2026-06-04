package basic_hashing;

class HighestOccurringElementInAnArrayBrute {
    /*
     * Function to get the highest
     * occurring element in array nums
     */
    public int mostFrequentElement(int[] nums) {

        // Variable to store the size of array
        int n = nums.length;

        // Variable to store maximum frequency
        int maxFreq = 0;

        /*
         * Variable to store element
         * with maximum frequency
         */
        int maxEle = 0;

        // Visited array
        boolean[] visited = new boolean[n];

        // First loop
        for (int i = 0; i < n; i++) {
            // Skip second loop if already visited
            if (visited[i])
                continue;

            /*
             * Variable to store frequency
             * of current element
             */
            int freq = 0;

            // Second loop
            for (int j = i; j < n; j++) {
                if (nums[i] == nums[j]) {
                    freq++;
                    visited[j] = true;
                }
            }

            /*
             * Update variables if new element having
             * highest frequency is found
             */
            if (freq > maxFreq) {
                maxFreq = freq;
                maxEle = nums[i];
            } else if (freq == maxFreq) {
                maxEle = Math.min(maxEle, nums[i]);
            }
        }

        // Return the result
        return maxEle;
    }

    public static void main(String[] args) {
        int[] nums = { 4, 4, 5, 5, 6 };

        /*
         * Creating an instance of
         * Solution class
         */
        HighestOccurringElementInAnArrayBrute sol = new HighestOccurringElementInAnArrayBrute();

        /*
         * Function call to get the
         * highest occurring element in array nums
         */
        int ans = sol.mostFrequentElement(nums);

        System.out.println("The highest occurring element in the array is: " + ans);
    }
}

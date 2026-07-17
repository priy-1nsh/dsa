int minimumLoss(vector<long> arr) {
    long long n = arr.size();
    set<long long> st;
    long long minLoss = LLONG_MAX;
    for (long long i = 0; i < n; i++) {
        auto it = st.upper_bound(arr[i]);
        if (it != st.end()) {
            // found it
            minLoss = min(minLoss, *it - arr[i]);
        }
        st.insert(arr[i]);
    }
    return minLoss;
}
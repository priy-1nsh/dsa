
bool isValidWindow(vector<int>& windowFreq, vector<int>& totalFreq, int n) {
    // find the outside frequency
    int divisor = n / 4;
    if ((totalFreq['A'] - windowFreq['A'] <= divisor) &&
        (totalFreq['C'] - windowFreq['C'] <= divisor) &&
        (totalFreq['G'] - windowFreq['G'] <= divisor) &&
        (totalFreq['T'] - windowFreq['T'] <= divisor)) {
        return true;
    }
    return false;
}

int steadyGene(string gene) {
    int minLen = INT_MAX;
    int n = gene.length();
    vector<int> totalFreq(256, 0);
    for (int i = 0; i < n; i++) {
        totalFreq[gene[i]]++;
    }
    int divisor = n / 4;
    if (totalFreq['A'] == divisor && totalFreq['G'] == divisor &&
        totalFreq['C'] == divisor && totalFreq['T'] == divisor)
        return 0;
    vector<int> windowFreq(256, 0);
    int l = 0, r = 0;
    for (r = 0; r < n; r++) {
        windowFreq[gene[r]]++;

        while (isValidWindow(windowFreq, totalFreq, n) && l <= r) {
            minLen = min(minLen, r - l + 1);
            windowFreq[gene[l]]--;
            l++;
        }
    }
    return minLen;
}
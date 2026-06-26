class QuickSort {
   private:
    int findPartitionIndex(vector<int>& arr, int low, int high) {
        // find the partition index
        int pivot = arr[low];
        int i = low + 1, j = high;
        while (i < j) {
            while (i <= high && arr[i] < pivot) i++;
            while (j >= low && arr[j] > pivot) j--;
            if (i < j) swap(arr[i], arr[j]);
        }
        swap(arr[low], arr[j]);
        return j;
    }

   public:
    void qSort(vector<int>& arr, int low, int high) {
        if (low >= high) return;
        int pIndex = findPartitionIndex(arr, low, high);
        qSort(arr, low, pIndex - 1);
        qSort(arr, pindex + 1, high);
    }
};
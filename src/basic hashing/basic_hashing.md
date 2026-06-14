### Important :
Always use `maxi+1` for both visited array size to check if you have visited the element arr[i]
and also for storing the frequency of each element of arr.
That is,
```cpp
maxi = *max_element(arr.begin(), arr.end());
vector<int> visited(maxi, 0); // visited array
vector<int> hash(maxi, 0); // hash array to store the frequency of each element of the array arr
```
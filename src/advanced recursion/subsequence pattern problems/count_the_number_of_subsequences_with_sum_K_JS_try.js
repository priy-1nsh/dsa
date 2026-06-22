// this is the js implementation, just for fun
// there is nothing like int main in JS
// let's start thinking
// we wanna do this by recursion

function countSubsequences(index, arr, n, sum) {
    // base case
    if (sum == 0) return 1;
    if (index == n) return 0;
    if (sum < 0) return 0; // only in the case of positives - why ? if there are negatives, we can make our sum == 0 still by subtracting those negative numbers from the sum

    // take
    let l = countSubsequences(index+1, arr, n, sum - arr[index]);

    // not take
    let r = countSubsequences(index+1, arr, n, sum);

    return l+r;
}

// let's call this function
let arr = [1, 2, 1, -2, 8, 9, 5, -4];
let n = arr.length;
let sum = 3;
const result = countSubsequences(0, arr, n, sum);
console.log(result);
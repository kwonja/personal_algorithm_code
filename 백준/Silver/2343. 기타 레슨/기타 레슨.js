const fs = require('fs');

const input = fs.readFileSync('/dev/stdin').toString().trim().split("\n");
const [n, m] = input[0].trim().split(" ").map(Number);
const arr = input[1].trim().split(" ").map(Number);

let left = Math.max(...arr); // Minimum possible size for Blu-ray
let right = arr.reduce((a, b) => a + b, 0); // Maximum possible size
let answer = right;

while (left <= right) {
    const mid = Math.floor((left + right) / 2);

    if (checkmcnt(mid)) {
        answer = mid; // Track the possible answer
        right = mid - 1; // Try to find a smaller max size
    } else {
        left = mid + 1; // Increase size if `mid` is too small
    }
}

console.log(answer);

function checkmcnt(mid) {
    let cnt = 1; // Start with the first Blu-ray
    let sum = 0;

    for (let i = 0; i < n; i++) {
        if (sum + arr[i] > mid) {
            cnt++; // Start a new Blu-ray
            sum = arr[i];
            if (cnt > m) return false; // If more than `m` Blu-rays, return false
        } else {
            sum += arr[i];
        }
    }
    return cnt <= m;
}

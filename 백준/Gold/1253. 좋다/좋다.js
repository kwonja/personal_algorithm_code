// /dev/stdin
const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let n = Number(input[0].trim());

let arr = input[1].trim().split(" ").map(Number);
// 함수

let goodcnt = 0;
// console.log(arr);

arr.sort((a, b) => a - b);

for (let k = 0; k < n; k++) {
  let left = 0;
  let right = n - 1;
  while (left < right) {
    //자기자신은 더하는값으로 사용할 수 없음
    if (right === k) {
      right--;
      continue;
    }
    if (left === k) {
      left++;
      continue;
    }
    let sum = arr[left] + arr[right];
    if (arr[k] < sum) {
      right = right - 1;
    } else if (arr[k] > sum) {
      left = left + 1;
    } else {
      // 같은 값을 찾은경우, 그리고 중복은 없어보인다
      goodcnt++;
      break;
    }
  }
}

console.log(goodcnt);

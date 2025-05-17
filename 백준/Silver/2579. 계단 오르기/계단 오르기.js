/**
 * 실버 3
 * 계단 세우기
 * dp 연습
 */

const fs = require("fs");

const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let n = Number(input[0].trim());
let arr = input.slice(1, n + 1).map((inner) => Number(inner.trim()));
arr.unshift(0); //0번째 계단을 의미하기 위해 사용

let dp = new Array(arr.length);
for (let i = 0; i < arr.length; i++) {
  dp[i] = new Array(3).fill(0);
}

dp[1][1] = arr[1];

for (let i = 2; i < arr.length; i++) {
  //연속 두면 뛸수도 있다.
  dp[i][1] = Math.max(dp[i - 2][2], dp[i - 2][1]) + arr[i];
  dp[i][2] = dp[i - 1][1] + arr[i];
}
console.log(Math.max(dp[n][1], dp[n][2]));
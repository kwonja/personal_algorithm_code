/**
 * 골드 4
 * 호텔
 */

const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

//고객을 적어도 C명 늘리기 위해서 투자해야하는 돈의 최솟값

// 홍보 비용 - 고객수
// 돈은 정수배 만큼 투자할 수 있다.

//C보다 많을수 있다.

// 1명일때 2명일때 3명일때 .. c명일때 돈의값을 가짐

// 해당 명이 3x + 1n의 상황이 되야함

//배낭문제인데 같은 물건을 여러개 넣을수 있는 상황인거같다.
// 아주 좋은문제같다

let [c, n] = input[0].trim().split(" ").map(Number);

let arr = input
  .slice(1, n + 1)
  .map((inner) => inner.trim().split(" ").map(Number));

let max = -Infinity;

for (let i = 0; i < arr.length; i++) {
  max = Math.max(max, arr[i][1]);
}
let dp = new Array(c + max + 1).fill(Infinity);
dp[0] = 0;
for (let i = 0; i < n; i++) {
  let cost = arr[i][0];
  let person = arr[i][1];

  for (let j = person; j < dp.length; j++) {
    dp[j] = Math.min(dp[j], dp[j - person] + cost);
  }
}
let ans = Infinity;
for (let i = c; i < c + max + 1; i++) {
  ans = Math.min(ans, dp[i]);
}
console.log(ans);

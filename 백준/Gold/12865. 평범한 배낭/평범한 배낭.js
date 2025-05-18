/**
 * 골드 5
 * 배낭 문제
 */

const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

// 최대 무게는 7이다
// 첫번째 배낭을 선택했다고 가정하고, 6,7일때 선택할수 있고, 그게 해당 배낭 가치의 최대값이 된다.

let [n, k] = input[0].trim().split(" ").map(Number);

let arr = input
  .slice(1, n + 1)
  .map((inner) => inner.trim().split(" ").map(Number));

//[0] 무게
//[1] 가치

let dp = new Array(n + 1);
for (let i = 0; i < n + 1; i++) {
  dp[i] = new Array(k + 1).fill(0);
}

//물건탐색
for (let i = 1; i <= n; i++) {
  for (let j = 0; j <= k; j++) {
    let weight = arr[i - 1][0];
    let value = arr[i - 1][1];

    //물건을 배낭에 담을수 있을때
    if (weight <= j) dp[i][j] = dp[i - 1][j - weight] + value;

    // 현재 물건을 담은 가치보다 물건들의 가치가 큰지 확인해야함
    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
  }
}

console.log(dp[n][k]);
function print() {
  for (let i = 0; i <= n; i++) {
    console.log(dp[i].join(" "));
  }
}

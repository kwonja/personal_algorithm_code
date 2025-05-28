const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let t = Number(input[0].trim());

let dp = [];
for (let i = 0; i < t; i++) {
  let n = Number(input[i + 1].trim());

  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 2;
  dp[4] = 2;

  for (let j = 5; j <= n; j++) {
    dp[j] = dp[j - 1] + dp[j - 5];
  }
  console.log(dp[n - 1]);
}
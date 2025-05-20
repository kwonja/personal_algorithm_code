/**
 * 골드 5
 * 숨바꼭질 3
 *
 */
let res = 100001;
const fs = require("fs");
const [n, k] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(" ")
  .map(Number);

let move = [-1, 1];
let dp = new Array(res).fill(-1);
// 1초 후에 x-1 x+1 이동
// 0초후에 2*x 로 순간이동

dp[n] = 0;
bfs();
function bfs() {
  let q = [];
  let head = 0;
  q.push(n);
  while (head < q.length) {
    let cur = q[head++];

    if (cur === k) {
      console.log(dp[k]);
      return;
    }

    //0초 이동

    for (let i = 0; i < 1; i++) {
      let next = cur * 2;
      if (next < 0 || next > res) continue;
      if (dp[next] !== -1) continue;
      q.push(next);
      dp[next] = dp[cur];
    }

    for (let i = 0; i < 2; i++) {
      let next = cur + move[i];
      if (next < 0 || next > res) continue;
      if (dp[next] !== -1) continue;
      q.push(next);
      dp[next] = dp[cur] + 1;
    }
  }
}

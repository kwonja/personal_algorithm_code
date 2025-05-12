// /dev/stdin

/**
 * 실버 2
 * 결혼식
 * 그래프 탐색 문제
 */
const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let n = Number(input[0].trim());
let m = Number(input[1].trim());
let visited = new Array(n + 1).fill(false);
let graph = new Array(n + 1);
for (let i = 1; i <= n; i++) {
  graph[i] = [];
}
let arr = input
  .slice(2, m + 2)
  .map((inner) => inner.trim().split(" ").map(Number));

for (let i = 0; i < m; i++) {
  let x = arr[i][0];
  let y = arr[i][1];

  graph[x].push(y);
  graph[y].push(x);
}
bfs(1);

let cnt = 0;
for (let i = 2; i <= n; i++) {
  if (visited[i] === true) cnt++;
}
console.log(cnt);

//친구의 친구까지만 즉 그래프로 탐색하는 거리를 측정해야함
// 그래프를 하더라도  bfs로 돌아야한다!
function bfs(start) {
  let q = [];
  let head = 0;
  q.push({
    value: start,
    cnt: 0,
  });
  visited[1] = true;

  while (head < q.length) {
    let { value, cnt } = q[head++];
    if (cnt >= 2) return;
    for (let i = 0; i < graph[value].length; i++) {
      let person = graph[value][i];
      if (visited[person] === false) {
        q.push({ value: person, cnt: cnt + 1 });
        visited[person] = true;
      }
    }
  }
}

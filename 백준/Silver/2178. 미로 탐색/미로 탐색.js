const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [n, m] = input[0].trim().split(" ").map(Number);
let board = new Array(n);
let visited = new Array(n);
let dx = [1, -1, 0, 0];
let dy = [0, 0, 1, -1];
let q = [];
for (let i = 0; i < n; i++) {
  board[i] = new Array(m);
  visited[i] = new Array(m).fill(0);
}

for (let i = 0; i < n; i++) {
  let str = input[i + 1].trim();
  for (let j = 0; j < str.length; j++) {
    board[i][j] = Number(str[j]);
  }
}

bfs();
console.log(visited[n - 1][m - 1]);

// 최단거리는 너비우선 탐색!
function bfs() {
  // 1,1 시작
  q.push({ x: 0, y: 0 });
  visited[0][0] = 1;
  while (q.length > 0) {
    let { x, y } = q.shift();

    for (let i = 0; i < 4; i++) {
      let nx = x + dx[i];
      let ny = y + dy[i];

      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (visited[nx][ny] > 0 || board[nx][ny] === 0) continue;

      q.push({ x: nx, y: ny });
      visited[nx][ny] = visited[x][y] + 1;
    }
  }
}

// 함수
// print(board);
function print(arr) {
  for (let i = 0; i < n; i++) {
    console.log(arr[i].join(" "));
  }
}

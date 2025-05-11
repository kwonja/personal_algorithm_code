/**
 * 벽 부수고 이동하기
 * 3차원 배열 연습
 */

const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let dx = [1, -1, 0, 0];
let dy = [0, 0, 1, -1];
let ans = -1;
let q = [];
let [n, m] = input[0].trim().split(" ").map(Number);
let board = [];

for (let i = 0; i < n; i++) {
  let str = input[i + 1].trim();
  board[i] = [];
  for (let j = 0; j < m; j++) {
    board[i][j] = Number(str[j]);
  }
}

// 방문을 했을때 그 방문한 위치가 벽을 부순상태인지, 아닌지 알아야함
// 벽은 한번만 부술 수 있다.

let visited = [];

// 이게 적절한 방법인가를 잘 생각해 보긴 해야할듯
for (let i = 0; i < 2; i++) {
  visited[i] = [];
  for (let j = 0; j < n; j++) {
    visited[i][j] = new Array(m).fill(0);
  }
}

bfs();
console.log(ans);
// print(visited[0]);
// console.log();
// print(visited[1]);
function bfs() {
  //무조건 시작은 0,0
  // 0 : 부신 횟수
  let head = 0;
  q.push({
    x: 0,
    y: 0,
    break: 0,
  });

  visited[0][0][0] = 1;

  while (head < q.length) {
    let { x: curx, y: cury, break: curbreak } = q[head++];

    if (curx === n - 1 && cury === m - 1) {
      ans = visited[curbreak][curx][cury];
      return;
    }

    for (let i = 0; i < 4; i++) {
      let nx = curx + dx[i];
      let ny = cury + dy[i];

      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      // 벽을 부수고 이동할때
      if (
        curbreak === 0 &&
        visited[curbreak + 1][nx][ny] === 0 &&
        board[nx][ny] === 1
      ) {
        q.push({
          x: nx,
          y: ny,
          break: curbreak + 1,
        });
        visited[curbreak + 1][nx][ny] = visited[curbreak][curx][cury] + 1;
      }

      //벽을 부수지 않고 이동할때
      if (visited[curbreak][nx][ny] === 0 && board[nx][ny] === 0) {
        q.push({
          x: nx,
          y: ny,
          break: curbreak,
        });
        visited[curbreak][nx][ny] = visited[curbreak][curx][cury] + 1;
      }
    }
  }
}

function print(arr) {
  for (let i = 0; i < n; i++) {
    console.log(arr[i].join(" "));
  }
}

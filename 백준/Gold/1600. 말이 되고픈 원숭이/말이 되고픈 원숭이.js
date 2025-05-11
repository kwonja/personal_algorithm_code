/**
 * 말이 되고픈 원숭이
 * 3차원 배열 연습
 */

const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
let k = Number(input[0].trim());
let [m, n] = input[1].trim().split(" ").map(Number);

// map -> 만들어진 배열을 돈다!
const board = input
  .slice(2, n + 2)
  .map((line) => line.trim().split(" ").map(Number));
// console.log(board);
let dx = [1, -1, 0, 0];
let dy = [0, 0, 1, -1];
let hx = [-1, -2, -2, -1, 1, 2, 2, 1];
let hy = [-2, -1, 1, 2, 2, 1, -1, -2];
let ans = -1;
let q = [];

// 방문을 했을때 그 방문한 위치가 벽을 부순상태인지, 아닌지 알아야함
// 벽은 한번만 부술 수 있다.

let visited = [];

// 이게 적절한 방법인가를 잘 생각해 보긴 해야할듯
for (let i = 0; i <= k; i++) {
  visited[i] = [];
  for (let j = 0; j < n; j++) {
    visited[i][j] = new Array(m).fill(0);
  }
}

// print(visited[1]);
bfs();
console.log(ans !== -1 ? ans - 1 : ans);
// console.log();
// print(visited[1]);
function bfs() {
  //무조건 시작은 0,0
  // 0 : 장애물을 뛰어넘은 횟수
  let head = 0;
  q.push({
    x: 0,
    y: 0,
    jump: 0,
  });

  visited[0][0][0] = 1;

  // 다른 자료구조들은 빅오의 1로 구현되어있다.
  // shift는 O(n)로직이라고 하는데, 포인터와 해시테이블 배열로 써 어떻게 동작하냐 차이인듯
  while (head < q.length) {
    let { x: curx, y: cury, jump: curjump } = q[head++];

    if (curx === n - 1 && cury === m - 1) {
      ans = visited[curjump][curx][cury];
      return;
    }

    for (let i = 0; i < 4; i++) {
      let nx = curx + dx[i];
      let ny = cury + dy[i];

      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      //점프를 하지 않고 이동할때
      if (visited[curjump][nx][ny] === 0 && board[nx][ny] === 0) {
        q.push({
          x: nx,
          y: ny,
          jump: curjump,
        });
        visited[curjump][nx][ny] = visited[curjump][curx][cury] + 1;
      }
    }

    //점프를 통해 이동할때는 이동거리가 다르다!

    if (curjump < k) {
      for (let i = 0; i < 8; i++) {
        let nx = curx + hx[i];
        let ny = cury + hy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (visited[curjump + 1][nx][ny] !== 0 || board[nx][ny] !== 0) continue;

        q.push({
          x: nx,
          y: ny,
          jump: curjump + 1,
        });
        visited[curjump + 1][nx][ny] = visited[curjump][curx][cury] + 1;
      }
    }
  }
}

function print(arr) {
  for (let i = 0; i < n; i++) {
    console.log(arr[i].join(" "));
  }
}

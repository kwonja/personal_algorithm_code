/**
 * 골드 5
 * 치킨배달
 */

//치킨집의 좌표 배열을 두고,m 개수 만큼 뽑는다

//이후 가장 가까운 치킨거리를 구하고, 그 합을 저장해놓는다
//그 값중 가장 낮은 값을 출력한다

const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let ans = Infinity;
let dx = [1, -1, 0, 0];
let dy = [0, 0, 1, -1];
let [n, m] = input[0].trim().split(" ").map(Number);
let chickenHouse = [];
let house = [];
let board = input
  .slice(1, n + 1)
  .map((inner) => inner.trim().split(" ").map(Number));

let sel = new Array(m);

for (let i = 0; i < n; i++) {
  for (let j = 0; j < n; j++) {
    if (board[i][j] === 2) {
      chickenHouse.push({ x: i, y: j });
    } else if (board[i][j] == 1) house.push({ x: i, y: j });
  }
}
comb(0, 0);
console.log(ans);
function comb(index, k) {
  if (k === m) {
    // 여기서 치킨거리 구하기 시작
    ans = Math.min(ans, searchChickRoad(sel));
    return;
  }
  if (index >= chickenHouse.length) return;

  sel[k] = chickenHouse[index];

  comb(index + 1, k + 1);
  comb(index + 1, k);
}

function searchChickRoad(sel) {
  // 한 집에서 선택된 치킨집간에 거리를 구하고, 그 중 가장 작은 값을 지속적으로 더해감
  let sum = 0;
  for (let i = 0; i < house.length; i++) {
    let ans = Infinity;
    for (let j = 0; j < sel.length; j++) {
      let x = Math.abs(sel[j].x - house[i].x);
      let y = Math.abs(sel[j].y - house[i].y);

      ans = Math.min(x + y, ans);
    }
    sum += ans;
  }
  // console.log(sum);
  return sum;
}

//js deepcopy -> 배열은 어떻게 하면 좋을까

// function deepcopy(board) {
//   let newBoard = new Array(board.length);
//   for (let i = 0; i < board.length; i++) {
//     newBoard[i] = [];
//     for (let j = 0; j < board[i].length; j++) {
//       newBoard[i][j] = board[i][j];
//     }
//   }
//   return newBoard;
// }

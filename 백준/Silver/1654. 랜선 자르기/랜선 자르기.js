/**
 * 이분탐색
 * 매개변수탐색
 * 항상 할때마다 헷갈린다..
 * 조건을 탐색하는 start,end 기준을 잘 정해야함!
 *
 * 실버 2
 * 랜선 자르기
 */

const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let [k, n] = input[0].trim().split(" ").map(Number);
let arr = input.slice(1, k + 1).map((inner) => Number(inner.trim()));

arr.sort((a, b) => a - b);

let start = 1;
let end = arr[arr.length - 1] + 1;
let answer = 0;
while (start <= end) {
  let mid = parseInt((start + end) / 2);
  //n개 보다 많이 나왔을때
  if (checkCnt(mid) >= n) {
    answer = mid;
    start = mid + 1;
  } else end = mid - 1;
}

console.log(answer);

function checkCnt(value) {
  let cnt = 0;
  for (let i = 0; i < arr.length; i++) {
    let temp = parseInt(arr[i] / value);
    cnt += temp;
  }

  return cnt;
}

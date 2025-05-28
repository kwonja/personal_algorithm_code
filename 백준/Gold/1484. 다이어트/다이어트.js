/**
 * 골드 5
 * 다이어트
 * G = 현재*현재 - 기억*기억
 *
 */

const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let g = Number(input[0].trim());

let memoryWeight = 1;
let curWeight = Math.ceil(Math.sqrt(g));

let ans = [];

while (memoryWeight < curWeight) {
  let res = curWeight * curWeight - memoryWeight * memoryWeight;
  if (res >= g) {
    if (res === g) ans.push(curWeight);
    memoryWeight += 1;
  } else {
    curWeight += 1;
  }
}

if (ans.length === 0) console.log(-1);
else {
  ans.sort((a, b) => {
    return a - b;
  });
  for (let i = 0; i < ans.length; i++) {
    console.log(ans[i]);
  }
}

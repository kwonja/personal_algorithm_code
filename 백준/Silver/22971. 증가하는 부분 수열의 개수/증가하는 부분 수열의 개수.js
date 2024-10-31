const fs = require('fs');
const input  = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let n = Number(input[0].trim());
let arr = input[1].trim().split(" ").map(Number);

//자기자신도 증가하는 부분수열이라는 점을 메모로 남겼다.

let dp=[];

for(let i=0;i<arr.length;i++){
    dp[i]=1;
    for(let j=0;j<i;j++){
        if(arr[i]>arr[j]) dp[i] = (dp[i] + dp[j]) % 998244353;
    }
}
console.log(dp.join(" "));
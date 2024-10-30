const fs = require('fs');
const input  = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let arr=[];
let [n,m,l] = input[0].trim().split(" ").map(Number);
if(n !==0) arr = input[1].trim().split(" ").map(Number);



arr.push(0);
arr.push(l);
arr.sort((a,b)=>a-b);
let left = 1;
let right = l-1;
let mid=0;
while(left <= right){
    mid = Math.floor((left + right) / 2);
    if(check(mid))
    {
        //해당 길이로 n보다 적은 휴게소를 만들 수 있을때
        right = mid-1;
    }else{
        //해당 길이로 m보다 많은 휴게소를 만들수 있을때
        left = mid+1;
    }
}

function check(mid){
    let sum=0;

    for(let i=0;i<arr.length-1;i++)
    {
        let diff = arr[i+1]-arr[i];
        let temp = Math.floor(diff/mid);
        if(diff % mid === 0) sum += temp-1;
        else sum += temp;
        if(sum > m)return false;
    }
    return true;
}

console.log(left);
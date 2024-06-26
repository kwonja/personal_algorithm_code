//LCS
const fs = require('fs');
const [n,inputArr] = fs.readFileSync('/dev/stdin').toString().trim().split("\n");


let arr = inputArr.trim().split(" ");
let dp = new Array(n);

for(let k=0;k<n;k++)
{
    dp[k]=1;
    for(let i=0;i<k;i++)
    {
        //건널수 있다
        if(+arr[i]< +arr[k])dp[k]=Math.max(dp[k],dp[i]+1);       
    }
}

console.log(Math.max(...dp));
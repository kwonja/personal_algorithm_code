const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');
const t = +input[0].trim();

let idx=0;
let arr;
for (let i = 1; i <= t; i++) {

    let n= input[++idx].trim();
    let uparr = input[++idx].trim().split(' ').map(Number);
    let downarr = input[++idx].trim().split(' ').map(Number);
    arr= new Array(2);
    arr[0] = new Array(n);
    arr[1]= new Array(n)
    for (let j = 0; j < n; j++) {
        arr[0][j] = uparr[j];
        arr[1][j] = downarr[j];
    }
    let  dp= new Array(2);
    dp[0] = new Array(n);
    dp[1]=new Array(n);


  
    dp[0][0] = uparr[0];
    dp[1][0] = downarr[0];
    if (n>=2)
    {
        dp[1][1]= arr[1][1]+ arr[0][0];
        dp[0][1]= arr[0][1]+ arr[1][0];
    }

    for(let i=2;i<n;i++)
    {
        dp[0][i]= Math.max(dp[1][i-1],dp[1][i-2]) + arr[0][i];
        dp[1][i]= Math.max(dp[0][i-1],dp[0][i-2]) + arr[1][i];
    }
    console.log(Math.max(dp[0][n-1],dp[1][n-1]));    
}
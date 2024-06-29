const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split("\n");

const n = +input[0].trim();
let totalscore = new Array(n).fill(0);


for(let i=1;i<=3;i++)
{
    let arr=[];
    let inputArr=input[i].trim().split(" ").map(Number);

    for(let k=0;k<n;k++)
    {
       arr.push({score : inputArr[k], id : k+1})
       totalscore[k]+=inputArr[k];
    }

    arr.sort(function(a,b){ return b.score - a.score; })

    arr[0].rank=1;
    let mx= arr[0].score;
    let rank=1;
    for(let j=1;j<n;j++)
    {
         if(arr[j].score<mx)
         {
            mx=arr[j].score;
            rank=j+1; 
         }
         arr[j].rank=rank;
    }
    arr.sort(function(a,b){
    return a.id - b.id;
    })

    let temp=[];
    for(let j=0;j<n;j++)temp.push(arr[j].rank);
    console.log(temp.join(' '));
}

let finalarr=[];
for(let k=0;k<n;k++)
{
  finalarr.push({score : totalscore[k], id : k})
}
finalarr.sort(function(a,b) {return b.score - a.score;})
    finalarr[0].rank=1;
    let mx= finalarr[0].score;
    let rank=1;
    for(let j=1;j<n;j++)
    {
         if(finalarr[j].score<mx)
         {
            mx=finalarr[j].score;
            rank=j+1; 
         }
         finalarr[j].rank=rank;
    }
    finalarr.sort(function(a,b){return a.id - b.id})
    let temp=[];
    for(let j=0;j<n;j++)temp.push(finalarr[j].rank);
    console.log(temp.join(' '));
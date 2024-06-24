/*
4 2
20 26 185 80
100 20 25 80
20 20 88 99
15 32 44 50
1 2
2 3

633
*/

const fs = require('fs'); 
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let temp = input[0].trim().split(" ");
let n = +temp[0];
let m = +temp[1];
let arr = new Array(n);
let visited = new Array(n);
for(let i=0;i<n;i++){
    arr[i]=new Array(n);
    visited[i] = new Array(n).fill(0);
}
let people =[];
let answer= 0;
for(let i=0;i<n;i++){
    let inputBoard = input[i+1].trim().split(" ");
    for(let j=0;j<n;j++){
        arr[i][j]=+inputBoard[j];
    }
}

for(let i=n+1; i<=m+n;i++)
{
    let [a,b] = input[i].trim().split(" ");
    people.push({x: a-1, y : b-1});
    answer += arr[a-1][b-1];
    visited[a-1][b-1]=1;
}

let dx = [1,-1,0,0];
let dy = [0,0,1,-1];
function dfs(x,y,cnt,sum,peopleCnt){
    if(cnt === 3)
    {
        if(peopleCnt+1 === people.length){
            answer = Math.max(answer,sum);
            return;
        }
        let x = people[peopleCnt+1].x;
        let y = people[peopleCnt+1].y;
        dfs(x ,y ,0,sum,peopleCnt+1);
        return;
    }
    for(let i=0;i<4;i++)
    {
        let nx = x + dx[i];
        let ny = y + dy[i];
        if(nx < 0 || nx>=n || ny<0 || ny>=n)continue;
        if(!visited[nx][ny]){
            visited[nx][ny]=1;
            dfs(nx,ny,cnt+1,sum + arr[nx][ny],peopleCnt);
            visited[nx][ny]=0;
        }
    }
}

dfs(people[0].x,people[0].y,0,answer,0);
console.log(answer);
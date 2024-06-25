const fs = require('fs');
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let [n,m] = input[0].trim().split(" ");

let board = new Array(n);
let ghostBoard = new Array(n);
let hq =[];
let gq=[];
let dx = [1,-1,0,0];
let dy = [0,0,1,-1];
let endx,endy;
//벽 : -1, 사람이동경로 : 1 //도착지 : 3
for(let i=0;i<n;i++)
{
    board[i]= new Array(m);
    ghostBoard[i] = new Array(m);
}
for(let i=1;i<=n;i++)
{
    let inputArr = input[i].trim();
    for(let j=0;j<m;j++)
    {
        ghostBoard[i-1][j]=0;
        if(inputArr[j]==='.')board[i-1][j]=0;
        if(inputArr[j]==='N'){
           board[i-1][j]=1;
           hq.push({x: i-1, y : j});
        }
        if(inputArr[j]==='#')board[i-1][j]=-1;
        if(inputArr[j]==='G'){
            board[i-1][j]=1;
            ghostBoard[i-1][j]=1;
            gq.push({x : i-1, y : j});
        }  
        if(inputArr[j]==='D'){
            endx =i-1;
            endy= j;
            board[i-1][j]=0;
        }
    }
}
gbfs();
bfs();
if(board[endx][endy]>0)console.log("Yes")
else console.log("No");


function gbfs(){
    while(gq.length){
        
        let {x : curx, y : cury} = gq.shift();
        for(let i=0;i<4;i++)
        {
            let nx = curx + dx[i];
            let ny = cury + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m)continue;
            if(ghostBoard[nx][ny]>0)continue;
            gq.push({x : nx , y : ny});
            ghostBoard[nx][ny]= ghostBoard[curx][cury]+1;
        }
    }
}
//사람인 경우
function bfs(){

    while(hq.length){    
    let {x : curx, y : cury} =hq.shift();

    if(curx === endx && cury ===endy)
    {
        return;
    }
    for(let i=0;i<4;i++)
    {
        let nx = curx + dx[i];
        let ny = cury + dy[i];
        if(nx<0 || nx>=n || ny<0 || ny>=m)continue;
        if(board[nx][ny]===-1 || board[nx][ny]>0)continue;
        if(ghostBoard[nx][ny]<=board[curx][cury]+1)continue;
        hq.push({x : nx , y : ny});
        board[nx][ny]= board[curx][cury]+1;
    }   
        
}
}
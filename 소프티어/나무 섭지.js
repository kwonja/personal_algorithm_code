const fs = require('fs');
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let [n,m] = input[0].trim().split(" ");

let board = Array.from({ length: n }, () => new Array(m).fill(0));
let ghostBoard = Array.from({ length: n }, () => new Array(m).fill(0));
let hq =[];
let gq=[];
let dx = [1,-1,0,0];
let dy = [0,0,1,-1];
let endx,endy;
//벽 : -1, 사람이동경로 : 1 //도착지 : 3
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
if(board[endx][endy]>0)console.log("Yes");
else console.log("No");


function gbfs(){
    let gqStart = 0;
    while(gqStart < gq.length){
        
        let {x : curx, y : cury} = gq[gqStart++];
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
    let hqStart = 0; 
    while(hqStart < hq.length){  
    let {x : curx, y : cury} =hq[hqStart++];

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


// q를 shift() 메소드는 O(N)의 시간복잡도를 가진다 이것을 인덱스로 직접 접근하게되면 O(1)에 접근할수 있다
// 인덱스를 만큼 사용하지 않는 공간을 차지할 수 있겠지만 메모리가 넉넉하다면 충분히 좋은 접근 방법인것 같다.

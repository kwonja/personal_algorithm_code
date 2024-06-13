let n;
let dx=[1,0,-1,0];
let dy=[0,-1,0,1];
let q=[];
let vcost;
let visited;
function solution(board) {
    n= board.length;
    vcost = Array.from({ length: n }, () => Array.from({ length: n }, () => Array(4).fill(Infinity)));
    visited=new Array(n);
    for(let i=0;i<n;i++)
    {
        visited[i]= new Array(n).fill(false);
    }
    bfs(board);
    return Math.min(...vcost[n-1][n-1]);
}


function bfs(board)
{
    
    q.push({x:0,y:0,rot : -1,weight:0});
    
    while(q.length)
    {
        q.sort((a,b)=>a.weight-b.weight);
        let {x: curx, y : cury, rot,weight} = q.shift();
        
        
        for(let i=0;i<4;i++)
        {
            
            let nx = curx + dx[i];
            let ny = cury + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n)continue;
            if(board[nx][ny]===1)continue;
            
            let newCost = weight + 100;
            if (rot !== -1 && (rot%2) !== (i%2)) {
                newCost += 500;
            }

            if (vcost[nx][ny][i] > newCost) {
                vcost[nx][ny][i] = newCost;
                q.push({ x: nx, y: ny, rot: i, weight: newCost });
            }
            
        }
        
    }
}
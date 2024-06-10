
let dx = [1,-1,0,0];
let dy = [0,0,1,-1];
let q = [];
let visited;
function solution(maps) {
    let n = maps.length;
    let m = maps[0].length;
    visited = new Array(n);
    for(let i=0;i<n;i++)
    {
        visited[i]= new Array(m).fill(-1);      
    }
    bfs(0,0,n,m,maps);
    
    return visited[n-1][m-1];
}

function bfs(x,y,n,m,maps)
{
    q.push({x,y}); //구조 분해 할당 -> 문법을 익혀야할듯
    visited[x][y]=1;
    
    while(q.length)
    {
        let cur = q.shift();
        let curx = cur.x;
        let cury = cur.y;
        
        if(curx === n-1 && cury ===m-1) return;
        for(let i=0;i<4;i++)
        {
            let nx = curx + dx[i];
            let ny = cury + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m)continue;
            if(visited[nx][ny]===-1 && maps[nx][ny]===1)
            {
                //방문
                q.push({x : nx, y : ny});
                visited[nx][ny]= visited[curx][cury]+1;
            }
        }
    }
}
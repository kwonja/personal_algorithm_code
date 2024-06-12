let dist;
let graph;
let q=[];
function solution(n, edge) {
    
    //시작 노드는 1번
    dist = new Array(n+1).fill(0);
    
    //그래프 설정
    graph = new Array(n+1);
    
    for(let i=1;i<=n;i++)
    {
        graph[i]=[];        
    }
    
    for(let [a,b] of edge)
    {
        graph[a].push(b);
        graph[b].push(a);
    }
    bfs(1);
    
    let mx = Math.max(...dist);
    let arr = dist.filter( (a) => a===mx);
    return arr.length;
}

function bfs(start)
{
    //시작노드는 거리가 1
    dist[start]=1;
    q.push(start);
    
    while(q.length)
    {
        let vertex = q.shift();
        for(let i=0;i<graph[vertex].length;i++)
        {
           if(!dist[graph[vertex][i]])
           {
              q.push(graph[vertex][i]);
               dist[graph[vertex][i]]= dist[vertex]+1;  
            }   
        }    
    }
}
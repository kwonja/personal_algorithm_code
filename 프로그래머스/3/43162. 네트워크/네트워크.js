let visited;
let answer=0;
function solution(n, computers) {
    //인접행렬로 이어진 부분을 알려줌
    visited = new Array(n).fill(false);
    
    for(let i=0;i<computers.length;i++)
    {
        if(!visited[i])
        {
            answer++;
            dfs(i,computers);        
        }
        
    }
    return answer;
}

function dfs(cur, computers){
    
    for(let i=0;i<computers[cur].length;i++)
    {
        if(!visited[i] && computers[cur][i] !==0)
        {
            visited[i]=true;
            dfs(i,computers);
        }
    }
}
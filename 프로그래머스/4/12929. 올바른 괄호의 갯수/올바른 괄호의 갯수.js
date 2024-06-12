let answer=0;
function solution(n) {
    dfs(n,1,0,1);
    
    return answer;
    
    
    
}



function dfs(n,open,close,cnt)
{
    if(cnt===2*n){
        answer++;
        return;
    }
    if(close>open)return;
    
    if(open<n)dfs(n,open+1,close,cnt+1)
    if(close<n)dfs(n,open,close+1,cnt+1)
}
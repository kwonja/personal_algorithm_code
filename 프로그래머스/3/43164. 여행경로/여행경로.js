var answer = [];
let check=false;
function solution(tickets) {
    let checked = new Array(tickets.length).fill(false);
    
    tickets.sort();
    
    dfs("ICN",0,tickets,checked);
    return answer;
}

function dfs(target,idx, tickets, checked)
{
    //모든 티켓을 사용했을때 종료
    if(idx===tickets.length)
    {
        answer.push(target);
        check=true;
        return 0;
    }
    
    for(let i=0;i<tickets.length;i++)
    {
        if(!checked[i] && target === tickets[i][0])
        {
            checked[i]=true;
            answer.push(target);
            dfs(tickets[i][1],idx+1,tickets,checked);
            //return을 하게되면 해당 함수가 종료되고 호출되고 있는 이 밑 코드를 실행하게된다.
            if(!check)
            {
                answer.pop();
                checked[i]=false;//티켓해제
            }
            
            
        }
    }
}
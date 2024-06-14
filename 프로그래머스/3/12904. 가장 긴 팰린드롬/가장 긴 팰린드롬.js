function solution(s)
{
    let answer=0;
    
    for(let i=0; i <s.length; i++)
    {
        let start=i-1;
        let end=i+1;
        let cnt1=1;
        
        //홀수
        while(start>=0 && end<=s.length-1)
        {
          if(s[start] === s[end]){
              cnt1+=2;
              start--;
              end++;
          }
          else{
              break;
          }
        }
        
        start=i;
        end=i+1;
        let cnt2=0;
        //짝수
        while(start>=0 && end<=s.length-1)
        {
          if(s[start] === s[end]){
              cnt2+=2;
              start--;
              end++;
          }
          else{
              break;
          }
        }
        console.log(cnt1 + " " + cnt2);
        let mx=Math.max(cnt1,cnt2);
        answer =Math.max(answer,mx);
    }

    return answer;
}
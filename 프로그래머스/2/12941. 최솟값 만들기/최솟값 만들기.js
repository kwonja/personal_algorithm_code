
function solution(A,B){
    let answer=0;
    A.sort(function(a,b){
        return a-b;
    })
    B.sort(function(a,b){
        return b-a;       
    })
    //제일큰수는 제일작은수와 곱 -> 최솟값
    for(let i=0;i<A.length;i++)
    {
      answer+= A[i]*B[i];
    }
    return answer;
}
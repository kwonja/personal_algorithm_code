
function solution(A, B) {
    let n=A.length;
    let answer=0;
    A.sort((a,b)=>a-b);
    B.sort((a,b)=>a-b);
    let aIdx=0;
    let bIdx=0;
    
    while(aIdx < n && bIdx < n){
        if(B[bIdx] > A[aIdx])
        {
            answer++;
            aIdx++;
        }
        bIdx++;
    }

    return answer;
}
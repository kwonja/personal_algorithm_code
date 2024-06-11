
//반대로 생각해도 된다.
function solution(triangle) {
    let leg = triangle[triangle.length-1].length;
    
    for(let i=leg-2;i>-1;i--)
    {
        for(let j=0;j<=i;j++)
        {
            triangle[i][j]+= Math.max(triangle[i+1][j],triangle[i+1][j+1]);   
        }
    }
    
    
    return triangle[0][0];
    
    
}






//dp
//테이블 설정
// arr[i][j] i,j번째 합의 최대값

//점화식
// dp[i][j] = Math.max( dp[i-1][j]+arr[i][j],dp[i-1][j-1]+arr[i][j])

//초기값
//arr[0][0]=7;
function solution(s) {
    let answer='';
    let arr = s.split(" ");
    
    for(let i=0;i<arr.length;i++)
    {
        if(arr[i]!=='')
        {
            answer += JadenCase(arr[i]);     
        }
        answer +=" ";
    }
    answer=answer.slice(0,answer.length-1);
    return answer;
}


function JadenCase(str){
    if(str.length>1)
    return str[0].toUpperCase() + str.slice(1).toLowerCase();
    else
    return str[0].toUpperCase();
}
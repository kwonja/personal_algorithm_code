function solution(s) {
    
    let t=0;
    let remove=0;
    
    
    while(s.length!==1)
    {
        let str=0;
        for(let i=0;i<s.length;i++)
        {
            if(s[i]==="1")str++;
            else remove++;
        }
        s = func1(str);
        t++;
    }
    
    var answer = [t,remove];
    return answer;
}

function func1(leg)
{
    let str="";
    
    while(leg)
    {
        str = (leg%2) + str;
        leg= Math.floor(leg/2);
    }
   
    return str;
}
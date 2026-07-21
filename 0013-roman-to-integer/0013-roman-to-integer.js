/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    let sum = 0;

    for(let i=0;i<s.length;i++){
        let str = s[i];


        if(i === s.length-1){
            return sum += strToInt(str);
        }

        if(str === 'I'){
            if(s[i+1] === 'V'){
                sum += (strToInt(s[i+1]) - strToInt(str));
                i++
                continue;
            }
            if(s[i+1] === 'X'){
                sum += (strToInt(s[i+1]) - strToInt(str));
                i++
                continue;
            }
        }

        if(str === 'X'){
            if(s[i+1] === 'L'){
                sum += (strToInt(s[i+1]) - strToInt(str));
                i++
                continue;
            }
            if(s[i+1] === 'C'){
                sum += (strToInt(s[i+1]) - strToInt(str));
                i++
                continue;
            }
        }

        if(str === 'C'){
            if(s[i+1] === 'D'){
                sum += (strToInt(s[i+1]) - strToInt(str));
                i++
                continue;
            }
            if(s[i+1] === 'M'){
                sum += (strToInt(s[i+1]) - strToInt(str));
                i++
               continue;
            }
        }

        sum += strToInt(str)
    }
    return sum;    
};







function strToInt (s){

    
    if(s ==='I') return 1;
    if(s === 'V') return 5;
    if(s === 'X') return 10;
    if(s === 'L') return 50;
    if(s === 'C') return 100;
    if(s === 'D') return 500;
    if(s ==='M') return 1000;
}

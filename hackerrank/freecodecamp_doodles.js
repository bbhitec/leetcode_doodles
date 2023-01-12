/*
'use strict';

const readline = require('readline');

var r1 = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });
    
    main();    
});

function readLine() {
    return inputString[currentLine++];
}

function regexVar() {
    //
    // Declare a RegExp object variable named 're'
    // It must match a string that starts and ends with the same vowel (i.e., {a, e, i, o, u})
    //
    let re = /^([aeiou]).+\1$/;
    return re;
    
    
    // 
    // Do not remove the return statement
    // 
    return re;
}


function main() {
    const re = regexVar();
    //const s = readLine();

    r1.question('Give me a number, I\'ll add five! ', function(num) {
    
        // Tell JS this is a number
        num = parseInt(num);
        console.log(num + 5);
        // Close, or it will keep reading forever
        r1.close();
    })
    
    // console.log(re.test(s));
    //console.log(re.test(s));
}


// function factorial(num) {
//     if (num === 0 || num === 1) {
//       return num;
//     }
//     return num * factorial(num - 1);
//   }
  
//   let n = factorial(8);
//   console.log(n); // 40320

*/


/*
'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });

    main();    
});

function readLine() {
    return inputString[currentLine++];
}


function main() {
    console.log("You entered the following text in the Input box:");

    const input = readLine();
    console.log(input);
}
*/


// caesar cypher
function rot13(str) {
    let res = [];
    for (let c = 0; c < str.length; c++) {
        let char = str.charCodeAt(c);
        //console.log(String.fromCharCode(char) + " : " +char, end="");
        //process.stdout.write(String.fromCharCode(char) + " : " +char)
        if (char >= 65 && char <= 90) {
            char = ((char-65 + 13) % 26)+65;        
        }
        //console.log(" -> " + char + " : " + String.fromCharCode(char));
        res.push(char);
    }
    let res_str = String.fromCharCode(...res);
    return res_str;
}

console.log(rot13("SERR PBQR PNZC"));
console.log(rot13("SERR CVMMN!"));
console.log(rot13("SERR YBIR?"));
console.log(rot13("GUR DHVPX OEBJA SBK WHZCF BIRE GUR YNML QBT."));



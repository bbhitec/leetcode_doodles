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


// 10 Days of Javascript: Day3: Try, Catch, and Finally
function day3() {
    function reverseString(s) {
        let str;
        try {
            str = s.split("").reverse().join("");
            console.log(str);
        } catch (e) {
            console.log(e.message);
            console.log(s);
        }

    }
    //reverseString("1234");
    reverseString(Number(1234));
}

// Day 7,8: Regular Expressions II
function day78() {
    function regexVar() {
        /*
         * Declare a RegExp object variable named 're'
         */

        // day7
        // It must match a string that starts with 'Mr.', 'Mrs.', 'Ms.', 'Dr.', or 'Er.', followed by one or more letters.
        // let re = /^(Mr\.|Mrs\.|Ms\.|Dr\.|Er\.)([a-zA-Z])+$/;

        // day8
        // It must match ALL occurrences of numbers in a string.
        let re = /\d+/g;



        /*
         * Do not remove the return statement
         */
        return re;
    }
    const re = regexVar();
    const s7 = "Mr.Az"
    const s8 = "102, 1948948 and 1.3 and 4.5"

    //console.log(re.test(s));
    //console.log(!!s.match(re));

    const r = s8.match(re);

    for (const e of r) {
        console.log(e);
    }
}

// day3();
day78();

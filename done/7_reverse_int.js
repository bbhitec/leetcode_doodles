/**
    @author [mst]
    @brief  leetcode series
    7_reverse_int
    Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
    Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

    gains:
    -basic math thinking
    -js divisions and prints


    @version 0.1 2023.03
*/



////////////////// LIBS



////////////////// DECL_IMPL


// basic math solution: using quotents and digits
//
// sub: 75 77
var reverse = function(x) {
    let res = 0;
    let digit = 0;
    const limit = Math.pow(2,31) -1

    while (x) {
        digit = x%10
        res *= 10
        res += digit
        x = ~~(x/10)    // [demo] can be used also: Math.floor(x/10)
    }

    if (res > limit || res < -(limit+1)) return 0

    return res
}




////////////////// DRIVER
console.log("[mst] leetcode doodles")

console.log(reverse(-123))

let x2 = Math.pow(2,31) -1
console.log(`res for ${x2} is: ` + reverse(x2))

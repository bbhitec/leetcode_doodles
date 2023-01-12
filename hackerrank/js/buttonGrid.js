const ids = [1, 2, 3, 6, 9, 8, 7, 4]; // start positions ids in clockwise order
let nums = [1, 2, 3, 6, 9, 8, 7, 4]; // rotating in clockwise order

let btn5 = document.getElementById("btn5");

btn5.onclick = function() {
    document.getElementById("btn4" ).innerHTML = 10;
    // nums.unshift(nums.pop());
    // for (i = 0; i <= 7; i++) {
    //     document.getElementById("btn" + ids[i]).innerHTML = nums[i];
    // }
};

function increment() {
  btn4.innerHTML++;
  //document.getElementById("btn5").innerHTML = 20;
}

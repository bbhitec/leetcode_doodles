/**
    @author [mst]
    @file   twosum.cpp
    @brief  leetcode problems series

    1_twosum
    Given an array of integers, return indices of the two numbers such that they add up to a specific target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
    Example:
    Given nums = [2, 7, 11, 15], target = 9,
    Because nums[0] + nums[1] = 2 + 7 = 9,
    return[0, 1].

    gains:
    -familiar problem in js
    -hasmap in js

    features, changelog:
    -2023.04

    @version 0.1 2021
*/


////////////////// LIBS

////////////////// DECL_IMPL

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    let map = {};   // [demo] hash map in js

    for (let i = 0; i < nums.length; i++) {
        let diff = target - nums[i];
        if (map[nums[i]] != null) {
            return [map[nums[i]], i];   // [demo] return an array
        } else {
            map[diff] = i;
        }
    }
};


let nums = [2, 7, 11, 15];
let target = 9;
let res = twoSum(nums, target);

console.log(res);


////////////////// DRIVER


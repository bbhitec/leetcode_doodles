/**
    @author [mst]
    @file   twosum.cpp
    @brief  leetcode problems series

    2215_diff_two_arrays
    Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
    answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
    answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
    Note that the integers in the lists may be returned in any order.

    gains:
    -sets in js

    @version 0.1 2023.05
*/


////////////////// LIBS

////////////////// DECL_IMPL

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[][]}
 *
 * simply build sets oyut of the arrays and then construct the desired answer
 *
 * sub: 76 75
 */
var findDifference = function(nums1, nums2) {
    let set1 = new Set(nums1);
    let set2 = new Set(nums2);
    let arr1 = [];
    let arr2 = [];

    set1.forEach(element => {
        if (!set2.has(element)) {
            arr1.push(element)
        }
    })
    set2.forEach(element => {
        if (!set1.has(element)) {
            arr2.push(element)
        }
    })

    return [arr1, arr2];
};

let nums1 = [1,2,3,3], nums2 = [1,1,2,2];
let res = findDifference(nums1, nums2);
console.log(res);


////////////////// DRIVER


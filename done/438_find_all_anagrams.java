package done;

/**
 * @author [mst]
 *
 * title or quick description
 *
 * full/optional description: this is a placeholder
 * template for new files creation
 *
 * gains:
 * -[wip] build java template and run tools
[wip] do the same for go
 *
 * @since 2023.02
 * @version 0.1
 **/

////////////////// LIBS
//import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;


////////////////// DECL_IMPL

class Solution {
    // good practice to define constant
    public static final int MAX = 256;

    public static List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();
        if (p == null || s == null || s.length() == 0 || p.length() > s.length()) {
            return res;
        }

        int[] targetMap = new int[MAX];
        int[] currentMap = new int[MAX];
        // init two maps
        for (int i = 0; i < p.length(); i++) {
            targetMap[p.charAt(i) - 'a']++;
            currentMap[s.charAt(i) - 'a']++;
        }

        int start = 0;
        int end = p.length();
        // Move two pointers
        while(end < s.length()) {
            if (isAnagram(currentMap, targetMap)) {
                res.add(start);
            }
            currentMap[s.charAt(start) - 'a']--;
            start++;
            currentMap[s.charAt(end) - 'a']++;
            end++;
        }
        // Don't forget the last step comparison
        if (isAnagram(currentMap, targetMap)) {
            res.add(start);
        }
        return res;
    }

    private static boolean isAnagram(int[] charMap, int[] targetMap) {
        for (int i = 0; i < MAX; i++) {
            if (charMap[i] != targetMap[i]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println("[mst] leetcode doodles");

        String s = "cbaebabacd", p = "abc";
		List<Integer> res = findAnagrams(s,p);

        System.out.printf("result for:%s and:%s %n", s,p);
		for (Integer i : res)
			System.out.println(i);
	}
}

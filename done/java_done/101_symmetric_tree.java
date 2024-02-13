// package done;

/**
    @author [bbht]
    @brief  leetcode problems series
    101_symmetric_tree
    Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

    gains:
	-algorithmic thinking in tree traversal
    -basic java classes and recursion
	-[next] run an example, build tree tools for it (array to list in java)

    @version 2023.02
 **/

////////////////// LIBS
//import java.util.Scanner;

////////////////// DECL_IMPL




class Solution101 {
	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode() {}
		TreeNode(int val) { this.val = val; }
		TreeNode(int val, TreeNode left, TreeNode right) {
			this.val = val;
			this.left = left;
			this.right = right;
		}
	}
    private boolean isSymmetric(TreeNode p, TreeNode q) {
        if (p == null || q == null)
            return p == q;
        return p.val == q.val && isSymmetric(p.left, q.right) && isSymmetric(p.right, q.left);
    }

    public boolean isSymmetric(TreeNode root) {
        return isSymmetric(root, root);
    }
}

class Driver {
    public static void main(String[] args) {
        System.out.println("[mst] leetcode doodles Solution101");

        Solution101 s = new Solution101();
        System.out.println(s);

    }

}

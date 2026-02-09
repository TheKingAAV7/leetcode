/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

import java.util.*;
class Solution {
    public void inorder(TreeNode root,Vector<Integer>v){
        if(root==null) return;
        inorder(root.left,v);
        v.add(root.val);
        inorder(root.right,v);
        return;

    }

    public TreeNode f(int lef, int rig, Vector<Integer>v){
        if(lef>rig) return null;
        if(lef==rig){
           
            return new TreeNode(v.get(lef));
        }
        int mid= (lef+rig)/2;
        TreeNode root= new TreeNode(v.get(mid));
        root.left=f(lef,mid-1,v);
        root.right=f(mid+1,rig,v);
        return root;
    }
    public TreeNode balanceBST(TreeNode root) {
        Vector<Integer>v= new Vector<>();
        inorder(root,v);
      //  for(int i:v) System.out.print(i+" ");

        int n=v.size();
        
        
        return f(0,n-1,v);
        
        
    }
}
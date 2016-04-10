package com.dacas.chepter4;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by dave on 2016/4/10.
 */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    int count;
    public TreeNode(){
       this(0);
    }
    public TreeNode(int val){
        this.val = val;
        left = null;
        right = null;
        count = 1;
    }
    public TreeNode(int val,TreeNode left,TreeNode right){
        this(val);
        this.left = left;
        this.right = right;
    }
    @Override
    public String toString(){
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(this);
        StringBuilder builder = new StringBuilder();

        while(!queue.isEmpty()){
            TreeNode head = queue.poll();
            if(head == null){
                builder.append('N');
            }
            else if(head.left != null || head.right != null){
                builder.append(head.val);
                queue.offer(head.left);
                queue.offer(head.right);
            }else{
                builder.append(head.val);
            }
        }
        return builder.toString();
    }
}

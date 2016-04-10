package com.dacas.chepter4;

/**
 * Created by dave on 2016/4/10.
 */
public class BSTImpl {
    //insert node
    public TreeNode insert(TreeNode root,int val){
        if(root == null){
            return new TreeNode(val);
        }
        if(root.val < val){
            root.right = insert(root.right,val);
        }else if(root.val > val){
            root.left = insert(root.left,val);
        }else{
            root.count++;
        }
        return root;
    }
    //find node
    public TreeNode findNode(TreeNode root,int val){
        if(root == null)
            return null;
        if(root.val < val)
            return findNode(root.right,val);
        if(root.val > val)
            return findNode(root.left, val);
        return root;
    }
    //find min
    public TreeNode findMin(TreeNode root){
        if(root == null)
            return null;
        if(root.left != null)
            return findMin(root.left);
        return root;
    }
    public TreeNode findMax(TreeNode root){
        if(root == null)
            return null;
        if(root.right != null)
            return findMax(root.right);
        return root;
    }
    public TreeNode findParents(TreeNode root,int val){
        if(root == null)
            return null;
        if(root.left != null && root.left.val == val || root.right != null && root.right.val == val){
            return root;
        }
        if(root.val < val)
            return findParents(root.right,val);
        else if(root.val > val)
            return findParents(root.left,val);
        return new TreeNode(-1,root,null);
    }
    //delete
    public void deleteNode(TreeNode root,int val){
        TreeNode parentNodeForDelete = findParents(root, val);
        if(parentNodeForDelete == null){
            System.out.println("node for delete not exist");
            return;
        }
        TreeNode nodeForDelete = null;
        boolean isLeft = false;
        if(parentNodeForDelete.left!=null && parentNodeForDelete.left.val == val) {
            isLeft = true;
            nodeForDelete = parentNodeForDelete.left;
        }else if(parentNodeForDelete.right!=null && parentNodeForDelete.right.val == val) {
            isLeft = false;
            nodeForDelete = parentNodeForDelete.right;
        }
        if(nodeForDelete.count > 1){
            nodeForDelete.count--;
            return;
        }
        if(nodeForDelete.left == null || nodeForDelete.right == null) {//待删除的节点有不多于一个子节点
            if(isLeft)
                parentNodeForDelete.left = nodeForDelete.left == null ? nodeForDelete.right:nodeForDelete.left;
            else
                parentNodeForDelete.right = nodeForDelete.left == null ? nodeForDelete.right:nodeForDelete.left;
        }else{//待删除的节点有两个子节点
            TreeNode rightMinNode = findMin(root.right);
            nodeForDelete.val = rightMinNode.val;
            deleteNode(nodeForDelete,rightMinNode.val);
        }
    }
}

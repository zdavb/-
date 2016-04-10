package com.dacas.chepter4;

/**
 * Created by dave on 2016/4/10.
 */
//第四章课后习题
public class Main {
    public static void main(String[] args) {
        //测试4.10
        test410();
    }
    //测试4.10题
    private static void test410(){
        BSTImpl impl = new BSTImpl();
        /***********插入*************/
        TreeNode root = impl.insert(null,3);
        impl.insert(root,1);
        impl.insert(root,4);
        impl.insert(root,6);
        impl.insert(root,9);
        impl.insert(root,2);
        impl.insert(root,5);
        impl.insert(root, 7);
        impl.insert(root, 6);

        System.out.println(root);
        /************查找*************/
        TreeNode minNode = impl.findMin(root);
        TreeNode maxNode = impl.findMax(root);
        System.out.println("min:"+minNode.val + ",max:"+maxNode.val);

        TreeNode searchNode = impl.findNode(root,6);
        System.out.println(searchNode.val+","+searchNode.count);
        searchNode = impl.findNode(root,11);
        if(searchNode == null)
            System.out.println("not exist");

        /**************删除**************/
        impl.deleteNode(root,7);
        System.out.println("delete val 7:"+root);
        impl.deleteNode(root,6);//因为6有两个值
        System.out.println("delete val 6:" + root);
        impl.deleteNode(root, 3);
        System.out.println("delete val 3:" + root);
    }
}

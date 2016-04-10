package com.dacas.chepter4;

/**
 * Created by dave on 2016/4/10.
 */
//�����¿κ�ϰ��
public class Main {
    public static void main(String[] args) {
        //����4.10
        test410();
    }
    //����4.10��
    private static void test410(){
        BSTImpl impl = new BSTImpl();
        /***********����*************/
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
        /************����*************/
        TreeNode minNode = impl.findMin(root);
        TreeNode maxNode = impl.findMax(root);
        System.out.println("min:"+minNode.val + ",max:"+maxNode.val);

        TreeNode searchNode = impl.findNode(root,6);
        System.out.println(searchNode.val+","+searchNode.count);
        searchNode = impl.findNode(root,11);
        if(searchNode == null)
            System.out.println("not exist");

        /**************ɾ��**************/
        impl.deleteNode(root,7);
        System.out.println("delete val 7:"+root);
        impl.deleteNode(root,6);//��Ϊ6������ֵ
        System.out.println("delete val 6:" + root);
        impl.deleteNode(root, 3);
        System.out.println("delete val 3:" + root);
    }
}

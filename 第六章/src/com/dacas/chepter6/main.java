package com.dacas.chepter6;

import java.util.Arrays;

/**
 * Created by dave on 2016/6/29.
 */
public class main {
    public static void main(String[] args) {
        //以插入形式建堆
        Heap firstHeap = new Heap(20);
        int[] nums = {10,12,1,14,6,5,8,15,3,9,7,4,11,13,2};
        for(int data:nums){
            firstHeap.insert(data);
        }
        System.out.println("插入建堆");
        firstHeap.printHeap();

        //直接建立堆
        Heap secondHeap = Heap.buildHeap(nums);
        System.out.println("直接建堆");
        secondHeap.printHeap();

        //deleteMin
        firstHeap.deleteMin();firstHeap.deleteMin();firstHeap.deleteMin();
        System.out.println("插入堆deleteMin 3次：");
        firstHeap.printHeap();

        secondHeap.deleteMin();secondHeap.deleteMin();secondHeap.deleteMin();
        System.out.println("直接堆deleteMin 3次");
        secondHeap.printHeap();

        firstHeap.increseKey(5, 5);
        System.out.println("在索引5处增加5时");
        firstHeap.printHeap();

        secondHeap.decreseKey(5, 5);
        System.out.println("在索引5处减少5");
        secondHeap.printHeap();

        secondHeap.delete(5);
        System.out.println("删除索引5后");
        secondHeap.printHeap();
    }
}

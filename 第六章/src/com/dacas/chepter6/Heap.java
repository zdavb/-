package com.dacas.chepter6;

/**
 * Created by dave on 2016/6/29.
 */
public class Heap {
    private int[] nums;
    int capacity;
    int size = 0;
    Heap(int capacity){
        nums = new int[capacity+1];
        nums[0] = Integer.MIN_VALUE;
        this.capacity = capacity;
    }
    //上滤
    void percolateUp(int index){
        if(index <= 0)
            return;
        int value = nums[index];
        int tmp;

        for(tmp = index;nums[tmp/2] > value;tmp/=2){
            nums[tmp] = nums[tmp/2];
        }
        nums[tmp] = value;
    }
    //下滤
    void percolateDown(int index){
        if(index <= 0)
            return;
        int value = nums[index];
        int child,i;

        for(i = index;i*2<=size;i=child){
            child = i*2;
            if(child < size && nums[child] > nums[child+1])
                ++child;
            if(nums[child] > value)
                break;
            else{
                nums[i] = nums[child];
            }
        }
        nums[i] = value;
    }
    //插入元素
    boolean insert(int value){
        if(size+1 > capacity)
            return false;
        nums[++size] = value;
        percolateUp(size);
        return true;
    }
    //删除最小元素
    int deleteMin(){
        if(size <= 0)
            return -1;
        int min = nums[1];
        nums[1] = nums[size--];
        percolateDown(1);
        return min;
    }
    //返回最小元素
    int findMin(){
        if(size <= 0)
            return -1;
        return nums[1];
    }
    //在索引位置处减少gap
    boolean decreseKey(int index,int gap){
        if(index <= 0 || index > size)
            return false;
        nums[index] -= gap;
        percolateUp(index);
        return true;
    }
    //在索引位置处增加gap
    boolean increseKey(int index,int gap){
        if(index <= 0 || index > size)
            return false;
        nums[index] += gap;
        percolateDown(index);
        return true;
    }
    //删除指定位置的元素
    boolean delete(int index){
        if(index <= 0 || index > size)
            return false;
        nums[index] = nums[size--];
        percolateDown(index);
        return true;
    }
    //建堆
    static Heap buildHeap(int[] nums){
        Heap heap = new Heap(nums.length);
        heap.size = nums.length;
        System.arraycopy(nums,0,heap.nums,1,nums.length);

        int index= nums.length;
        for(index/=2;index>0;index--){
            heap.percolateDown(index);
        }
        return heap;
    }
    //按层打印堆
    void printHeap(){
        StringBuilder builder = new StringBuilder();
        int level = 1;
        int indexWithinLevel;

        for(int i = 1;i<=size;){
            for(indexWithinLevel = 0;i<=size&&indexWithinLevel<level;indexWithinLevel++,i++){
                builder.append('-');
                builder.append(nums[i]);
            }
            builder.append('-');
            builder.append('\n');
            level*=2;
        }
        System.out.println(builder);
    }
}

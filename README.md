### 造轮子之 BitMap 实现

#### 思路

减少数据存放的占用内存大小的方式。考虑一个4字节int数值，也就是32bit，当有10000000个int会占用

```
4*10000000/1024/1024=38MB
```

若一个字节，占8bit，每个bit位用来标识下标数字是否存在，共需要

```
10000000/8/1024/1024=1.2MB
```

BitMap适合处理大量数据的加载、排序（鸽巢）和查询，缺点是无法对存在重复的数据进行排序和查找。做到这个需要建立一个十进制到二进制bit位的映射。

假设需要排序或者查找的总数N=10000000，那么我们需要申请的内存空间为 int a[N/32 + 1]。其中a[0]在内存中占32位：

```
a[0] ------> 0 - 31
a[1] ------> 32 - 63
a[2] ------> 64 - 95
a[3] ------> 96 - 127
...
```

需要以下转换：
1. 求十进制数 0-N 对应的在数组 a 中的下标。index_loc = N / 32即可，index_loc即为n对应的数组下标。例如n = 76，则loc = 76 / 32 = 2，因此76在a[2]中；
2. 求十进制数 0-N 对应的bit位。bit_loc = N % 32即可，例如 n = 76，bit_loc = 76 % 32 = 12；
3. 利用移位 0-31 使得对应的 32bit 位为 1 。

一般见到不重复的大量数字，都可以用位图。

本项目中使用`char[]`代替`int[]`作为BitMap的数据结构。

#### 进阶

线程安全设计
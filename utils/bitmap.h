//
// Created by GaoChong on 2020/5/7.
//

#ifndef GCBITMAP_BITMAP_H
#define GCBITMAP_BITMAP_H

#include <iostream>
#include "common.h"

GC_NS_BEGIN

    /*
     * BitMap轮子实现
     * 成员变量:
     *      1. nums_:       支持的最大存放容量
     *      2. size_:       需要的存储单元的个数, 这里使用的是char[]
     *      3. map_ptr_:    指向存储位置的智能指针
     * 对外接口:
     *      1. Get: 查看一个值是否在BitMap中, 存在返回1, 不存在返回0
     *      2. Set: 向BitMap中设置一个值, 成功返回1, 不成功返回0
     *      3. Del: 从BitMap中删除一个值, 成功返回1, 不成功返回0; 若原本就没有, 返回1
     * 注意事项:
     *      1. 最大存放容量类型是int32_t, 且受到BITMAP_CAPACITY限制
     *      2. 实现了拷贝语义和移动语义
     * */
    class BitMap
    {
    public:
        BitMap();

        explicit BitMap(int32_t nums);

        ~BitMap();

        BitMap(const BitMap &rhs);

        BitMap(BitMap &&rhs) noexcept;

        BitMap &operator=(const BitMap &rhs);

        BitMap &operator=(BitMap &&rhs) noexcept;

    public:
        int32_t Get(int32_t n) const;

        int32_t Set(int32_t n);

        int32_t Del(int32_t n);

    private:
        static u_int32_t LocateByte(int32_t n) ;

        static u_int32_t LocateBit(int32_t n) ;

    private:
        int32_t nums_;
        int32_t size_;
        std::shared_ptr<char> map_ptr_;
    };

GC_NS_END


#endif //GCBITMAP_BITMAP_H

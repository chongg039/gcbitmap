//
// Created by GaoChong on 2020/5/7.
//

#include "bitmap.h"

GC_NS_BEGIN

    BitMap::BitMap()
            : nums_(0),
              size_(0),
              map_ptr_(nullptr)
    {}

    BitMap::BitMap(int32_t nums)
            : nums_(nums),
              size_(0),
              map_ptr_(nullptr)
    {
        if (nums > BITMAP_CAPACITY) {
            nums_ = BITMAP_CAPACITY;
        }
        size_ = nums_ / BIT_OF_BYTE + 1;
        // 指定删除器
        map_ptr_ = std::shared_ptr<char>(new char[size_], std::default_delete<char[]>());
        if (map_ptr_ == nullptr) {
            std::cerr << "Fail to create bitmap!" << std::endl;
            // 这里会不会退出
            // 构造函数不能抛出异常
        } else {
            memset(map_ptr_.get(), 0x0, size_ * sizeof(char));
        }
    }

    BitMap::~BitMap() = default;

    BitMap::BitMap(const BitMap &rhs)
    {
        nums_ = rhs.nums_;
        size_ = rhs.size_;
        map_ptr_ = std::shared_ptr<char>(new char[size_], std::default_delete<char[]>());
        if (map_ptr_ == nullptr) {
            std::cerr << "Fail to create bitmap!" << std::endl;
            // 这里会不会退出
        } else {
            memcpy(map_ptr_.get(), rhs.map_ptr_.get(), size_);
        }
    }

    BitMap::BitMap(BitMap &&rhs) noexcept
    {
        nums_ = rhs.nums_;
        size_ = rhs.size_;
        map_ptr_ = rhs.map_ptr_;
        rhs.nums_ = 0;
        rhs.size_ = 0;
        rhs.map_ptr_.reset();
        rhs.map_ptr_ = nullptr;
    }

    BitMap &BitMap::operator=(const BitMap &rhs)
    {
        if (this != &rhs) {
            nums_ = rhs.nums_;
            size_ = rhs.size_;
            map_ptr_ = std::shared_ptr<char>(new char[size_], std::default_delete<char[]>());
            if (map_ptr_ == nullptr) {
                std::cerr << "Fail to create bitmap!" << std::endl;
                // 这里会不会退出
            } else {
                memcpy(map_ptr_.get(), rhs.map_ptr_.get(), size_);
            }
        }
        return *this;
    }

    BitMap &BitMap::operator=(BitMap &&rhs) noexcept
    {
        if (this != &rhs) {
            nums_ = rhs.nums_;
            size_ = rhs.size_;
            map_ptr_ = rhs.map_ptr_;
            rhs.nums_ = 0;
            rhs.size_ = 0;
            rhs.map_ptr_.reset();
            rhs.map_ptr_ = nullptr;
        }
        return *this;
    }

    int32_t BitMap::Get(int32_t n) const
    {
        u_int32_t loc_byte = LocateByte(n);
        u_int32_t loc_bit = LocateBit(n);
        unsigned char offset = 0x1u << loc_bit;
        if (loc_byte > size_) {
            return 0;
        } else {
            return ((unsigned) (map_ptr_.get()[loc_byte]) & offset) > 0 ? 1 : 0;
        }
    }

    int32_t BitMap::Set(int32_t n)
    {
        u_int32_t loc_byte = LocateByte(n);
        u_int32_t loc_bit = LocateBit(n);
        unsigned char offset = 0x1u << loc_bit;
        if (loc_byte > size_) {
            return 0;
        } else {
            map_ptr_.get()[loc_byte] |= offset;
            return 1;
        }
    }

    int32_t BitMap::Del(int32_t n)
    {
        if (Get(n) == 0) return 1;
        u_int32_t loc_byte = LocateByte(n);
        u_int32_t loc_bit = LocateBit(n);
        unsigned char offset = 0x1u << loc_bit;
        if (loc_byte > size_) {
            return 0;
        } else {
            map_ptr_.get()[loc_byte] ^= offset;
            return 1;
        }
    }

    u_int32_t BitMap::LocateByte(int32_t n)
    {
        return n / BIT_OF_BYTE;
    }

    u_int32_t BitMap::LocateBit(int32_t n)
    {
        return n % BIT_OF_BYTE;
    }

GC_NS_END
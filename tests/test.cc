//
// Created by GaoChong on 2020/5/7.
//
#include <iostream>
#include "../utils/bitmap.h"

int main()
{
    gc::BitMap mm(100000);
    std::cout << mm.Set(10) << " ";

    gc::BitMap bak = std::move(mm);
    std::cout << bak.Get(10) << " ";
    std::cout << mm.Get(10) << " ";
    return 0;
}
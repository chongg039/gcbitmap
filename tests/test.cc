//
// Created by GaoChong on 2020/5/7.
//
#include <iostream>

#include "gcbitmap/bitmap.h"
#include "gtest/gtest.h"

TEST(BitMapTest, GetTest) {
  gc::BitMap mm(100000);
  EXPECT_EQ(0, mm.Get(10));
}

TEST(BitMapTest, SetTest) {
  gc::BitMap mm(100000);
  mm.Set(10);
  EXPECT_EQ(1, mm.Get(10));
}

TEST(BitMapTest, DelTest) {
  gc::BitMap mm(100000);
  mm.Set(10);
  EXPECT_EQ(1, mm.Get(10));
  mm.Del(10);
  EXPECT_EQ(0, mm.Get(10));
}

TEST(BitMapTest, OutOfRange) {
  gc::BitMap mm(100);
  mm.Set(1000);
  EXPECT_EQ(0, mm.Get(1000));
}

TEST(BitMapTest, OutOfRangeDel) {
  gc::BitMap mm(100);
  mm.Del(1000);
  EXPECT_EQ(0, mm.Get(10));
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
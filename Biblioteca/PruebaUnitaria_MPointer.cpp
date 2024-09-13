#include "gtest/gtest.h"
#include "MPointer.h"
/*
#include <gtest/gtest.h>
#include "MPointer.h"
#include "MPointerGC.h" // Incluye MPointerGC para asegurarte de que está disponible

// Asume que MPointerGC tiene una implementación que permite resetear el estado para pruebas
class MPointerGCTestFixture : public ::testing::Test {
protected:
    void SetUp() override {
        //MPointerGC::getInstance().reset();
    }
};

TEST_F(MPointerGCTestFixture, CanCreateAndAssignPointer) {
    MPointer<int> ptr = MPointer<int>::New();
    *ptr = 10;

    EXPECT_EQ(*ptr, 10);
}

TEST_F(MPointerGCTestFixture, CanAssignValueToPointer) {
    MPointer<int> ptr = MPointer<int>::New();
    *ptr = 20;
    EXPECT_EQ(*ptr, 20);

    *ptr = 30;
    EXPECT_EQ(*ptr, 30);
}

TEST_F(MPointerGCTestFixture, CanCopyPointer) {
    MPointer<int> ptr1 = MPointer<int>::New();
    *ptr1 = 40;

    MPointer<int> ptr2 = ptr1;
    EXPECT_EQ(*ptr2, 40);

    *ptr2 = 50;
    EXPECT_EQ(*ptr1, 50);
    EXPECT_EQ(*ptr2, 50);
}

TEST_F(MPointerGCTestFixture, PointerComparison) {
    MPointer<int> ptr1 = MPointer<int>::New();
    MPointer<int> ptr2 = MPointer<int>::New();

    *ptr1 = 60;
    *ptr2 = 60;

    EXPECT_NE(ptr1, ptr2);

    MPointer<int> ptr3 = ptr1;
    EXPECT_EQ(ptr1, ptr3);
}*/



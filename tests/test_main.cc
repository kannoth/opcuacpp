#include <gtest/gtest.h>

int main(int argc, char **argv) {
  // Init gtest framework
  ::testing::InitGoogleTest(&argc, argv);

  // Run all tests
  return RUN_ALL_TESTS();
}
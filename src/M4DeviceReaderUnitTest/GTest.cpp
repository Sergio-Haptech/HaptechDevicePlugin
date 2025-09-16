#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char** argv)
{
  // Since Google Mock depends on Google Test,
  // InitGoogleMock() will invoke InitGoogleTest() internally.
  testing::InitGoogleMock(&argc, argv);
  auto gtest_result = RUN_ALL_TESTS();
  // If not specifying an output xml file
  if (testing::GTEST_FLAG(output).empty())
  {
    std::getchar(); // keep console window open until Return keystroke
  }
  return gtest_result;
}

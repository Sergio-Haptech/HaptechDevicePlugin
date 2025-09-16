#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "M4DeviceReaderUnitTest.h"

/*
* GEARS NOTES:
* This file contains an example of using the Google C++ Testing Framework (Google Test).
* Below you will find a sample Test Fixture class and a sample Test Case function.
*
* The Text Fixture class can be used when multiple tests need to operate on similar data.
* Use the Text Fixture to initialize and clean up any data needed by the Test Cases.
*
* The Test Case function is a simple example of how to check for an expected value.
* This Test Case should be replaced with Test Cases relevant to your source code.
*
* Also feel free to add additional cpp files to the Unit Test project that define
* more Test Fixtures and Test Cases. Google Test will find them and run them.
*
* Google Test Documentation:
* https://github.com/google/googletest/blob/master/docs/primer.md
*
* Google Mock Documentation:
* https://github.com/google/googletest/blob/master/docs/gmock_for_dummies.md
*
* REMINDER:
* The Unit Test project can utilize any functions or types defined in the static library.
*/

namespace gears
{
namespace test
{
class M4DeviceReaderTestFixture : public ::testing::Test
{
protected:
  void SetUp() override
  {
    // GEARS NOTE: Use the SetUp function to prepare the data needed for each test.
  }

  void TearDown() override
  {
    // GEARS NOTE: Use the TearDown function to clean up any resources allocated
    // by the SetUp function.
  }
};

TEST_F(M4DeviceReaderTestFixture, PassTest)
{
  // Test things...
  int test_value = 0;

  // Confirm tested things...
  EXPECT_EQ(0, test_value); // This is going to pass.
}

} // namespace test
} // namespace gears

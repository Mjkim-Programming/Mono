#include <gtest/gtest.h>

#include <mono/observable.hpp>

TEST(ObservableTest, SetGet) {
  obs::Observable<int> obs;
  bool called = false;

  obs.watch([&](const std::string& key, const int& value) {
    called = true;
    EXPECT_EQ(key, "x");
    EXPECT_EQ(value, 123);
  });

  obs.set("x", 123);
  EXPECT_EQ(obs.get("x"), 123);
  EXPECT_TRUE(called);
}

TEST(ObservableTest, OperatorAssignProxy) {
  obs::Observable<int> obs;
  bool called = false;

  obs.watch([&](const std::string& key, const int& value) {
    called = true;
    EXPECT_EQ(key, "y");
    EXPECT_EQ(value, 456);
  });

  obs["y"] = 456;
  EXPECT_EQ(int(obs["y"]), 456);
  EXPECT_TRUE(called);
}

TEST(ObservableTest, MultipleWatchers) {
  obs::Observable<int> obs;
  int count1 = 0, count2 = 0;

  obs.watch([&](const std::string&, const int&) { count1++; });
  obs.watch([&](const std::string&, const int&) { count2++; });

  obs.set("a", 1);
  obs["b"] = 2;

  EXPECT_EQ(count1, 2);
  EXPECT_EQ(count2, 2);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
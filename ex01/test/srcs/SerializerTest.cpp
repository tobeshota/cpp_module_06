#include "TestUtils.cpp"

// シリアライズ前後で同じ値が取得できる
TEST(SerializerTest, SerializerTest) {
  Data* data = getData("username", 42, "VeryStrongPassword!");
  uintptr_t data_raw = Serializer::serialize(data);
  Data* deserializedData = Serializer::deserialize(data_raw);

  EXPECT_TRUE(getCapturedConvertStdout(data) ==
              getCapturedConvertStdout(deserializedData));
  delete data;
}

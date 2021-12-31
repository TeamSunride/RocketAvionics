//
// Created by Tom Danvers on 30/12/2021.
// 2021 TeamSunride.
//

#include "unity.h"
#include "Arduino.h"
#include "SD.h"

const int csPin = BUILTIN_SDCARD;  // change this if not using a Teensy

void test_SD_begin() {
    TEST_ASSERT_TRUE(SD.begin(csPin));
}

void test_SD_mkdir() {
    TEST_ASSERT_TRUE(SD.mkdir("test_dir"));
    TEST_ASSERT_TRUE(SD.exists("test_dir"));
    TEST_ASSERT_TRUE(SD.rmdir("test_dir"));
    TEST_ASSERT_FALSE(SD.exists("test_dir"));
}

void test_SD_files() {
    const char *filepath = "test.txt";
    File file = SD.open(filepath, FILE_WRITE);

    // test that created file exists
    TEST_ASSERT_TRUE(SD.exists(filepath));

    String message = "Hello World";
    file.print(message);

    file.close();

    File file2 = SD.open(filepath, FILE_READ);
    TEST_ASSERT_TRUE(message == file2.readString());
    SD.remove(filepath);
    TEST_ASSERT_FALSE(SD.exists(filepath));

}

void setup() {
    UNITY_BEGIN();
    // delay (2000); // uncomment if using an Arduino rather than a Teensy
    Serial.begin(9600);
    RUN_TEST(test_SD_begin);
    RUN_TEST(test_SD_mkdir);
    RUN_TEST(test_SD_files);

    UNITY_END();
}

void loop() {

}
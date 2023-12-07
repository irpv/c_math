#include <check.h>
#include <float.h>
#include <stdint.h>

#include "tests.h"

START_TEST(floor_1) {
  for (double x = -100; x < 100; x += 0.3) {
    ck_assert_double_eq(s21_floor(x), floor(x));
  }
}
END_TEST

START_TEST(floor_2) { ck_assert_double_eq(s21_floor('\0'), floor('\0')); }
END_TEST

START_TEST(floor_3) { ck_assert_float_infinite(s21_floor(1. / 0.)); }
END_TEST

START_TEST(floor_4) { ck_assert_float_infinite(s21_floor(-1. / 0.)); }
END_TEST

START_TEST(floor_5) { ck_assert_double_nan(s21_floor(0. / 0.)); }
END_TEST

START_TEST(floor_6) { ck_assert_double_eq(s21_floor(DBL_MAX), floor(DBL_MAX)); }
END_TEST

Suite *suite_floor() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_floor" RESET);
  TCase *tc = tcase_create("strcsuite_floor_tc");

  tcase_add_test(tc, floor_1);
  tcase_add_test(tc, floor_2);
  tcase_add_test(tc, floor_3);
  tcase_add_test(tc, floor_4);
  tcase_add_test(tc, floor_5);
  tcase_add_test(tc, floor_6);

  suite_add_tcase(s, tc);

  return s;
}

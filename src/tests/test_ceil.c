#include <check.h>
#include <stdint.h>

#include "tests.h"

START_TEST(ceil_1) {
  for (double x = -100; x < 100; x += 0.3) {
    ck_assert_double_eq(s21_ceil(x), ceil(x));
  }
}
END_TEST

START_TEST(ceil_2) { ck_assert_double_eq(s21_ceil('\0'), ceil('\0')); }
END_TEST

START_TEST(ceil_3) { ck_assert_float_infinite(s21_ceil(1. / 0.)); }
END_TEST

START_TEST(ceil_4) { ck_assert_float_infinite(s21_ceil(-1. / 0.)); }
END_TEST

START_TEST(ceil_5) { ck_assert_double_eq(s21_ceil(DBL_MAX), ceil(DBL_MAX)); }
END_TEST

START_TEST(ceil_6) { ck_assert_double_nan(s21_ceil(0. / 0.)); }
END_TEST

Suite *suite_ceil() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_ceil" RESET);
  TCase *tc = tcase_create("strcsuite_ceil_tc");

  tcase_add_test(tc, ceil_1);
  tcase_add_test(tc, ceil_2);
  tcase_add_test(tc, ceil_3);
  tcase_add_test(tc, ceil_4);
  tcase_add_test(tc, ceil_5);
  tcase_add_test(tc, ceil_6);

  suite_add_tcase(s, tc);

  return s;
}

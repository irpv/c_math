#include <check.h>
#include <stdint.h>

#include "tests.h"

START_TEST(asin_1) {
  for (double x = -0.999; x < 0.999; x += 0.02) {
    ck_assert_float_eq((s21_asin(x)), (asin(x)));
  }
}
END_TEST

START_TEST(asin_2) { ck_assert_double_nan(s21_asin(s21_PI_div2)); }
END_TEST

START_TEST(asin_3) { ck_assert_double_nan(s21_asin(-s21_PI_div2)); }
END_TEST

START_TEST(asin_4) { ck_assert_double_eq_tol(s21_asin(1), asin(1), 1e-04); }
END_TEST

START_TEST(asin_5) { ck_assert_double_eq_tol(s21_asin(-1), asin(-1), 1e-04); }
END_TEST

START_TEST(asin_6) {
  ck_assert_double_eq_tol(s21_asin('\0'), asin('\0'), 1e-06);
}
END_TEST

START_TEST(asin_7) { ck_assert_double_nan(s21_asin(1.0 / 0.0)); }
END_TEST

START_TEST(asin_8) { ck_assert_double_nan(s21_asin(-1.0 / 0.0)); }
END_TEST

START_TEST(asin_9) { ck_assert_double_nan(s21_asin(0.0 / 0.0)); }
END_TEST

Suite *suite_asin() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_asin" RESET);
  TCase *tc = tcase_create("strcsuite_asin_tc");

  tcase_add_test(tc, asin_1);
  tcase_add_test(tc, asin_2);
  tcase_add_test(tc, asin_3);
  tcase_add_test(tc, asin_4);
  tcase_add_test(tc, asin_5);
  tcase_add_test(tc, asin_6);
  tcase_add_test(tc, asin_7);
  tcase_add_test(tc, asin_8);
  tcase_add_test(tc, asin_9);

  suite_add_tcase(s, tc);

  return s;
}

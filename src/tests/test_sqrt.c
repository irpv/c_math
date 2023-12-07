#include <check.h>
#include <stdint.h>
#include <stdio.h>

#include "tests.h"

START_TEST(sqrt_1) {
  for (double x = 0.0; x <= 100.0; x += 0.21) {
    ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), 1e-06);
  }
}
END_TEST

START_TEST(sqrt_2) { ck_assert_ldouble_nan(s21_sqrt(-1. / 0.)); }
END_TEST

START_TEST(sqrt_3) { ck_assert_float_infinite(s21_sqrt(1. / 0.)); }
END_TEST

Suite *suite_sqrt() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_sqrt" RESET);
  TCase *tc = tcase_create("strcsuite_sqrt_tc");

  tcase_add_test(tc, sqrt_1);
  tcase_add_test(tc, sqrt_2);
  tcase_add_test(tc, sqrt_3);

  suite_add_tcase(s, tc);

  return s;
}

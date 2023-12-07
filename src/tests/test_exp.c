#include <check.h>
#include <stdint.h>
#include <stdio.h>

#include "tests.h"

START_TEST(exp_1) {
  for (double x = 0.0; x <= 10.0; x += 0.21) {
    ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-06);
  }
}
END_TEST

START_TEST(exp_2) { ck_assert_ldouble_nan(s21_exp(0. / 0.)); }
END_TEST

START_TEST(exp_3) { ck_assert_float_infinite(s21_exp(1. / 0.)); }
END_TEST

START_TEST(exp_4) {
  ck_assert_ldouble_eq_tol(s21_exp(-1. / 0.), exp(-1. / 0.), 1e-06);
}
END_TEST

Suite *suite_exp() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_exp" RESET);
  TCase *tc = tcase_create("strcsuite_exp_tc");

  tcase_add_test(tc, exp_1);
  tcase_add_test(tc, exp_2);
  tcase_add_test(tc, exp_3);
  tcase_add_test(tc, exp_4);

  suite_add_tcase(s, tc);

  return s;
}

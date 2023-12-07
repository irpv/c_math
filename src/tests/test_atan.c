#include <check.h>
#include <stdint.h>

#include "tests.h"

START_TEST(atan_1) {
  for (double x = -1; x < 1; x += 0.1) {
    ck_assert_double_eq_tol((s21_atan(x)), (atan(x)), 1e-06);
  }
}
END_TEST

START_TEST(atan_2) {
  for (double x = -2; x < -1; x += 0.1) {
    ck_assert_double_eq_tol((s21_atan(x)), (atan(x)), 1e-06);
  }
}
END_TEST

START_TEST(atan_3) {
  for (double x = 1; x < 2; x += 0.1) {
    ck_assert_double_eq_tol((s21_atan(x)), (atan(x)), 1e-06);
  }
}
END_TEST

START_TEST(atan_4) {
  ck_assert_double_eq_tol(s21_atan('\0'), atan('\0'), 1e-06);
}
END_TEST

START_TEST(atan_5) {
  ck_assert_double_eq_tol(s21_atan(s21_PI_div2), atan(s21_PI_div2), 1e-06);
}
END_TEST

START_TEST(atan_6) {
  ck_assert_double_eq_tol(s21_atan(-s21_PI_div2), atan(-s21_PI_div2), 1e-06);
}
END_TEST

START_TEST(atan_7) {
  ck_assert_double_eq_tol(s21_atan(1. / 0.), atan(1. / 0.), 1e-04);
}
END_TEST

START_TEST(atan_8) {
  ck_assert_double_eq_tol(s21_atan(-1. / 0.), atan(-1. / 0.), 1e-04);
}
END_TEST

START_TEST(atan_9) { ck_assert_double_nan(s21_atan(0.0 / 0.0)); }
END_TEST

Suite *suite_atan() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_atan" RESET);
  TCase *tc = tcase_create("strcsuite_atan_tc");

  tcase_add_test(tc, atan_1);
  tcase_add_test(tc, atan_2);
  tcase_add_test(tc, atan_3);
  tcase_add_test(tc, atan_4);
  tcase_add_test(tc, atan_5);
  tcase_add_test(tc, atan_6);
  tcase_add_test(tc, atan_7);
  tcase_add_test(tc, atan_8);
  tcase_add_test(tc, atan_9);

  suite_add_tcase(s, tc);

  return s;
}

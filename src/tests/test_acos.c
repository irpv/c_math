#include <check.h>
#include <stdint.h>

#include "tests.h"

START_TEST(acos_1) {
  for (double x = -0.999; x < 0.999; x += 0.02) {
    ck_assert_float_eq((s21_acos(x)), (acos(x)));
  }
}
END_TEST

START_TEST(acos_2) { ck_assert_double_nan(s21_acos(s21_PI)); }
END_TEST

START_TEST(acos_3) { ck_assert_double_nan(s21_acos(-s21_PI)); }
END_TEST

START_TEST(acos_4) { ck_assert_double_eq_tol(s21_acos(1), acos(1), 1e-04); }
END_TEST

START_TEST(acos_5) { ck_assert_double_eq_tol(s21_acos(-1), acos(-1), 1e-04); }
END_TEST

START_TEST(acos_6) {
  ck_assert_double_eq_tol(s21_acos('\0'), acos('\0'), 1e-06);
}
END_TEST

START_TEST(acos_7) { ck_assert_double_nan(s21_acos(1.0 / 0.0)); }
END_TEST

START_TEST(acos_8) { ck_assert_double_nan(s21_acos(-1.0 / 0.0)); }
END_TEST

START_TEST(acos_9) { ck_assert_double_nan(s21_acos(0.0 / 0.0)); }
END_TEST

START_TEST(acos_10) { ck_assert_double_nan(s21_acos(1000)); }
END_TEST

START_TEST(acos_11) { ck_assert_double_nan(s21_acos(-1000)); }
END_TEST

Suite *suite_acos() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_acos" RESET);
  TCase *tc = tcase_create("strcsuite_acos_tc");

  tcase_add_test(tc, acos_1);
  tcase_add_test(tc, acos_2);
  tcase_add_test(tc, acos_3);
  tcase_add_test(tc, acos_4);
  tcase_add_test(tc, acos_5);
  tcase_add_test(tc, acos_6);
  tcase_add_test(tc, acos_7);
  tcase_add_test(tc, acos_8);
  tcase_add_test(tc, acos_9);
  tcase_add_test(tc, acos_10);
  tcase_add_test(tc, acos_11);

  suite_add_tcase(s, tc);

  return s;
}

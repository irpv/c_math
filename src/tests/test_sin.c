#include <check.h>
#include <stdint.h>

#include "tests.h"

START_TEST(sin_1) {
  for (double x = -10; x < 10; x += 0.05) {
    ck_assert_double_eq_tol((s21_sin(x)), (sin(x)), 1e-06);
  }
}
END_TEST

START_TEST(sin_2) { ck_assert_double_eq(s21_sin('\0'), sin('\0')); }
END_TEST

START_TEST(sin_3) { ck_assert_double_nan(s21_sin(1.0 / 0.0)); }
END_TEST

START_TEST(sin_4) { ck_assert_double_nan(s21_sin(-1.0 / 0.0)); }
END_TEST

START_TEST(sin_5) { ck_assert_double_nan(s21_sin(0.0 / 0.0)); }
END_TEST

START_TEST(sin_6) {
  ck_assert_double_eq_tol(s21_sin(s21_PI / 6), sin(s21_PI / 6), 1e-06);
}
END_TEST

START_TEST(sin_7) {
  ck_assert_double_eq_tol(s21_sin(s21_PI / 4), sin(s21_PI / 4), 1e-06);
}
END_TEST

START_TEST(sin_8) {
  ck_assert_double_eq_tol(s21_sin(s21_PI / 3), sin(s21_PI / 3), 1e-06);
}
END_TEST

START_TEST(sin_9) {
  ck_assert_double_eq_tol(s21_sin(s21_PI / 2), sin(s21_PI / 2), 1e-06);
}
END_TEST

START_TEST(sin_10) {
  ck_assert_double_eq_tol(s21_sin(3 * s21_PI / 2), sin(3 * s21_PI / 2), 1e-06);
}
END_TEST

START_TEST(sin_11) {
  ck_assert_double_eq_tol(s21_sin(2 * s21_PI), sin(2 * s21_PI), 1e-06);
}
END_TEST

START_TEST(sin_12) {
  ck_assert_double_eq_tol(s21_sin(-2 * s21_PI), sin(-2 * s21_PI), 1e-06);
}
END_TEST

START_TEST(sin_13) {
  ck_assert_double_eq_tol(s21_sin(-3 * s21_PI), sin(-3 * s21_PI), 1e-06);
}
END_TEST

START_TEST(sin_14) {
  ck_assert_double_eq_tol(s21_sin(-s21_PI), sin(-s21_PI), 1e-06);
}
END_TEST

START_TEST(sin_15) {
  ck_assert_double_eq_tol(s21_sin(s21_PI), sin(s21_PI), 1e-06);
}
END_TEST

START_TEST(sin_16) {
  ck_assert_double_eq_tol(s21_sin(-174.532925199433), sin(-174.532925199433),
                          1e-06);
}
END_TEST

START_TEST(sin_17) {
  ck_assert_double_eq_tol(s21_sin(174.532925199433), sin(174.532925199433),
                          1e-06);
}
END_TEST

Suite *suite_sin() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_sin" RESET);
  TCase *tc = tcase_create("strcsuite_sin_tc");

  tcase_add_test(tc, sin_1);
  tcase_add_test(tc, sin_2);
  tcase_add_test(tc, sin_3);
  tcase_add_test(tc, sin_4);
  tcase_add_test(tc, sin_5);
  tcase_add_test(tc, sin_6);
  tcase_add_test(tc, sin_7);
  tcase_add_test(tc, sin_8);
  tcase_add_test(tc, sin_9);
  tcase_add_test(tc, sin_10);
  tcase_add_test(tc, sin_11);
  tcase_add_test(tc, sin_12);
  tcase_add_test(tc, sin_13);
  tcase_add_test(tc, sin_14);
  tcase_add_test(tc, sin_15);
  tcase_add_test(tc, sin_16);
  tcase_add_test(tc, sin_17);

  suite_add_tcase(s, tc);

  return s;
}

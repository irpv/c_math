#include <check.h>
#include <stdint.h>

#include "tests.h"

START_TEST(cos_1) {
  for (double x = -10; x < 10; x += 0.05) {
    ck_assert_double_eq_tol((s21_cos(x)), (cos(x)), 1e-06);
  }
}
END_TEST

START_TEST(cos_2) {
  ck_assert_double_eq_tol((s21_cos('\0')), (cos('\0')), 1e-06);
  ;
}
END_TEST

START_TEST(cos_3) { ck_assert_double_nan(s21_cos(1.0 / 0.0)); }
END_TEST

START_TEST(cos_4) { ck_assert_double_nan(s21_cos(-1.0 / 0.0)); }
END_TEST

START_TEST(cos_5) { ck_assert_double_nan(s21_cos(0.0 / 0.0)); }
END_TEST

START_TEST(cos_6) {
  ck_assert_double_eq_tol(s21_cos(s21_PI / 6), cos(s21_PI / 6), 1e-06);
}
END_TEST

START_TEST(cos_7) {
  ck_assert_double_eq_tol(s21_cos(s21_PI / 4), cos(s21_PI / 4), 1e-06);
}
END_TEST

START_TEST(cos_8) {
  ck_assert_double_eq_tol(s21_cos(s21_PI / 3), cos(s21_PI / 3), 1e-06);
}
END_TEST

START_TEST(cos_9) {
  ck_assert_double_eq_tol(s21_cos(s21_PI / 2), cos(s21_PI / 2), 1e-06);
}
END_TEST

START_TEST(cos_10) {
  ck_assert_double_eq_tol(s21_cos(3 * s21_PI / 2), cos(3 * s21_PI / 2), 1e-06);
}
END_TEST

START_TEST(cos_11) {
  ck_assert_double_eq_tol(s21_cos(2 * s21_PI), cos(2 * s21_PI), 1e-06);
}
END_TEST

START_TEST(cos_12) {
  ck_assert_double_eq_tol(s21_cos(-2 * s21_PI), cos(-2 * s21_PI), 1e-06);
}
END_TEST

START_TEST(cos_13) {
  ck_assert_double_eq_tol(s21_cos(-3 * s21_PI), cos(-3 * s21_PI), 1e-06);
}
END_TEST

START_TEST(cos_14) {
  ck_assert_double_eq_tol(s21_cos(-s21_PI), cos(-s21_PI), 1e-06);
}
END_TEST

START_TEST(cos_15) {
  ck_assert_double_eq_tol(s21_cos(s21_PI), cos(s21_PI), 1e-06);
}
END_TEST

START_TEST(cos_16) {
  ck_assert_double_eq_tol(s21_cos(-174.532925199433), cos(-174.532925199433),
                          1e-06);
}
END_TEST

START_TEST(cos_17) {
  ck_assert_double_eq_tol(s21_cos(174.532925199433), cos(174.532925199433),
                          1e-06);
}
END_TEST

Suite *suite_cos() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_cos" RESET);
  TCase *tc = tcase_create("strcsuite_cos_tc");

  tcase_add_test(tc, cos_1);
  tcase_add_test(tc, cos_2);
  tcase_add_test(tc, cos_3);
  tcase_add_test(tc, cos_4);
  tcase_add_test(tc, cos_5);
  tcase_add_test(tc, cos_6);
  tcase_add_test(tc, cos_7);
  tcase_add_test(tc, cos_8);
  tcase_add_test(tc, cos_9);
  tcase_add_test(tc, cos_10);
  tcase_add_test(tc, cos_11);
  tcase_add_test(tc, cos_12);
  tcase_add_test(tc, cos_13);
  tcase_add_test(tc, cos_14);
  tcase_add_test(tc, cos_15);
  tcase_add_test(tc, cos_16);
  tcase_add_test(tc, cos_17);

  suite_add_tcase(s, tc);

  return s;
}

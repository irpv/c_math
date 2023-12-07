#include <check.h>
#include <stdint.h>

#include "tests.h"

START_TEST(tan_1) {
  for (double x = -10; x < 10; x += 0.2) {
    ck_assert_double_eq_tol((s21_tan(x)), (tan(x)), 1e-06);
  }
}
END_TEST

START_TEST(tan_2) {
  ck_assert_double_eq_tol((s21_tan('\0')), (tan('\0')), 1e-06);
  ;
}
END_TEST

START_TEST(tan_3) { ck_assert_double_nan(s21_tan(1.0 / 0.0)); }
END_TEST

START_TEST(tan_4) { ck_assert_double_nan(s21_tan(-1.0 / 0.0)); }
END_TEST

START_TEST(tan_5) { ck_assert_double_nan(s21_tan(0.0 / 0.0)); }
END_TEST

START_TEST(tan_6) {
  ck_assert_double_eq_tol(s21_tan(s21_PI / 6), tan(s21_PI / 6), 1e-06);
}
END_TEST

START_TEST(tan_7) {
  ck_assert_double_eq_tol(s21_tan(s21_PI / 4), tan(s21_PI / 4), 1e-06);
}
END_TEST

START_TEST(tan_8) {
  ck_assert_double_eq_tol(s21_tan(s21_PI / 3), tan(s21_PI / 3), 1e-06);
}
END_TEST

START_TEST(tan_9) {
  ck_assert_double_eq_tol(s21_tan(s21_PI / 2), tan(s21_PI / 2), 1e-06);
}
END_TEST

START_TEST(tan_10) {
  ck_assert_double_eq_tol(s21_tan(3 * s21_PI / 4), tan(3 * s21_PI / 4), 1e-06);
}
END_TEST

START_TEST(tan_11) {
  ck_assert_double_eq_tol(s21_tan(2 * s21_PI), tan(2 * s21_PI), 1e-06);
}
END_TEST

START_TEST(tan_12) {
  ck_assert_double_eq_tol(s21_tan(-2 * s21_PI), tan(-2 * s21_PI), 1e-06);
}
END_TEST

START_TEST(tan_13) {
  ck_assert_double_eq_tol(s21_tan(-3 * s21_PI), tan(-3 * s21_PI), 1e-06);
}
END_TEST

START_TEST(tan_14) {
  ck_assert_double_eq_tol(s21_tan(-s21_PI), tan(-s21_PI), 1e-06);
}
END_TEST

START_TEST(tan_15) {
  ck_assert_double_eq_tol(s21_tan(s21_PI), tan(s21_PI), 1e-06);
}
END_TEST

START_TEST(tan_16) {
  ck_assert_double_eq_tol(s21_tan(-174.532925199433), tan(-174.532925199433),
                          1e-06);
}
END_TEST

START_TEST(tan_17) {
  ck_assert_double_eq_tol(s21_tan(174.532925199433), tan(174.532925199433),
                          1e-06);
}
END_TEST

START_TEST(tan_18) {
  ck_assert_double_eq_tol(s21_tan(-s21_PI / 2), tan(-s21_PI / 2), 1e-06);
}
END_TEST

Suite *suite_tan() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_tan" RESET);
  TCase *tc = tcase_create("strcsuite_tan_tc");

  tcase_add_test(tc, tan_1);
  tcase_add_test(tc, tan_2);
  tcase_add_test(tc, tan_3);
  tcase_add_test(tc, tan_4);
  tcase_add_test(tc, tan_5);
  tcase_add_test(tc, tan_6);
  tcase_add_test(tc, tan_7);
  tcase_add_test(tc, tan_8);
  tcase_add_test(tc, tan_9);
  tcase_add_test(tc, tan_10);
  tcase_add_test(tc, tan_11);
  tcase_add_test(tc, tan_12);
  tcase_add_test(tc, tan_13);
  tcase_add_test(tc, tan_14);
  tcase_add_test(tc, tan_15);
  tcase_add_test(tc, tan_16);
  tcase_add_test(tc, tan_17);
  tcase_add_test(tc, tan_18);

  suite_add_tcase(s, tc);

  return s;
}

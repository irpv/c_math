#include <check.h>
#include <stdint.h>
#include <stdio.h>

#include "tests.h"

START_TEST(log_1) {
  for (double x = 0.1; x <= 100.0; x += 0.21) {
    // printf("log(%lf) is %lf\n", x, log(x));
    ck_assert_float_eq(((s21_log(x))), ((log(x))));
  }
}
END_TEST

START_TEST(log_2) { ck_assert_float_eq(((s21_log(0))), ((log(0)))); }
END_TEST

START_TEST(log_3) { ck_assert_float_nan(((s21_log(-0. / 0.)))); }
END_TEST

START_TEST(log_4) { ck_assert_float_nan(((s21_log(0. / 0.)))); }
END_TEST

START_TEST(log_5) { ck_assert_float_nan(((s21_log(-1. / 0.)))); }
END_TEST

START_TEST(log_6) { ck_assert_float_infinite(((s21_log(1. / 0.)))); }
END_TEST

START_TEST(log_7) {
  for (double x = -10; x > 0; x += 0.21) {
    ck_assert_float_nan(((s21_log(1. / 0.))));
  }
}
END_TEST

Suite *suite_log() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_log" RESET);
  TCase *tc = tcase_create("strcsuite_log_tc");

  tcase_add_test(tc, log_1);
  tcase_add_test(tc, log_2);
  tcase_add_test(tc, log_3);
  tcase_add_test(tc, log_4);
  tcase_add_test(tc, log_5);
  tcase_add_test(tc, log_6);
  tcase_add_test(tc, log_7);

  suite_add_tcase(s, tc);

  return s;
}

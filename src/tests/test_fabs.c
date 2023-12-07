#include <check.h>
#include <stdint.h>

#include "tests.h"

START_TEST(fabs_1) {
  for (double x = -10.0; x < 10.0; x += 0.5) {
    ck_assert_double_eq(s21_fabs(x), fabs(x));
  }
}
END_TEST

START_TEST(fabs_2) { ck_assert_double_eq(s21_fabs(-0.0), fabs(-0.0)); }
END_TEST

START_TEST(fabs_3) {
  ck_assert_double_eq(s21_fabs(1.0 / 0.0), fabs(1.0 / 0.0));
}
END_TEST

START_TEST(fabs_4) {
  ck_assert_double_eq(s21_fabs(-1.0 / 0.0), fabs(-1.0 / 0.0));
}
END_TEST

Suite *suite_fabs() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_fabs" RESET);
  TCase *tc = tcase_create("strcsuite_fabs_tc");

  tcase_add_test(tc, fabs_1);
  tcase_add_test(tc, fabs_2);
  tcase_add_test(tc, fabs_3);
  tcase_add_test(tc, fabs_4);

  suite_add_tcase(s, tc);

  return s;
}

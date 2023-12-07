#include <check.h>
#include <stdint.h>

#include "tests.h"

START_TEST(abs_1) {
  for (int x = -100; x < 100; x++) {
    ck_assert_int_eq(s21_abs(x), abs(x));
  }
}
END_TEST

START_TEST(abs_2) { ck_assert_int_eq(s21_abs('\0'), abs('\0')); }
END_TEST

Suite *suite_abs() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_abs" RESET);
  TCase *tc = tcase_create("strcsuite_abs_tc");

  tcase_add_test(tc, abs_1);
  tcase_add_test(tc, abs_2);

  suite_add_tcase(s, tc);

  return s;
}

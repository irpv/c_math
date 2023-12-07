#include <check.h>
#include <stdint.h>
#include <stdio.h>

#include "tests.h"

START_TEST(fmod_1) {
  for (double x = -10.0; x <= 10.0; x += 0.65) {
    for (double y = 10.0; y >= -10.0; y -= 0.76) {
      ck_assert_double_eq_tol((s21_fmod(x, y)), (fmod(x, y)), 1e-06);
    }
  }
}
END_TEST

START_TEST(fmod_2) { ck_assert_float_nan((s21_fmod(-0.0, 0.0))); }
END_TEST

START_TEST(fmod_3) { ck_assert_float_nan((s21_fmod(1.0 / 0.0, 1.0 / 0.0))); }
END_TEST

START_TEST(fmod_4) { ck_assert_float_nan((s21_fmod(-1.0 / 0.0, -1.0 / 0.0))); }
END_TEST

Suite *suite_fmod() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_fmod" RESET);
  TCase *tc = tcase_create("strcsuite_fmod_tc");

  tcase_add_test(tc, fmod_1);
  tcase_add_test(tc, fmod_2);
  tcase_add_test(tc, fmod_3);
  tcase_add_test(tc, fmod_4);

  suite_add_tcase(s, tc);

  return s;
}

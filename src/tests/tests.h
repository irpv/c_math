#ifndef SRC_TESTS_TESTS_H_
#define SRC_TESTS_TESTS_H_

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_math.h"

#define RESET "\x1b[0m"
#define YELLOW_BG "\x1b[43m"
#define BLACK "\x1b[30m"

#define RED_BG "\x1b[41m"
#define GREEN_BG "\x1b[42m"
#define WHITE_BG "\x1b[47m"

Suite *suite_abs();
Suite *suite_fabs();
Suite *suite_fmod();
Suite *suite_log();
Suite *suite_sqrt();
Suite *suite_exp();
Suite *suite_pow();
Suite *suite_ceil();
Suite *suite_floor();
Suite *suite_sin();
Suite *suite_cos();
Suite *suite_tan();
Suite *suite_asin();
Suite *suite_acos();
Suite *suite_atan();

void run();

#endif  // SRC_TESTS_TESTS_H_

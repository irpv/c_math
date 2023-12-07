// #include "math_suitecases.h"
#include "tests.h"

START_TEST(pow_8) {
  long double base = -16.161435;
  long double exp = 9.;
  ck_assert_float_eq(s21_pow(base, exp), pow(base, exp));
}
END_TEST

START_TEST(pow_9) {
  long double base = -10.1261;
  long double exp = -0.72;
  ck_assert_double_nan(s21_pow(base, exp));
  ck_assert_double_nan(pow(base, exp));
}
END_TEST

START_TEST(pow_10) {
  long double base = +0;
  long double exp = -0.33;
  ck_assert_float_infinite(s21_pow(base, exp));
  ck_assert_float_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_12) {
  long double base = -0;
  long double exp = -0.33;
  ck_assert_float_infinite(s21_pow(base, exp));
  ck_assert_float_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_13) {
  long double base = -0;
  long double exp = 1. / 0.;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), s21_eps);
}
END_TEST

START_TEST(pow_14) {
  long double base = +0;
  long double exp = 123;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_15) {
  long double base = -0;
  long double exp = 123;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_16) {
  long double base = -0;
  long double exp = 1. / 0.;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_17) {
  long double base = -1;
  long double exp = 1. / 0.;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_18) {
  long double base = -1;
  long double exp = 0. / 0.;
  ck_assert_double_nan(pow(base, exp));
  ck_assert_double_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_19) {
  long double base = 0. / 0.;
  long double exp = 0;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_20) {
  long double base = -123;
  long double exp = 0. / 0.;
  ck_assert_double_nan(s21_pow(base, exp));
  ck_assert_double_nan(pow(base, exp));
}
END_TEST

START_TEST(pow_21) {
  long double base = 0.5591951;
  long double exp = -1. / 0.;
  ck_assert_float_infinite(pow(base, exp));
  ck_assert_float_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_22) {
  long double base = 1.5591951;
  long double exp = -1. / 0.;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_23) {
  long double base = 0.5591951;
  long double exp = 1. / 0.;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_24) {
  long double base = 1.5591951;
  long double exp = 1. / 0.;
  ck_assert_float_infinite(s21_pow(base, exp));
  ck_assert_float_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_25) {
  long double base = -1. / 0.;
  long double exp = -193491;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_26) {
  long double base = -1. / 0.;
  long double exp = -142;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_27) {
  long double base = -1. / 0.;
  long double exp = 141;
  ck_assert_float_infinite(s21_pow(base, exp));
  ck_assert_float_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_28) {
  long double base = -1. / 0.;
  long double exp = 142;
  ck_assert_float_infinite(s21_pow(base, exp));
  ck_assert_float_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_29) {
  long double base = 1. / 0.;
  long double exp = -1;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_30) {
  long double base = 1. / 0.;
  long double exp = 1;
  ck_assert_float_infinite(s21_pow(base, exp));
  ck_assert_float_infinite(pow(base, exp));
}
END_TEST

START_TEST(pow_31) {
  ck_assert_ldouble_eq_tol(s21_pow(0.0, 0.0), pow(0.0, 0.0), 1e-6);
}
END_TEST

START_TEST(pow_32) {
  ck_assert_ldouble_eq_tol(s21_pow(-1, 4), pow(-1, 4), 1e-6);
}
END_TEST

START_TEST(pow_33) {
  ck_assert_ldouble_eq_tol(s21_pow(2, 18), pow(2, 18), 1e-6);
}
END_TEST

START_TEST(pow_34) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1, 11), pow(2.1, 11), 1e-6);
}
END_TEST

START_TEST(pow_35) {
  ck_assert_ldouble_eq_tol(s21_pow(1.23456e-7, 2.21), pow(1.23456e-7, 2.21),
                           1e-6);
}
END_TEST

START_TEST(pow_36) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1234567, -2), pow(2.1234567, -2), 1e-6);
}
END_TEST

START_TEST(pow_37) {
  ck_assert_ldouble_eq_tol(s21_pow(2.1234567, -2), pow(2.1234567, -2), 1e-6);
}
END_TEST

START_TEST(pow_39) {
  ck_assert_ldouble_eq_tol(s21_pow(9.99999999e3, 9.95e-4),
                           pow(9.99999999e3, 9.95e-4), 1e-6);
}
END_TEST

START_TEST(pow_40) {
  long double exp = -12;
  ck_assert_float_infinite(s21_pow(+0, exp));
  ck_assert_float_infinite(pow(+0, exp));
}
END_TEST

START_TEST(pow_41) {
  long double exp = -12;
  ck_assert_float_infinite(s21_pow(-0, exp));
  ck_assert_float_infinite(pow(-0, exp));
}
END_TEST

START_TEST(pow_42) {
  long double exp = 0;
  ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), 1e-6);
}
END_TEST

START_TEST(pow_43) {
  long double exp = 0. / 0.;
  ck_assert_double_nan(s21_pow(+0, exp));
  ck_assert_double_nan(pow(+0, exp));
}
END_TEST

START_TEST(pow_44) {
  long double exp = 2.456;
  ck_assert_ldouble_eq_tol(s21_pow(+0, exp), pow(+0, exp), 1e-6);
}
END_TEST

START_TEST(pow_45) {
  long double exp = -1. / 0.;
  ck_assert_float_infinite(s21_pow(+0, exp));
  ck_assert_float_infinite(pow(+0, exp));
}
END_TEST

START_TEST(pow_46) {
  long double exp = 56;
  ck_assert_ldouble_eq_tol(s21_pow(+0, exp), pow(+0, exp), 1e-6);
}
END_TEST

START_TEST(pow_47) {
  long double exp = 56;
  ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), 1e-6);
}
END_TEST

START_TEST(pow_48) {
  long double exp = 56.345;
  ck_assert_ldouble_eq_tol(s21_pow(-0, exp), pow(-0, exp), 1e-6);
}
END_TEST

START_TEST(pow_49) {
  long double exp = 1. / 0.;
  ck_assert_ldouble_eq_tol(s21_pow(-1, exp), pow(-1, exp), 1e-6);
}
END_TEST

START_TEST(pow_50) {
  long double exp = -1. / 0.;
  ck_assert_ldouble_eq_tol(s21_pow(-1, exp), pow(-1, exp), 1e-6);
}
END_TEST

START_TEST(pow_51) {
  long double exp = 0. / 0.;
  ck_assert_ldouble_eq_tol(s21_pow(+1, exp), pow(+1, exp), 1e-6);
}
END_TEST

START_TEST(pow_52) {
  long double exp = -0;
  ck_assert_ldouble_eq_tol(s21_pow(4567, exp), pow(4567, exp), 1e-6);
}
END_TEST

START_TEST(pow_53) {
  long double exp = +0;
  ck_assert_ldouble_eq_tol(s21_pow(34567, exp), pow(34567, exp), 1e-6);
}
END_TEST

START_TEST(pow_54) {
  long double exp = -0;
  ck_assert_ldouble_eq_tol(s21_pow(0. / 0., exp), pow(0. / 0., exp), 1e-6);
}
END_TEST

START_TEST(pow_55) {
  long double exp = +0;
  ck_assert_ldouble_eq_tol(s21_pow(0. / 0., exp), pow(0. / 0., exp), 1e-6);
}
END_TEST

START_TEST(pow_56) {
  long double exp = 0. / 0.;
  ck_assert_double_nan(s21_pow(0. / 0., exp));
  ck_assert_double_nan(pow(0. / 0., exp));
}
END_TEST

START_TEST(pow_57) {
  long double exp = 1. / 0.;
  ck_assert_float_infinite(s21_pow(1. / 0., exp));
  ck_assert_float_infinite(pow(1. / 0., exp));
}
END_TEST

START_TEST(pow_58) {
  long double exp = -1. / 0.;
  ck_assert_ldouble_eq_tol(s21_pow(-1. / 0., exp), pow(-1. / 0., exp), 1e-6);
}
END_TEST

START_TEST(pow_59) {
  double exp = 1. / 0.;
  ck_assert_float_infinite(s21_pow(-1. / 0., exp));
  ck_assert_float_infinite(pow(-1. / 0., exp));
}
END_TEST

START_TEST(pow_60) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp > -1000; exp -= 0.1) {
    res1 = pow(1. / 0., exp);
    res2 = s21_pow(1. / 0., exp);
  }
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(pow_61) {
  double base;
  double res1;
  long double res2;

  for (base = 0.0; base < 10; base += 0.1) {
    res1 = pow(base, 1. / 0.);
    res2 = s21_pow(base, 1. / 0.);
  }
  ck_assert_float_infinite(res1);
  ck_assert_float_infinite(res2);
}
END_TEST

START_TEST(pow_62) {
  double base;
  double res1;
  long double res2;

  for (base = 0.0; base > -10; base -= 0.1) {
    res1 = pow(base, 1. / 0.);
    res2 = s21_pow(base, 1. / 0.);
  }
  ck_assert_float_infinite(res1);
  ck_assert_float_infinite(res2);
}
END_TEST

START_TEST(pow_63) {
  long double base;
  long double res1;
  long double res2;

  for (base = 0.0; base < 10; base += 0.1) {
    res1 = pow(base, -1. / 0.);
    res2 = s21_pow(base, -1. / 0.);
  }
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(pow_64) {
  long double base;
  long double res1;
  long double res2;

  for (base = 0.0; base > -10; base -= 0.1) {
    res1 = pow(base, -1. / 0.);
    res2 = s21_pow(base, -1. / 0.);
  }
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(pow_66) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp > -10; exp -= 0.1) {
    if (fmod(exp, 2) == 0) {
      res1 = pow(-1. / 0., exp);
      res2 = s21_pow(-1. / 0., exp);
    }
  }
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(pow_67) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp < 10; exp += 0.1) {
    if (fmod(exp, 2) != 0) {
      res1 = pow(-1. / 0., exp);
      res2 = s21_pow(-1. / 0., exp);
    }
  }
  ck_assert_float_infinite(res1);
  ck_assert_float_infinite(res2);
}
END_TEST

START_TEST(pow_68) {
  double exp;
  double res1;
  long double res2;

  for (exp = 0.0; exp < 10; exp += 0.1) {
    if (fmod(exp, 2) == 0) {
      res1 = pow(-1. / 0., exp);
      res2 = s21_pow(-1. / 0., exp);
    }
  }
  ck_assert_ldouble_eq_tol(res2, res1, 1e-6);
}
END_TEST

START_TEST(pow_69) {
  long double exp = 3;
  ck_assert_ldouble_eq_tol(s21_pow(-3, exp), pow(-3, exp), 1e-6);
}
END_TEST

START_TEST(pow_70) {
  long double exp = -3;
  ck_assert_ldouble_eq_tol(s21_pow(-3, exp), pow(-3, exp), 1e-6);
}
END_TEST

START_TEST(pow_71) {
  long double exp = -3;
  ck_assert_ldouble_eq_tol(s21_pow(3, exp), pow(3, exp), 1e-6);
}
END_TEST

START_TEST(pow_72) {
  long double exp = 3;
  ck_assert_ldouble_eq_tol(s21_pow(3, exp), pow(3, exp), 1e-6);
}
END_TEST

START_TEST(pow_73) {
  long double base = -0;
  long double exp = 1. / 0.;
  long double res = pow(base, exp);
  long double res1 = s21_pow(base, exp);
  ck_assert_ldouble_eq_tol(res, res1, 1e-6);
}
END_TEST

START_TEST(pow_74) {
  long double exp;
  long double base = -0;
  long double res;
  long double res1;
  for (exp = 0.0; exp < 10; exp += 0.1) {
    if (fmod(exp, 2) != 0) {
      res = pow(base, exp);
      res1 = s21_pow(base, exp);
    }
  }
  ck_assert_ldouble_eq_tol(res, res1, 1e-6);
}
END_TEST

Suite *suite_pow() {
  Suite *s = suite_create(YELLOW_BG BLACK "s21_pow" RESET);
  TCase *tc = tcase_create("strcsuite_pow_tc");

  tcase_add_test(tc, pow_8);
  tcase_add_test(tc, pow_9);
  tcase_add_test(tc, pow_10);
  tcase_add_test(tc, pow_12);
  tcase_add_test(tc, pow_13);
  tcase_add_test(tc, pow_14);
  tcase_add_test(tc, pow_15);
  tcase_add_test(tc, pow_16);
  tcase_add_test(tc, pow_17);
  tcase_add_test(tc, pow_18);
  tcase_add_test(tc, pow_19);
  tcase_add_test(tc, pow_20);
  tcase_add_test(tc, pow_21);
  tcase_add_test(tc, pow_22);
  tcase_add_test(tc, pow_23);
  tcase_add_test(tc, pow_24);
  tcase_add_test(tc, pow_25);
  tcase_add_test(tc, pow_26);
  tcase_add_test(tc, pow_27);
  tcase_add_test(tc, pow_28);
  tcase_add_test(tc, pow_29);
  tcase_add_test(tc, pow_30);
  tcase_add_test(tc, pow_31);
  tcase_add_test(tc, pow_32);
  tcase_add_test(tc, pow_33);
  tcase_add_test(tc, pow_34);
  tcase_add_test(tc, pow_35);
  tcase_add_test(tc, pow_36);
  tcase_add_test(tc, pow_37);
  tcase_add_test(tc, pow_39);  // was inf now ok
  tcase_add_test(tc, pow_40);
  tcase_add_test(tc, pow_41);
  tcase_add_test(tc, pow_42);
  tcase_add_test(tc, pow_43);
  tcase_add_test(tc, pow_44);
  tcase_add_test(tc, pow_45);
  tcase_add_test(tc, pow_46);
  tcase_add_test(tc, pow_47);
  tcase_add_test(tc, pow_48);
  tcase_add_test(tc, pow_49);
  tcase_add_test(tc, pow_50);
  tcase_add_test(tc, pow_51);
  tcase_add_test(tc, pow_52);  // was inf now ok
  tcase_add_test(tc, pow_53);  // was inf now ok
  tcase_add_test(tc, pow_54);
  tcase_add_test(tc, pow_55);
  tcase_add_test(tc, pow_56);
  tcase_add_test(tc, pow_57);
  tcase_add_test(tc, pow_58);
  tcase_add_test(tc, pow_59);
  tcase_add_test(tc, pow_60);
  tcase_add_test(tc, pow_61);
  tcase_add_test(tc, pow_62);
  tcase_add_test(tc, pow_63);
  tcase_add_test(tc, pow_64);
  tcase_add_test(tc, pow_66);
  tcase_add_test(tc, pow_67);
  tcase_add_test(tc, pow_68);
  tcase_add_test(tc, pow_69);
  tcase_add_test(tc, pow_70);
  tcase_add_test(tc, pow_71);
  tcase_add_test(tc, pow_72);
  tcase_add_test(tc, pow_73);
  tcase_add_test(tc, pow_74);

  suite_add_tcase(s, tc);
  return s;
}

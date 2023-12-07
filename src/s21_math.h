#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define EXP 2.71828182845
#define s21_PI 3.14159265358979323846
#define s21_2PI 6.28318530718
#define s21_PI_div2 1.57079632679489661923
#define s21_eps 1e-15

#define s21_isnan __builtin_isnan
#define s21_isinf __builtin_isinf

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif  // SRC_S21_MATH_H_

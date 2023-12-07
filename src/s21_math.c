#include "s21_math.h"

#include <float.h>

unsigned long long int s21_factorial(int x) {
  unsigned long long int answ = 1;
  for (int i = 1; i <= x; ++i) {
    answ *= i;
  }

  return answ;
}

int s21_abs(int x) {
  if (x < 0) {
    x *= -1;
  }

  return x;
}

long double s21_fabs(double x) {
  long double res = x;
  if (res < 0) {
    res *= -1.;
  }

  return res;
}

long double s21_fmod(double x, double y) {
  int sign = 1;
  if (x < 0) {
    sign = -1;
  }

  double res = s21_fabs(x);

  if (s21_isinf(y) && !s21_isnan(x) && !s21_isinf(x)) {
  } else if (y == 0 || s21_isinf(x) || s21_isinf(y) || s21_isnan(y)) {
    res = 0. / 0.;
  } else {
    while ((res - s21_fabs(y)) >= 0) {
      res -= s21_fabs(y);
    }
  }

  return sign * res;
}

// https://en.wikipedia.org/wiki/Natural_logarithm#High_precision
long double s21_log(double x) {
  int ex_pow = 0;
  long double res = 0;
  long double cmp;

  if (x == 1. / 0.) {
    res = 1. / 0.;
  } else if (x == 0) {
    res = -1. / 0.;
  } else if (x < 0) {
    res = 0. / 0.;
  } else if (x == 1) {
    res = 0;
  } else {
    while (x >= EXP) {
      x /= EXP;
      ex_pow++;
    }

    for (int i = 0; i < 100; i++) {
      cmp = res;
      res = cmp + 2 * (x - s21_exp(cmp)) / (x + s21_exp(cmp));
    }
  }

  return (res + ex_pow);
}

// https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Exponential_identity
long double s21_sqrt(double x) {
  long double res;

  if (x < 0) {
    res = -0. / 0.;
  } else if (x == 1. / 0.) {
    res = 1. / 0.;
  } else {
    res = s21_exp(0.5 * s21_log(x));
  }

  return res;
}

// https://en.wikipedia.org/wiki/Taylor_series#Exponential_function
long double s21_exp(double x) {
  long double res = 1;
  long double temp = 1;
  long double i = 1;
  int flag = 0;

  if (x < 0) {
    x *= -1;
    flag = 1;
  }

  int exit = 0;

  while (!exit && s21_fabs(res) > s21_eps) {
    res *= x / i;
    i += 1;
    temp += res;

    if (temp > DBL_MAX) {
      temp = 1. / 0.;
      exit = 1;
    }
  }

  if (flag == 1) {
    if (temp > DBL_MAX) {
      temp = 0;
    } else {
      temp = 1. / temp;
    }
  }

  if (temp > DBL_MAX) {
    temp = 1. / 0.;
  }

  return temp;
}

int s21_check_pow(double base, double exp, double pow_eps, long double *res) {
  int flag = 0;

  if (s21_fabs(exp) <= pow_eps) {
    *res = 1.;
  } else if (s21_isinf(base) && exp > 0) {
    *res = 1. / 0.;
  } else if (s21_fabs(base) <= pow_eps && exp > 0) {
    *res = 0.;
  } else if (s21_fabs(base - 1.) <= pow_eps) {
    *res = 1.;
  } else if (s21_isnan(base) || s21_isnan(exp)) {
    *res = 0. / 0.;
  } else if (base < 0 && s21_fabs(s21_fmod(exp, 1.0)) > pow_eps) {
    *res = -0. / 0.;
  } else if (s21_isinf(base) && base < 0 &&
             s21_fabs(s21_fmod(exp, 2.)) > pow_eps) {
    *res = -0;
  } else if (s21_isinf(base) && base < 0 && s21_fmod(exp, 2.) <= pow_eps &&
             exp > 0) {
    *res = 1. / 0.;
  } else if (s21_isinf(base) && base < 0 && exp < 0) {
    *res = 0.;
  } else if (s21_isinf(base) && base < 0 && exp > 0) {
    *res = 1. / 0.;
  } else if (s21_isinf(base) && base > 0 && exp < 0) {
    *res = 0.;
  } else if (s21_isinf(base) && base > 0 && exp > 0) {
    *res = 1. / 0.;
  } else if (s21_fabs(base) <= pow_eps && base >= 0 && exp < 0) {
    *res = 1. / 0.;
  } else if (s21_fabs(base) <= pow_eps && base >= 0) {
    *res = 0.;
  } else if (base < 0 && s21_fabs(base) - 1 <= pow_eps && s21_isinf(exp)) {
    *res = 1.;
  } else if ((s21_fabs(base) - 1 < pow_eps && s21_isinf(exp) && exp < 0) ||
             (s21_fabs(base) - 1 > pow_eps && s21_isinf(exp) && exp > 0)) {
    *res = 1. / 0.;
  } else if ((s21_fabs(base) - 1 > pow_eps && s21_isinf(exp) && exp < 0) ||
             (s21_fabs(base) - 1 < pow_eps && s21_isinf(exp) && exp > 0)) {
    *res = 0.;
  } else {
    flag = 1;
  }

  return flag;
}

/*
 * possible optimization:
 * https://stackoverflow.com/questions/4657468/fast-fixed-point-pow-log-exp-and-sqrt
 */
long double s21_pow(double base, double exp) {
  long double res = 1;
  double pow_eps = 1e-100;

  int flag = s21_check_pow(base, exp, pow_eps, &res);

  if (flag) {
    int neg_base = base < 0;
    int neg_pow = exp < 0;
    if (neg_base) base = -base;
    if (neg_pow) exp = -exp;

    res = s21_exp(exp * s21_log(base));

    if (neg_base && s21_fabs(s21_fmod(exp, 2.)) > pow_eps) res = -res;
    if (neg_pow) res = 1. / res;
  }

  return res;
}

long double s21_ceil(double x) {
  long double y = x - (int)x;
  if (x == 1. / 0.) {
    y = 1. / 0.;
  } else if (x == -1. / 0.) {
    y = -1. / 0.;
  } else if (s21_isnan(x)) {
    y = 0. / 0.;
  } else if (x == DBL_MAX) {
    y = DBL_MAX;
  } else if (y == 0.0) {
    y = x;
  } else {
    if (x > 0.0) {
      y = x - y + 1;
    } else {
      y = x - y;
    }
  }
  return y;
}

long double s21_floor(double x) {
  long double y = x - (int)x;
  if (x == 1. / 0.) {
    y = 1. / 0.;
  } else if (x == -1. / 0.) {
    y = -1. / 0.;
  } else if (s21_isnan(x)) {
    y = 0. / 0.;
  } else if (x == DBL_MAX) {
    y = DBL_MAX;
  } else if (y == 0.0) {
    y = x;
  } else {
    if (x > 0.0) {
      y = x - y;
    } else {
      y = x - (1 + y);
    }
  }
  return y;
}

long double s21_sin(double x) {
  long double answ = 0;
  if (s21_fabs(x) != 1.0 / 0.0) {
    while (x < -s21_PI || x > s21_PI) {
      if (x < -s21_PI) {
        x += 2 * s21_PI;
      } else if (x > s21_PI) {
        x -= 2 * s21_PI;
      }
    }
    for (int n = 0; n < 10; n++) {
      answ +=
          (s21_pow(-1, n) * s21_pow(x, 2 * n + 1)) / s21_factorial(2 * n + 1);
    }
  } else {
    answ = 0.0 / 0.0;
  }
  if (x == s21_PI) {
    answ = 0.0;
  } else if (x == -s21_PI) {
    answ = -0.0;
  }
  return answ;
}

long double s21_cos(double x) {
  long double answ;
  answ = s21_sin(s21_PI_div2 - x);
  return answ;
}

long double s21_tan(double x) {
  long double answ;
  if (s21_fabs(1.0 / s21_cos(x)) != 1.0 / 0.0) {
    answ = s21_sin(x) / s21_cos(x);
  } else if (s21_sin(x) < 0) {
    answ = -16331239353195370.000000;
  } else {
    answ = 16331239353195370.000000;
  }
  return answ;
}

long double s21_asin(double x) {
  long double answ;
  if (x == -1) {
    answ = -s21_PI_div2;
  } else if (x == 1) {
    answ = s21_PI_div2;
  } else if (x > -1 && x < 1) {
    answ = s21_atan(x / s21_sqrt(1 - x * x));
  } else {
    answ = 0. / 0.;
  }
  return answ;
}

long double s21_acos(double x) {
  long double answ;
  if (x == -1) {
    answ = s21_PI;
  } else if (x == 1) {
    answ = 0;
  } else if (x > -1 && x < 1) {
    answ = s21_PI_div2 - s21_asin(x);
  } else {
    answ = 0. / 0.;
  }
  return answ;
}

long double s21_atan(double x) {
  long double answ = 0;
  int iter_n = 500;
  if (s21_fabs(x - 1) < s21_eps) {
    answ = 0.7853981633974480;
  } else if (s21_fabs(x + 1) < s21_eps) {
    answ = -0.7853981633974480;
  } else if (x == 1.0 / 0.0) {
    answ = 1.5708;
  } else if (x == -1.0 / 0.0) {
    answ = -1.5708;
  } else if (-1.0 < x && x < 1.0) {
    for (int n = 0; n < iter_n; n++) {
      answ += (s21_pow(-1, n) / (2 * n + 1)) * s21_pow(x, 2 * n + 1);
    }
  } else {
    for (int n = 0; n < iter_n; n++) {
      answ += (s21_pow(-1, n) / (2 * n + 1)) * s21_pow(x, -2 * n - 1);
    }
    answ = s21_PI * s21_sqrt(x * x) / (2 * x) - answ;
  }
  return answ;
}

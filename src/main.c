#include <stdio.h>

#include "tests/tests.h"

void run() {
  Suite *tests[] = {
      suite_abs(),   suite_fabs(), suite_fmod(), suite_log(),
      suite_sqrt(),  suite_exp(),  suite_pow(),  suite_ceil(),
      suite_floor(), suite_sin(),  suite_cos(),  suite_tan(),
      suite_asin(),  suite_acos(), suite_atan(), NULL,
  };

  int total = 0;
  int failed = 0;

  for (Suite **current = tests; *current; current++) {
    SRunner *sr = srunner_create(*current);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    total += srunner_ntests_run(sr);
    failed += srunner_ntests_failed(sr);

    srunner_free(sr);
  }

  printf("\n" WHITE_BG BLACK " total: %d " RESET RED_BG BLACK
         " failed: %d " RESET GREEN_BG BLACK " success: %d " RESET "\n",
         total, failed, total - failed);
}

int main() {
  run();

  return 0;
}

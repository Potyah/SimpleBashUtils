#include "../cat/s21_cat.h"
#include <check.h>

START_TEST(test_cat_no_flag) {
  char catChar;
  char s21_catChar;

  system("cat ../common/text.txt > cat.txt");
  system("./../cat/s21_cat ../common/text.txt > s21_cat.txt");

  FILE* catFile = fopen("cat.txt", "r");
  FILE* s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR NO-1");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");

  system("cat ../common/empty.txt > cat.txt");
  system("./../cat/s21_cat ../common/empty.txt > s21_cat.txt");

  catFile = fopen("cat.txt", "r");
  s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR NO-2");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");

  system("cat ../common/text.txt ../common/text2.txt > cat.txt");
  system("./../cat/s21_cat ../common/text.txt ../common/text2.txt > s21_cat.txt");

  catFile = fopen("cat.txt", "r");
  s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR NO-3");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");
}
END_TEST

START_TEST(test_cat_b) {
  char catChar;
  char s21_catChar;

  system("cat -b ../common/text.txt > cat.txt");
  system("./../cat/s21_cat -b ../common/text.txt > s21_cat.txt");

  FILE* catFile = fopen("cat.txt", "r");
  FILE* s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR B-1");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");

  system("cat -b ../common/text.txt > cat.txt");
  system("./../cat/s21_cat --number-nonblank ../common/text.txt > s21_cat.txt");

  catFile = fopen("cat.txt", "r");
  s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR B-1");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");

  system("cat -b ../common/empty.txt > cat.txt");
  system("./../cat/s21_cat -b ../common/empty.txt > s21_cat.txt");

  catFile = fopen("cat.txt", "r");
  s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR B-2");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");

  system("cat -b ../common/text2.txt > cat.txt");
  system("./../cat/s21_cat -b ../common/text2.txt > s21_cat.txt");

  catFile = fopen("cat.txt", "r");
  s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR B-3");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");
}
END_TEST

START_TEST(test_cat_s) {
  char catChar;
  char s21_catChar;

  system("cat -s ../common/text.txt > cat.txt");
  system("./../cat/s21_cat -s ../common/text.txt > s21_cat.txt");

  FILE* catFile = fopen("cat.txt", "r");
  FILE* s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR S-1");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");

  system("cat -s ../common/text.txt > cat.txt");
  system("./../cat/s21_cat --squeeze-blank ../common/text.txt > s21_cat.txt");

  catFile = fopen("cat.txt", "r");
  s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR S-1");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");

  system("cat -s ../common/empty.txt > cat.txt");
  system("./../cat/s21_cat -s ../common/empty.txt > s21_cat.txt");

  catFile = fopen("cat.txt", "r");
  s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR S-1");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");

  system("cat -s ../common/text.txt ../common/text2.txt > cat.txt");
  system("./../cat/s21_cat -s ../common/text.txt ../common/text2.txt > s21_cat.txt");

  catFile = fopen("cat.txt", "r");
  s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR S-3");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");
}
END_TEST

START_TEST(test_cat_n) {
  char catChar;
  char s21_catChar;

  system("cat -n ../common/text.txt > cat.txt");
  system("./../cat/s21_cat -n ../common/text.txt > s21_cat.txt");

  FILE* catFile = fopen("cat.txt", "r");
  FILE* s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR N-1");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");

  system("cat -n ../common/text.txt > cat.txt");
  system("./../cat/s21_cat --number ../common/text.txt > s21_cat.txt");

  catFile = fopen("cat.txt", "r");
  s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR N-2");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");

  system("cat -n ../common/empty.txt > cat.txt");
  system("./../cat/s21_cat -n ../common/empty.txt > s21_cat.txt");

  catFile = fopen("cat.txt", "r");
  s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR N-3");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");

  system("cat -n ../common/text2.txt > cat.txt");
  system("./../cat/s21_cat -n ../common/text2.txt > s21_cat.txt");

  catFile = fopen("cat.txt", "r");
  s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR N-4");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");
}
END_TEST

START_TEST(test_cat_t) {
  char catChar;
  char s21_catChar;

  system("cat -t ../common/text.txt > cat.txt");
  system("./../cat/s21_cat -t ../common/text.txt > s21_cat.txt");

  FILE* catFile = fopen("cat.txt", "r");
  FILE* s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR T-1");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");

  system("cat -t ../common/empty.txt > cat.txt");
  system("./../cat/s21_cat -t ../common/empty.txt > s21_cat.txt");

  catFile = fopen("cat.txt", "r");
  s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR T-2");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");

  system("cat -t ../common/text2.txt > cat.txt");
  system("./../cat/s21_cat -t ../common/text2.txt > s21_cat.txt");

  catFile = fopen("cat.txt", "r");
  s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR T-3");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");
}
END_TEST

START_TEST(test_cat_combo) {
  char catChar;
  char s21_catChar;

  system("cat -benst ../common/text.txt > cat.txt");
  system("./../cat/s21_cat -benst ../common/text.txt > s21_cat.txt");

  FILE* catFile = fopen("cat.txt", "r");
  FILE* s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR COMBO-1");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");

  system("cat -t ../common/empty.txt > cat.txt");
  system("./../cat/s21_cat -t ../common/empty.txt > s21_cat.txt");

  catFile = fopen("cat.txt", "r");
  s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR N-2");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");

  system("cat -t ../common/text2.txt > cat.txt");
  system("./../cat/s21_cat -t ../common/text2.txt > s21_cat.txt");

  catFile = fopen("cat.txt", "r");
  s21_catFile = fopen("s21_cat.txt", "r");

  while ((catChar = fgetc(catFile)) != EOF && (s21_catChar = fgetc(s21_catFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR N-3");
  }

  fclose(catFile);
  fclose(s21_catFile);

  remove("cat.txt");
  remove("s21_cat.txt");
}
END_TEST

Suite * s21_cat_suite(void) {
  Suite *s;
  TCase *tc_all;
  s = suite_create("s21_cat");
  tc_all = tcase_create("all_cat");
  tcase_add_test(tc_all, test_cat_no_flag);
  suite_add_tcase(s, tc_all);

  TCase *tc_cat_b;
  tc_cat_b = tcase_create("cat_b");
  tcase_add_test(tc_cat_b, test_cat_b);
  suite_add_tcase(s, tc_cat_b);

  TCase *tc_cat_n;
  tc_cat_n = tcase_create("cat_n");
  tcase_add_test(tc_cat_n, test_cat_n);
  suite_add_tcase(s, tc_cat_n);

  TCase *tc_cat_s;
  tc_cat_s = tcase_create("cat_s");
  tcase_add_test(tc_cat_s, test_cat_s);
  suite_add_tcase(s, tc_cat_s);

  TCase *tc_cat_t;
  tc_cat_t = tcase_create("cat_t");
  tcase_add_test(tc_cat_t, test_cat_t);
  suite_add_tcase(s, tc_cat_t);

  TCase *tc_cat_combo;
  tc_cat_combo = tcase_create("cat_combo");
  tcase_add_test(tc_cat_combo, test_cat_combo);
  suite_add_tcase(s, tc_cat_combo);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;
  s = s21_cat_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

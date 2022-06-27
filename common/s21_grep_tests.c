#include "../grep/s21_grep.h"
#include <check.h>

START_TEST(test_grep_e) {
  char catChar;
  char s21_catChar;

  system("grep -e b -e a ../common/text.txt > grep.txt");
  system("./../grep/s21_grep -e b -e a ../common/text.txt > s21_grep.txt");

  FILE* grepFile = fopen("grep.txt", "r");
  FILE* s21_grepFile = fopen("s21_grep.txt", "r");

  while ((catChar = fgetc(grepFile)) != EOF && (s21_catChar = fgetc(s21_grepFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR E-1");
  }

  fclose(grepFile);
  fclose(s21_grepFile);

  remove("grep.txt");
  remove("s21_grep.txt");

  system("grep -e [a-g] -e [A-D] ../common/text.txt ../common/text2.txt > grep.txt");
  system("./../grep/s21_grep -e [a-g] -e [A-D] ../common/text.txt ../common/text2.txt > s21_grep.txt");

  grepFile = fopen("grep.txt", "r");
  s21_grepFile = fopen("s21_grep.txt", "r");

  while ((catChar = fgetc(grepFile)) != EOF && (s21_catChar = fgetc(s21_grepFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR E-2");
  }

  fclose(grepFile);
  fclose(s21_grepFile);

  remove("grep.txt");
  remove("s21_grep.txt");
}
END_TEST

START_TEST(test_grep_i) {
  char catChar;
  char s21_catChar;

  system("grep -i a ../common/text.txt > grep.txt");
  system("./../grep/s21_grep -i a ../common/text.txt > s21_grep.txt");

  FILE* grepFile = fopen("grep.txt", "r");
  FILE* s21_grepFile = fopen("s21_grep.txt", "r");

  while ((catChar = fgetc(grepFile)) != EOF && (s21_catChar = fgetc(s21_grepFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR I-1");
  }

  fclose(grepFile);
  fclose(s21_grepFile);

  remove("grep.txt");
  remove("s21_grep.txt");

  system("grep -i [A-D] ../common/text.txt ../common/text2.txt > grep.txt");
  system("./../grep/s21_grep -i [A-D] ../common/text.txt ../common/text2.txt > s21_grep.txt");

  grepFile = fopen("grep.txt", "r");
  s21_grepFile = fopen("s21_grep.txt", "r");

  while ((catChar = fgetc(grepFile)) != EOF && (s21_catChar = fgetc(s21_grepFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR I-2");
  }

  fclose(grepFile);
  fclose(s21_grepFile);

  remove("grep.txt");
  remove("s21_grep.txt");
}
END_TEST

START_TEST(test_grep_v) {
  char catChar;
  char s21_catChar;

  system("grep -v a ../common/text.txt > grep.txt");
  system("./../grep/s21_grep -v a ../common/text.txt > s21_grep.txt");

  FILE* grepFile = fopen("grep.txt", "r");
  FILE* s21_grepFile = fopen("s21_grep.txt", "r");

  while ((catChar = fgetc(grepFile)) != EOF && (s21_catChar = fgetc(s21_grepFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR I-1");
  }

  fclose(grepFile);
  fclose(s21_grepFile);

  remove("grep.txt");
  remove("s21_grep.txt");

  system("grep -v [A-D] ../common/text.txt ../common/text2.txt > grep.txt");
  system("./../grep/s21_grep -v [A-D] ../common/text.txt ../common/text2.txt > s21_grep.txt");

  grepFile = fopen("grep.txt", "r");
  s21_grepFile = fopen("s21_grep.txt", "r");

  while ((catChar = fgetc(grepFile)) != EOF && (s21_catChar = fgetc(s21_grepFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR I-2");
  }

  fclose(grepFile);
  fclose(s21_grepFile);

  remove("grep.txt");
  remove("s21_grep.txt");
}
END_TEST

START_TEST(test_grep_c) {
  char catChar;
  char s21_catChar;

  system("grep -c a ../common/text.txt > grep.txt");
  system("./../grep/s21_grep -c a ../common/text.txt > s21_grep.txt");

  FILE* grepFile = fopen("grep.txt", "r");
  FILE* s21_grepFile = fopen("s21_grep.txt", "r");

  while ((catChar = fgetc(grepFile)) != EOF && (s21_catChar = fgetc(s21_grepFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR C-1");
  }

  fclose(grepFile);
  fclose(s21_grepFile);

  remove("grep.txt");
  remove("s21_grep.txt");

  system("grep -c [A-D] ../common/text.txt ../common/text2.txt > grep.txt");
  system("./../grep/s21_grep -c [A-D] ../common/text.txt ../common/text2.txt > s21_grep.txt");

  grepFile = fopen("grep.txt", "r");
  s21_grepFile = fopen("s21_grep.txt", "r");

  while ((catChar = fgetc(grepFile)) != EOF && (s21_catChar = fgetc(s21_grepFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR C-2");
  }

  fclose(grepFile);
  fclose(s21_grepFile);

  remove("grep.txt");
  remove("s21_grep.txt");
}
END_TEST

START_TEST(test_grep_l) {
  char catChar;
  char s21_catChar;

  system("grep -l a ../common/text.txt > grep.txt");
  system("./../grep/s21_grep -l a ../common/text.txt > s21_grep.txt");

  FILE* grepFile = fopen("grep.txt", "r");
  FILE* s21_grepFile = fopen("s21_grep.txt", "r");

  while ((catChar = fgetc(grepFile)) != EOF && (s21_catChar = fgetc(s21_grepFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR L-1");
  }

  fclose(grepFile);
  fclose(s21_grepFile);

  remove("grep.txt");
  remove("s21_grep.txt");

  system("grep -l [A-D] ../common/text.txt ../common/text2.txt > grep.txt");
  system("./../grep/s21_grep -l [A-D] ../common/text.txt ../common/text2.txt > s21_grep.txt");

  grepFile = fopen("grep.txt", "r");
  s21_grepFile = fopen("s21_grep.txt", "r");

  while ((catChar = fgetc(grepFile)) != EOF && (s21_catChar = fgetc(s21_grepFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR L-2");
  }

  fclose(grepFile);
  fclose(s21_grepFile);

  remove("grep.txt");
  remove("s21_grep.txt");
}
END_TEST

START_TEST(test_grep_n) {
  char catChar;
  char s21_catChar;

  system("grep -n a ../common/text.txt > grep.txt");
  system("./../grep/s21_grep -n a ../common/text.txt > s21_grep.txt");

  FILE* grepFile = fopen("grep.txt", "r");
  FILE* s21_grepFile = fopen("s21_grep.txt", "r");

  while ((catChar = fgetc(grepFile)) != EOF && (s21_catChar = fgetc(s21_grepFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR N-1");
  }

  fclose(grepFile);
  fclose(s21_grepFile);

  remove("grep.txt");
  remove("s21_grep.txt");

  system("grep -n [A-D] ../common/text.txt ../common/text2.txt > grep.txt");
  system("./../grep/s21_grep -n [A-D] ../common/text.txt ../common/text2.txt > s21_grep.txt");

  grepFile = fopen("grep.txt", "r");
  s21_grepFile = fopen("s21_grep.txt", "r");

  while ((catChar = fgetc(grepFile)) != EOF && (s21_catChar = fgetc(s21_grepFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR N-2");
  }

  fclose(grepFile);
  fclose(s21_grepFile);

  remove("grep.txt");
  remove("s21_grep.txt");
}
END_TEST

START_TEST(test_grep_h) {
  char catChar;
  char s21_catChar;

  system("grep -h [A-D] ../common/text.txt ../common/text2.txt > grep.txt");
  system("./../grep/s21_grep -h [A-D] ../common/text.txt ../common/text2.txt > s21_grep.txt");

  FILE* grepFile = fopen("grep.txt", "r");
  FILE* s21_grepFile = fopen("s21_grep.txt", "r");

  while ((catChar = fgetc(grepFile)) != EOF && (s21_catChar = fgetc(s21_grepFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR H-1");
  }

  fclose(grepFile);
  fclose(s21_grepFile);

  remove("grep.txt");
  remove("s21_grep.txt");
}
END_TEST

START_TEST(test_grep_s) {
  char catChar;
  char s21_catChar;

  system("grep -s [A-D] ../common/text.txt qwerty.txt ../common/text2.txt 12345.txt > grep.txt");
  system("./../grep/s21_grep -s [A-D] ../common/text.txt qwerty.txt ../common/text2.txt 12345.txt > s21_grep.txt");

  FILE* grepFile = fopen("grep.txt", "r");
  FILE* s21_grepFile = fopen("s21_grep.txt", "r");

  while ((catChar = fgetc(grepFile)) != EOF && (s21_catChar = fgetc(s21_grepFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR H-1");
  }

  fclose(grepFile);
  fclose(s21_grepFile);

  remove("grep.txt");
  remove("s21_grep.txt");
}
END_TEST

START_TEST(test_grep_f) {
  char catChar;
  char s21_catChar;

  system("grep -f ../common/regular.txt ../common/text.txt ../common/text2.txt > grep.txt");
  system("./../grep/s21_grep -f ../common/regular.txt ../common/text.txt ../common/text2.txt > s21_grep.txt");

  FILE* grepFile = fopen("grep.txt", "r");
  FILE* s21_grepFile = fopen("s21_grep.txt", "r");

  while ((catChar = fgetc(grepFile)) != EOF && (s21_catChar = fgetc(s21_grepFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR F-1");
  }

  fclose(grepFile);
  fclose(s21_grepFile);

  remove("grep.txt");
  remove("s21_grep.txt");

  system("grep -f ../common/regular.txt -f ../common/regular2.txt ../common/text.txt > grep.txt");
  system("./../grep/s21_grep -f ../common/regular.txt -f ../common/regular2.txt ../common/text.txt > s21_grep.txt");

  grepFile = fopen("grep.txt", "r");
  s21_grepFile = fopen("s21_grep.txt", "r");

  while ((catChar = fgetc(grepFile)) != EOF && (s21_catChar = fgetc(s21_grepFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR F-2");
  }

  fclose(grepFile);
  fclose(s21_grepFile);

  remove("grep.txt");
  remove("s21_grep.txt");
}
END_TEST

START_TEST(test_grep_o) {
  char catChar;
  char s21_catChar;

  system("grep -o Aa ../common/text.txt ../common/text2.txt > grep.txt");
  system("./../grep/s21_grep -o Aa ../common/text.txt ../common/text2.txt > s21_grep.txt");

  FILE* grepFile = fopen("grep.txt", "r");
  FILE* s21_grepFile = fopen("s21_grep.txt", "r");

  while ((catChar = fgetc(grepFile)) != EOF && (s21_catChar = fgetc(s21_grepFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR O-1");
  }

  fclose(grepFile);
  fclose(s21_grepFile);

  remove("grep.txt");
  remove("s21_grep.txt");

  system("grep -o [a-h] ../common/text.txt > grep.txt");
  system("./../grep/s21_grep -o [a-h] ../common/text.txt > s21_grep.txt");

  grepFile = fopen("grep.txt", "r");
  s21_grepFile = fopen("s21_grep.txt", "r");

  while ((catChar = fgetc(grepFile)) != EOF && (s21_catChar = fgetc(s21_grepFile)) != EOF) {
    fail_unless(catChar - s21_catChar == 0, "ERROR O-2");
  }

  fclose(grepFile);
  fclose(s21_grepFile);

  remove("grep.txt");
  remove("s21_grep.txt");
}
END_TEST

Suite * s21_grep_suite(void) {
  Suite *s;
  TCase *tc_all;
  s = suite_create("s21_grep");
  tc_all = tcase_create("all_grep");
  tcase_add_test(tc_all, test_grep_e);
  suite_add_tcase(s, tc_all);

  TCase *tc_grep_i;
  tc_grep_i = tcase_create("grep_i");
  tcase_add_test(tc_grep_i, test_grep_i);
  suite_add_tcase(s, tc_grep_i);

  TCase *tc_grep_v;
  tc_grep_v = tcase_create("grep_v");
  tcase_add_test(tc_grep_v, test_grep_v);
  suite_add_tcase(s, tc_grep_v);

  TCase *tc_grep_c;
  tc_grep_c = tcase_create("grep_c");
  tcase_add_test(tc_grep_c, test_grep_c);
  suite_add_tcase(s, tc_grep_c);

  TCase *tc_grep_l;
  tc_grep_l = tcase_create("grep_l");
  tcase_add_test(tc_grep_l, test_grep_l);
  suite_add_tcase(s, tc_grep_l);

  TCase *tc_grep_n;
  tc_grep_n = tcase_create("grep_n");
  tcase_add_test(tc_grep_n, test_grep_n);
  suite_add_tcase(s, tc_grep_n);

  TCase *tc_grep_h;
  tc_grep_h = tcase_create("grep_h");
  tcase_add_test(tc_grep_h, test_grep_h);
  suite_add_tcase(s, tc_grep_h);

  TCase *tc_grep_s;
  tc_grep_s = tcase_create("grep_s");
  tcase_add_test(tc_grep_s, test_grep_s);
  suite_add_tcase(s, tc_grep_s);

  TCase *tc_grep_f;
  tc_grep_f = tcase_create("grep_f");
  tcase_add_test(tc_grep_f, test_grep_f);
  suite_add_tcase(s, tc_grep_f);

  TCase *tc_grep_o;
  tc_grep_o = tcase_create("grep_o");
  tcase_add_test(tc_grep_o, test_grep_o);
  suite_add_tcase(s, tc_grep_o);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;
  s = s21_grep_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

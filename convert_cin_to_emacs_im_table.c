/*
** test3.c
** 
** Made by (Gong-Yi Liao)
** Login   <gong-yi@GongTop1>
** 
** Started on  Thu Sep 15 11:33:52 2011 Gong-Yi Liao
** Last update Thu Sep 22 11:22:08 2011 Gong-Yi Liao
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

int main(int argc, char *argv[]) {
  setlocale(LC_CTYPE, "en_US.utf8");
  int root = 0;
  const wchar_t letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  const wchar_t roots_orig[] = {L'日', L'月', L'金', L'木', L'水', L'火', L'土', L'竹', L'戈', L'十', L'大', L'中', L'一', L'弓', L'人', L'心', L'手', L'口', L'尸', L'廿', L'山', L'女', L'田', L'難', L'卜', L'重'};
  const wchar_t roots[] = {'a', 'u', 'f', 'r', 'k', 'b', 'g', 'i', 'd', 'c', 'l', 'n', 't', 's', 'h', 'x', 'q', 'o', 'p', 'y', 'm', 'w', 'j', 'v', 'e', 'z'};
  FILE *orig_table = fopen("cj5.cin", "r");
  FILE *new_table = fopen("cj5_ergonomic.cin", "wb");
  wint_t wc = 0;
  wchar_t letter = L' ';
  wchar_t replace_root = L' ';
  while (EOF != (wc = fgetwc(orig_table))) {
    letter = wc;
    replace_root = letter;
    for (root = 0; root < 26; root++) {
      if (letter == letters[root]) 
	replace_root = roots[root]; 
    }
    fprintf(new_table, "%lc", replace_root);
  }
  fclose(orig_table);
  fclose(new_table);
  return 0;
}


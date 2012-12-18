/*
** count_root_key_frequency.c
** 
** 
** Made by (Gong-Yi Liao)
** Login   <gong-yi@GongTop1>
** 
** Started on  Thu Sep 15 15:24:27 2011 Gong-Yi Liao
** Last update Mon Dec 17 20:57:20 2012 Gong-Yi Liao
*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <malloc.h>
#include <string.h>

int main(int argc, char **argv) {
  setlocale(LC_CTYPE, "en_US.utf8");
  int dataCounts = 0, j = 0, k = 0, i = 0;
  const wchar_t letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  const wchar_t roots[] = {L'日', L'月', L'金', L'木', L'水', L'火', L'土', L'竹', L'戈', L'十', L'大', L'中', L'一', L'弓', L'人', L'心', L'手', L'口', L'尸', L'廿', L'山', L'女', L'田', L'難', L'卜', L'重'};
  int *root_count = malloc(26*sizeof(int));
  double *root_freq = malloc(26*sizeof(double));
  for (i = 0; i < 26; i++) {
    root_count[i] = 0;
    root_freq[i] = 0.0;
  }
  FILE *fp = fopen ("cj5.cin", "r");
  FILE *fp_sample = fopen (argv[1], "r");  
  wchar_t str4 = L' ';  
  wchar_t *glyphs = malloc(sizeof(wchar_t));
  wchar_t **cangjies = malloc(sizeof(wchar_t));
  wchar_t *cangjie = malloc(sizeof(wchar_t));
  int *cangjie_counts = malloc(sizeof(int));

  while (fwscanf(fp, L"%ls %lc\n", cangjie, &str4) != WEOF) {
#ifdef DEBUG
    printf("%lc %lu %ls ", glyphs[dataCounts-1], wcslen(cangjie), cangjie);
#endif
    dataCounts++;
    cangjie_counts = realloc(cangjie_counts, dataCounts*sizeof(int));
    cangjie_counts[dataCounts-1] = wcslen(cangjie); 
    glyphs = (wchar_t *) realloc(glyphs, dataCounts*sizeof(wchar_t));
    cangjies = realloc(cangjies, dataCounts*sizeof(wchar_t*)); 
    cangjies[dataCounts-1] = malloc((wcslen(cangjie))*sizeof(wchar_t));
    glyphs[dataCounts-1] = str4;
#ifdef DEBUG
    printf("%lc %lu %ls ", glyphs[dataCounts-1], wcslen(cangjie), cangjie);
#endif
    for (i = 0; i < wcslen(cangjie); i++) {
      cangjies[dataCounts-1][i] = cangjie[i];
#ifdef DEBUG
      printf("%lc ", cangjies[dataCounts-1][i]);
#endif
    }
#ifdef DEBUG
    printf("%ls\n", cangjies[dataCounts-1]);
#endif
  }
  fclose(fp);
  printf("%5d\n", dataCounts);
  wint_t wc;
  int word_counts = 0;
  wchar_t letter = L' ';
  while (WEOF != (wc = fgetwc(fp_sample))) {
    letter = wc;
    for (i = 0; i < dataCounts; i++) {
      if (glyphs[i] == letter) {
#ifdef DEBUG
	printf("%lc v.s. %lc: matched!\n", glyphs[i], letter); 
#endif
	for (j = 0; j < cangjie_counts[i]; j++ ) {
	  for (k = 0; k < 26; k++) {
	    if (cangjies[i][j] == letters[k]) {
	      word_counts++;
	      root_count[k] = root_count[k] + 1;
	    }
	  }
	}
      }
    }
  }
  for (k = 0; k < 26; k++) {
    root_freq[k] = ((double) root_count[k])/((double) word_counts);
    printf("%lc:  %lf\n", roots[k], root_freq[k]);
  }
  fclose(fp_sample);
  return 0;
}


/*
** test9.c
** 
** Made by (Gong-Yi Liao)
** Login   <gong-yi@GongTop1>
** 
** Started on  Thu Sep 15 15:24:27 2011 Gong-Yi Liao
** Last update Thu Sep 22 12:13:03 2011 Gong-Yi Liao
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
#ifdef DVORAK
  const wchar_t row_key[] = {'H', 'B', 'T', 'H', 'H', 'T', 'T', 'H', 'H', 'B', 'B', 'T', 'B', 'H', 'H', 'T', 'B', 'T', 'H', 'H', 'H', 'B', 'B', 'B', 'T', 'B'};
  FILE *fp = fopen ("cj5_ergonomic.cin", "r");
#elif defined DVORAK_HT
  const wchar_t row_key[] = {'H', 'B', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'B', 'B', 'H', 'B', 'H', 'H', 'H', 'B', 'H', 'H', 'H', 'H', 'B', 'B', 'B', 'H', 'B'};
  FILE *fp = fopen ("cj5_ergonomic.cin", "r");
#elif defined DVORAK_HB
  const wchar_t row_key[] = {'H', 'H', 'T', 'H', 'H', 'T', 'T', 'H', 'H', 'H', 'H', 'T', 'H', 'H', 'H', 'T', 'H', 'T', 'H', 'H', 'H', 'H', 'H', 'H', 'T', 'H'};
  FILE *fp = fopen ("cj5_ergonomic.cin", "r");
#elif defined DVORAK_TB
  const wchar_t row_key[] = {'H', 'T', 'T', 'H', 'H', 'T', 'T', 'H', 'H', 'T', 'T', 'T', 'T', 'H', 'H', 'T', 'T', 'T', 'H', 'H', 'H', 'T', 'T', 'T', 'T', 'T'};
  FILE *fp = fopen ("cj5_ergonomic.cin", "r");
#elif defined QWERTY_HT
  const wchar_t row_key[] = {'H', 'B', 'B', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'B', 'B', 'H', 'H', 'H', 'H', 'H', 'H', 'H', 'B', 'H', 'B', 'H', 'B'};
  FILE *fp = fopen ("cj5.cin", "r");
#elif defined QWERTY_HB
  const wchar_t row_key[] = {'H', 'H', 'H', 'H', 'T', 'H', 'H', 'H', 'T', 'H', 'H', 'H', 'H', 'H', 'T', 'T', 'T', 'T', 'H', 'T', 'T', 'H', 'T', 'H', 'T', 'H'};
  FILE *fp = fopen ("cj5.cin", "r");
#else 
  const wchar_t row_key[] = {'H', 'B', 'B', 'H', 'T', 'H', 'H', 'H', 'T', 'H', 'H', 'H', 'B', 'B', 'T', 'T', 'T', 'T', 'H', 'T', 'T', 'B', 'T', 'B', 'T', 'B'};
  FILE *fp = fopen ("cj5.cin", "r");
#endif 
  const wchar_t rows[] = {'H', 'T', 'B', 'N'};
  int *row_count = malloc(4*sizeof(int));
  for (i = 0; i < 4; i++ )
    row_count[i] = 0;  
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
#ifdef DEBUG
  printf("%5d\n", dataCounts);
#endif 
  wint_t wc;
  wchar_t row1 = L'@';
  wchar_t row2 = L'@';  
  wchar_t letter = L' ';
  int one_row = 1;
  int matched_root = 0;
  int matched_glyph = 0;
  while (WEOF != (wc = fgetwc(fp_sample))) {
    letter = wc;
    matched_glyph = 0;
    i = 0;
    while ((i < dataCounts) && (matched_glyph == 0)) {
      if (glyphs[i] == letter) {
	row_count[3]++;
	matched_glyph = 1;
#ifdef DEBUG
	printf("%lc v.s. %lc: matched!\n", glyphs[i], letter); 
#endif
	row1 = L'@';
	row2 = L'@';  
	one_row = 1;
	j = 0;
	while ((j < cangjie_counts[i])  && (one_row == 1)) {
	  k = 0; 
	  matched_root = 0;
	  while ((k < 26) && (matched_root == 0)) {
	    if (cangjies[i][j] == letters[k]) {
	      matched_root = 1;
	      row1 = row_key[k];
	    }
	    k++;		  
	  }
	  if ((row1 != row2) && (j > 0))  {
	    one_row = 0;
	  } else {
	    row2 = row1;
	  }
	  j++;	  
	}
#ifdef DEBUG
	printf("%lc \n", row2);	
#endif
	if (one_row == 1) {
	  switch (row2) {
	  case 'H':
	    row_count[0]++;
	    break;
	  case 'T':
	    row_count[1]++;
	  break;
	  case 'B':
	    row_count[2]++;
	    break;
	  default:
	    break;
 	  }
	}
      }
      i++;
    }
  }
  for (k = 0; k < 4; k++) {
    printf("%lc:  %d\n", rows[k], row_count[k]);
  }
  fclose(fp_sample);
  free(glyphs);
  for (i = 0; i < dataCounts; i++)
    free(cangjies[i]);
  free(cangjies);
  free(cangjie_counts);
  free(cangjie);
  free(row_count);
  return 0;
}



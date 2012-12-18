/*
** test9.c
** 
** Made by (Gong-Yi Liao)
** Login   <gong-yi@GongTop1>
** 
** Started on  Thu Sep 15 15:24:27 2011 Gong-Yi Liao
** Last update Tue Oct 11 12:33:59 2011 Gong-Yi Liao
*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <malloc.h>
#include <string.h>

int main(int argc, char **argv) {
  setlocale(LC_CTYPE, "en_US.utf8");
  int glyphCounts = 0, j = 0, k = 0, i = 0;
  const wchar_t letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  FILE *fp = fopen ("cj5_ergonomic.cin", "r");
  wchar_t glyph = L' ';  
  wchar_t *cangjie = malloc(sizeof(wchar_t));
  wchar_t *cangjie_old = malloc(sizeof(wchar_t));;
  
  while (fwscanf(fp, L"%ls %lc\n", cangjie, &glyph) != WEOF) {
    if (wcscmp(cangjie_old, cangjie)) {
      printf(")\n(\"%ls\" \"%lc\"", cangjie, glyph);
    } else {
      printf(" \"%lc\"", glyph);
    }
    wcscpy(cangjie_old, cangjie);
    /* cangjie_counts = realloc(cangjie_counts, dataCounts*sizeof(int)); */
    /* cangjie_counts[dataCounts-1] = wcslen(cangjie);  */
    /* glyphs = (wchar_t *) realloc(glyphs, dataCounts*sizeof(wchar_t)); */
    /* cangjies = realloc(cangjies, dataCounts*sizeof(wchar_t*));  */
    /* cangjies[dataCounts-1] = malloc((wcslen(cangjie))*sizeof(wchar_t)); */
    /* glyphs[dataCounts-1] = str4; */
  }
  fclose(fp);
  return 0;
}





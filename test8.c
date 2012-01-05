/*
** test8.c
** 
** Made by (Gong-Yi Liao)
** Login   <gong-yi@GongTop1>
** 
** Started on  Thu Sep 15 14:58:53 2011 Gong-Yi Liao
** Last update Fri Sep 16 11:14:15 2011 Gong-Yi Liao
*/


#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <malloc.h>
#include <stdlib.h>
#include <wctype.h>

int main() {
  setlocale(LC_CTYPE, "en_US.utf8");
  FILE *fp = fopen ("cj5.cin", "r");
  wchar_t *str4 = malloc(sizeof(wchar_t));
  wchar_t glyph = L' ';
  while (fwscanf(fp, L"%ls %lc\n", str4, &glyph) != WEOF) {
    printf("%lc %ls\n", glyph, str4);
  }  
    
  printf("%ls\n", L"Schöne  Grüße中Grüße");
  return 0;
}




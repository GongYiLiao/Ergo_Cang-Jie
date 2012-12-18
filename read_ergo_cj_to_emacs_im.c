#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>

int main (int argc, char** argv) {
  setlocale(LC_CTYPE, "en_US.utf8");
  wchar_t k1 = L' ';
  wchar_t k2 = L' ';
  wchar_t *s1 = malloc (sizeof(wchar_t));
  wchar_t *s2 = malloc (sizeof(wchar_t)); 
  FILE *fp = fopen ("cj5_ergonomic.cin", "r");
  FILE *fpw = fopen ("cj5input_dvorak_ergonomic.el", "w");
  printf("(\"");
  while(fwscanf (fp, L"%ls %lc\n", s1, &k1) != WEOF) {    
    if (wcscmp (s1, s2) == 0) {
      fprintf(fpw, "%lc", k1);
    } else {
      fprintf(fpw, "\")\n(\"%ls\" \"%lc", s1, k1);
      wcscpy (s2, s1);
    }
  }
  fclose (fp);
  fclose (fpw);
  return 0;
}


 



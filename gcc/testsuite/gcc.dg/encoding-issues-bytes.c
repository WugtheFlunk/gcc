// { dg-options "-fdiagnostics-show-caret -fdiagnostics-escape-format=bytes" }

  /* { dg-warning "null character\\(s\\) ignored" } */
/* { dg-begin-multiline-output "" }
 <00>
 ^~~~
   { dg-end-multiline-output "" } */

/* Stray UTF-8 trailing byte: */
� /* { dg-error "stray '.200' in program" } */
/* { dg-begin-multiline-output "" }
 <80>
 ^~~~
   { dg-end-multiline-output "" } */

const char *fmt = "\"; /* { dg-warning "unknown escape sequence: '.001'" } */
/* { dg-begin-multiline-output "" }
 const char *fmt = "\<01>";
                          ^
   { dg-end-multiline-output "" } */

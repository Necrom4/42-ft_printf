#include "includes/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(void) {
  int n;
  char *s;
  void *p;

  n = 42;
  p = &n;

  /* %c */
  printf("%c\n", 'A');
  ft_printf("%c\n", 'A');
  printf("%c\n", 'z');
  ft_printf("%c\n", 'z');
  printf("%c\n", '0');
  ft_printf("%c\n", '0');
  printf("%c\n", ' ');
  ft_printf("%c\n", ' ');

  /* %s */
  printf("%s\n", "hello");
  ft_printf("%s\n", "hello");
  printf("%s\n", "");
  ft_printf("%s\n", "");
  printf("%s\n", "Hello, World!");
  ft_printf("%s\n", "Hello, World!");
  s = NULL;
  ft_printf("%s\n", s); /* NULL string: ft_printf prints (null) */

  /* %d */
  printf("%d\n", 0);
  ft_printf("%d\n", 0);
  printf("%d\n", 42);
  ft_printf("%d\n", 42);
  printf("%d\n", -42);
  ft_printf("%d\n", -42);
  printf("%d\n", INT_MAX);
  ft_printf("%d\n", INT_MAX);
  printf("%d\n", INT_MIN);
  ft_printf("%d\n", INT_MIN);
  printf("%d\n", -1);
  ft_printf("%d\n", -1);

  /* %i */
  printf("%i\n", 0);
  ft_printf("%i\n", 0);
  printf("%i\n", 42);
  ft_printf("%i\n", 42);
  printf("%i\n", -42);
  ft_printf("%i\n", -42);
  printf("%i\n", INT_MAX);
  ft_printf("%i\n", INT_MAX);
  printf("%i\n", INT_MIN);
  ft_printf("%i\n", INT_MIN);

  /* %u */
  printf("%u\n", 0u);
  ft_printf("%u\n", 0u);
  printf("%u\n", 42u);
  ft_printf("%u\n", 42u);
  printf("%u\n", UINT_MAX);
  ft_printf("%u\n", UINT_MAX);
  printf("%u\n", (unsigned int)-1);
  ft_printf("%u\n", (unsigned int)-1);

  /* %x */
  printf("%x\n", 0u);
  ft_printf("%x\n", 0u);
  printf("%x\n", 42u);
  ft_printf("%x\n", 42u);
  printf("%x\n", 255u);
  ft_printf("%x\n", 255u);
  printf("%x\n", 0xdeadbeefu);
  ft_printf("%x\n", 0xdeadbeefu);
  printf("%x\n", UINT_MAX);
  ft_printf("%x\n", UINT_MAX);

  /* %X */
  printf("%X\n", 0u);
  ft_printf("%X\n", 0u);
  printf("%X\n", 42u);
  ft_printf("%X\n", 42u);
  printf("%X\n", 255u);
  ft_printf("%X\n", 255u);
  printf("%X\n", 0xDEADBEEFu);
  ft_printf("%X\n", 0xDEADBEEFu);
  printf("%X\n", UINT_MAX);
  ft_printf("%X\n", UINT_MAX);

  /* %p */
  printf("%p\n", p);
  ft_printf("%p\n", p);
  printf("%p\n", (void *)NULL);
  ft_printf("%p\n", (void *)NULL);
  printf("%p\n", (void *)&s);
  ft_printf("%p\n", (void *)&s);

  /* %% */
  printf("%%\n");
  ft_printf("%%\n");
  printf("100%%\n");
  ft_printf("100%%\n");

  /* bonus: # flag */
  printf("%#x\n", 0u);
  ft_printf("%#x\n", 0u);
  printf("%#x\n", 42u);
  ft_printf("%#x\n", 42u);
  printf("%#x\n", 255u);
  ft_printf("%#x\n", 255u);
  printf("%#X\n", 42u);
  ft_printf("%#X\n", 42u);
  printf("%#X\n", 255u);
  ft_printf("%#X\n", 255u);

  /* bonus: + flag */
  printf("%+d\n", 0);
  ft_printf("%+d\n", 0);
  printf("%+d\n", 42);
  ft_printf("%+d\n", 42);
  printf("%+d\n", -42);
  ft_printf("%+d\n", -42);
  printf("%+d\n", INT_MAX);
  ft_printf("%+d\n", INT_MAX);
  printf("%+d\n", INT_MIN);
  ft_printf("%+d\n", INT_MIN);

  /* bonus: space flag */
  printf("% d\n", 0);
  ft_printf("% d\n", 0);
  printf("% d\n", 42);
  ft_printf("% d\n", 42);
  printf("% d\n", -42);
  ft_printf("% d\n", -42);

  /* mixed */
  printf("%s=%d\n", "val", -1);
  ft_printf("%s=%d\n", "val", -1);
  printf("%c %s %d\n", 'X', "hi", 7);
  ft_printf("%c %s %d\n", 'X', "hi", 7);
  printf("%d + %d = %d\n", 1, 2, 3);
  ft_printf("%d + %d = %d\n", 1, 2, 3);
  printf("hex: %x / %X\n", 255u, 255u);
  ft_printf("hex: %x / %X\n", 255u, 255u);
  printf("ptr=%p str=%s\n", p, "ok");
  ft_printf("ptr=%p str=%s\n", p, "ok");
  printf("%% done: %d%%\n", 100);
  ft_printf("%% done: %d%%\n", 100);

  /* return values */
  int r1 = printf("%d\n", -42);
  int r2 = ft_printf("%d\n", -42);
  printf("ret printf=%d ft_printf=%d\n", r1, r2);

  r1 = printf("%s\n", "hello world");
  r2 = ft_printf("%s\n", "hello world");
  printf("ret printf=%d ft_printf=%d\n", r1, r2);

  r1 = printf("%p\n", (void *)NULL);
  r2 = ft_printf("%p\n", (void *)NULL);
  printf("ret printf=%d ft_printf=%d\n", r1, r2);

  return (0);
}

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <limits.h>
#include "../libft.h"

TestSuite(ft_memchr, .timeout = 5);

Test(ft_memchr, first_byte)
{
    char s[] = "hello";
    cr_assert(eq(ptr, ft_memchr(s, 'h', 5), &s[0]));
}

Test(ft_memchr, middle_byte)
{
    char s[] = "hello";
    cr_assert(eq(ptr, ft_memchr(s, 'l', 5), &s[2]));
}

Test(ft_memchr, last_byte)
{
    char s[] = "hello";
    cr_assert(eq(ptr, ft_memchr(s, 'o', 5), &s[4]));
}

Test(ft_memchr, no_match)
{
    char s[] = "hello";
    cr_assert(zero(ptr, ft_memchr(s, 'x', 5)));
}

Test(ft_memchr, limit_search_to_n)
{
    char s[] = "hello";
    cr_assert(zero(ptr, ft_memchr(s, 'o', 4)));
}

Test(ft_memchr, zero_n)
{
    char s[] = "hello";
    cr_assert(zero(ptr, ft_memchr(s, 'h', 0)));
}

Test(ft_memchr, past_null_byte)
{
    unsigned char s[] = {'a', '\0', 'b', 'c'};
    cr_assert(eq(ptr, ft_memchr(s, 'b', sizeof(s)), &s[2]));
}

Test(ft_memchr, find_null_byte)
{
    unsigned char s[] = {'a', '\0', 'b'};
    cr_assert(eq(ptr, ft_memchr(s, '\0', sizeof(s)), &s[1]));
}

Test(ft_memchr, treat_c_as_uchar)
{
    unsigned char s[] = {'a', UCHAR_MAX, 'b'};
    cr_assert(eq(ptr, ft_memchr(s, -1, sizeof(s)), &s[1]));
}

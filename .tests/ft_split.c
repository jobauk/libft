#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

Test(libft, ft_split)
{
	{
		char **actual = ft_split("hello world test", ' ');
	    char *expected[] = {
	        "hello",
	        "world",
	        "test",
			NULL
	    };

	    cr_assert(eq(str[3], actual, expected));
		cr_assert(zero(actual[3]));
	}
	{
		char **actual = ft_split("   hello world  test ", ' ');
	    char *expected[] = {
			"",
			"",
			"",
	        "hello",
	        "world",
			"",
	        "test",
			"",
			NULL
	    };

	    cr_assert(eq(str[7], actual, expected));
		cr_assert(zero(actual[7]));
	}
	{
		char **actual = ft_split("", ' ');
	    char *expected[] = {
	        "",
			NULL
	    };

	    cr_assert(eq(str[1], actual, expected));
		cr_assert(zero(actual[1]));
	}
	{
		char **actual = ft_split("Hello, world", '\0');
	    char *expected[] = {
	        "Hello, world",
			NULL
	    };

	    cr_assert(eq(str[1], actual, expected));
		cr_assert(zero(actual[1]));
	}
	{
		char **actual = ft_split("Hello, world", '&');
	    char *expected[] = {
	        "Hello, world",
			NULL
	    };

	    cr_assert(eq(str[1], actual, expected));
		cr_assert(zero(actual[1]));
	}
}

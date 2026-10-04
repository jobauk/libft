#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../libft.h"

TestSuite(ft_split, .timeout = 5);

Test(ft_split, empty_input) {
	char **actual = ft_split("", ',');
	char *expected[] = {""};

	cr_assert(all(eq(str[1], actual, expected), zero(ptr, actual[1])));
}

Test(ft_split, no_seperator) {
	char **actual = ft_split("abc", ',');
	char *expected[] = {"abc", NULL};

	cr_assert(all(eq(str[1], actual, expected), zero(ptr, actual[1])));
}

Test(ft_split, null_seperator) {
	char **actual = ft_split("abc", '\0');
	char *expected[] = {"abc", NULL};

	cr_assert(all(eq(str[1], actual, expected), zero(ptr, actual[1])));
}

Test(ft_split, single_separator) {
	char **actual = ft_split("a,b", ',');
	char *expected[] = {"a", "b", NULL};

	cr_assert(all(eq(str[2], actual, expected), zero(ptr, actual[2])));
}

Test(ft_split, leading_separator) {
	char **actual = ft_split(",a", ',');
	char *expected[] = {"", "a", NULL};

	cr_assert(all(eq(str[2], actual, expected), zero(ptr, actual[2])));
}

Test(ft_split, trailing_separator) {
	char **actual = ft_split("a,", ',');
	char *expected[] = {"a", "", NULL};

	cr_assert(all(eq(str[2], actual, expected), zero(ptr, actual[2])));
}

Test(ft_split, consecutive_separators) {
	char **actual = ft_split("a,,b", ',');
	char *expected[] = {"a", "", "b", NULL};

	cr_assert(all(eq(str[3], actual, expected), zero(ptr, actual[3])));
}

Test(ft_split, only_separators) {
	char **actual = ft_split(",,,", ',');
	char *expected[] = {"", "", "", "", NULL};

	cr_assert(all(eq(str[4], actual, expected), zero(ptr, actual[4])));
}

Test(ft_split, multiple_separators) {
	char **actual = ft_split("a,b,c", ',');
	char *expected[] = {"a", "b", "c", NULL};

	cr_assert(all(eq(str[3], actual, expected), zero(ptr, actual[3])));
}

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(fazz_bizz, basic, .init=redirect_all_stdout)
{
    printf("test\n");

	fflush(stdout);
    cr_assert_stdout_eq_str("test\n", "");
}

Test(test, always_true)
{
	cr_assert(0, 0);
}

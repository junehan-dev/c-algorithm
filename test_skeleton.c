#include "minunit.h"
char	*test_functions() {
	return (NULL);
}
char	*test_failures() {
	return (NULL);
}
char	*test_all() {
	mu_suite_start();
	mu_run_test(test_function);
	mu_run_test(test_failures);
	
	return (NULL);
}

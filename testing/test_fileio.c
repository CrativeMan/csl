#include "test.h"

#include "fileio/text.h"

void test_fileio_readFile(void) {
    {
        char *buffer = csl_read_string_from_file("testing/testtxt.txt");
        int passed = (strcmp(buffer, "Hello, World!\nLorem Ipsum\n") == 0);
        evaluate_test_results("csl_read_string_from_file_txt", passed);
        free(buffer);
    }
    {
        char *buffer = csl_read_string_from_file("testing/testmd.md");
        int passed = (strcmp(buffer, "# Heading1\n## Heading2\n") == 0);
        evaluate_test_results("csl_read_string_from_file_md", passed);
        free(buffer);
    }
    {
        char *buffer = csl_read_string_from_file("testing/testbin");
        int passed = (buffer == NULL);
        evaluate_test_results("csl_read_string_from_file_bin", passed);
        free(buffer);
    }
    {
        char *buffer = csl_read_string_from_file("testing/testpng.png");
        int passed = (buffer == NULL);
        evaluate_test_results("csl_read_string_from_file_png", passed);
        free(buffer);
    }
    {
        char *buffer = csl_read_string_from_file("testing/testjpg.jpg");
        int passed = (buffer == NULL);
        evaluate_test_results("csl_read_string_from_file_jpg", passed);
        free(buffer);
    }
    {
        char *buffer = csl_read_string_from_file("testing/notfound.txt");
        int passed = (buffer == NULL);
        evaluate_test_results("csl_read_string_from_file_not_found", passed);
        free(buffer);
    }
}

void test_fileio_writeFile(void) {
    {
        const char *buffer = "Hello, World!\nThis is a new line.\nThis is a "
                             "new line with numbers.";
        int result = csl_write_string_to_file(buffer, "testing/wrote.txt");
        evaluate_test_results("csl_write_string_to_file_txt", result);
    }
}

#include "test.h"

#include "fileio/text.h"

void test_fileio_readFile(void) {
    {
        char *buffer = csl_read_string_from_file("testing/files/testtxt.txt");
        int passed = (strcmp(buffer, "Hello, World!\nLorem Ipsum\n") == 0);
        cslint_test("csl_read_string_from_file_txt", false, passed);
        free(buffer);
    }
    {
        char *buffer = csl_read_string_from_file("testing/files/testmd.md");
        int passed = (strcmp(buffer, "# Heading1\n## Heading2\n") == 0);
        cslint_test("csl_read_string_from_file_md", false, passed);
        free(buffer);
    }
    {
        char *buffer = csl_read_string_from_file("testing/files/testbin");
        int passed = (buffer == NULL);
        cslint_test("csl_read_string_from_file_bin", false, passed);
        free(buffer);
    }
    {
        char *buffer = csl_read_string_from_file("testing/files/testpng.png");
        int passed = (buffer == NULL);
        cslint_test("csl_read_string_from_file_png", false, passed);
        free(buffer);
    }
    {
        char *buffer = csl_read_string_from_file("testing/files/testjpg.jpg");
        int passed = (buffer == NULL);
        cslint_test("csl_read_string_from_file_jpg", false, passed);
        free(buffer);
    }
    {
        char *buffer = csl_read_string_from_file("testing/files/testjpg.jpg");
        int passed = (buffer == NULL);
        cslint_test("csl_read_string_from_file_jpg", false, passed);
        free(buffer);
    }
    {
        char *buffer = csl_read_string_from_file("testing/files/notfound.txt");
        int passed = (buffer == NULL);
        cslint_test("csl_read_string_from_file_not_found", false, passed);
        free(buffer);
    }
}

void test_fileio_writeFile(void) {
    {
        const char *buffer = "Hello, World!\nThis is a new line.\nThis is a "
                             "new line with numbers.";
        int result = csl_write_string_to_file(buffer, "testing/files/wrote.txt");
        cslint_test("csl_write_string_to_file_txt", false, result);
    }
}

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

    write(1,"1",1);
	fd = open("../test/inputs/test_1_a", O_RDONLY);
	assert(strcmp(get_next_line(fd), "a") == 0);

	write(1,"2",1);
	fd = open("../test/inputs/test_1_b", O_RDONLY);
	assert(strcmp(get_next_line(fd), "b") == 0);

	write(1,"3",1);
	fd = open("../test/inputs/test_1_aa", O_RDONLY);
	assert(strcmp(get_next_line(fd), "aa") == 0);

	write(1,"4",1);
	fd = open("../test/inputs/test_1_aa", O_RDONLY);
	assert(strcmp(get_next_line_core(fd, 1), "aa") == 0);

	write(1,"5",1);
	fd = open("../test/inputs/test_3_a", O_RDONLY);
	assert(strcmp(get_next_line_core(fd, 1), "a\n") == 0);
	assert(strcmp(get_next_line_core(fd, 1), "b\n") == 0);
	assert(strcmp(get_next_line_core(fd, 1), "c\n") == 0);

	write(1,"6",1);
	fd = open("../test/inputs/test_3_aaa", O_RDONLY);
	assert(strcmp(get_next_line_core(fd, 5), "aaa\n") == 0);
	assert(strcmp(get_next_line_core(fd, 5), "b\n") == 0);
	assert(strcmp(get_next_line_core(fd, 5), "c\n") == 0);

	// write(1,"7",1);
	// fd = open("../test/inputs/test_empty", O_RDONLY);
    //assert(get_next_line_core(fd, 5) == NULL);

	printf("\nAll Green\n");
}
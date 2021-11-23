#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int	index;//読み込み回数を確認する用
	//static int i;
	int	fd = open("test.txt", O_RDONLY);
	printf("fd = %d\n", fd);

	char	*receiver = NULL;
	index = 0;
	//printf("static=%d\n", i);//staticの初期値を調べている。デフォルトがある。
	while (1){
		receiver = get_next_line(fd);
		if (!receiver){
			printf("EOF or ERROR\n");
			break ;
		}
		printf("[%d]%s", index, receiver);
		index ++;
		free(receiver);
	}
	system("leaks a.out");
	close(fd);
}
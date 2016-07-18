#include <stdio.h>
#include <stdlib.h>

#include "kalman.h"

int main(int argc,char *argv[])
{
	int i;
	if(argc < 2)
	{
		printf("Usage kalman_demo  file_name\n");
		return -1;
	}
	FILE* out = fopen(argv[1],"w");
    if(out == NULL)
        return 1;

	kalmanState_t kalmanFilter = kalmanState_new();
	kalmanState_init(kalmanFilter);
	kalmanFilter_update(kalmanFilter,out);

	fclose(out);
}

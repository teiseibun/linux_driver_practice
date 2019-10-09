#include <stdio.h>

int main(void)
{
	char buf[512];

	FILE *fp = fopen("/dev/demo_drv", "w+");

	if(fp == NULL) {
		printf("can't open device, try: sudo ./user!\n");
		return 0;
	}

	//type dmesg to check the result
	fread(buf, sizeof(buf), 1, fp);
	fwrite(buf, sizeof(buf), 1, fp);
	fclose(fp);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
	struct sockaddr_in addr1, addr2;
	char *str_ptr;
	char str_arr[20];

	if(argc != 3)
	{
		printf("Usage : %s <IP1> <IP2>\n", argv[0]);
		exit(1);
	}

	printf("IP address1 : %s \n", argv[1]);
	printf("IP address2 : %s \n", argv[2]);
	
	if(!inet_aton(argv[1], &addr1.sin_addr))
		printf("Conversion error\n");
	else
		printf("network orderd integer addr1 : %#x \n", addr1.sin_addr.s_addr);

	if(!inet_aton(argv[2], &addr2.sin_addr))
		printf("Conversion error\n");
	else
		printf("network orderd integer addr2 : %#x \n", addr2.sin_addr.s_addr);

	str_ptr=inet_ntoa(addr1.sin_addr);
	strcpy(str_arr, str_ptr);
	printf("Dotted-Decimal notation1: %s \n", str_ptr);

	inet_ntoa(addr2.sin_addr);
	printf("Dotted-Decimal notation2: %s \n", str_ptr);
	printf("Dotted-Decimal notation3: %s \n", str_arr);
	return 0;
}

	

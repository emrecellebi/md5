#include "md5.h"
#include <string.h>

int main(int argc, char** argv)
{	
	if(argc <= 1)
	{
		printf("md5 : No command specified. Use 'md5 -h or --help' for a detailed command list");
		return 1;
	}
	
	if(argc == 3 && (strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "--hex") == 0))
	{
		unsigned char res[MD5_DIGEST_SIZE];
		struct md5_ctx ctx;
		int i;
		
		FILE* fs;
		const char* data = argv[2];
		if((fs = fopen(data, "rb")) != NULL)
		{
			md5_stream(fs, res);
			for(i = 0; i < MD5_DIGEST_SIZE; i++)
				printf("%02x", res[i]);
			fclose(fs);
			return 1;
		}
		
		md5_init_ctx(&ctx);
		md5_process_bytes(data, strlen(data), &ctx);
		md5_finish_ctx(&ctx, res);
		for(i = 0; i < MD5_DIGEST_SIZE; i++)
			printf("%02x", res[i]);
		
		return 1;
	}
	
	if(argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")))
	{
		printf("\nCopyright (c) 2012-2025 Emre Celebi\n\n");
		printf("Usage: md5 [-options] <parameters>\n");
		printf("  -i, --hex <str>\n");
		printf("  -v, --version\n");
		printf("  -h, --help\n");
		return 1;
	}
	
	if(argc == 2 && (!strcmp(argv[1], "-v") || !strcmp(argv[1], "--version")))
	{
		printf("\nmd5 version: 0.0.2 Pre-Alpha\n");
		printf("Last revised: 05th Apr 2025\n");
		printf("The last version is always avaible\n");
		printf("Created By Emre Celebi\n");
		return 1;
	}
	
	return 0;
}
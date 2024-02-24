/*
Name : SAI HARI HARA CHANDRA TALAGADADEEVI
Description : Steganography
Sample Input : NIL 
sample Output : NIL
 */
#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "decode.h"
#include "types.h"

int main(int argc, char *argv[])
{
	DecodeInfo decodeinfo;
	EncodeInfo encodeinfo;
	if(argc > 1 && argc <= 5)
	{
		if(check_operation_type(argv) == e_encode)
		{
			if(read_and_validate_encode_args(argv, &encodeinfo) == e_success)
			{
				if(do_encoding(&encodeinfo) == e_success)
				{
					printf("**Encoding Finished**\n");
				}
				else
					printf("ERROR: Encoding Terminated\n");
			}
			else
				printf("ERROR: Arguments should be given in sequence ./a.out -e <.bmp_file> <.text_file> [output file]\n");
		}

		else if(check_operation_type(argv) == e_decode)
		{
			if(read_and_validate_decode_args(argv, &decodeinfo) == e_success)
			{
				if(do_decoding(&decodeinfo) == e_success)
				{
					printf("**Decoding Finished**\n");
				}
				else
					printf("ERROR: Decoding Terminated\n");
			}
			else
				printf("ERROR: Arguments should be given in sequence ./a.out -d <.bmp_file> <.text_file>\n");
		}
		else
		{
			printf("ERROR: Invalid option\n");
		}
	}
	else
	{
		printf("Error : Arguments missing\nEncode requires atleast 4 Arguments\nDecode reqiures atleast 2 Arguments\n");
		printf("Example encode : ./a.out -e <.bmp_file> <.text_file> [option file]\nExample decode : ./a.out -d <.bmp_file>\n");
	}

	return 0;
}

OperationType check_operation_type(char *argv[])
{
	if(strcmp(argv[1],"-e") == 0)
		return e_encode;
	else if(strcmp(argv[1],"-d") == 0)
		return e_decode;
	else
		return e_unsupported;
}

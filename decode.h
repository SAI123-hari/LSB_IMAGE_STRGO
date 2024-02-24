#ifndef DECODE_H
#define DECODE_H

#include "types.h" // Contains user defined types

/*
 * Structure to store information required for
 * decoding secret file to source Image
 * Info about output and intermediate data is
 * also stored
 */

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)

typedef struct _DecodeInfo
{
    /* Stego image Info */
    char *d_src_image_fname;
    FILE *fptr_d_src_image;

    char d_image_data[MAX_IMAGE_BUF_SIZE];
    char *magic_data;
    char *d_extn_secret_file;

    int size_secret_file;
    FILE *fptr_d_dest_image;

    char *d_secret_fname;
    FILE *fptr_d_secret;
} DecodeInfo;


/* Decoding Function Prototypes */

/* 1 Read and validate decode args from argv */
Status read_and_validate_decode_args(char *argv[], DecodeInfo *decInfo);

/* 2 Perform the decoding */
Status do_decoding(DecodeInfo *decInfo);

/* 3 Get File pointers for i/p and o/p files */
Status open_files_dec(DecodeInfo *decInfo);

/* 4 Decode Magic String */
Status decode_magic_string(DecodeInfo *decInfo);

/* 5 Decode data from image */
Status decode_data_from_image(int size, FILE *fptr_d_src_image, DecodeInfo *decInfo);

/* 6 Decode byte from lsb */
Status decode_byte_from_lsb(char *data, char *image_buffer);

/* 7 Decode file extn size */ 
Status decode_file_extn_size (int size, FILE *fptr_d_src_image);

/* 8 Decode size from lsb */
Status decode_size_from_lsb (char *buffer, int *size);

/* 9 Decode secret file extn */
Status decode_secret_file_extn (char *file_ext, DecodeInfo *decInfo) ;

/* 10 Decode extension data from image */
Status decode_extension_data_from_image ( int size, FILE *fptr_d_src_image, DecodeInfo *decInfo); 

/* 11 Decode secret file size */
Status decode_secret_file_size (int file_size, DecodeInfo *decInfo);

/* 12 Decode secret file data */
Status decode_secret_file_data (DecodeInfo *decInfo);

#endif

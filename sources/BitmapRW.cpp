#include <stdio.h>
#include <stdlib.h>

#define READ_SUCCESS 1
#define READ_FAILED 0

void reverseBytes(void *x, const int n)
{
    char *ch = (char *)ch;
    for(int i = 0; i<n/2; i++)
    {
        char tmp = ch[i];
        ch[i] = ch[n-1-i];
        ch[n-1-i] = tmp;
    }
}


void* readBitmap(char *filename)
{
    FILE *fp;
    fp = fopen(filename, "rb");
    if(!fp)
    {
        printf("Couldn't open file.\n");
        printf("Line: %d\n", __LINE__);
        perror("Error:");
        return READ_FAILED;
    }

    /*
     * 0-2    magic_number
     * 2-18   other_data, read Bitmap file format article on wikipedia, we're skipping this data
     * 18-22  width
     * 22-26  height
     * 26-30  image_size
     * 30-32  planes per pixel
     * 32-34  bits per pixel
     * 54 -   image data
     */

    unsigned short magic_number;
    unsigned int width, height, imagesize;
    unsigned short ppp, bpp;
    unsigned int compression;
    unsigned char *imagedata;


    if(fread(&magic_number, 2, 1, fp) != 1)
    {
        printf("Error on reading magic number.\n Line:%d \n", __LINE__);
        return READ_FAILED;
    }

    if(magic_number != 0x4D42 && magic_number != 0x424D)
    {
        printf("Error: Seems like not a Bitmap file or its header is corrupted.\n Line:%d \n", __LINE__);
        return READ_FAILED;
    }

    if( fseek(fp, 16, SEEK_CUR) || fread(&width, 4, 1, fp) != 1 || fread(&height, 4, 1, fp) != 1 ||
        fread(&ppp, 2, 1, fp) != 1 || fread(&bpp, 2, 1, fp) != 1  ||
        fread(&compression, 4, 1, fp) != 1 )
    {
        printf("Error: Problem with reading header.\n Line:%d \n", __LINE__);
        return READ_FAILED;
    }

    if( magic_number == 0x424D ) //Stored as Little-Endian, so need to reverse the bytes then
    {
        reverseBytes(&width, 4);
        reverseBytes(&height, 4);
        reverseBytes(&ppp, 2);
        reverseBytes(&bpp, 2);
        reverseBytes(&compression, 4);
    }

    if( width<1 || width>65536 )
    {
        printf("Error: Image width is out of range.\n Line:%d\n", __LINE__);
        return READ_FAILED;
    }
    if( height<1 || height>65536 )
    {
        printf("Error: Image height is out of range.\n Line:%d\n", __LINE__);
        return READ_FAILED;
    }
    if( ppp != 1 )
    {
        printf("Error: Bit Plane > 1 is not supported.\n Line:%d\n", __LINE__);
        return READ_FAILED;
    }
    if( bpp != 24 )
    {
        printf("Error: Bits/pixel > 24 is not supported.\n Line:%d\n", __LINE__);
        return READ_FAILED;
    }

    int i;
    for(i=1; i<width; i++);
    if(i != width)
    {
        printf("Error: Image width is not a power of 2.\n Line:%d\n", __LINE__);
        return READ_FAILED;
    }
    for(i=1; i<height; i++);
    if(i != height)
    {
        printf("Error: Image height is not a power of 2.\n Line:%d\n", __LINE__);
        return READ_FAILED;
    }

    //Now we need to read the image-data
    imagesize = 3 * width * height;

    imagedata = malloc(sizeof(char) * imagesize);

    printf("%d", SEEK_CUR);
    if( fseek(fp, 20, SEEK_CUR) || fread(imagedata, imagesize, 1, fp) != 1)
    {
        printf("Error: Couldn't read the image data.\n Line:%d\n", __LINE__);
        return READ_FAILED;
    }

    printf("ImageDimensions: [%dx%d] \nImageSize: %d kB\n", width, height, imagesize/1024);
    printf("BPP: %d \t PPP: %d", bpp, ppp);

    return imagedata;
    //don't forget to release memory for image;

}

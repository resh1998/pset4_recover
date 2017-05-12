#include <stdio.h>
#include <cs50.h>
#include <stdint.h>

// creating a datatype of size 8 bytes
typedef uint8_t BYTE;

int main(void)
{
    
    // open the cardfile
    FILE *raw_file = fopen("card.raw", "r");
    
    // check for the error in cardfile
    if (raw_file == NULL)
    {
        fprintf(stderr, "Could not open the cardfile\n");
        
        return 1;
    }
    
    // creating an array buffer for storing bytes
    BYTE buffer[512];
    
    // num for the image count    
    int num = 0;
    
    // creating an array of char to store output filename
    char filename[10];
    
    // creating an outfile
    FILE* out_file = NULL;
    
    // loop continues till the end of the file
    while(fread(&buffer, sizeof(buffer), 1, raw_file))
    {
        
        // checking the start of the jpeg file
        if (buffer[0] == 0xff && 
            buffer[1] == 0xd8 && 
            buffer[2] == 0xff && 
            (buffer[3] & 0xf0) == 0xe0)
        {
            
        }
        
    }
    
    // close the card.raw file
    fclose(raw_file);
    
    // close the outfile
    fclose(out_file);
    
    return 0; 

    
}
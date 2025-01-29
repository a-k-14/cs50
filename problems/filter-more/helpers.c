#include <math.h>

#include "helpers.h"

int min_value(int x);
int clamp(int x);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;
    // loop over the rows using height
    for (int i = 0; i < height; i++)
    {
        // loop over a row i.e. width of the row
        for (int j = 0; j < width; j++)
        {
            // calculate the average of rgb value
            RGBTRIPLE pixel = image[i][j];
            average = round((pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed) / 3.0);
            // printf("%i\n", average);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // we loop through the rows with height
    for (int i = 0; i < height; i++)
    {
        // we llop through a single row with width

        // to reverse the order of pixels, we can traverse halfway
        int halfway = width / 2;

        // we loop from 0th pixel to halfway th pixel
        for (int k = 0; k < halfway; k++)
        {
            // assigning original pixel value to a temp pixel
            RGBTRIPLE t_pixel = image[i][k];

            // getting the mirror pixel location
            int mirror_loc = width - k - 1;

            // getting the mirror pixel
            RGBTRIPLE m_pixel = image[i][mirror_loc];

            // updating the original pixel with mirror pixel value
            image[i][k] = m_pixel;

            // updating the mirror pixel with original pixel value
            image[i][mirror_loc] = t_pixel;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // we loop through the rows with height
    for (int i = 0; i < height; i++)
    {
        // we decide the row start and end for each iteration to handle the edge cases
        int is = (i == 0) ? i : i - 1;          // start row
        int ie = (i == height - 1) ? i : i + 1; // end row

        /*
        if (i == 0)
        {
            is = i;
            ie = i + 1;
        } else if (i == height - 1)
        {
            is = i - 1;
            ie = i;
        } else
        {
            is = i- 1;
            ie = i + 1;
        }
        */

        // we loop through the width of the row with width
        for (int j = 0; j < width; j++)
        {
            // we decide the width start and end for each iteration to handle edge cases
            int js = (j == 0) ? j : j - 1;         // row start
            int je = (j == width - 1) ? j : j + 1; // row end

            /*
            if (j == 0)
            {
                js = j;
                je = j + 1;
            } else if (j == width - 1)
            {
                js = j - 1;
                je = j;
            } else
            {
                js = j - 1;
                je = j + 1;
            }
            */

            // we iterate through the is, ie, js, je matrix to get the averages
            int Rsum = 0;
            int Gsum = 0;
            int Bsum = 0;
            int counter = 0;

            for (int k = is; k <= ie; k++)
            {
                for (int l = js; l <= je; l++)
                {
                    Rsum += copy[k][l].rgbtRed;
                    Gsum += copy[k][l].rgbtGreen;
                    Bsum += copy[k][l].rgbtBlue;
                    counter += 1;
                }
            }

            image[i][j].rgbtRed = round(Rsum / (float) counter);
            image[i][j].rgbtGreen = round(Gsum / (float) counter);
            image[i][j].rgbtBlue = round(Bsum / (float) counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // we create a copy of image to preserve original values
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // we create the Gx and Gy matrix
    int g_x[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int g_y[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};


    // we loop through the rows with height
    for (int i = 0; i < height; i++)
    {

        // we create the start and end rows for getting the 3 x 3 matrix for a pixel
        int is = (i == 0) ? i : i - 1; // start row
        int ie = (i == height - 1) ? i : i + 1; // end row

        // we loop through the width of a row
        for (int j = 0; j < width; j++)
        {
            // we create the width start and end
            int js = (j == 0) ? j : j -1; // start of the row
            int je = (j == width -1) ? j : j + 1; // end of the row

            int rx = 0;
            int ry = 0;
            int gx = 0;
            int gy = 0;
            int bx = 0;
            int by = 0;

            // int el_h = 0; // to traverse the rows of kernel
            // int el_y = 0; // to traverse along the row (width) of kernel

            for (int k = is; k <= ie; k++)
            {
                // el_y = 0; // reset width wise traverse

                for (int l = js; l <= je; l++)
                {
                    /*
                    rx += copy[k][l].rgbtRed * (g_x[k - is][l - js]);
                    ry += copy[k][l].rgbtRed * (g_y[k - is][l - js]);

                    gx += copy[k][l].rgbtGreen * (g_x[k - is][l - js]);
                    gy += copy[k][l].rgbtGreen * (g_y[k - is][l - js]);

                    bx += copy[k][l].rgbtBlue * (g_x[k - is][l - js]);
                    by += copy[k][l].rgbtBlue * (g_y[k - is][l - js]);
                    */

                       // Calculate the kernel indices
                    int kernel_row = k - (i - 1);
                    int kernel_col = l - (j - 1);

                    // Apply the Gx and Gy kernels to each color channel
                    rx += copy[k][l].rgbtRed * g_x[kernel_row][kernel_col];
                    ry += copy[k][l].rgbtRed * g_y[kernel_row][kernel_col];

                    gx += copy[k][l].rgbtGreen * g_x[kernel_row][kernel_col];
                    gy += copy[k][l].rgbtGreen * g_y[kernel_row][kernel_col];

                    bx += copy[k][l].rgbtBlue * g_x[kernel_row][kernel_col];
                    by += copy[k][l].rgbtBlue * g_y[kernel_row][kernel_col];

                    // el_y += 1;
                }

                // el_h += 1;
            }

            image[i][j].rgbtRed = clamp( round( sqrt( rx * rx + ry * ry) ) );
            image[i][j].rgbtGreen = clamp(  round( sqrt( gx * gx + gy * gy) ) );
            image[i][j].rgbtBlue = clamp(  round( sqrt( bx * bx + by * by) ) );
        }
    }

    return;
}

int clamp(int x)
{
    if (x < 0)
    {
        return 0;
    } else if (x > 255)
    {
        return 255;
    } else
    {
        return x;
    }
}

int min_value(int x)
{
    return x < 255 ? x : 255;
}

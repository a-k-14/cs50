#include <math.h>
#include <stdio.h>

#include "helpers.h"

int min_value(int x);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average = 0;
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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int average = 0;
    // loop over the rows using height
    for (int i = 0; i < height; i++)
    {
        // loop over a row i.e. width of the row
        for (int j = 0; j < width; j++)
        {
            // printf("%i\n", width);

            // calculate the sepia values
            RGBTRIPLE pixel = image[i][j];

            int sepiaRed =
                round(.393 * pixel.rgbtRed + .769 * pixel.rgbtGreen + .189 * pixel.rgbtBlue);
            int sepiaGreen =
                round(.349 * pixel.rgbtRed + .686 * pixel.rgbtGreen + .168 * pixel.rgbtBlue);
            int sepiaBlue =
                round(.272 * pixel.rgbtRed + .534 * pixel.rgbtGreen + .131 * pixel.rgbtBlue);

            // printf("%i\n", average);

            image[i][j].rgbtBlue = min_value(sepiaBlue);
            image[i][j].rgbtGreen = min_value(sepiaGreen);
            image[i][j].rgbtRed = min_value(sepiaRed);
        }
    }

    return;
}

int min_value(int x)
{
    return x < 255 ? x : 255;
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
        int is = (i == 0) ? i : i -1 ; // start row
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
        for(int j = 0; j < width; j++)
        {
            // we decide the width start and end for each iteration to handle edge cases
            int js = (j == 0) ? j : j - 1; // row start
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

            for(int k = is; k <= ie; k++)
            {
                for(int l = js; l <= je; l++)
                {
                    Rsum += copy[k][l].rgbtRed;
                    Gsum += copy[k][l].rgbtGreen;
                    Bsum += copy[k][l].rgbtBlue;
                    counter += 1;
                }
            }

            // we calculate the average, we make counter float to preserve decimals
            // we round as RGB values are integers
            image[i][j].rgbtRed = round( Rsum / (float) counter );
            image[i][j].rgbtGreen = round( Gsum / (float) counter );
            image[i][j].rgbtBlue = round( Bsum / (float) counter );
        }
    }
    return;
}

// vertical flip
void vertical(int height, int width, RGBTRIPLE image[height][width])
{
    // to vertically flip an image, we only need to loop through half of the rows

    // get half of the rows as int
    int halfway = height / 2;

    for (int i = 0; i < halfway; i++)
    {

        for (int j = 0; j < width; j++)
        {
            // assigning original pixel to a temp pixel
            RGBTRIPLE t_pixel = image[i][j];

            // getting the mirror pixel location
            int mirror_loc = height - i - 1;

            // getting the mirror pixel
            RGBTRIPLE m_pixel = image[mirror_loc][j];

            // updating the original pixel with mirror pixel value
            image[i][j] = m_pixel;

            // updating the mirror pixel with original pixel value
            image[mirror_loc][j] = t_pixel;
        }
    }

    return;
}

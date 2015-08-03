#include "epng.h"

// sets up the output image
epng::png* setupOutput(int w, int h);

// Returns my favorite color
epng::rgba_pixel* myFavoriteColor(int intensity);

int main()
{
    // Load in.png
    epng::png* original=new epng::png;

    original->load("in.png");
    int width = original->width();
    int height = original->height();

    // Create out.png
    epng::png* output=setupOutput(width, height);
    

    // Loud our favorite color to color the outline
    epng::rgba_pixel* myPixel = myFavoriteColor(192);

    // Go over the whole image, and if a pixel differs from that to its upper
    // left, color it my favorite color in the output
    for (int y = 1; y < height; y++)
    {
        for (int x = 1; x < width; x++)
        {
            // Calculate the pixel difference
            epng::rgba_pixel* prev = (*original)(x - 1, y - 1);
            epng::rgba_pixel* curr = (*original)(x, y);
            int diff = abs(curr->red - prev->red) +
                       abs(curr->green - prev->green) +
                       abs(curr->blue - prev->blue);

            // If the pixel is an edge pixel,
            // color the output pixel with my favorite color
            epng::rgba_pixel* currOutPixel = (*output)(x, y);
            if (diff > 100)
                *currOutPixel = *myPixel;
        }
    }

    // Save the output file
    output->save("out.png");

    // Clean up memory
    delete myPixel;
    delete output;
    delete original;
    return 0;
}

// sets up the output image
epng::png* setupOutput(int w, int h)
{
    epng::png* image = new epng::png(w, h);
    return image;
}

// Returns my favorite color
epng::rgba_pixel* myFavoriteColor(int intensity)
{
    epng::rgba_pixel* color=new epng::rgba_pixel;
    (*color).red = 0;
    (*color).green = intensity / 2;
    (*color).blue = intensity;
    return color;
}

#include <iostream>

#include "wlt/wlt.h"

int main( int argc, char** argv )
{
	float compressionQuality = 0.f;
	if ( argc != 2 )
	{
		return 0;
	}

	compressionQuality = atof( argv[ 1 ] );

	if ( compressionQuality <= 0.f
		|| compressionQuality >= 1.f )
	{
		return 0;
	}

	wlt::Image< float > img;
	wlt::readImage( img, "apples.ppm" );
	wlt::daub_nonStandardDecomposition( img );
	wlt::compress( img, compressionQuality );
	wlt::daub_nonStandardComposition( img );

	// std::cout << "Total Energy: " << img.energy << std::endl;
	// std::cout << "Quality:      " << compressionQuality << std::endl;
	// std::cout << "threshold:    " << threshold << std::endl;

	wlt::writeImage( img, "out_img.ppm" );
	wlt::releaseImage( img );

	return 0;
}
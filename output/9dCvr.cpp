// error:	OK
// langId:	44
// langName:	C++11
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-07-26 23:15:05
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
#ifndef LABEL_H
#define LABEL_H

#include <array>
#include <string>
#include <vector>
 
class Labels
{

private:
 
	struct ImageInfo
	{
		int xOffset;	/* pixel count offset before next digit */
		std::string fileName;
		//cairo_surface_t *image;
		char *image;	
	};

	//std::array<ImageInfo, 14> NumberImages;
    std::vector<ImageInfo> NumberImages;

public:
    Labels();
    ~Labels();
 };
 
#endif//
#include <cairo/cairo.h> 
#include <iostream>
#include <array> 


// Constructor
Labels::Labels() : 
    NumberImages{	{
		{ 8, "images/0.png", NULL },
		{ 10, "images/1.png", NULL },
		{ 10, "images/2.png", NULL },
		{ 10, "images/3.png", NULL },
		{ 10, "images/4.png", NULL },
		{ 10, "images/5.png", NULL },
		{ 10, "images/6.png", NULL },
		{ 10, "images/7.png", NULL },
		{ 10, "images/8.png", NULL },
		{ 10, "images/9.png", NULL },
		{ 7, "images/$.png", NULL },
		{ 10, "images/euro.png", NULL },
		{ 7, "images/pound.png", NULL },
		{ 7, "images/yen.png", NULL }
	}}
    { 
	

	std::cout << "NumberImages[0].fileName = " << NumberImages[0].fileName << std::endl;
	// InitImages

    std::cout << "Labels Created" << std::endl;
}


Labels::~Labels() 
{
	// call DestroyNumberImages
    std::cout << "Labels Destroyed" << std::endl;
}


int main()
{
	Labels label;
	
	std::cout << "Exit main\n";

	return( 0 );
}

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.cpp:30:26: fatal error: cairo/cairo.h: No such file or directory
compilation terminated.

#endif

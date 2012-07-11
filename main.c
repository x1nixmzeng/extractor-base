/*
	Generic file extractor base
	x1nixmzeng
	v0.01
*/
#include <windows.h>
#include <stdio.h>

#include "binaryhelper.h"

typedef unsigned char uint8;
typedef char int8;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned int uint32;
typedef int int32;

/*
struct YOUR_HEADER
{
	// .. todo
};

struct YOUR_ENTRY_STRUCT
{
	// .. todo
};
*/

typedef int (*entryCallback)( HANDLE/*, struct YOUR_ENTRY_STRUCT **/ );

int processFile( HANDLE fhand, entryCallback itemFunc )
{
	/*
	struct YOUR_HEADER header;
	int i;
	
	if( !( fcReadFile( fhand, (char *)&header, sizeof( header ) ) ) )
	{
		printf("processFile() failed to read from file\n");
		return 0;
	}
	
	i = 0;
	
	while( i < header.items )
	{
		struct YOUR_ENTRY_STRUCT entry;
		
		// attempt to read the entry structure
		if( !( fcReadFile( fhand, (char *)&entry, sizeof( entry ) ) ) )
		{
			printf("processFile() failed to read from file\n");
			return 0;
		}
		
		//
		// Try calling item processing function
		//
		if( *itemFunc )
			if( !( itemFunc( fhand, &entry ) == 1 ) )
				return 0;
		
		++i;
	}
	*/
	return 1;
}

int main( int argc, char **argv )
{
	char *strFilename;
	entryCallback func;
	
	func = 0;
	strFilename = 0;
	
	//
	// Print extractor detail
	//
	printf("TITLE\n");
	printf("XYZ tool by AUTHOR (EXAMPLE.COM)\n\n");
	
	#define usage_switch(argCount,argOption) \
		( ( argc == argCount ) && ( *argv[1] == argOption ) )
	
	//
	// Check function arguments
	//
	/*
	if( usage_switch( 3, 'i' ) )
	{
		strFilename = argv[2];
		func = &printInfo;
		
		printf("File info:\n");
	}
	else
	*/
	
	//
	// Open file and run specified function
	//
	
	if( func && strFilename )
	{
		HANDLE fhnd;
		
		fhnd = fcOpenRead( strFilename );
		
		if( fhnd )
		{
			if( !( processFile( fhnd, func ) == 1 ) )
				printf("main() did not return successfully\n");
			
			fcCloseFile( fhnd );
		}
		else
		{
			printf("main() failed to open file\n");
		}
	}
	else
	{
		//
		// Print usage detail
		//
		
		printf("Usage:\n");
		// .. todo
	}
	
	return 0;
}

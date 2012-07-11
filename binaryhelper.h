/*
	Generic file extractor base
	x1nixmzeng
	v0.01
*/

#ifndef BINARYHELPER_H
#define BINARYHELPER_H

//
// Open file for shared reading
//
HANDLE fcOpenRead( const char *strFilename )
{
	return(
		CreateFileA(
			strFilename,
			GENERIC_READ,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL
		)
	);
}

//
// Open file for writing (use force=1 to replace file)
//
HANDLE fcOpenWrite( const char *strFilename, int force )
{
	return(
		CreateFileA(
			strFilename,
			GENERIC_WRITE,
			FILE_SHARE_READ,
			NULL,
			force ? CREATE_ALWAYS : CREATE_NEW,
			FILE_ATTRIBUTE_NORMAL,
			NULL
		)
	);
}

//
// Seek to absolute offset
//
void fcSeek( HANDLE fcFile, DWORD absOffset )
{
	SetFilePointer( fcFile, absOffset, NULL, FILE_BEGIN );
}

//
// Seek to relative offset
//
void fcSkip( HANDLE fcFile, DWORD relOffset )
{
	SetFilePointer( fcFile, relOffset, NULL, FILE_CURRENT );
}

//
// Get the current position
//
DWORD fcGetOffset( HANDLE fcFile )
{
	return(
		SetFilePointer(
			fcFile,
			0,
			NULL,
			FILE_CURRENT
		)
	);
}

//
// Get the file size
//
DWORD fcGetSize( HANDLE fcFile )
{
	return(
		GetFileSize( fcFile, NULL )
	);
}

//
// Close a file handle
//
void fcCloseFile( HANDLE fcFile )
{
	CloseHandle( fcFile );
}

//
// Read from file into buffer
//
int fcReadFile( HANDLE fcFile, char *outBuf, DWORD fcSize )
{
	DWORD bRead;
	return(
		ReadFile(
			fcFile,
			outBuf,
			fcSize,
			&bRead,
			NULL
		)
	);
}

//
// Write to file from buffer
//
int fcWriteFile( HANDLE fcFile, char *inBuf, DWORD fcSize )
{
	DWORD bWritten;
	
	WriteFile(
		fcFile,
		inBuf,
		fcSize,
		&bWritten,
		NULL
	);
	
	return( bWritten == fcSize );
}

//
// Buffer allocation
//
char *fcAllocate( DWORD fcSize )
{
	return(
		(char *)malloc( fcSize )
	);
}

//
// Create directory
//
int fcCreateDir( char *str )
{
	return(
		CreateDirectory(
			str,
			NULL
		)
	);
}

#endif

#pragma once

//----------------GB----------------

struct Vector3
{
	float x;
	float y;
	float z;
};

//---------------PDB----------------

struct String
{
	char* ptr;
};


struct FastString : String
{
};

struct HSound
{
	int handle;
};

struct CDialogDatabaseEntry
{
	FastString tag;
	FastString text;
	HSound hSound;
};
//---------------PDB-END------------
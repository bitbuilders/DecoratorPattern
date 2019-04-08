#include "pch.h"
#include <iostream>
#include <fstream>
#include "WriterComponent.h"
#include "SignatureWriter.h"

int main()
{
	Writer* writer = new SignatureWriter(new WriterComponent());
	writer->Write("../../bob.txt", "hi");

	return 0;
}
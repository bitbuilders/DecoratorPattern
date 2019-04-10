#include "pch.h"

#include <iostream>
#include <fstream>

#include "WriterComponent.h"
#include "WriteSignature.h"
#include "WriteShiftUp.h"
#include "ReaderComponent.h"
#include "ReadShiftDown.h"
#include "ReadLineEndings.h"

/*
	English Answer to Question No. 4:
		For my application if I wrap decorator 1 (the signature) inside decorator 2 (the shift up)
		then the shifting will happen BEFORE the signature is stamped. So I would get an encoded
		message with my un-touched signature. If decorator 2 is inside decorator 1, then the
		signature will get encoded along with the contents of the file. This occurs because
		I needed to have each decorator do their action before their subsequent decorators.
		If I didn't do this, then the file would have already been written to, and manipulating
		the strings would have no effect.
*/

namespace 
{
	std::string file = "../../bob.txt";
}

int GetLineEndings(const std::string& content, const char& ending);
std::string CalculateLineEndings(const std::string& content);

int main()
{
	// Write to a file using decorators

	Writer* writer = new WriteShiftUp(new WriteSignature(new WriterComponent()));
		  //writer = new WriteSignature(new WriteShiftUp((new WriterComponent())));
	writer->Write(file, "hi\rHow's it goin dude?\rThat's Nice");
	writer->Destroy();
	delete writer;
	
	// Read from file for debugging later

	ReaderComponent fileReader;
	std::string originalString = fileReader.Read(file);

	// Read from file using decorators

	Reader* reader = new ReadLineEndings(new ReadShiftDown(new ReaderComponent()));
	std::string text = reader->Read(file);
	std::cout << "Reading File:\n<><><><><><><><><><>\n" << text << "\n<><><><><><><><><><>\n\n";
	reader->Destroy();
	delete reader;

	// Prove that line endings are properly converted

	std::cout << "Original File:" << CalculateLineEndings(originalString);
	std::cout << "Windows -> Unix File:" << CalculateLineEndings(text);

	return 0;
}

int GetLineEndings(const std::string& content, const char& ending)
{
	int count = 0;
	for (int i = 0; i < content.size(); i++)
	{
		if (content[i] == ending)
		{
			count++;
		}
	}

	return count;
}

std::string CalculateLineEndings(const std::string& content) 
{
	int carriageReturns = GetLineEndings(content, '\r');
	int newLines = GetLineEndings(content, '\n');

	std::string message = "\n---------------\nCarriage Returns: " + std::to_string(carriageReturns)
		+ "\nNew Lines: " + std::to_string(newLines) + "\n---------------\n";

	return message;
}
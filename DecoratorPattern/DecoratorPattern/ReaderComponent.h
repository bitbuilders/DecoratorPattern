#include "Reader.h"

class ReaderComponent : public Reader
{
public:
	ReaderComponent() { }

	std::string Read(const std::string& file) const;
	void Destroy() { }
};


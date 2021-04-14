#pragma once

#include <string>
#include <vector>

struct utleiested {
	std::string navn;
	int postnr;
};

class Kunder {
private:
	std::vector <kunde*> gkunder;
public:
	Kunder();
	~Kunder();
	void nyKunde(const std::string& nvn);
	void display() const;
	void lesFraFil();
	void handling();
};

// Exercise 2A

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string find_field(const string& xml, string tag_name);

int main() {
	string page, line, location, temperature;
	ifstream inputFile("weather.xml");

	while (getline(inputFile, line)) {
		page.append(line);
		line.erase();
	}

	if (!inputFile.is_open()) {
		cout << "ERORR " << endl;
	}

	else {
		location = find_field(page, "location");
		temperature = find_field(page, "temp_c");

		cout << "Location: " << location << endl;
		cout << "Temperature: " << temperature << endl;
	}
	return 0;
}

string find_field(const string& xml, string tag_name) {
// add angle brackets to both tags and also slash to end tag
// then search for tags 
// if both are found then return the substring between the tags
	vector<string> res; 
	string result;
	auto postion = 0, start = 0; 

	while (true) {
		// find position of tag_name(New York), in a html page. If found return first possition 
		start = xml.find("<" + tag_name + ">", postion);
		//if not found return npos
		if (start == string::npos) {
			break;
		}
		//while != end
		start = xml.find(">", start); 
		start++;

		//result
		postion = xml.find("</" + tag_name + ">", start);

		if (postion == string::npos) {
			break;
		}

		//add to vector
		res.push_back(xml.substr(start, postion - start));
	}

	//vector to string
	result = res[0]; 


	//Error if not found
	if (result.empty()) { 
		return "not found"; 
	}
	//if true return string result to main func
	else {
		return result; 
	}	
}

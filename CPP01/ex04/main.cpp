#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(const std::string &text, const std::string &s1, const std::string &s2)
{
    //Handle edge cases
    if (s1.empty() || text.empty() || s1 == s2)
        return text;
    //Pre-allocate memory for result to avoid multiple reallocations
    std::string result;
    result.reserve(text.length());
    size_t pos = 0;
    size_t prev = 0;
    //Searching for the string s1 in text starting from position prev.
    while ((pos = text.find(s1, prev)) != std::string::npos)
    {
        //Append text up to the match
        result.append(text, prev, pos - prev);                                       
        //Append replacement
        result.append(s2);
        //Move past this occurrence
        prev = pos + s1.length();
    }
    result.append(text, prev, std::string::npos);
    return result;
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return (1); 
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return (1);
	}
	//Opening input file
	std::ifstream inFile(filename);
	
	//Trying to open a file that doesn’t exist.
	//Trying to read from a file that couldn’t be opened.
	//Trying to open a directory as if it were a file.
	
	if (inFile.fail())
	{
		std::cerr << "Error: Cannot open input file '" << filename << "'" << std::endl;
		return (1);
	}
	//Reading file line by line
	std::string content;
	std::string line;
	while (std::getline(inFile, line))
	{
		content += line;
		if (!inFile.eof())
		{
			content += '\n';
		}
	}
	inFile.close();
	
	std::string modifiedContent = replaceAll(content, s1, s2);
	//Creating output filename
	std::string outFilename = filename + ".replace";
	std::ofstream outFile(outFilename);
	if (!outFile.is_open())
	{
		std::cerr << "Error: Cannot create output file '" << outFilename << "'" << std::endl;
		return (1);
	}

	outFile << modifiedContent;
	outFile.close();
	
	return (0);
}


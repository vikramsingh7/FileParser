
![befunky design](https://user-images.githubusercontent.com/26244906/32987076-575f1548-cc95-11e7-8df2-91b52d0fad58.jpg)

# Overview
This application is written in C++. The idea is to convert the file format from one to any other file format with easy steps. But this app is specifically designed to 
convert CSV (Comma seperated value) file into TSV (Tab seperated value) file. It takes the name of Input file and output file as a commandline 
aguments.

- Feel free to download the code and incorporate any kind of functionality according to your requirement.

# Functionalities
- There are two main functions used in the c++ code 
- trim(): It is used to check if any word has any empty space before or after the quotes. It it does then this function removes that empty
space from it.
- CSV_Parser_(): This function reads each line and extracts every word from it and stores it into a vector. It acceps the file line and a delimeter
as it's parameters In this case it is a coma. It returns a vector at end.
- It also check and removes if there is any newline between any word.

# Setup

- git clone https://github.com/vikramsingh7/FileParser.git
- g++ parser.cpp -o converted.exe
- coverted.exe input.csv ouput.tsv

- You need to include libstdc++6.dll with your executable file








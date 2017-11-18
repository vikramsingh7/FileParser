#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
 
using namespace std;
 
vector<string> csv_read_row(istream &in, char delimiter);
string trim(string word);

 

int main(int argc, char *argv[])
{
     string arg1 ;
     string arg2 ;
   	
   	if(argc == 3){
	 arg1 = argv[1];
	 arg2 = argv[2];
}
else {
	cout << "Incorrect number of arguments" <<endl;
}
  
 
  
	//Input file stream
    ifstream in(arg1);
    //Output file stream
    ofstream output(arg2);
    
    
    if (in.fail()) return (cout << "File not found" << endl) && 0;
    while(in.good())
    {
        vector<string> row = csv_read_row(in, ',');
        for(int i=0, leng=row.size(); i<leng; i++){
      //Trimming of function
        output << trim(row[i]) << "\t";
	  }
       output << "\n";
    }
    in.close();
    return 0;
}

 
vector<string> csv_read_row(istream &in, char delimiter)
{

    stringstream ss;
    stringstream wedontneed;
    bool inquotes = false;
    vector<string> row;//relying on RVO
    while(in.good())
    {
        char c = in.get();
        if (!inquotes && c=='"') //beginquotechar
        {
            inquotes=true;
        } 
        else if (inquotes && c=='"') //quotechar
        {
            if ( in.peek() == '"')//2 consecutive quotes resolve to 1
            {
                ss << (char)in.get();
            }
            else //endquotechar
            {
            	// end of word and the c is "
                inquotes=false;  
            }
        }
        else if (!inquotes && c==delimiter) //end of field
        {
            row.push_back( ss.str() );
            ss.str(""); // empty the box
        }
        else if (!inquotes &&  c=='\n' ) // if it is the end of line 
        {
            if(in.peek()=='\n') { in.get(); } // if the other char is also end of line
            
            //if the other char is not end of line 
            else{
            row.push_back( ss.str() );
           // check(row);
            return row;
        }
        }
        else
        {
        	if(c == '\n'){
               in.get();  // removes the newline
        	}
        	else{
            ss << c;
        }
        }
    }
}

//This function removes any kind empty space before and after the first and last quotes respectively
//It returns a trimmed word
//It won't execute if the entered word don't require any trimming


string trim(string word){
int lastQ = 0;
int firstQ = 0;
for(int i=0; i<word.size(); i++){
if(word[0] ==' '){
firstQ = word.find_first_of("\"");
word.erase(0,firstQ);
}
if(word[word.size()] ==' '){
lastQ = word.find_last_of("\"");
word.erase(lastQ+1,word.size());
}
}	
	return word;
}

#include <boost/filesystem.hpp>
#include <boost/filesystem/directory.hpp>
#include <boost/range/iterator_range.hpp>
#include <iostream>
#include "fileCopy.h"

using namespace boost::filesystem;
using std::cout, std::cin, std::vector;

Parser::DemoOperator dop;
Parser::demoToJSON dj;
Parser::JSON_FORMATTER JsF;
Parser::JSONtoCharts JtC;

const path demoPath = "./demos/";
const vector<std::string> extensionList = {"replay.Gbx", "dem", "dem2", "lsp", "SC2Replay"};

int main(int argc, char* argv[1]){
        path Path;
  
        cout<<"Verifying the existence of the demo folder...";
        if(!exists(demoPath)){
                cout<<"\nThe demo folder does not exist... creating now !";
                create_directory(demoPath);
        }

        cout<<"\n\nEnter a path to recursively search on : ";
        cin>>Path;

        while(!(exists(Path))){
                cout<<"\nThis path does not exist, please enter an existing path : ";
                cin>>Path;
        }
}

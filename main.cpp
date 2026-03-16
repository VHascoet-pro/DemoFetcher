#include <boost/filesystem.hpp>

#include <iostream>
#include "fileCopy.h"

using std::cout, std::cin;

DemoParsers::GAME_MAP gm;
DemoParsers::GAME_PATHS gp;

DemoParsers::DemoOperator dop;
DemoParsers::demoToJSON dj;
DemoParsers::JSON_FORMATTER JsF;
DemoParsers::JSONtoCharts JtC;

int main(int argc, char* argv[1]){
        boost::filesystem::path Path;
  
        cout<<"Verifying the existence of the demo folder...";
        if(!boost::filesystem::exists(gp.timeFolder)){
                cout<<"\nThe demo folder does not exist... creating now !";
                boost::filesystem::create_directory(gp.timeFolder);
        }

        cout<<"\n\nEnter a path to recursively search on : ";
        cin>>Path;

        while(!(boost::filesystem::exists(Path))){
                cout<<"\nThis path does not exist, please enter an existing path : ";
                cin>>Path;
        }
        dop.FileCopy(Path);
}

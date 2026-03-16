#include <boost/filesystem.hpp>

#include <boost/filesystem/file_status.hpp>
#include <boost/filesystem/operations.hpp>
#include <iostream>
#include "fileCopy.h"

DemoParsers::GAME_MAP gm;
DemoParsers::GAME_PATHS gp;

DemoParsers::DemoOperator dop;
DemoParsers::JSON_FORMATTER JsF;
DemoParsers::JSONtoCharts JtC;

int main(int argc, char* argv[1]){
        boost::filesystem::path inputPath;
  
        std::cout<<"Verifying the existence of the folders...";
        if(!boost::filesystem::exists(gp.timeFolder)){
                std::cout<<"\nThe time folder does not exist... creating now !";
                boost::filesystem::create_directory(gp.timeFolder);
        } else if(!boost::filesystem::exists(gp.jsonFolder)){
                std::cout<<"\nThe JSON folder does not exist... creating now !";
                boost::filesystem::create_directory(gp.jsonFolder);
        } else if(!boost::filesystem::exists(gp.chartsFolder)){
                std::cout<<"\nThe Charts folder does not exist... creating now !";
                boost::filesystem::create_directory(gp.chartsFolder);
        }

        std::cout<<"\n\nEnter a path to recursively search on : ";
        std::cin>>inputPath;

        while(!(boost::filesystem::exists(inputPath))){
                std::cout<<"\nThis path does not exist, please enter an existing path : ";
                std::cin>>inputPath;
        }
        dop.FileCopy(inputPath);
        JsF.fileAnalyser(gp.timeFolder);
}

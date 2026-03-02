#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>
#include <iostream>
using namespace boost::filesystem;
using std::cout, std::cin;

void fileChecker(path filePath, path demoPath){
  bool valid = false;
  std::vector<std::string> extensionList = {"replay.Gbx", "dem", "dem2", "lsp", "SC2Replay"};
  int* i = new int;
  while(valid == false){
    for(*i = 0;*i < extensionList.size(); i++){
      if(filePath.extension() == extensionList[*i]){
        copy_file(filePath, demoPath);
        valid = true;
      }
    }
  }
  delete i;
}

int main(){
  // std::vector<std::string> extensionList = {"replay.Gbx", "dem", "dem2", "lsp", "SC2Replay"};
 
  path Path;
  const path demoPath = "./demos/";

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
  fileChecker(Path, demoPath);
}

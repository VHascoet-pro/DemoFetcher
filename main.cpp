#include <boost/filesystem.hpp>
#include <boost/filesystem/directory.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/range/iterator_range_core.hpp>
#include <iostream>

using namespace boost::filesystem;
using std::cout, std::cin, std::vector;
const path demoPath = "./demos/";

bool fileChecker(path filePath, path demoPath){
  bool valid, found= false;
  vector<std::string> extensionList = {"replay.Gbx", "dem", "dem2", "lsp", "SC2Replay"};
  while(valid == false){
    for(int i; i < extensionList.size(); i++){
      if(filePath.extension() == extensionList[i]){
        copy_file(filePath, demoPath);
        valid = true;
        found = true;
      }
    }
  }
  return found;
}

void recursiveCheck(path filePath){
  for(auto& entry : boost::make_iterator_range(recursive_directory_iterator(filePath), {})){
    if(is_regular_file(entry))
      fileChecker(entry.path(), demoPath);
  }
}

int main(){
  // std::vector<std::string> extensionList = {"replay.Gbx", "dem", "dem2", "lsp", "SC2Replay"};
 
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
  if(fileChecker(Path, demoPath) == 0){
    recursiveCheck(Path);
  }
}

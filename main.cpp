#include <boost/filesystem.hpp>
#include <iostream>
using namespace boost::filesystem; 
bool FileChecker(path inputPath, path demoPath, const std::string exList[]){
  int i = 0;
  bool validFile;
  while(inputPath.extension() != exList[i] && (i>=0 && i <= 3)){
    i++;
    validFile = false;
    if(inputPath.extension() == exList[i]){
      validFile = true;
    }
  }

  if(validFile == true){
    copy_file(inputPath, demoPath);
    return validFile;
  } else return validFile;
}

void RecursiveCheck(path inputPath, const std::string exList[]){
  directory_iterator dir;
  for(recursive_directory_iterator end; dir != end; ++dir){} // Prototype, I don't know how to continue this shit'
}

int main(int argc, char* argv[1]){
  const std::string extensionList[] = {".replay.Gbx", ".dem", ".lsp", ".SC2Replay"};

  path Path;
  path demoPath = "./demos/";

  std::cout<<"Verifying the existence of the demo folder...";
  if(!exists(demoPath)){
    create_directory(demoPath);
  }

  std::cout<<"Enter a path to recursively search on : ";
  std::cin>>Path;
  while(!(exists(Path))){
    std::cout<<"This path does not exist, please enter an existing path : ";
    std::cin>>Path;
  }
  if(Path.has_extension()){
    FileChecker(Path, demoPath, extensionList);
  } else RecursiveCheck(Path, extensionList);
}

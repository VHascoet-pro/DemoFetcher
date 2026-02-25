#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/directory.hpp>
#include <boost/filesystem/path.hpp>
#include <iostream>

bool FileChecker(boost::filesystem::path inputPath, boost::filesystem::path demoPath, const std::string exList[]){
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
    boost::filesystem::copy_file(inputPath, demoPath);
    return validFile;
  } else return validFile;
}

void RecursiveCheck(boost::filesystem::path inputPath, const std::string exList[]){
  for(boost::filesystem::recursive_directory_iterator end; inputPath != end; ++inputPath){} // Prototype, I don't know how to continue this shit'
}

int main(int argc, char* argv[1]){
  const std::string extensionList[] = {".replay.Gbx", ".dem", ".lsp", ".SC2Replay"};

  boost::filesystem::path Path;
  boost::filesystem::path demoPath = "./demos/";

  std::cout<<"Verifying the existence of the demo folder...";
  if(!boost::filesystem::exists(demoPath)){
    boost::filesystem::create_directory(demoPath);
  }

  std::cout<<"Enter a path to recursively search on : ";
  std::cin>>Path;
  while(!(boost::filesystem::exists(Path))){
    std::cout<<"This path does not exist, please enter an existing path : ";
    std::cin>>Path;
  }
  if(Path.has_extension()){
    FileChecker(Path, demoPath, extensionList);
  } else RecursiveCheck(Path, extensionList);
}

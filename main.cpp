#include <boost/filesystem.hpp>
#include <boost/filesystem/directory.hpp>
#include <iostream>
using namespace boost::filesystem;

void recursiveCheck(std::string Path){
  path verifiedPath = Path;
  for(path::iterator it = verifiedPath.begin();it != verifiedPath.end();it++){
    if(*it == is_directory(verifiedPath)){
      verifiedPath += *it;
    }
  }
}

bool fileVerifier(){
  bool isVerified;
  return isVerified;
}

bool pathVerifier(std::string inPath){
  while(exists(inPath)){
    if(is_directory(inPath)){
      return 1;
    }
  }
  return 0;
}

int main(int argc, char* argv[1]){
  std::string rootPath;
  bool verifiedPATH;
  // On contrôle si le chemin entré est un string ou non
  std::cout<<"Enter a root path (it will search recursively through this path, it can be long… veeery long) : ";
  while(!(std::cin>>rootPath)){
    std::cout<<"\nError, this is not a char array, please enter a correct path : ";
    std::cin>>rootPath;
  }

  // On vérifie l'existence du chemin et SI le chemin est un dossier (voir la fonction pathVerifier)
  while(pathVerifier(rootPath) == false){
    std::cout<<"\nError, this is not a correct path, please enter a correct path : ";
    std::cin>>rootPath;
  }

  // Si le chemin est un dossier, on commence la recherche récursive
  if(pathVerifier(rootPath) == true){
    recursiveCheck(rootPath);
  }
}

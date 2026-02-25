#include <boost/filesystem/directory.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/system/detail/error_category.hpp>
#include <iostream>

int main(int argc, char* argv[1]){
  boost::filesystem::path inpPath;
  std::cout<<"Enter a path to recursively search on : ";
  std::cin>>inpPath;
  if(boost::filesystem::exists(inpPath) && boost::filesystem::is_directory(inpPath)){
    for(boost::filesystem::recursive_directory_iterator end, dir("./"); dir != end; ++dir){}
  } else while(!(boost::filesystem::exists(inpPath)) || !(boost::filesystem::is_directory(inpPath))){}
}
 // test for Sublime Merge

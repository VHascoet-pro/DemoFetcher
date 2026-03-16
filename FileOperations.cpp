#include "fileCopy.h"
#include <boost/filesystem/directory.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>

DemoParsers::DemoOperator dop;
DemoParsers::GAME_MAP gm;
DemoParsers::GAME_PATHS gp;

//! Cette fonction va vérifier l'extension des fichiers pour en déterminer leur type
//! elle va ensuite copier ce-dit fichier dans le dossier ./times créé (ou non) dans le
//! main
//! @function FileCopy La fonction de vérification de fichiers
//  @param initPath chemin initial du chemin entré par l'utilisateur
//! @param filePath chemin du fichier exporté depuis la fonction recursiveCheck
//! @param demoPath chemin du dossier de démos
void DemoParsers::DemoOperator::FileCopy(boost::filesystem::path initPath){
        // Creation des dossiers de démos si les dossiers initiaux ne sont pas trouvés
        while(boost::filesystem::exists(gp.timeFolder)){
                if(!boost::filesystem::exists(gp.QuakeFolder) || !boost::filesystem::exists(gp.Quake2Folder) || !boost::filesystem::exists(gp.DoomFolder)){
                        boost::filesystem::create_directory(gp.QuakeFolder);
                        boost::filesystem::create_directory(gp.Quake2Folder);
                        boost::filesystem::create_directory(gp.DoomFolder);
                }
        }

        // Initialisation de la recherche récursive
        boost::filesystem::recursive_directory_iterator it(initPath),end;
        for(; it != end; ++it){
                for(int i; i<gm.exList.size(); ++i){
                        while(it->path().extension() == gm.exList[i]){
                                // Copie des fichiers selon l'extension de ceux-ci
                                if(it->path().extension() == ".dem") boost::filesystem::copy_file(it->path(), gp.QuakeFolder);
                                else if(it->path().extension() == ".dem2") boost::filesystem::copy_file(it->path(), gp.Quake2Folder);
                                else boost::filesystem::copy_file(it->path(), gp.DoomFolder);
                        }
                }
        }
}

#include "fileCopy.h"
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <stdexcept>
#include <vector>

DemoParsers::GAME_PATHS gp;

/**
  Intégration du fichier binaire intégralement en buffer
*/

struct BitStream{
        const uint8_t data;
        size_t size;
        size_t pos = 0;
        
        uint8_t ReadByte() {check(1) }
};

struct QUAKE_BLOCKS{
        float viewangles[3];
        int32_t msg_length;
        std::vector<uint32_t> msg_data;
};

/**
    Lecture du fichier .dem en entier
*/

std::vector<QUAKE_BLOCKS> LoadDem(boost::filesystem::path q1DemoPath){
        std::ifstream file(q1DemoPath, std::ios::binary);
        if(!file) throw std::runtime_error("Cannot open the file");

        // lire la piste CD (ASCII + '\n')
        std::string cdtrack;
        char c;
        while(file.get(c) && c != '\n'){
          cdtrack += c;
        }

        
}

struct MAP_RESULT{
        std::string MapName;
        float finishTime;
        bool completed;
};

std::vector<MAP_RESULT> ExtractMapTimes(boost::filesystem::path q1DemoPath){
        auto blocks = LoadDem(q1DemoPath);
}
/**
 On à pas besoin de beaucoup de trames afin d'analyser les trames, analyser toutes les trames
 serait trop long et demandera trop de mémoire, on doit SKIPPER des trames.
*/

void SkipSVC(){
        
}

/**
 Cette fonction permet de parser les données du fichier de démo et en sortir le niveau + temps
 pour pouvoir l'inclure dans le fichier JSON nécessaire
 @param q1DemoPath Chemin absolu du fichier de démo envoyé depuis la recherche récursive de la
                   fonction FileCopy
 */

void DemoParsers::DemoOperator::Quake1DemoToJson(boost::filesystem::path q1DemoPath){}

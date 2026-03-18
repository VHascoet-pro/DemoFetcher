#include "fileCopy.h"
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include <cstdint>
#include <fstream>
#include <stdexcept>
#include <vector>

DemoParsers::GAME_PATHS gp;

/**
 Ces deux structures sont pour avoir :
 1) Les blocks à ne PAS skipper triés par Identification
 2) Les types des blocks suivant l'identification (EX: pour SVC_TIME : 27.13s, on à 0x07 F5D8D941 > trié en Little-endian : 41D9D8F5 > calcul suivant IEEE :
                                                                       1x 2^131-127 x (1+ 5878261 / 2^23) = 27.21189308s)
*/
struct QUAKE_BLOCKS{
        float viewangles[3];
        int32_t msg_length;
        std::vector<uint32_t> msg_data;
};

std::vector<QUAKE_BLOCKS> LoadDem(boost::filesystem::path q1DemoPath){
        std::ifstream file(q1DemoPath, std::ios::binary);
        if(!file) throw std::runtime_error("Cannot open the file");

        // lire la piste CD (ASCII + '\n')
        std::string cdtrack;
        char c;
        while(file.get(c) && c != '\n') cdtrack += c;
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

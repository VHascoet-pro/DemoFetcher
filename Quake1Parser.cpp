#include "fileCopy.h"
#include <boost/filesystem.hpp>
#include <fstream>

DemoParsers::GAME_PATHS gp;

/**
 Ces deux structures sont pour avoir :
 1) Les blocks à ne PAS skipper triés par Identification
 2) Les types des blocks suivant l'identification (EX: pour SVC_TIME : 27.13s, on à 0x07 F5D8D941 > trié en Little-endian : 41D9D8F5 > calcul suivant IEEE :
                                                                       1x 2^131-127 x (1+ 5878261 / 2^23) = 27.21189308s)
*/
struct QUAKE_BLOCKS{
        int SVC_TIME = 0x07;
        int SVC_PLAYERNAME = 0x0D;
        int SVC_INTERMISSION = 0x1E;
        int SVC_DISCONNECTMESSAGE = 0x02;
};

struct QUAKE_BLOCKTYPES{
        long SVC_TIMESIZE;
        char SVC_PLAYER;
        char SVC_IntMessage;
        bool DISCONNECTED;
};

/**
 On à pas besoin de beaucoup de trames afin d'analyser les trames, analyser toutes les trames
 serait trop long et demandera trop de mémoire, on doit SKIPPER des trames.

 @param isSkipped Retourne l'état du Parseur (est bel et bien évité).
*/

bool BlockSkip(){
        bool isSkipped = false;
        return isSkipped;
}

/**
 Cette fonction permet de parser les données du fichier de démo et en sortir le niveau + temps
 pour pouvoir l'inclure dans le fichier JSON nécessaire
 @param q1DemoPath Chemin absolu du fichier de démo envoyé depuis la recherche récursive de la
                   fonction FileCopy
 
 @param QUAKE_BLOCKS Une structure me permettant d'y inclure les types de messages
                     renvoyés depuis le parseur

 @param SVC_MESSAGE Message contenant le temps (1 unité par tic de 10Hz) de la démo, le nom de
                    la map, joueur, angle de la caméra du joueur (x-pitch, y-roll, z-yaw) par
                    tic
 
 @param SVC_DISCONNECTMESSAGE permet un message contenant le temps final de la démo (UTILE)
*/

void DemoParsers::DemoOperator::Quake1DemoToJson(boost::filesystem::path q1DemoPath){
        std::ifstream LocalDemo(q1DemoPath, std::ios_base::in | std::ios_base::binary);
        
}

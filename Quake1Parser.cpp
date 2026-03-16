#include "fileCopy.h"
#include <boost/filesystem.hpp>

DemoParsers::GAME_PATHS gp;

struct Quake1Demo_MAP{
        // Inclus tous les messages réseau envoyés dans le fichier .dem
        int SVC_PROTOCOL = 15;
        std::string SVC_MESSAGE;
        bool SVC_DISCONNECTMESSAGE;
};
/**
 Cette fonction permet de parser les données du fichier de démo et en sortir le niveau + temps
 pour pouvoir l'inclure dans le fichier JSON nécessaire
 @param q1DemoPath Chemin absolu du fichier de démo envoyé depuis la recherche récursive de la
                   fonction FileCopy
 
 @param Quake1Demo_MAP Une structure me permettant d'y inclure les types de messages
                       rencoyés depuis le parseur
 
 @param SVC_PROTOCOL Protocole réseau exploité dans le client Quake
 
 @param SVC_MESSAGE Message contenant le temps (1 unité par tic de 10Hz) de la démo, le nom de
                    la map, joueur, angle de la caméra du joueur (x-pitch, y-roll, z-yaw) par
                    tic
 
 @param SVC_DISCONNECTMESSAGE permet un message contenant le temps final de la démo (UTILE)
*/

void DemoParsers::DemoOperator::Quake1DemoToJson(boost::filesystem::path q1DemoPath){}

# Demo Fetcher
Hey !
So this is a small (I think… I believe, please I hope I will not divague to a 20 cpp file, 4 header file) project.

This is a demo fetcher that will check recursively from a folder to archive (almost) every type of demo/replay files known in the gaming industry.

It will find and archive :
 - Dem files :
   - Quake        - In Progress (High Priority for this one)
   - Quake II     - In Progress
   - Half-Life    - Not Supported Yet
   - Half-Life²   - Not Supported Yet
 - lmp files :
   - Doom engine games/mods (like Hexen/Heretic)        - In Progress (The Features will be limited)
 - Trackmania replay files (Gamebox engine [Gbx files]) - Not Supported Yet
 - Starcraft II replay files (SC2Replay)                - Not Supported Yet

The main purpose of this program is to help with speedrunning tracking (I may summon a python file to create a graph based on the leveltables recorded in the files [Time related to tries per level]).

This is for my demos and will help for creating graphs for my own website I am building to help with the statistics and tracking of my training sessions and marathons but if you think it would be helpful for you, feel free to fork this project for your use (because it's obviously nor finished yet, you won't be able to fork this now).

This program may create a graph for EACH level for EACH demo (PNG + SVG).

#### French
Salut !
Donc ceci est un petit (j'espère, je vous en supplie ne me faites pas divaguer sur un projet à 20 fichiers cpp, 4 fichiers d'en-têtes) projet.

C'est un projet permettant de vérifier récursivement depuis un dossier, les fichiers de replays ou de démos sur le plus de types de démos possibles.

It va trouver et récupérer :
 - Fichiers Dem :
   - Quake      - En Cours (Haute Priorité pour celui-là)
   - Quake II   - En Cours
   - Half-Life  - Non Prévu
   - Half-Life² - Non Prévu
 - Fichiers lmp (Les fonctionnalitées seront très limitées pour celui-là car cela va demander de simuler le moteur complet) :
   - Doom        - En Cours
   - Doom II     - En Cours
   - Heretic     - Basse Priorité
   - Hexen       - Basse Priorité 
   - Autres mods - Non Prévu (Pour l'instant)
 - Replays Trackmania [Fichiers GBX] - Non supporté pour l'instant
 - Replays Starcraft II              - Non supporté pour l'instant

Le but principal de ce programme est de pouvoir tracker mes progrès en Speedrun (ou dans des parties en ligne)

Ceci est pour mes démos et servira à le linker à mon site afin que pouvoir tracker le tout en plus des démos à télécharger et à faire des statistiques.

Le programme pourra également créer un graphique [format Vectoriel SVG + Image PNG - utilisation de Cairo pour cela] afin de visuellement visualiser le tout.

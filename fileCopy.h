#pragma once

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <string>
#include <vector>

namespace DemoParsers{
        struct GAME_MAP{const std::vector<std::string> exList = {".dem", ".dem2", ".lsp"};};

        struct GAME_PATHS{
                const boost::filesystem::path timeFolder = boost::filesystem::current_path().append("./times");
                const boost::filesystem::path QuakeFolder = timeFolder / "/quake";
                const boost::filesystem::path Quake2Folder = timeFolder / "/quake2";
                const boost::filesystem::path DoomFolder = timeFolder / "/doom";
       };
        
        class DemoOperator{
                public:
                        void FileCopy(boost::filesystem::path initPath);        

                        void Quake1DemoToJson(boost::filesystem::path q1DemPath);
                        void Quake2DemoToJson(boost::filesystem::path q2DemPath);
                        void DoomDemoToJson(boost::filesystem::path doomDemPath);
        };

        class JSON_FORMATTER{
                public:
                        void fileAnalyser(boost::filesystem::path populatedPath);
                        void timeFormat();
        };

        class JSONtoCharts{
                public:
                        void JsonParser();
                        void ChartToSVG();
                        void ChartToPng();
        };
}

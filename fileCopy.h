#pragma once

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <string>
#include <vector>
namespace DemoParsers{
        struct GAME_MAP{
                const std::vector<std::string> exList = {".dem", ".dem2", ".lsp"};
        };

        struct GAME_PATHS{
                const boost::filesystem::path timeFolder = boost::filesystem::current_path().append("./times");
                const boost::filesystem::path QuakeFolder = timeFolder / "/quake";
                const boost::filesystem::path Quake2Folder = timeFolder / "/quake2";
                const boost::filesystem::path DoomFolder = timeFolder / "/doom";
       };
        
        class DemoOperator{
                public:
                        void FileCopy(boost::filesystem::path initPath);
                        void QuakeDemoParser();
                        void Quake2DemoParser();
                        void DoomDemoParser();
        };

        class demoToJSON{
                public:
                        void Quake1DemoToJson();
                        void Quake2DemoToJson();
                        void DoomDemoToJson();
        };

        class JSON_FORMATTER{
                public:
                        void timeFormat();
        };

        class JSONtoCharts{
                public:
                        void JsonParser();
                        void ChartToSVG();
                        void ChartToPng();
        };
}

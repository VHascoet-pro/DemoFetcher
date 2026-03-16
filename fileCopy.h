#pragma once

namespace Parser{
        void FileCopy();

        class DemoOperator{
                public:
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

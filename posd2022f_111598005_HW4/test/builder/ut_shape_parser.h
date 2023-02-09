#include "../../src/builder/shape_parser.h"
#include "../../src/circle.h"
#include <string>

class ShapeParserTest : public ::testing::Test{
    protected:
        std::string input;
        std::string input2;
        ShapeParser *parser,*parser2;

        void SetUp() override{
            input="Circle (Vector ((-4.28, 0.26), (-4.83, 0.73)))";
            input2="Circle (Vector ((0.0, 0.0), (1.0, 0.0)))";
            parser=new ShapeParser(input);
            parser2=new ShapeParser(input2);
            parser2->parse();
        }

        void TearDown() override{
            delete parser;
            delete parser2;
        }
};


TEST_F(ShapeParserTest, testParse) {
  parser->parse();
  ASSERT_EQ(input, (parser->getResult()[0])->info());
}

TEST_F(ShapeParserTest, testGetResult) {
  ASSERT_EQ(1.0, dynamic_cast<Circle *>(parser2->getResult()[0])->radius());
}



#include "../../src/builder/scanner.h"
#include <string>

class ScannerTest : public ::testing::Test{
    protected:
        std::string input;
        Scanner *scanner;

        void SetUp() override{
            input="Circle (Vector ((-4.28, 0.26), (-4.83, 0.73)))";
            scanner=new Scanner(input);
        }

        void TearDown() override{
            delete scanner;
        }
};


TEST_F(ScannerTest, testNext) {
    scanner->next();
    ASSERT_EQ("(", scanner->next());
}

TEST_F(ScannerTest, testNextDouble) {
    scanner->next();                        //Circle
    scanner->next();                        //(
    scanner->next();                        //Vector
    scanner->next();                        //(
    scanner->next();                        //(
    ASSERT_EQ(-4.28, scanner->nextDouble());
}

TEST_F(ScannerTest, testIsDone){
    delete scanner;
    scanner=new Scanner("");
    ASSERT_TRUE(scanner->isDone());
}
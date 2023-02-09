#include "../../../../src/graphics/drag_and_drop/command/macro_command.h"
#include "./mock_command.h"

class MacroCommandTest : public ::testing::Test{
    protected:
        MacroCommand macroCommand;
        Command *mockCommand1,*mockCommand2;

        void SetUp() override{
            macroCommand=MacroCommand();
            mockCommand1=new MockCommand();
            mockCommand2=new MockCommand();
        }

        void TearDown() override{}
};

TEST_F(MacroCommandTest, testExecute){

    macroCommand.addCommand(mockCommand1);
    macroCommand.addCommand(mockCommand2);
    macroCommand.execute();

    std::vector<Command *> commands=macroCommand.getCommands();

    ASSERT_TRUE(dynamic_cast<MockCommand *>(commands.at(0))->isExecuteCalled());
}

TEST_F(MacroCommandTest, testUndo){

    macroCommand.addCommand(mockCommand1);
    macroCommand.addCommand(mockCommand2);
    macroCommand.execute();
    macroCommand.undo();

    std::vector<Command *> commands=macroCommand.getCommands();

    ASSERT_TRUE(dynamic_cast<MockCommand *>(commands.at(0))->isUndoCalled());
}

TEST_F(MacroCommandTest, testAddCommand){
    
    macroCommand.addCommand(mockCommand1);
    macroCommand.addCommand(mockCommand2);
    macroCommand.execute();

    std::vector<Command *> commands=macroCommand.getCommands();

    ASSERT_TRUE(dynamic_cast<MockCommand *>(commands.at(1))->isExecuteCalled());
    
}

TEST_F(MacroCommandTest, testGetCommands){
    macroCommand.addCommand(mockCommand1);
    macroCommand.addCommand(mockCommand2);
    macroCommand.execute();
    macroCommand.undo();

    std::vector<Command *> commands=macroCommand.getCommands();

    ASSERT_TRUE(dynamic_cast<MockCommand *>(commands.at(1))->isUndoCalled());
}




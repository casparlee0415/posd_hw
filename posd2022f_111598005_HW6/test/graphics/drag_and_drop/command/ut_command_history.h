#include "./mock_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"

class CommandHistoryTest : public ::testing::Test{
    protected:
        Command *mock1,*mock2; 
        CommandHistory history;

        void SetUp() override{
            history=CommandHistory();
            mock1=new MockCommand();
            mock2=new MockCommand();
        }

        void TearDown() override{}
};

TEST_F(CommandHistoryTest, testAddCommand){
    history.addCommand(mock1);
    history.addCommand(mock2);

    mock2->execute();

    std::stack<Command *> result=history.getHistory();

    ASSERT_TRUE(dynamic_cast<MockCommand *>(result.top())->isExecuteCalled());
}

TEST_F(CommandHistoryTest, testUndo){
    history.addCommand(mock1);
    history.addCommand(mock2);

    mock1->execute();

    history.undo();

    std::stack<Command *> result=history.getHistory();

    ASSERT_TRUE(dynamic_cast<MockCommand *>(result.top())->isExecuteCalled());
}

TEST_F(CommandHistoryTest, testBeginMacroCommand){
    history.beginMacroCommand();
    history.addCommand(mock1);
    history.addCommand(mock2);
    history.endMacroCommand();

    mock1->execute();
    std::vector<Command *> result=history.getHistory().top()->getCommands();

    ASSERT_TRUE(dynamic_cast<MockCommand *>(result.at(0))->isExecuteCalled());
}

TEST_F(CommandHistoryTest, testEndMacroCommand){
    history.beginMacroCommand();
    history.addCommand(mock1);
    history.addCommand(mock2);
    history.endMacroCommand();

    mock2->execute();
    std::vector<Command *> result=history.getHistory().top()->getCommands();

    ASSERT_TRUE(dynamic_cast<MockCommand *>(result.at(1))->isExecuteCalled());
}

TEST_F(CommandHistoryTest, testGetHistory){
    history.addCommand(mock2);
    history.addCommand(mock1);

    mock1->execute();

    std::stack<Command *> result=history.getHistory();

    ASSERT_TRUE(dynamic_cast<MockCommand *>(result.top())->isExecuteCalled());
}



#include "../mock_drag_and_drop.h"
#include "../../../../src/graphics/drag_and_drop/command/drop_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"

class DropCommandTest : public ::testing::Test{
    protected:
        MockDragAndDrop mockDragAndDrop;
        CommandHistory history;
        DropCommand *dropCommand;

        void SetUp() override{
            MousePosition::getInstance()->setPos(85.23, 232.7);
            dropCommand=new DropCommand(&mockDragAndDrop, &history);
            mockDragAndDrop=MockDragAndDrop();
            history=CommandHistory();
        }

        void TearDown() override{
            delete dropCommand;
        }
};

TEST_F(DropCommandTest, testExecute){
    dropCommand->execute();

    ASSERT_NEAR(85.23, mockDragAndDrop.getDropX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getDropY(), 0.001);
}

TEST_F(DropCommandTest, testUndo){
    dropCommand->execute();
    dropCommand->undo();

    ASSERT_NEAR(85.23, mockDragAndDrop.getGrabX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getGrabY(), 0.001);
}

TEST_F(DropCommandTest, testgetX){
    dropCommand->execute();
    
    ASSERT_NEAR(85.23, dropCommand->getX(), 0.001);
}

TEST_F(DropCommandTest, testgetY){
    dropCommand->execute();
    
    ASSERT_NEAR(232.7, dropCommand->getY(), 0.001);
}

TEST_F(DropCommandTest, testAddCommand){
    Command *command=new DropCommand(*dropCommand);
    ASSERT_ANY_THROW(dropCommand->addCommand(command));
    delete command;
}

TEST_F(DropCommandTest, testGetCommands){
    ASSERT_ANY_THROW(dropCommand->getCommands());
}




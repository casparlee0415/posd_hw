#include "../mock_drag_and_drop.h"
#include "../../../../src/graphics/drag_and_drop/command/grab_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"

class GrabCommandTest : public ::testing::Test{
    protected:
        MockDragAndDrop mockDragAndDrop;
        CommandHistory history;
        GrabCommand *grabCommand;

        void SetUp() override{
            MousePosition::getInstance()->setPos(85.23, 232.7);
            grabCommand=new GrabCommand(&mockDragAndDrop, &history);
            mockDragAndDrop=MockDragAndDrop();
            history=CommandHistory();
        }

        void TearDown() override{
            delete grabCommand;
        }
};

TEST_F(GrabCommandTest, testExecute){
    grabCommand->execute();

    ASSERT_NEAR(85.23, mockDragAndDrop.getGrabX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getGrabY(), 0.001);
}

TEST_F(GrabCommandTest, testUndo){
    grabCommand->execute();
    grabCommand->undo();

    ASSERT_NEAR(85.23, mockDragAndDrop.getDropX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getDropY(), 0.001);
}

TEST_F(GrabCommandTest, testgetX){
    grabCommand->execute();
    
    ASSERT_NEAR(85.23, grabCommand->getX(), 0.001);
}

TEST_F(GrabCommandTest, testgetY){
    grabCommand->execute();
    
    ASSERT_NEAR(232.7, grabCommand->getY(), 0.001);
}

TEST_F(GrabCommandTest, testAddCommand){
    Command *command=new GrabCommand(*grabCommand);
    ASSERT_ANY_THROW(grabCommand->addCommand(command));
    delete command;
}

TEST_F(GrabCommandTest, testGetCommands){
    ASSERT_ANY_THROW(grabCommand->getCommands());
}




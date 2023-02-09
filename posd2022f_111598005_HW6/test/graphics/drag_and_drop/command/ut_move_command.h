#include "../mock_drag_and_drop.h"
#include "../../../../src/graphics/drag_and_drop/command/move_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"

class MoveCommandTest : public ::testing::Test{
    protected:
        MockDragAndDrop mockDragAndDrop;
        CommandHistory history;
        MoveCommand *moveCommand;

        void SetUp() override{
            MousePosition::getInstance()->setPos(85.23, 232.7);
            moveCommand=new MoveCommand(&mockDragAndDrop, &history);
            mockDragAndDrop=MockDragAndDrop();
            history=CommandHistory();
        }

        void TearDown() override{
            delete moveCommand;
        }
};

TEST_F(MoveCommandTest, testExecute){
    moveCommand->execute();

    ASSERT_NEAR(85.23, mockDragAndDrop.getMoveX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getMoveY(), 0.001);
}

TEST_F(MoveCommandTest, testUndo){
    moveCommand->execute();
    moveCommand->undo();

    ASSERT_NEAR(85.23, mockDragAndDrop.getMoveX(), 0.001);
    ASSERT_NEAR(232.7, mockDragAndDrop.getMoveY(), 0.001);
}

TEST_F(MoveCommandTest, testgetX){
    moveCommand->execute();
    
    ASSERT_NEAR(85.23, moveCommand->getX(), 0.001);
}

TEST_F(MoveCommandTest, testgetY){
    moveCommand->execute();
    
    ASSERT_NEAR(232.7, moveCommand->getY(), 0.001);
}

TEST_F(MoveCommandTest, testAddCommand){
    Command *command=new MoveCommand(*moveCommand);
    ASSERT_ANY_THROW(moveCommand->addCommand(command));
    delete command;
}

TEST_F(MoveCommandTest, testGetCommands){
    ASSERT_ANY_THROW(moveCommand->getCommands());
}




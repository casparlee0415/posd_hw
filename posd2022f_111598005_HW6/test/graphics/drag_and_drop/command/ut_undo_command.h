#include "../mock_drag_and_drop.h"
#include "../../../../src/graphics/drag_and_drop/command/undo_command.h"
#include "./mock_command.h"
#include "../../../../src/graphics/drag_and_drop/command/command_history.h"

class UndoCommandTest : public ::testing::Test{
    protected:
        MockDragAndDrop mockDragAndDrop;
        CommandHistory history;
        UndoCommand *undoCommand;
        MockCommand *mockCommand1,*mockCommand2;

        void SetUp() override{
            mockCommand1=new MockCommand();
            mockCommand2=new MockCommand();

            MousePosition::getInstance()->setPos(85.23, 232.7);
            undoCommand=new UndoCommand(&mockDragAndDrop, &history);
            mockDragAndDrop=MockDragAndDrop();
            history=CommandHistory();
            
            history.addCommand(mockCommand1);
            history.addCommand(mockCommand2);
        }

        void TearDown() override{
            delete undoCommand;
        }
};

TEST_F(UndoCommandTest, testExecute){

    undoCommand->execute();

    ASSERT_TRUE(mockCommand2->isUndoCalled());
}

TEST_F(UndoCommandTest, testUndo){
    ASSERT_NO_THROW(undoCommand->undo());
}

TEST_F(UndoCommandTest, testAddCommand){
    Command *command=new MockCommand();
    ASSERT_ANY_THROW(undoCommand->addCommand(command));
    delete command;
}

TEST_F(UndoCommandTest, testGetCommands){
    ASSERT_ANY_THROW(undoCommand->getCommands());
}




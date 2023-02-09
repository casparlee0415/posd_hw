#pragma once

#include "command.h"
#include "command_history.h"
#include "../drag_and_drop.h"
#include "../mouse_position.h"

class MoveCommand : public Command
{
private:
    DragAndDrop *_dragAndDrop;
    CommandHistory *_commandHistory;
    double _x, _y;

public:
    MoveCommand(DragAndDrop *dragAndDrop, CommandHistory *commandHistory) 
        :_dragAndDrop(dragAndDrop),_commandHistory(commandHistory){
    }

    MoveCommand(const MoveCommand &moveCommand) 
        :MoveCommand(moveCommand._dragAndDrop,moveCommand._commandHistory){
        _x=moveCommand._x;
        _y=moveCommand._y;
    }                                                                                       // copy constructor

    void execute() override {
        MousePosition *instance=MousePosition::getInstance();
        _x=instance->getX();
        _y=instance->getY();
        _dragAndDrop->move(_x,_y);
        _commandHistory->addCommand(new MoveCommand(*this));
    }

    void undo() override {
        _dragAndDrop->move(_x,_y);
    }

    double getX() const {
        return _x;
    }

    double getY() const {
        return _y;
    }
};

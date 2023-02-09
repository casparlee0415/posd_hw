#pragma once

#include "command.h"
#include "command_history.h"
#include "../drag_and_drop.h"
#include "../mouse_position.h"

class DropCommand : public Command
{
private:
    DragAndDrop *_dragAndDrop;
    CommandHistory *_commandHistory;
    double _x, _y;

public:
    DropCommand(DragAndDrop *dragAndDrop, CommandHistory *commandHistory)
        :_dragAndDrop(dragAndDrop),_commandHistory(commandHistory){
    }
    DropCommand(const DropCommand &dropCommand) // copy constructor
        :DropCommand(dropCommand._dragAndDrop,dropCommand._commandHistory){
        _x=dropCommand._x;
        _y=dropCommand._y;
    }

    void execute() override {
        MousePosition *instance=MousePosition::getInstance();
        _x=instance->getX();
        _y=instance->getY();
        _dragAndDrop->drop(_x,_y);
        _commandHistory->addCommand(new DropCommand(*this));
        _commandHistory->endMacroCommand();
    }

    void undo() override {
        _dragAndDrop->grab(_x,_y);
    }

    double getX() const {
        return _x;
    }

    double getY() const {
        return _y;
    }
};

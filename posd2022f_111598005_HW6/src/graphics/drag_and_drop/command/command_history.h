#pragma once

#include <stack>
#include "command.h"
#include "macro_command.h"

class CommandHistory
{
private:
    bool inMacro = false;
    std::stack<Command *> _history;
    std::stack<Command *> _undoCommands;

public:
    CommandHistory() {}
    ~CommandHistory() {
        while(!_history.empty()){
            delete _history.top();
            _history.pop();
        }
        while(!_undoCommands.empty()){
            delete _undoCommands.top();
            _undoCommands.pop();
        }
    }

    void beginMacroCommand() {
        inMacro=true;
        _history.push(new MacroCommand());
    }

    void addCommand(Command *command) {
        if(inMacro) _history.top()->addCommand(command);
        else _history.push(command);
    }

    void endMacroCommand() {
        inMacro=false;
    }

    void undo() {
        _history.top()->undo();
        _undoCommands.push(_history.top()); 
        _history.pop();
    }

    std::stack<Command *> getHistory() {
        return _history;
    }
};
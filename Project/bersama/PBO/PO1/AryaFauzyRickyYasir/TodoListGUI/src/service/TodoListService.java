package service;

import model.TodoList;

public interface TodoListService {
    void showTodoList();

    void addTodoList(String todo);

    void removeTodoList(Integer number);

    void updateTodoList(Integer number, String todo);

    TodoList[] showTodoListForGUI();
}
